#ifndef ODAS_CURDIR
#define ODAS_CURDIR
#include "odas.h"
#include "odas_ucs.h"
#ifndef DA_OS_MSWIN
struct odas_curdir {
	odas_ucs_t DosPath;
	void *Handle;
};
#endif
#endif
