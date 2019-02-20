#ifndef INC_ODAS_FAST_MUTEX
#define INC_ODAS_FAST_MUTEX
#include "odas.h"
#include "odas_kevent.h"
#ifndef DA_OS_MSWIN
struct odas_fast_mutex {
	idal_t Count;
	odas_kthread_t *Owner;
	udal_t Contention;
	odas_kevent_t Gate;
	udal_t OldIrql;
};
#endif
#endif
