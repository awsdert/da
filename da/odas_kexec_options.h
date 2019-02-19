#ifndef INC_ODAS_KEXEC_OPTIONS
#define INC_ODAS_KEXEC_OPTIONS
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_kexec_options {
	udal_t ExecuteDisable: 1;
	udal_t ExecuteEnable: 1;
	udal_t DisableThunkEmulation: 1;
	udal_t Permanent: 1;
	udal_t ExecuteDispatchEnable: 1;
	udal_t ImageDispatchEnable: 1;
	udal_t Spare: 2;
};
#endif
#endif
