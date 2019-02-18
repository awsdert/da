#include "das.h"
static const CDAC dabase_large[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const CDAC dabase_small[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dautos( CDAC *dst, size_t size, udam_t val, size_t base, bool small ) {
	const CDAC *txt = small ? dabase_small : dabase_large;
	size_t i = 0, len = size - 1;
	CDAC *tmp = &dst[len];
	if ( base < 2 || base > strlen(txt) ) goto dautos_range;
	for ( ; val > 0 && tmp >= dst; --tmp ) {
		*tmp = txt[val % base];
		val /= base; ++i;
	} if ( val > 0 ) goto dautos_nomem;
	for ( tmp = &dst[len]; dst != tmp; ++dst, --tmp, --i ) {
		*dst = *tmp;
		*tmp = 0;
	} dst[len] = 0;
	if ( i > 0 ) goto dautos_nomem;
	return 0;
	dautos_range:
	memset( dst, 0, size );
	return ERANGE;
	dautos_nomem:
	memset( dst, 0, size );
	return ENOMEM;
}
int daitos( CDAC *dst, size_t size, idam_t val, size_t base, bool small ) {
	if ( val < 0 ) {
		*dst = '-';
		++dst; --size;
		return ( val == INTMAX_MIN )
			? dautos( dst, size, val, base, small )
			: dautos( dst, size, -val, base, small );
	} return dautos( dst, size, val, base, small );
}
int dasncat( CDAC *dst, const CDAC *src, size_t size, CDAC **end ) {
	CDAC *e = strncat( dst, src, size );
	int result = e ? 0 : errno;
	if ( !e ) errno = 0;
	if ( end ) *end = e;
	return result;
}
int dasmatch( const CDAC *str, const CDAC *txt, size_t upto ) {
	size_t i = 0, len = strlen(txt);
	for ( ; *str && *txt && i < upto; ++i ) {
		if ( *str != *txt ) return (i >=len) ? 1 : -1;
	} return (i == upto) ? 2 : 0;
}
#if CHAR_BIT >= 8
static const size_t U4_LIM = 5;
static const size_t U2_LIM = 3;
#else
static const size_t U4_LIM = 7;
static const size_t U2_LIM = 5;
#endif
size_t dasncpy32( CDAC *str, const CDAC32_t *txt, size_t upto ) {
	size_t i = 0, done;
	if ( !str || !txt || !upto ) return EINVAL;
	for ( ; *txt; ++txt ) {
		if (
			( *txt > CHAR16_MAX && upto < U4_LIM ) ||
			( *txt > CHAR_MAX && upto < U2_LIM )
		) return ENOMEM;
		done = c32rtomb( str, *txt, NULL );
		i += done;
		/* Indicate failure to copy whole txt */
		if ( i >= upto ) return 0;
		str = &str[done];
	}
	return i;
}
size_t dasncpy16( CDAC *str, const CDA16 *txt, size_t upto ) {
	size_t i = 0, done;
	if ( !str || !txt || !upto ) return EINVAL;
	for ( ; *txt; ++txt, --upto ) {
		if ( *txt > CHAR_MAX && upto < U2_LIM ) return ENOMEM;
		done = c16rtomb( str, *txt, NULL );
		i += done; upto -= done;
		/* Indicate failure to copy whole txt */
		if ( i >= upto ) return 0;
		str = &str[done];
	}
	return i;
}
size_t dasncpyw( CDAC *str, const CDAW *txt, size_t upto ) {
#if WCHAR_MAX == CHAR16_MAX
	return dasncpy16( str, (CDA16*)txt, upto );
#else
	return dasncpy32( str, (CDAC32_t*)txt, upto );
#endif
}
size_t dasncat32( CDAC *str, CDAC32_t *txt, size_t upto ) {
	size_t len = 0;
	if ( !str ) return 0;
	while ( *str ) { ++len; if (len >= upto) { return 0; } }
	return dasncpy32( &str[len], txt, upto - len );
}
size_t dasncat16( CDAC *str, CDA16 *txt, size_t upto ) {
	size_t len = 0;
	if ( !str ) return 0;
	while ( *str ) { ++len; if (len >= upto) { return 0; } }
	return dasncpy16( &str[len], txt, upto - len );
}
size_t dasncatw( CDAC *str, CDAW *txt, size_t upto ) {
	size_t len = 0;
	if ( !str ) return 0;
	while ( *str ) { ++len; if (len >= upto) { return 0; } }
#if WCHAR_MAX == CHAR16_MAX
	return dasncpy16( str, (CDA16*)txt, upto );
#else
	return dasncpy32( str, (CDAC32_t*)txt, upto );
#endif
}
#define DAFORMAT_C	0x1
#define DAFORMAT_S	0x2
#define DAFORMAT_L	0x3
#define DAFORMAT_LL	0x4
#define DAFORMAT_M	0x5
#define DAFORMAT_P	0x6
#define DAFORMAT_Z	0x7
#define DAFORMAT_U2	0x8
#define DAFORMAT_U4 0x9
typedef struct daformat {
	int min;
	udac_t info;
	CDAC pfx;
	CDAC type;
	const CDAC *text;
	fdam_t fmax;
	idam_t imax;
	udam_t umax;
} daformat_t;
/* Prevents accidentally breaking loop */
int _dasnprintfv_getarg(
	CDAC *dst,
	size_t size,
	daformat_t *f, 
	va_list list
) {
	size_t len = strlen(f->text);
	int result = 0;
	if (dasmatch(f->text,"c",len)==1) f->info = DAFORMAT_C;
	else if (dasmatch(f->text,"s",len)==1) f->info = DAFORMAT_S;
	else if (dasmatch(f->text,"ll",len)==1) f->info = DAFORMAT_LL;
	else if (dasmatch(f->text,"l",len)==1) f->info = DAFORMAT_L;
	else if (dasmatch(f->text,"u",len)==1) f->info = DAFORMAT_U2;
	else if (dasmatch(f->text,"U",len)==1) f->info = DAFORMAT_U4;
	else if (dasmatch(f->text,"m",len)==1) f->info = DAFORMAT_M;
	else if (dasmatch(f->text,"p",len)==1) f->info = DAFORMAT_P;
	else if (dasmatch(f->text,"z",len)==1) f->info = DAFORMAT_Z;
	else f->info = 0;
	switch ( f->type ) {
	case 'i': case 'd': case 'c':
		if (f->info == DAFORMAT_C)
			f->imax = *(va_arg( list, idac_t * ));
		else if (f->info == DAFORMAT_S)
			f->imax = *(va_arg( list, idas_t * ));
		else if (f->info == DAFORMAT_LL)
#ifdef IDALL
			f->imax = *(va_arg( list, idall_t * ));
#else
			return ENOKEY;
#endif
		else if (f->info == DAFORMAT_L)
			f->imax = *(va_arg( list, idal_t * ));
		else if (f->info == DAFORMAT_M)
			f->imax = *(va_arg( list, idam_t * ));
		else if (f->info == DAFORMAT_P)
			f->imax = *(va_arg( list, idap_t * ));
		else if (f->info == DAFORMAT_Z)
			f->imax = *(va_arg( list, size_t * ));
		else
			f->imax = va_arg( list, idai_t );
		break;
	case 'u': case 'b': case 'o': case 'x': case 'X':
		if (f->info == DAFORMAT_C)
			f->umax = *(va_arg( list, udac_t * ));
		else if (f->info == DAFORMAT_S)
			f->umax = *(va_arg( list, udas_t * ));
		else if (f->info == DAFORMAT_LL)
#ifdef UDALL
			f->umax = *(va_arg( list, udall_t * ));
#else
			return ENOKEY;
#endif
		else if (f->info == DAFORMAT_L)
			f->umax = *(va_arg( list, udal_t * ));
		else if (f->info == DAFORMAT_M)
			f->umax = *(va_arg( list, udam_t * ));
		else if (f->info == DAFORMAT_P)
			f->umax = *(va_arg( list, udap_t * ));
		else if (f->info == DAFORMAT_Z)
			f->umax = *(va_arg( list, size_t * ));
		else
			f->umax = va_arg( list, udai_t );
		break;
	}
	switch ( f->type ) {
	case 'c':
		if ( size < U4_LIM ) return ENOMEM;
		if ( f->imax < CHAR32_MIN || f->imax > CHAR32_MAX ) return ERANGE;
		c32rtomb( dst, (CDAC32_t)f->imax, NULL );
		break;
	case 'B': result = dasncat( dst, f->umax ? "true" : "false", size, NULL );
		break;
	case 'i':
	case 'd': result = daitos( dst, size, f->imax, 10, false );	break;
	case 'b': result = dautos( dst, size, f->umax, 2, false );	break;
	case 'o': result = dautos( dst, size, f->umax, 8, false );	break;
	case 'u': result = dautos( dst, size, f->umax, 10, false );	break;
	case 'x': result = dautos( dst, size, f->umax, 16, true );	break;
	case 'X': result = dautos( dst, size, f->umax, 16, false );	break;
	case 's':
		if ( f->info == DAFORMAT_U4 )
			result = (dasncat32( dst, va_arg( list, CDAC32_t* ), size ))
			? 0 : ENOMEM;
		else if ( f->info == DAFORMAT_U2 )
			result = (dasncat16( dst, va_arg( list, CDA16* ), size ))
			? 0 : ENOMEM;
		else if ( f->info == DAFORMAT_L )
			result = (dasncatw( dst, va_arg( list, CDAW* ), size ))
			? 0 : ENOMEM;
		else
			result = (dasncat( dst, va_arg( list, CDAC* ), size, NULL ))
			? 0 : ENOMEM;
		break;
	}
	(void)memset( f, 0, sizeof(daformat_t) );
	return result;
}
int dasnprintfv(
	CDAC *dst,
	size_t size,
	const CDAC *format,
	va_list list
)
{
	int c, result = 0, m = 0;
	size_t i = 0, len = size - 1;
	bool chk = 0, set = 0;
	daformat_t f;
	/* Now we read our format & arguments */
	for (;(c = *format) && i < len;++format) {
		if ( chk ) {
			switch ( c ) {
			case '%':
			{
				*dst++ = c;
				--size; ++i;
				chk = 0;
				continue;
			}
			case '0': f.pfx = '0'; continue;
			case '7': case '8': case '9':
			case '4': case '5': case '6':
			case '1': case '2': case '3':
			{
				m = f.min;
				f.min *= 10;
				if (f.min < m) {
					return ERANGE;
				}
				f.min += (c - '0');
				break;
			}
			case 's': case 'b': case 'B':
			case 'l': case 'd': case 'i':
			case 'X': case 'x': case 'u':
				f.type = c;
				chk = 0;
				set = 1;
			}
			if ( set ) {
				result = _dasnprintfv_getarg( dst, size, &f, list );
				if ( result != 0 ) { return result; }
				len = strlen(dst);
				i += len; size -= len;
				dst = &dst[len];
				set = 0;
			}
		} else if ( c == '%' ) {
			f.type = 0;
			f.pfx = ' ';
			f.min = 0;
			chk = 1;
		}
	} *dst = 0;
	return result;
}
int dasnprintf(
	CDAC *dst,
	size_t size,
	const CDAC *format,
	...
) {
	int result;
	va_list list;
	va_start( list, format );
	result = dasnprintfv( dst, size, format, list );
	va_end( list );
	return result;
}
