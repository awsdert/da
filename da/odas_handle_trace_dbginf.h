#ifndef INC_ODAS_HANDLE_TRACE_DBGINF
#define INC_ODAS_HANDLE_TRACE_DBGINF
#include "odas.h"
#include "odas_fast_mutex.h"
#ifndef DA_OS_MSWIN
struct odas_handle_trace_dbginf {
	idal_t RefCount;
	udal_t TableSize;
	udal_t BitMaskFlags;
	odas_fast_mutex_t CloseCompactionLock;
	udal_t CurrentStackIndex;
	HANDLE_TRACE_DB_ENTRY TraceDb[1];
};
#endif
#endif
