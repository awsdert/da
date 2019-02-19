#ifndef INC_ODAS_KAPC_STATE
#define INC_ODAS_KAPC_STATE
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kapc_state {
	odas_listent_t ApcListHead[2];
	odas_kproc_t *Process;
	udac_t KernelApcInProgress;
	udac_t KernelApcPending;
	udac_t UserApcPending;
};
#endif
#endif
