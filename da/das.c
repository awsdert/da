#include "das.h"
static const cdac_t dabase_large[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const cdac_t dabase_small[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dautos( cdac_t *dst, size_t upto, udam_t val, size_t base, bool small ) {
	const cdac_t *txt = small ? dabase_small : dabase_large;
	size_t i = 0, len = upto - 1;
	cdac_t *tmp = &dst[len];
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
	memset( dst, 0, upto );
	return ERANGE;
	dautos_nomem:
	memset( dst, 0, upto );
	return ENOMEM;
}
int daitos( cdac_t *dst, size_t upto, idam_t val, size_t base, bool small ) {
	if ( val < 0 ) {
		*dst = '-';
		++dst; --upto;
		return ( val == IDAM_MIN )
			? dautos( dst, upto, val, base, small )
			: dautos( dst, upto, -val, base, small );
	} return dautos( dst, upto, val, base, small );
}
int dasmatch( const cdac_t *str, const cdac_t *txt, size_t upto ) {
	size_t i = 0, len = strlen(txt);
	for ( ; *str && *txt && i < upto; ++i ) {
		if ( *str != *txt ) return (i >=len) ? 1 : -1;
	} return (i == upto) ? 2 : 0;
}
#if IDAC_BIT >= 8
static const size_t U4_LIM = 5;
static const size_t U2_LIM = 3;
#else
static const size_t U4_LIM = 7;
static const size_t U2_LIM = 5;
#endif
/* Very useful reference
https://www.ibm.com/developerworks/library/l-linuni/index.html
*/
const size_t CDAM_MAX_BIT = IDAC_BIT - 2;
/* Account for '\0' also */
const size_t CDAM_MAX_LEN = (32/(IDAC_BIT - 2)) + (IDAC_BIT>=8 ? 2 : 3);
int dalctoc( cdac_t *dst, size_t upto, unsigned long c32, size_t *done ) {
	size_t i = 0, bits = 0, bytes = 0;
	unsigned long bit = IDAL_MIN, rec;
	if ( !dst || upto < CDAM_MAX_LEN
#if UDAL_MAX >= 0xFFFFFFFFUL
	|| c32 > 0xFFFFFFFFUL
#endif
	) {
		if ( done ) *done = 0;
		return 1;
	}
	memset( dst, 0, CDAM_MAX_LEN );
	if ( c32 <= IDAC_MAX ) {
		*dst = (cdac_t)c32;
		if ( done ) *done = 1;
		return 0;
	}
	for ( ; !(bit & c32); bit >>= 1 );
	rec = bit;
	for ( ; bit; bit >>= 1, ++bits );
	bytes = (bits / CDAM_MAX_BIT) + ((bits % CDAM_MAX_BIT) ? 1 : 0);
	bit = IDAC_MIN;
	for ( ; bytes; --bytes ) {
		bit >>= 1;
		dst[i] |= bit;
		if ( (udac_t)(dst[i]) == UDAC_MAX ) {
			++i;
			bit = IDAC_MIN;
		}
	}
	for ( ; i < CDAM_MAX_LEN && c32; ++i ) {
		for ( ; c32 && bit; c32 <<= 1 ) {
			if ( c32 & rec ) {
				dst[i] |= (cdac_t)bit;
			}
		}
		bit = IDAL_MIN;
		bit >>= 2;
	}
	if ( done ) *done = i;
	return 0;
}
int dasncpy32( cdac_t *dst, size_t upto, const cda32_t *txt, size_t *done ) {
	int ret = 0;
	size_t i = 0, used = 0, left = upto;
	if ( !dst || !txt || !upto ) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; *txt; ++txt ) {
		if ( (ret = dalctoc( &(dst[i]), left, *txt, &used )) != 0 ) {
			if ( done ) *done = i;
			return ret;
		}
		i += used;
		left -= used;
	}
	if ( done ) *done = i;
	return 0;
}
int dasncpy16(
	cdac_t *dst, size_t upto, const cda16_t *txt, size_t *done ) {
	int ret = 0;
	size_t i = 0, used = 0, left = upto;
	if ( !dst || !txt || !upto ) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; *txt; ++txt ) {
		if ( (ret = dalctoc( &(dst[i]), left, *txt, &used )) != 0 ) {
			if ( done ) *done = i;
			return ret;
		}
		i += used;
		left -= used;
	}
	if ( done ) *done = i;
	return 0;
}
int dasncpyw( cdac_t *dst, size_t upto, const cdaw_t  *txt, size_t *done ) {
#if CDAW_MAX == CDA16_MAX
	return dasncpy16( dst, upto, (cda16_t*)txt, done );
#else
	return dasncpy32( dst, upto, (cda32_t*)txt, done );
#endif
}
int dasncpy( cdac_t *dst, size_t upto, const cdac_t *txt, size_t *done ) {
	size_t i = 0;
	if ( !dst || !txt || !upto ) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; *txt; ++dst, ++txt, ++i ) {
		if ( i >= upto ) {
			if ( done ) *done = i;
			return 2;
		}
		*dst = *txt;
	}
	if ( done ) *done = i;
	return 0;
}
int dasncat32(
	cdac_t *dst, size_t upto, const cda32_t *txt, size_t *done ) {
	size_t len = 0;
	if ( !dst || !upto) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; dst[len]; ++len ) {
		if (len >= upto) {
			if ( done ) *done = 0;
			return 2;
		}
	}
	return dasncpy32( &dst[len], upto - len, txt, done );
}
int dasncat16(
	cdac_t *dst, size_t upto, const cda16_t *txt, size_t *done ) {
	size_t len = 0;
	if ( !dst || !upto ) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; dst[len]; ++len ) {
		if (len >= upto) {
			if ( done ) *done = 0;
			return 2;
		}
	}
	return dasncpy16( &dst[len], upto - len, txt, done );
}
int dasncatw(
	cdac_t *dst, size_t upto, const cdaw_t  *txt, size_t *done ) {
	size_t len = 0;
	if ( !dst || !upto) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; dst[len]; ++len ) {
		if (len >= upto) {
			if ( done ) *done = 0;
			return 2;
		}
	}
