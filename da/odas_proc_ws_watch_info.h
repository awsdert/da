#ifndef INC_PROC_WS_WATCH_INFO
#define INC_PROC_WS_WATCH_INFO
#include "odas.h"
#ifndef DA_OS_WIN
struct odas_proc_ws_watch_info {
	void *FaultingPc;
	void *FaultingVa;
};
#endif
#endif
