#ifndef INC_ODAS_ETHREAD
#define INC_ODAS_ETHREAD
#include "odas_lli.h"
#include "odas_client_id.h"
#include "odas_ps_client_sctx.h"
#include "odas_listent.h"
#include "odas_dev.h"
#include "odas_termport.h"
#include "odas_ksemaphore.h"
#include "odas_xrundown_ref.h"
#include "odas_xpushlock.h"
#ifndef DA_OS_MSWIN
struct odas_ethread {
	odas_kthread_t Tcb;
	odas_lli_t CreateTime;
	union
	{
		odas_lli_t ExitTime;
		odas_listent_t KeyedWaitChain;
	};
	union
	{
		idal_t ExitStatus;
		void* OfsChain;
	};
	union
	{
		odas_listent_t PostBlockList;
		struct
		{
			void* ForwardLinkShadow;
			void* StartAddress;
		};
	};
	union
	{
		odas_termport_t *TerminationPort;
		odas_ethread_t *ReaperLink;
		void* KeyedWaitValue;
		void* Win32StartParameter;
	};
	udal_t ActiveTimerListLock;
	odas_listent_t ActiveTimerListHead;
	odas_client_id_t Cid;
	union
	{
		odas_ksemaphore_t KeyedWaitSemaphore;
		odas_ksemaphore_t AlpcWaitSemaphore;
	};
	odas_ps_client_sctx_t ClientSecurity;
	odas_listent_t IrpList;
	udal_t TopLevelIrp;
	odas_dev_t *DeviceToVerify;
	_PSP_RATE_APC *RateControlApc;
	void *Win32StartAddress;
	void *SparePtr0;
	odas_listent_t ThreadListEntry;
	odas_xrundown_ref_t RundownProtect;
	odas_xpushlock_t ThreadLock;
	udal_t ReadClusterSize;
	idal_t MmLockOrdering;
	udal_t CrossThreadFlags;
	udal_t Terminated: 1;
	udal_t ThreadInserted: 1;
	udal_t HideFromDebugger: 1;
	udal_t ActiveImpersonationInfo: 1;
	udal_t SystemThread: 1;
	udal_t HardErrorsAreDisabled: 1;
	udal_t BreakOnTermination: 1;
	udal_t SkipCreationMsg: 1;
	udal_t SkipTerminationMsg: 1;
	udal_t CopyTokenOnOpen: 1;
	udal_t ThreadIoPriority: 3;
	udal_t ThreadPagePriority: 3;
	udal_t RundownFail: 1;
	udal_t SameThreadPassiveFlags;
	udal_t ActiveExWorker: 1;
	udal_t ExWorkerCanWaitUser: 1;
	udal_t MemoryMaker: 1;
	udal_t ClonedThread: 1;
	udal_t KeyedEventInUse: 1;
	udal_t RateApcState: 2;
	udal_t SelfTerminate: 1;
	udal_t SameThreadApcFlags;
	udal_t Spare: 1;
	udal_t StartAddressInvalid: 1;
	udal_t EtwPageFaultCalloutActive: 1;
	udal_t OwnsProcessWorkingSetExclusive: 1;
	udal_t OwnsProcessWorkingSetShared: 1;
	udal_t OwnsSystemWorkingSetExclusive: 1;
	udal_t OwnsSystemWorkingSetShared: 1;
	udal_t OwnsSessionWorkingSetExclusive: 1;
	udal_t OwnsSessionWorkingSetShared: 1;
	udal_t OwnsProcessAddressSpaceExclusive: 1;
	udal_t OwnsProcessAddressSpaceShared: 1;
	udal_t SuppressSymbolLoad: 1;
	udal_t Prefetching: 1;
	udal_t OwnsDynamicMemoryShared: 1;
	udal_t OwnsChangeControlAreaExclusive: 1;
	udal_t OwnsChangeControlAreaShared: 1;
	udal_t PriorityRegionActive: 4;
	udac_t CacheManagerActive;
	udac_t DisablePageFaultClustering;
	udac_t ActiveFaultCount;
	udal_t AlpcMessageId;
	union
	{
		void *AlpcMessage;
		udal_t AlpcReceiveAttributeSet;
	};
	odas_listent_t AlpcWaitListEntry;
	udal_t CacheManagerCount;
};
#endif
#endif