#if CDAW_MAX == CDA16_MAX
	return dasncpy16( &dst[len], upto - len, (cda16_t*)txt, done );
#else
	return dasncpy32( &dst[len], upto - len, (cda32_t*)txt, done );
#endif
}
int dasncat(
	cdac_t *dst, size_t upto, const cdac_t *txt, size_t *done ) {
	size_t len = 0;
	if ( !dst || !upto) {
		if ( done ) *done = 0;
		return 1;
	}
	for ( ; dst[len]; ++len ) {
		if (len >= upto) {
			if ( done ) *done = 0;
			return 2;
		}
	}
	return dasncpy( &dst[len], upto - len, txt, done );
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
	cdac_t pfx;
	cdac_t type;
	const cdac_t *text;
	fdam_t fmax;
	idam_t imax;
	udam_t umax;
} daformat_t;
/* Prevents accidentally breaking loop */
int _dasnprintfv_getarg(
	cdac_t *dst, size_t upto, daformat_t *f, va_list list ) {
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
		if ( upto < U4_LIM ) return ENOMEM;
		if ( f->imax < CDA32_MIN || f->imax > CDA32_MAX ) return ERANGE;
		dalctoc( dst, upto, (cda32_t)f->imax, NULL );
		break;
	case 'B': result = dasncat( dst, upto, f->umax ? "true" : "false", NULL );
		break;
	case 'i':
	case 'd': result = daitos( dst, upto, f->imax, 10, false );	break;
	case 'b': result = dautos( dst, upto, f->umax, 2, false );	break;
	case 'o': result = dautos( dst, upto, f->umax, 8, false );	break;
	case 'u': result = dautos( dst, upto, f->umax, 10, false );	break;
	case 'x': result = dautos( dst, upto, f->umax, 16, true );	break;
	case 'X': result = dautos( dst, upto, f->umax, 16, false );	break;
	case 's':
		if ( f->info == DAFORMAT_U4 )
			result = (dasncat32( dst, upto, va_arg( list, cda32_t* ), NULL ))
			? 0 : ENOMEM;
		else if ( f->info == DAFORMAT_U2 )
			result = (dasncat16( dst, upto, va_arg( list, cda16_t* ), NULL ))
			? 0 : ENOMEM;
		else if ( f->info == DAFORMAT_L )
			result = (dasncatw( dst, upto, va_arg( list, cdaw_t* ), NULL ))
			? 0 : ENOMEM;
		else
			result = (dasncat( dst, upto, va_arg( list, cdac_t* ), NULL ))
			? 0 : ENOMEM;
		break;
	}
	(void)memset( f, 0, sizeof(daformat_t) );
	return result;
}
int dasnprintfv(
	cdac_t *dst,
	size_t upto,
	const cdac_t *format,
	va_list list
)
{
	int c, result = 0, m = 0;
	size_t i = 0, len = upto - 1;
	udab_t chk = 0, set = 0;
	daformat_t f;
	/* Now we read our format & arguments */
	for (;(c = *format) && i < len;++format) {
		if ( chk ) {
			switch ( c ) {
			case '%':
			{
				*dst++ = c;
				--upto; ++i;
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
				result = _dasnprintfv_getarg( dst, upto, &f, list );
				if ( result != 0 ) { return result; }
				len = strlen(dst);
				i += len; upto -= len;
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
	cdac_t *dst,
	size_t upto,
	const cdac_t *format,
	...
) {
	int result;
	va_list list;
	va_start( list, format );
	result = dasnprintfv( dst, upto, format, list );
	va_end( list );
	return result;
}
