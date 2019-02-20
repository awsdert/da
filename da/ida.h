#ifndef INC_DA_IDA_H
#define INC_DA_IDA_H
#include "os.h"

#ifdef DA_OS_MSWIN
#include <BaseTsd.h>
typedef HANDLE			dah_t;
typedef BOOL				idab_t;
typedef BOOLEAN			udab_t;
typedef SCHAR				idac_t;
typedef UCHAR				udac_t;
typedef SHORT				idas_t;
typedef USHORT			udas_t;
typedef INT					idai_t;
typedef INT_PTR			idaip_t;
typedef UINT				udai_t;
typedef UINT_PTR		udaip_t;
typedef LONG				idal_t;
typedef LONG_PTR		idalp_t;
typedef ULONG				udal_t;
typedef ULONG_PTR		udalp_t;
#define IDALL LONGLONG
#define UDALL ULONGLONG

#if !defined(_M_IX86)
#define DALL_CAN_DO_BITWISE
#if defined(_MSC_EXTENSIONS) || (defined(_MSC_VER) && (_MSC_VER >= 1400))
#define DALL_IS_INT64
#define IDALLf "I64d"
#define UDALLf "I64u"
#else
#define DALL_IS_LLONG
#define IDALLf "lld"
#define UDALLf "llu"
#endif
#else
#define DALL_IS_DBL
#define IDALLf "g"
#define UDALLf "g"
#endif /* !defined(_M_IX86) */
#define IDALL_MAX LONGLONG_MAX
#define IDALL_MIN LONGLONG_MIN
#define UDALL_MAX ULONGLONG_MAX
typedef INTMAX idam_t;
typedef UINTMAX udam_t;

typedef BYTE dab_t;
typedef WORD daw_t;
typedef DWORD dad_t;
typedef QWORD daq_t;

#define DA8_DEFINED
typedef INT8 ida8_t;
typedef UINT8 uda8_t;
#define DA16_DEFINED
typedef INT16 ida16_t;
typedef UINT16 uda16_t;
#define DA32_DEFINED
typedef INT32 ida32_t;
typedef UINT32 uda32_t;
#define DA64_DEFINED
typedef INT64 ida64_t;
typedef UINT64 uda64_t;

#define DAL8_DEFINED
typedef INT8 idal8_t;
typedef UINT8 udal8_t;
#define IDAL8_MAX INT8_MAX
#define IDAL8_MIN INT8_MIN
#define UDAL8_MAX UINT8_MAX
#define DAL16_DEFINED
typedef INT16 idal16_t;
typedef UINT16 udal16_t;
#define IDAL16_MAX INT16_MAX
#define IDAL16_MIN INT16_MIN
#define UDAL16_MAX UINT16_MAX
#define DAL32_DEFINED
typedef INT32 idal32_t;
typedef UINT32 udal32_t;
#define IDAL32_MAX INT32_MAX
#define IDAL32_MIN INT32_MIN
#define UDAL32_MAX UINT32_MAX
#define DAL64_DEFINED
typedef INT64 idal64_t;
typedef UINT64 udal64_t;
#define IDAL64_MAX INT64_MAX
#define IDAL64_MIN INT64_MIN
#define UDAL64_MAX UINT64_MAX
#else
#include <linux/limits.h>
#include <linux/types.h>
#include <float.h>
#include <stdbool.h>
#include <linux/kernel.h>

#define DAPRAGMA( DO ) _Pragma( #DO )
#define DAMSG( TXT ) DAPRAGMA( message TXT )
#define _DAVARIS( TXT, VAR ) DAMSG( TXT " = " #VAR )
#define DAVARIS( VAR ) _DAVARIS( #VAR, VAR )

