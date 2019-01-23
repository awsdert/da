#ifndef INC_DA_DAS_H
#define INC_DA_DAS_H
#include "ida.h"
#include <stdarg.h>
#include <string.h>
/** @param max is max number of characters to check
@return -1 if initial portion of str did not match txt
@return 0 if both strings match
@return 1 if initial portion of str matches txt but goes on beyond txt
@return 2 reached maximum characters to compare
**/
int dasmatch( const char *str, const char *txt, size_t max );
int dasncat(
	char *dst,
	const char *src,
	size_t size,
	char **end
);
int daftoa(
	char *dst.
	size_t size,
	idam_t val,
	size_t base,
	bool small
);
int dautoa(
	char *dst.
	size_t size,
	udam_t val,
	size_t base,
	bool small
);
int daitoa(
	char *dst.
	size_t size,
	intmax_t val,
	size_t base,
	bool small
);
int dasnprintf(
	char *dst,
	size_t size,
	size_t *done,
	char *format,
	...
);
#endif
