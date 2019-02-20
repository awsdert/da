#ifndef INC_ODAS_EJOB
#define INC_ODAS_EJOB
#include "odas.h"
#include "odas_kevent.h"
#include "odas_listent.h"
#include "odas_lli.h"
#include "odas_xpushlock.h"
#include "odas_eresource.h"
#ifndef DA_OS_MSWIN
struct odas_ejob {
	odas_kevent_t Event;
	odas_listent_t JobLinks;
	odas_listent_t ProcessListHead;
	odas_eresource_t JobLock;
	odas_lli_t TotalUserTime;
	odas_lli_t TotalKernelTime;
	odas_lli_t ThisPeriodTotalUserTime;
	odas_lli_t ThisPeriodTotalKernelTime;
	udal_t TotalPageFaultCount;
	udal_t TotalProcesses;
	udal_t ActiveProcesses;
	udal_t TotalTerminatedProcesses;
	odas_lli_t PerProcessUserTimeLimit;
	odas_lli_t PerJobUserTimeLimit;
	udal_t LimitFlags;
	udal_t MinimumWorkingSetSize;
	udal_t MaximumWorkingSetSize;
	udal_t ActiveProcessLimit;
	udal_t Affinity;
	udac_t PriorityClass;
	da_job_access_state_t * AccessState;
	udal_t UIRestrictionsClass;
	udal_t EndOfJobTimeAction;
	void *CompletionPort;
	void *CompletionKey;
	udal_t SessionId;
	udal_t SchedulingClass;
	udal64_t ReadOperationCount;
	udal64_t WriteOperationCount;
	udal64_t OtherOperationCount;
	udal64_t ReadTransferCount;
	udal64_t WriteTransferCount;
	udal64_t OtherTransferCount;
	udal_t ProcessMemoryLimit;
	udal_t JobMemoryLimit;
	udal_t PeakProcessMemoryUsed;
	udal_t PeakJobMemoryUsed;
	udal_t CurrentJobMemoryUsed;
	odas_xpushlock_t MemoryLimitsLock;
	odas_listent_t JobSetLinks;
	udal_t MemberLevel;
	udal_t JobFlags;
};
#endif
#endif