/* Try compiler predefines first */
#ifdef __CHAR_BIT__
#define IDAC_BIT __CHAR_BIT__
#define IDAC_MAX __SCHAR_MAX__
#define IDAC_MIN ((-__SCHAR_MAX__)-1)
#define UDAC_MAX ((__SCHAR_MAX__##U * 2) + 1)
#define IDAS_MAX __SHRT_MAX__
#define IDAS_MIN ((-__SHRT_MAX__)-1)
#define UDAS_MAX ((__SHRT_MAX__##U * 2) + 1)
#define IDAI_MAX __INT_MAX__
#define IDAI_MIN ((-__INT_MAX__)-1)
#define UDAI_MAX ((__INT_MAX__##U * 2) + 1)
#define IDAL_MAX __LONG_MAX__
#define IDAL_MIN ((-__LONG_MAX__)-1)
#define UDAL_MAX ((__LONG_MAX__##U * 2) + 1)
/* Check for fixed scenarios */
#elif defined( DA_OS_LLP64 ) || defined( DA_OS_ILP64 ) \
	|| defined( DA_OS_ILP32 ) || defined( DA_OS_LP64 ) \
	|| defined( DA_OS_LP32 )
#define IDAC_BIT 8
#define IDAC_MAX 127
#define IDAC_MIN -128
#define UDAC_MAX 255
#define IDAS_MAX 32767
#define IDAS_MIN -32768
#define UDAS_MAX 65535
#ifdef DA_OS_LP32 )
#define IDAI_MAX 32767
#define IDAI_MIN -32768
#define UDAI_MAX 65535
#elif defined( DA_OS_ILP64 )
#define IDAI_MAX 9223372036854775807
#define IDAI_MIN -9223372036854775808
#define UDAI_MAX 18446744073709551615
#else
#define IDAI_MAX 2147483647
#define IDAI_MIN -2147483648
#define UDAI_MAX 4294967295
#endif
#if defined( DA_OS_ILP64 ) || defined( DA_OS_LP64 )
#define IDAL_MAX 9223372036854775807L
#define IDAL_MIN -9223372036854775808L
#define UDAL_MAX 18446744073709551615L
#else
#define IDAL_MAX 2147483647L
#define IDAL_MIN -2147483648L
#define UDAL_MAX 4294967295L
#endif
/* Assume shortest known size */
#else
#define IDAC_BIT 6
#define IDAC_MAX 31
#define IDAC_MIN -32
#define UDAC_MAX 63
#define IDAS_MAX 2047
#define IDAS_MIN -2048
#define UDAS_MAX 4095
#define IDAI_MAX ((~0) & ((~0U) >> 1))
#define IDAI_MIN ((-IDAI_MAX)-1)
#define UDAI_MAX (~0U)
#define IDAL_MAX ((~0L) & ((~0UL) >> 1))
#define IDAL_MIN ((-IDAL_MAX)-1)
#define UDAL_MAX (~0UL)
#endif

#define _IDA1_MAX IDAC_MAX
#define _IDA1_MIN IDAC_MIN
#define _UDA1_MAX UDAC_MAX
#define _IDA2_MAX IDAS_MAX
#define _IDA2_MIN IDAS_MIN
#define _UDA2_MAX UDAS_MAX
#define _IDA4_MAX ((_IDA2_MAX << (IDAC_BIT * 2)) | _UDA2_MAX)
#define _IDA4_MIN ((-_IDA4_MAX)-1)
#define _UDA4_MAX ((_UDA2_MAX << (IDAC_BIT * 2)) | _UDA2_MAX)
#define _IDA8_MAX ((_IDA4_MAX << (IDAC_BIT * 2)) | _UDA4_MAX)
#define _IDA8_MIN ((-_IDA8_MAX)-1)
#define _UDA8_MAX ((_UDA4_MAX << (IDAC_BIT * 2)) | _UDA4_MAX)

#ifdef __INTPTR_TYPE__
#define IDAP_DEFINED
typedef __INTPTR_TYPE__ idap_t;
typedef __UINTPTR_TYPE__ udap_t;
#define IDAP_MAX __INTPTR_MAX__
#define IDAP_MIN __INTPTR_MIN__
#define UDAP_MAX __UINTPTR_MAX__
#endif

