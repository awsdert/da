#ifndef INC_ODAS_NAME_INFO
#define INC_ODAS_NAME_INFO
#include "odas.h"
#include "odas_ucs.h"
#ifndef DA_OS_MSWIN
struct odas_name_info {
	odas_ucs_t Name;
};
#endif
#endif
