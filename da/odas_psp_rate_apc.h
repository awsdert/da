#ifndef INC_ODAS_PSP_RATE_APC
#define INC_ODAS_PSP_RATE_APC
#include "odas_single_listent.h"
#ifndef DA_OS_MSWIN
struct odas_psp_rate_apc {
	odas_single_listent_t NextApc;
	udall_t ExcessCycles;
};
#endif
#endif
