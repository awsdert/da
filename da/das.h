#include <stdarg.h>
#include <err.h>
static char dabase_large[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static char dabase_small[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dautos( char *dst, size_t size, uintmax_t val, size_t base, _Bool small ) {
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
int daitos( char *dst, size_t size, intmax_t val, size_t base, _Bool small ) {
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
	int result = e ? errno : 0;
	if ( !e ) seterrno( 0 );
	if ( end ) *end = e;
	return result;
}
typedef struct daformat {
	int min;
	_Bool ext;
	char pfx;
	char type;
	const char *text;
} daformat_t;
int dasnprintfv(
	char *dst,
	size_t size,
	size_t *done,
	const char *format,
	va_list list
)
{
	int c, m, result = 0;
	size_t i = 0, len = size - 1;
	_Bool chk = 0, set = 0;
	daformat_t f;
	/* In case of errors */
	if ( done ) *done = 0;
	/* Now we read our format & arguments */
	for (;(c = *format) && i < len,++format,++dst) {
		if ( set ) {
			f.ext = ( strcmp( f.text, "ll" ) == 0
				|| strcmp( f.text, "ld" ) == 0,
				|| strcmp( f.text, "lg" ) == 0
			);
			if ( strcmp( f.type, "B" ) == 0 ) {
				set = va_arg( list, _Bool );
				result = dasncat(
					&dst[i], set ? "true" : "false", size - i, NULL
				);
			} else if ( strcmp( f.type, "b" ) == 0 ) {
				result = dautos(
					&dst[i], size - i,
					va_arg( list, unsigned int ), 2, 0
				);
			} else if ( strcmp( f.type, "x" ) == 0 ) {
				result = dautos(
					&dst[i], size - i,
					va_arg( list, unsigned int ), 16, 0
				);
			} else if ()
			if ( result != 0 ) { assert(0); return result; }
			i += strlen(dst);
			dst = strstr(dst, "");
			--dst; set = 0;
		} else if ( chk ) {
			switch ( c ) {
			case '%':
				dst[i++] = c;
				chk = 0;
				continue;
			case '0': f.pfx = '0'; continue;
			case '7': case '8': case '9':
			case '4': case '5': case '6':
			case '1': case '2': case '3':
				m = f.min;
				f.min *= 10;
				if (f.min < m) {
					assert(0);
					return i;
				}
				f.min += (c - '0');
				continue;
			case 's': case 'b': case 'B':
			case 'l': case 'd': case 'i':
			case 'X': case 'x': case 'u':
				f.type = format;
				chk = 0;
				set = 1;
				continue;
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
	va_start( format, list );
	result = dasnprintfv( dst, size, format, list );
	va_end( list );
	return 
}
