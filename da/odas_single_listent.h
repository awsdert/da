#ifndef INC_ODAS_SINGLE_LISTENT
#define INC_ODAS_SINGLE_LISTENT
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_single_listent {
	odas_single_listent_t *Next;
};
#endif
#endif