#if ((~0ULL) > (~0UL)) || (defined(IDAP_DEFINED) && IDAP_MAX > IDAL_MAX)
#define DALL_CAN_DO_BITWISE
#define DALL_IS_LLONG
#define DALL(V) (V##LL)
#define DALLd "lld"
#define DALLu "llu"
#define DALLx "llx"
#define DALLX "llX"
typedef long long idall_t;
typedef unsigned long long udall_t;
#ifdef __LONG_LONG_MAX__
#define IDALL_MAX __LONG_LONG_MAX__
#define IDALL_MIN __LONG_LONG_MIN__
#define UDALL_MAX __ULONG_LONG_MAX__
#else
#define IDALL_MAX (~0LL & (~0ULL >> 1))
#define IDALL_MIN ((-IDALL_MAX)-1)
#define UDALL_MAX (~0ULL)
#endif
#elif IDAL_MAX > IDAI_MAX && IDAI_MAX > IDAS_MAX
#define DALL_CAN_DO_BITWISE
#define DALL_IS_LONG
#define DALL(V) (V##L)
#define DALLd "ld"
#define DALLu "lu"
#define DALLx "lx"
#define DALLX "lX"
typedef long idall_t;
typedef unsigned long udall_t;
#define IDALL_MAX IDAL_MAX
#define IDALL_MIN IDAL_MIN
#define UDALL_MAX UDAL_MAX
#else
#define DALL_IS_LDBL
#define DALL(V) (V##
#define DALLd "lg"
#define DALLu "lg"
#define DALLd "le"
#define DALLu "lE"
typedef long double idall_t;
typedef long double udall_t;
#define IDALL_MAX LDBL_MAX
#define IDALL_MIN LDBL_MIN
#define UDALL_MAX LDBL_MAX
#endif /* DALL */

#if (defined( IDAP_DEFINED ) && IDAP_MAX > IDAL_MAX) || defined( DA_OS_LLP64 )
#define DA_OS_LLP
#elif IDAL_MAX > IDAI_MAX
#define DA_OS_LP
#elif IDAI_MAX > IDAS_MAX
#define DA_OS_ILP
#else
#define DA_OS_IP
#endif

typedef int idab_t;
typedef bool udab_t;
typedef signed char idac_t;
typedef unsigned char udac_t;
typedef short idas_t;
typedef unsigned short udas_t;
typedef int idai_t;
typedef unsigned int udai_t;
typedef long idal_t;
typedef unsigned long udal_t;

#ifdef DALL_CAN_DO_BITWISE
#define IDAMd IDALLd
#define IDAMu IDALLu
#define IDAMx IDALLx
#define IDAMX IDALLX
typedef idall_t idam_t;
typedef udall_t udam_t;
#define IDAM_MAX IDALL_MAX
#define IDAM_MIN IDALL_MIN
#define UDAM_MAX UDALL_MAX
#else
#define IDAMd "ld"
#define IDAMu "lu"
#define IDAMx "lx"
#define IDAMX "lX"
typedef long idam_t;
typedef unsigned long udam_t;
#define IDAM_MAX IDAL_MAX
#define IDAM_MIN IDAL_MIN
#define UDAM_MAX UDAL_MAX
#endif

#ifndef IDAP_DEFINED
#define IDAP_DEFINED
#ifdef DA_OS_LLP
typedef idall_t idap_t;
typedef udall_t udap_t;
#define IDAP_MAX IDALL_MAX
#define IDAP_MIN IDALL_MIN
#define UDAP_MAX UDALL_MAX
#elif defined( DA_OS_LP )
typedef long idap_t;
typedef unsigned long udap_t;
#define IDAP_MAX IDAL_MAX
#define IDAP_MIN IDAL_MIN
#define UDAP_MAX UDAL_MAX
#else
typedef int idap_t;
typedef unsigned int udap_t;
#define IDAP_MAX IDAI_MAX
#define IDAP_MIN IDAI_MIN
#define UDAP_MAX UDAI_MAX
#endif
#endif

#if IDAP_MAX > IDAL_MAX
typedef idall_t idalp_t;
typedef udall_t udalp_t;
#else
typedef long idalp_t;
typedef unsigned long udalp_t;
#endif

typedef unsigned char dab_t;
typedef unsigned short daw_t;
#ifdef DALL_IS_LONG
typedef unsigned int dad_t;
#else
typedef unsigned long dad_t;
#endif
typedef udall_t daq_t;

