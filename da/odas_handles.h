#ifndef INC_ODAS_HANDLES
#define INC_ODAS_HANDLES
#include "odas.h"
#include "odas_listent.h"
#include "odas_xpushlock.h"
#ifndef DA_OS_MSWIN
struct odas_handles {
	udal_t TableCode;
	odas_eproc_t *QuotaProcess;
	void *UniqueProcessId;
	odas_xpushlock_t HandleLock;
	odas_listent_t HandleTableList;
	odas_xpushlock_t HandleContentionEvent;
	odas_handle_trace_dbginf_t *DebugInfo;
	idal_t ExtraInfoPages;
	udal_t Flags;
	udal_t StrictFIFO: 1;
	idal_t FirstFreeHandle;
	PHANDLE_TABLE_ENTRY *LastFreeHandleEntry;
	idal_t HandleCount;
	udal_t NextHandleNeedingPool;
};
#endif
#endif
