#ifndef INC_DA_OS_H
#define INC_DA_OS_H

#ifdef __WIN64__
#define DA_OS_WIN64 __WIN64__
#elif defined( __WIN64 )
#define DA_OS_WIN64 __WIN64
#elif defined( _WIN64_ )
#define DA_OS_WIN64 _WIN64_
#elif defined( _WIN64 )
#define DA_OS_WIN64 _WIN64
#elif defined( WIN64 )
#define DA_OS_WIN64 WIN64
#endif

#ifdef __WIN32__
#define DA_OS_WIN32 __WIN32__
#elif defined( __WIN32 )
#define DA_OS_WIN32 __WIN32
#elif defined( _WIN32_ )
#define DA_OS_WIN32 _WIN32_
#elif defined( _WIN32 )
#define DA_OS_WIN32 _WIN32
#elif defined( WIN32 )
#define DA_OS_WIN32 WIN32
#endif

#ifdef __WIN16__
#define DA_OS_WIN16 __WIN16__
#elif defined( __WIN16 )
#define DA_OS_WIN16 __WIN16
#elif defined( _WIN16_ )
#define DA_OS_WIN16 _WIN16_
#elif defined( _WIN16 )
#define DA_OS_WIN16 _WIN16
#elif defined( WIN16 )
#define DA_OS_WIN16 WIN16
#endif

#ifdef __WINNT__
#define DA_OS_WINNT __WINNT__
#elif defined( __WINNT )
#define DA_OS_WINNT __WINNT
#elif defined( _WINNT_ )
#define DA_OS_WINNT _WINNT_
#elif defined( _WINNT )
#define DA_OS_WINNT _WINNT
#elif defined( WINNT )
#define DA_OS_WINNT WINNT
#endif

#ifdef __linux__
#define DA_OS_linux __linux__
#elif defined( __linux )
#define DA_OS_linux __linux
#elif defined( _linux_ )
#define DA_OS_linux _linux_
#elif defined( _linux )
#define DA_OS_linux _linux
#elif defined( linux )
#define DA_OS_linux linux
#endif

#ifdef __unix__
#define DA_OS_unix __unix__
#elif defined( __unix )
#define DA_OS_unix __unix
#elif defined( _unix_ )
#define DA_OS_unix _unix_
#elif defined( _unix )
#define DA_OS_unix _unix
#elif defined( unix )
#define DA_OS_unix unix
#endif

#ifdef __posix__
#define DA_OS_posix __posix__
#elif defined( __posix )
#define DA_OS_posix __posix
#elif defined( _posix_ )
#define DA_OS_posix _posix_
#elif defined( _posix )
#define DA_OS_posix _posix
#elif defined( posix )
#define DA_OS_posix posix
#endif

#ifdef DA_OS_WIN64
#define DA_OS_MSWIN DA_OS_WIN64
#elif defined( DA_OS_WIN16 )
#define DA_OS_MSWIN DA_OS_WIN16
#elif defined( DA_OS_WIN32 )
#define DA_OS_MSWIN DA_OS_WIN32
#elif defined( DA_OS_WINNT )
#define DA_OS_MSWIN DA_OS_WINNT
#endif

#endif
