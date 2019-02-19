#ifndef INC_ODAS_RTL_CRIT_SECT_DBG
#define INC_ODAS_RTL_CRIT_SECT_DBG
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_rtl_crit_sect_dbg {
	daw_t Type;
	daw_t CreatorBackTraceIndex;
	odas_rtl_crit_sect_t *CriticalSection;
	odas_listent_t ProcessLocksList;
	udal_t EntryCount;
	udal_t ContentionCount;
	udal_t Flags;
	daw_t CreatorBackTraceIndexHigh;
	daw_t SpareUSHORT;
};
#endif
#endif
