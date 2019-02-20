#ifndef INC_ODAS_MM_WORKING_SET_LISTEPTR
#define INC_ODAS_MM_WORKING_SET_LISTEPTR
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_mm_working_set_listeptr {
	void *Key;
	udal_t Index;
};
#endif
#endif