#if IDAC_BIT == 8
#define DA8_DEFINED
typedef __s8 ida8_t;
typedef __u8 uda8_t;
#define IDA8_MAX 127
#define IDA8_MIN -128
#define UDA8_MAX 255
#define DA16_DEFINED
typedef __s16 ida16_t;
typedef __u16 uda16_t;
#define IDA16_MAX 32767
#define IDA16_MIN -32768
#define UDA16_MAX 65535
#define DA32_DEFINED
typedef __s32 ida32_t;
typedef __u32 uda32_t;
#if IDAI_MAX == IDAS_MAX
#define IDA32_MAX 2147483647L
#define IDA32_MIN -2147483648L
#define UDA32_MAX 4294967295L
#else
#define IDA32_MAX 2147483647
#define IDA32_MIN -2147483648
#define UDA32_MAX 4294967295
#endif
#define DA64_DEFINED
typedef __s64 ida64_t;
typedef __u64 uda64_t;
#if IDAL_MAX < IDALL_MAX
#define IDA64_MAX 9223372036854775807LL
#define IDA64_MIN -9223372036854775808LL
#define UDA64_MAX 18446744073709551615LL
#else
#define IDA64_MAX 9223372036854775807L
#define IDA64_MIN -9223372036854775808L
#define UDA64_MAX 18446744073709551615L
#endif
#define DAL8_DEFINED
typedef __s8 idal8_t;
typedef __u8 udal8_t;
#define IDAL8_MAX 127
#define IDAL8_MIN -128
#define UDAL8_MAX 255
#define DAL16_DEFINED
typedef __s16 idal16_t;
typedef __u16 udal16_t;
#define IDAL16_MAX 32767
#define IDAL16_MIN -32768
#define UDAL16_MAX 65535
#define DAL32_DEFINED
typedef __s32 idal32_t;
typedef __u32 udal32_t;
#if IDAI_MAX == IDAS_MAX
#define IDAL32_MAX 2147483647L
#define IDAL32_MIN -2147483648L
#define UDAL32_MAX 4294967295L
#else
#define IDAL32_MAX 2147483647
#define IDAL32_MIN -2147483648
#define UDAL32_MAX 4294967295
#endif
#define DAL64_DEFINED
typedef __s64 idal64_t;
typedef __u64 udal64_t;
#if IDAL_MAX < IDALL_MAX
#define IDAL64_MAX 9223372036854775807LL
#define IDAL64_MIN -9223372036854775808LL
#define UDAL64_MAX 18446744073709551615LL
#else
#define IDAL64_MAX 9223372036854775807L
#define IDAL64_MIN -9223372036854775808L
#define UDAL64_MAX 18446744073709551615L
#endif
#elif defined( __INT_LEAST8_TYPE__ )
#define DAL8_DEFINED
typedef __INT_LEAST8_TYPE__ ida8_t;
typedef __UINT_LEAST8_TYPE__ uda8_t;
#define IDAL8_MAX __INT8_MAX__
#define IDAL8_MIN __INT8_MIN__
#define UDAL8_MAX __UINT8_MAX__
#define DAL16_DEFINED
typedef __INT_LEAST16_TYPE__ ida16_t;
typedef __UINT_LEAST16_TYPE__ uda16_t;
#define IDAL16_MAX __INT16_MAX__
#define IDAL16_MIN __INT16_MIN__
#define UDAL16_MAX __UINT16_MAX__
#define DAL32_DEFINED
typedef __INT_LEAST32_TYPE__ ida32_t;
typedef __UINT_LEAST32_TYPE__ uda32_t;
#define IDAL32_MAX __INT32_MAX__
#define IDAL32_MIN __INT32_MIN__
#define UDAL32_MAX __UINT32_MAX__
#define DAL64_DEFINED
typedef __INT_LEAST64_TYPE__ ida64_t;
typedef __UINT_LEAST64_TYPE__ uda64_t;
#define IDAL64_MAX __INT64_MAX__
#define IDAL64_MIN __INT64_MIN__
#define UDAL64_MAX __UINT64_MAX__
#elif IDAC_BIT >= 8
#define DAL8_DEFINED
typedef signed char idal8_t;
typedef unsigned char udal8_t;
#define IDAL8_MAX IDAC_MAX
#define IDAL8_MIN IDAC_MIN
#define UDAL8_MAX UDAC_MAX
#define DAL16_DEFINED
typedef short idal16_t;
typedef unsigned short udal16_t;
#define IDAL16_MAX IDAS_MAX
#define IDAL16_MIN IDAS_MIN
#define UDAL16_MAX UDAS_MAX
#define DAL32_DEFINED
#if IDAI_MAX > IDAS_MAX
typedef int idal32_t;
typedef unsigned int udal32_t;
#define IDAL32_MAX IDAI_MAX
#define IDAL32_MIN IDAI_MIN
#define UDAL32_MAX UDAI_MAX
#define DAL64_DEFINED
#if IDAL_MAX > IDAI_MAX
typedef long idal64_t;
typedef unsigned long udal64_t;
#define IDAL64_MAX IDAL_MAX
#define IDAL64_MIN IDAL_MIN
#define UDAL64_MAX UDAL_MAX
#else
typedef idall_t idal64_t;
typedef udall_t udal64_t;
#define IDAL64_MAX IDALL_MAX
#define IDAL64_MIN IDALL_MIN
#define UDAL64_MAX UDALL_MAX
#endif
#else
typedef long idal32_t;
typedef unsigned long udal32_t;
#define IDAL32_MAX IDAL_MAX
#define IDAL32_MIN IDAL_MIN
#define UDAL32_MAX UDAL_MAX
#if IDALL_MAX > IDAL_MAX
#define IDAL64_DEFINED
typedef idall_t idal64_t;
typedef udall_t udal64_t;
#define IDAL64_MAX IDALL_MAX
#define IDAL64_MIN IDALL_MIN
#define UDAL64_MAX UDALL_MAX
#endif
#endif
#endif /* IDAC == 8 */

