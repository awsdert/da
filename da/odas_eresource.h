#ifndef INC_ODAS_ERESOURCE
#define INC_ODAS_ERESOURCE
#include "odas.h"
#include "odas_listent.h"
#include "odas_ownerent.h"
#ifndef DA_OS_MSWIN
struct odas_parentent {
	odas_listent_t SystemResourcesList;
	odas_ownerent_t *OwnerTable;
	idas_t ActiveCount;
	daw_t Flag;
	odas_ksemaphore_t *SharedWaiters;
	odas_kevent_t *ExclusiveWaiters;
	odas_ownerent_t OwnerEntry;
	udal_t ActiveEntries;
	udal_t ContentionCount;
	udal_t NumberOfSharedWaiters;
	udal_t NumberOfExclusiveWaiters;
	union
	{
		void *Address;
		udal_t CreatorBackTraceIndex;
	};
	udal_t SpinLock;
};
#endif
#endif
