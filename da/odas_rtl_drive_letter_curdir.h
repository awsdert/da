#ifndef ODAS_RTL_DRIVE_LETTER_CURDIR
#define ODAS_RTL_DRIVE_LETTER_CURDIR
#include "odas.h"
#include "odas_str.h"
#ifndef DA_OS_MSWIN
struct odas_rtl_drive_letter_curdir {
	daw_t Flags;
	daw_t Length;
	udal_t TimeStamp;
	odas_str_t DosPath;
};
#endif
#endif
