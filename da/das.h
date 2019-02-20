#ifndef INC_DA_DAS_H
#define INC_DA_DAS_H
#include "ida.h"
#include <stdarg.h>
#include <linux/err.h>
#include <linux/string.h>

#define _DA_TOSTR(VAL) (cdac_t*)(#VAL)
#define DA_TOSTR(VAL) _DA_TOSTR(VAL)
#define _DA_TOWCS(VAL) (cdaw_t*)(L###VAL)
#define DA_TOWCS(VAL) _DA_TOWCS(VAL)

#ifdef DA_OS_MSWIN
typedef CHAR cdac_t;
#define CDAC_MAX CHAR_MAX
#define CDAC_MIN CHAR_MAX
typedef WCHAR cdaw_t;
#define CDAW_MAX WCHAR_MAX
#define CDAW_MIN WCHAR_MIN
typedef USHORT cda16_t;
#define CDA16_MAX USHRT_MAX
#define CDA16_MIN 0
typedef LONG cda32_t;
#define CDA32_MAX ULONG_MAX
#define CDA32_MIN 0
#else
typedef char cdac_t;
#ifdef UNSIGNED_CHAR
#define CDAC_MAX UDAC_MAX
#define CDAC_MIN 0
#else
#define CDAC_MAX IDAC_MAX
#define CDAC_MIN IDAC_MIN
#endif
#if defined( __WCHAR_TYPE__ )
typedef __WCHAR_TYPE__ cdaw_t;
#define CDAW_MAX __WCHAR_MAX__
#define CDAW_MIN __WCHAR_MIN__
typedef __CHAR16_TYPE__ cda16_t;
typedef __CHAR32_TYPE__ cda32_t;
#define CDA16_MAX __UINT_LEAST16_MAX__
#define CDA16_MIN 0
#define CDA32_MAX __UINT_LEAST32_MAX__
#define CDA32_MIN 0
#else
typedef unsigned int cdaw_t;
#define CDAW_MAX UDAI_MAX
#define CDAW_MIN 0
typedef udal16_t cda16_t;
typedef udal32_t cda32_t;
#define CDA16_MAX UDAL16_MAX
#define CDA16_MIN 0
#define CDA32_MAX UDAL32_MAX
#define CDA32_MIN 0
#endif
#endif

#ifndef CHAR16_MAX
#define CHAR16_MAX UDAL16_MAX
#define CHAR16_MIN 0
#endif

#ifndef CHAR32_MAX
#define CHAR32_MAX UDAL32_MAX
#define CHAR32_MIN 0
#endif

/** @param max is max number of characters to check
@return -1 if initial portion of str did not match txt
@return 0 if both strings match
@return 1 if initial portion of str matches txt but goes on beyond txt
@return 2 reached maximum characters to compare
**/
int dasmatch( const char *str, const char *txt, size_t max );
int dasncat(
	cdac_t *dst,
	const cdac_t *src,
	size_t size,
	char **end
);
int daftoa(
	cdac_t *dst,
	size_t size,
	idam_t val,
	size_t base,
	bool small
);
int dautoa(
	cdac_t *dst,
	size_t size,
	udam_t val,
	size_t base,
	bool small
);
int daitoa(
	cdac_t *dst,
	size_t size,
	idam_t val,
	size_t base,
	bool small
);
int dasnprintf(
	cdac_t *dst,
	size_t size,
	const cdac_t *format,
	...
);
#endif
