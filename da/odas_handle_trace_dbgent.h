#ifndef INC_ODAS_HANDLE_TRACE_DBGENT
#define INC_ODAS_HANDLE_TRACE_DBGENT
#include "odas.h"
#include "odas_client_id.h"
#ifndef DA_OS_MSWIN
struct odas_handle_trace_dbgent {
	odas_client_id_t ClientId;
	void *Handle;
	udal_t Type;
	void *StackTrace[16];
};
#endif
#endif
