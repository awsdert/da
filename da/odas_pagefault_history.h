#ifndef INC_ODAS_PAGEFAULT_HISTORY
#define INC_ODAS_PAGEFAULT_HISTORY
#include "odas.h"
#include "odas_proc_ws_watch_info.h"
#ifndef DA_OS_MSWIN
struct odas_pagefault_history {
	udal_t CurrentIndex;
	udal_t MapIndex;
	da_kspin_lock_t SpinLock;
	void *Reserved;
	odas_proc_ws_watch_info_t WatchInfo[1];
};
#endif
#endif
