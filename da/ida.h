#ifndef INC_DA_IDA_H
#define INC_DA_IDA_H
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#if defined( LDBL_MAX )
#define FDAM long double
#define _FDAM LDBL
#elif defined( DBL_MAX )
#define FDAM double
#define _FDAM DBL
#elif defined( FLT_MAX )
#define FDAM float
#define _FDAM FLT
#endif

/* IDALLf is intended for printf/scanf family of functions
for da* family just use "ll"
*/
#if defined(_MSC_EXTENSIONS) || (defined(_MSC_VER) && (_MSC_VER >= 1400))
#define IDALL __int64
#define _IDALL INT64
#define IDALLf "I64"
#elif defined( LONG_LONG_MAX )
#define IDALL long long
#define _DALL LONG_LONG
#define IDALLf "ll"
#elif defined( LLONG_MAX )
#define IDALL long long
#define _IDALL LLONG
#define IDALLf "ll"
#endif

typedef signed char	idac_t;
#define IDAC_MAX SCHAR_MAX
#define IDAC_MIN SCHAR_MIN
typedef unsigned char udac_t;
#define UDAC_MAX UCHAR_MAX
typedef signed short idas_t;
#define IDAS_MAX SHRT_MAX
#define IDAS_MIN SHRT_MIN
typedef unsigned short udas_t;
#define UDAS_MAX USHRT_MAX
typedef signed int idai_t;
#define IDAI_MAX INT_MAX
#define IDAI_MIN INT_MIN
typedef unsigned int udai_t;
#define UDAI_MAX UINT_MAX
typedef signed long idal_t;
#define IDAL_MAX LONG_MAX
#define IDAL_MIN LONG_MIN
typedef unsigned long udal_t;
#define UDAL_MAX ULONG_MAX
#ifdef IDALL
typedef signed IDALL idall_t;
#define IDALL_MAX _IDALL##_MAX
#define IDALL_MIN _IDALL##_MIN
typedef unsigned IDALL udall_t;
#define UDALL_MAX U##_IDALL##_MAX
#endif
/* It's shorter so why not */
typedef intmax_t idam_t;
typedef uintmax_t udam_t;
typedef intptr_t idap_t;
typedef uintptr_t udap_t;
#ifdef FDAM
typedef FDAM fdam_t;
#define FDAM_DIG		_FDAM##_DIG
#define FDAM_EPSILON	_FDAM##_EPSILON
#define FDAM_MANT_DIG	_FDAM##_MANT_DIG
#define FDAM_MAX		_FDAM##_MAX
#define FDAM_MAX_10_EXP	_FDAM##_MAX_10_EXP
#define FDAM_MAX_EXP	_FDAM##_MAX_EXP
#define FDAM_MIN		_FDAM##_MIN
#define FDAM_MIN_10_EXP	_FDAM##_MIN_10_EXP
#define FDAM_MIN_EXP	_FDAM##_MIN_EXP
#endif
#endif