#endif /* DA_OS_MSWIN */

typedef float fdaf_t;
typedef double fdad_t;
typedef long double fdal_t;

#ifdef _Float128
typedef _Float128 fdam_t;
#define FDAMf "l128g"
#define FDAM_DIG				LDBL_DIG
#define FDAM_EPSILON		LDBL_EPSILON
#define FDAM_MANT_DIG		LDBL_MANT_DIG
#define FDAM_MAX				LDBL_MAX
#define FDAM_MAX_10_EXP	LDBL_MAX_10_EXP
#define FDAM_MAX_EXP		LDBL_MAX_EXP
#define FDAM_MIN				LDBL_MIN
#define FDAM_MIN_10_EXP	LDBL_MIN_10_EXP
#define FDAM_MIN_EXP		LDBL_MIN_EXP
#else
typedef long double fdam_t;
#define FDAMf "lg"
#define FDAM_DIG				LDBL_DIG
#define FDAM_EPSILON		LDBL_EPSILON
#define FDAM_MANT_DIG		LDBL_MANT_DIG
#define FDAM_MAX				LDBL_MAX
#define FDAM_MAX_10_EXP	LDBL_MAX_10_EXP
#define FDAM_MAX_EXP		LDBL_MAX_EXP
#define FDAM_MIN				LDBL_MIN
#define FDAM_MIN_10_EXP	LDBL_MIN_10_EXP
#define FDAM_MIN_EXP		LDBL_MIN_EXP
#endif

#ifdef _Float16
#define FDA16_DEFINED
typedef _Float16 fda16_t;
#endif
#ifdef _Float32
#define FDA32_DEFINED
typedef _Float32 fda32_t;
#elif IDAC_BIT == 8
#define FDA32_DEFINED
typedef float fda32_t;
#endif
#ifdef _Float64
#define FDA64_DEFINED
typedef _Float64 fda64_t;
#elif IDAC_BIT == 8
#define FDA64_DEFINED
typedef double fda64_t;
#endif
#ifdef _Float128
#define FDA128_DEFINED
typedef _Float128 fda128_t;
#endif

#endif  /* INC_IDA_H */
