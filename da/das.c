#include <stdarg.h>
#include <err.h>
#include <types.h>
static char dabase_large[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static char dabase_small[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dautos( char *dst, size_t size, udam_t val, size_t base, bool small ) {
	char *txt = small ? base_small : base_large;
	size_t i = 0, len = size - 1;
	char *tmp = &dst[len];
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
int daitos( char *dst, size_t size, idam_t val, size_t base, bool small ) {
	if ( val < 0 ) {
		*dst = '-';
		++dst; --size;
		return ( val == INTMAX_MIN )
			? dautos( tmp, size, val, base, small )
			: dautos( tmp, size, -val, base, small );
	} return dautos( dst, size, val, base, small );
}
int dasncat( char *dst, const char *src, size_t size, char **end ) {
	char *e = strncat( dst, src, size );
	int result = e ? 0 : errno;
	if ( !e ) errno = 0;
	if ( end ) *end = e;
	return result;
}
int dasmatch( const char *str, const char *txt, size_t max ) {
	size_t i = 0, len = strlen(txt);
	for ( ; *str && *txt && i < max; ++i ) {
		if ( *str != *txt ) return (i >=len) ? 1 : -1;
	} return (i == max) ? 2 : 0;
}
#define DAFORMAT_C	0x1
#define DAFORMAT_S	0x2
#define DAFORMAT_L	0x3
#define DAFORMAT_LL	0x4
#define DAFORMAT_M	0x5
#define DAFORMAT_P	0x6
#define DAFORMAT_Z	0x7
typedef struct daformat {
	int min;
	dauc_t info;
	char pfx;
	char type;
	const char *text;
	fltmax_t gmax;
	idam_t imax;
	udam_t umax;
} daformat_t;
/* Prevents accidentally breaking loop */
int _dasnprintfv_getarg(
	char *dst,
	size_t size,
	size_t *done,
	daformat_t *f, 
	va_list list
) {
	size_t len = strlen(f.text);
	int result = 0;
	if (dasmatch(f.text,"c",len)==1) f->info = DAFORMAT_C;
	else if (dasmatch(f.text,"s",len)==1) f->info = DAFORMAT_S;
	else if (dasmatch(f.text,"ll",len)==1) f->info = DAFORMAT_LL;
	else if (dasmatch(f.text,"l",len)==1) f->info = DAFORMAT_L;
	else if (dasmatch(f.text,"m",len)==1) f->info = DAFORMAT_M;
	else if (dasmatch(f.text,"p",len)==1) f->info = DAFORMAT_P;
	else if (dasmatch(f.text,"z",len)==1) f->info = DAFORMAT_Z;
	else f->info = 0;
	switch ( f.type ) {
	case 'i': case 'd':
		if (f->info == DAFORMAT_C)
			imax = *(va_arg( list, idac_t * ));
		else if (f->info == DAFORMAT_S)
			imax = *(va_arg( list, idas_t * ));
		else if (f->info == DAFORMAT_LL)
#ifdef DALL
			imax = *(va_arg( list, idall_t * ));
#else
			return ENOKEY;
#endif
		else if (f->info == DAFORMAT_L)
			imax = *(va_arg( list, idal_t * ));
		else if (f->info == DAFORMAT_M)
			imax = *(va_arg( list, idam_t * ));
		else if (f->info == DAFORMAT_P)
			imax = *(va_arg( list, idap_t * ));
		else if (f->info == DAFORMAT_Z)
			imax = *(va_arg( list, size_t * ));
		else
			imax = va_arg( list, idai_t );
		break;
	case 'u': case 'b': case 'o': case 'x': case 'X':
		if (f->info == DAFORMAT_C)
			umax = *(va_arg( list, udac_t * ));
		else if (f->info == DAFORMAT_S)
			umax = *(va_arg( list, udas_t * ));
		else if (f->info == DAFORMAT_LL)
#ifdef DA_LLONG
			umax = *(va_arg( list, udall_t * ));
#else
			return ENOKEY;
#endif
		else if (f->info == DAFORMAT_L)
			umax = *(va_arg( list, udal_t * ));
		else if (f->info == DAFORMAT_M)
			umax = *(va_arg( list, udam_t * ));
		else if (f->info == DAFORMAT_P)
			umax = *(va_arg( list, udap_t * ));
		else if (f->info == DAFORMAT_Z)
			umax = *(va_arg( list, size_t * ));
		else
			umax = va_arg( list, udai_t );
		break;
	}
	switch ( f.type ) {
	case 'B': result = dasncat( dst, bval ? "true" : "false", NULL );
		break;
	case 'i':
	case 'd': result = daitos( dst, size, val, 10, false );	break;
	case 'b': result = dautos( dst, size, val, 2, false );	break;
	case 'o': result = dautos( dst, size, val, 8, false );	break;
	case 'u': result = dautos( dst, size, val, 10, false );	break;
	case 'x': result = dautos( dst, size, val, 16, true );	break;
	case 'X': result = dautos( dst, size, val, 16, false );	break;
	case 's': result = dasncat( dst, va_arg( list, char* ), size );
		break;
	}
	(void)memset( f, 0, sizeof(daformat_t) );
	return result;
}
int dasnprintfv(
	char *dst,
	size_t size,
	size_t *done,
	const char *format,
	va_list list
)
{
	int c, result = 0;
	size_t i = 0, len = size - 1;
	bool chk = 0, set = 0;
	daformat_t f;
	/* In case of errors */
	if ( done ) *done = 0;
	/* Now we read our format & arguments */
	for (;(c = *format) && i < len,++format,++dst) {
		if ( chk ) {
			switch ( c ) {
			case '%':
			{
				dst[i++] = c;
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
					assert(0);
					return i;
				}
				f.min += (c - '0');
				break;
			}
			case 's': case 'b': case 'B':
			case 'l': case 'd': case 'i':
			case 'X': case 'x': case 'u':
				f.type = format;
				chk = 0;
				set = 1;
			}
			if ( set ) {
				result = _dasnprintfv_getarg( &f, list );
				if ( result != 0 ) { assert(0); return result; }
				i += strlen(dst);
				dst = strstr(dst, "");
				--dst; set = 0;
			}
		} else if ( c == '%' ) {
			f.type = NULL;
			f.pfx = ' ';
			f.min = 0;
			chk = 1;
		}
	} *dst = 0;
	if ( done ) *done = i;
	return result;
}
int dasnprintf(
	char *dst,
	size_t size,
	const char *format,
	...
) {
	int result;
	va_list list;
	va_start( list, format );
	result = dasnprintfv( dst, size, format, list );
	va_end( list );
	return 
}
