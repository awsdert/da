#ifndef INC_ODAS_MM_SUPPORT
#define INC_ODAS_MM_SUPPORT
#include "odas.h"
#include "odas_listent.h"
#include "odas_xpushlock.h"
#include "odas_mm_support_flags.h"
#ifndef DA_OS_MSWIN
struct odas_mm_support {
	odas_listent_t WorkingSetExpansionLinks;
	daw_t LastTrimStamp;
	daw_t NextPageColor;
	odas_mm_support_flags_t Flags;
	udal_t PageFaultCount;
	udal_t PeakWorkingSetSize;
	udal_t Spare0;
	udal_t MinimumWorkingSetSize;
	udal_t MaximumWorkingSetSize;
	odas_mm_working_set_list_t *VmWorkingSetList;
	udal_t Claim;
	udal_t Spare[1];
	udal_t WorkingSetPrivateSize;
	udal_t WorkingSetSizeOverhead;
	udal_t WorkingSetSize;
	odas_kevent_t *ExitEvent;
	odas_xpushlock_t WorkingSetMutex;
	void *AccessLog;
};
#endif
#endif
