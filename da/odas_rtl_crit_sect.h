#ifndef INC_ODAS_RTL_CRIT_SECT
#define INC_ODAS_RTL_CRIT_SECT
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_rtl_crit_sect {
	odas_rtl_crit_sect_dbg_t *DebugInfo;
	idal_t LockCount;
	idal_t RecursionCount;
	void *OwningThread;
	void *LockSemaphore;
	udal_t SpinCount;
};
#endif
#endif
