#ifndef INC_ODAS_EPROC
#define INC_ODAS_EPROC
#include "odas.h"
#include "odas_kproc.h"
#include "odas_listent.h"
#include "odas_xrundown_ref.h"
#include "odas_xfast_ref.h"
#include "odas_xpushlock.h"
#include "odas_mmaddr_node.h"
#include "odas_mm_available_table.h"
#include "odas_eproc_quota_block.h"
#include "odas_pagefault_history.h"
#ifndef DA_OS_MSWIN
struct odas_eproc {
	odas_kproc_t Pcb;
	odas_xpushlock_t ProcessLock;
	odas_lli_t CreateTime;
	odas_lli_t ExitTime;
	odas_xrundown_ref_t RundownProtect;
	void* UniqueProcessId;
	odas_listent_t ActiveProcessLinks;
	udal_t QuotaUsage[3];
	udal_t QuotaPeak[3];
	udal_t CommitCharge;
	udal_t PeakVirtualSize;
	udal_t VirtualSize;
	odas_listent_t SessionProcessLinks;
	void* DebugPort;
	union
	{
	void* ExceptionPortData;
	udal_t ExceptionPortValue;
	udal_t ExceptionPortState: 3;
	};
	PHANDLE_TABLE ObjectTable;
	odas_xfast_ref_t Token;
	udal_t WorkingSetPage;
	odas_xpushlock_t AddressCreationLock;
	odas_ethread_t *RotateInProgress;
	odas_ethread_t *ForkInProgress;
	udal_t HardwareTrigger;
	odas_mm_available_table_t *PhysicalVadRoot;
	void* CloneRoot;
	udal_t NumberOfPrivatePages;
	udal_t NumberOfLockedPages;
	void* Win32Process;
	PEJOB Job;
	void* SectionObject;
	void* SectionBaseAddress;
	odas_eproc_quota_block_t * QuotaBlock;
	odas_pagefault_history_t * WorkingSetWatch;
	void* Win32WindowStation;
	void* InheritedFromUniqueProcessId;
	void* LdtInformation;
	void* VadFreeHint;
	void* VdmObjects;
	void* DeviceMap;
	void* EtwDataSource;
	void* FreeTebHint;
	union
	{
	HARDWARE_PTE PageDirectoryPte;
	udal64_t Filler;
	};
	void* Session;
	udac_t ImageFileName[16];
	odas_listent_t JobLinks;
	void *LockedPagesList;
	odas_listent_t ThreadListHead;
	void *SecurityPort;
	void *PaeTop;
	udal_t ActiveThreads;
	udal_t ImagePathHash;
	udal_t DefaultHardErrorProcessing;
	idal_t LastThreadExitStatus;
	odas_peb_t *Peb;
	odas_xfast_ref_t PrefetchTrace;
	odas_lli_t ReadOperationCount;
	odas_lli_t WriteOperationCount;
	odas_lli_t OtherOperationCount;
	odas_lli_t ReadTransferCount;
	odas_lli_t WriteTransferCount;
	odas_lli_t OtherTransferCount;
	udal_t CommitChargeLimit;
	udal_t CommitChargePeak;
	void *AweInfo;
	SE_AUDIT_PROCESS_CREATION_INFO SeAuditProcessCreationInfo;
	MMSUPPORT Vm;
	odas_listent_t MmProcessLinks;
	udal_t ModifiedPageCount;
	udal_t Flags2;
	udal_t JobNotReallyActive: 1;
	udal_t AccountingFolded: 1;
	udal_t NewProcessReported: 1;
	udal_t ExitProcessReported: 1;
	udal_t ReportCommitChanges: 1;
	udal_t LastReportMemory: 1;
	udal_t ReportPhysicalPageChanges: 1;
	udal_t HandleTableRundown: 1;
	udal_t NeedsHandleRundown: 1;
	udal_t RefTraceEnabled: 1;
	udal_t NumaAware: 1;
	udal_t ProtectedProcess: 1;
	udal_t DefaultPagePriority: 3;
	udal_t PrimaryTokenFrozen: 1;
	udal_t ProcessVerifierTarget: 1;
	udal_t StackRandomizationDisabled: 1;
	udal_t Flags;
	udal_t CreateReported: 1;
	udal_t NoDebugInherit: 1;
	udal_t ProcessExiting: 1;
	udal_t ProcessDelete: 1;
	udal_t Wow64SplitPages: 1;
	udal_t VmDeleted: 1;
	udal_t OutswapEnabled: 1;
	udal_t Outswapped: 1;
	udal_t ForkFailed: 1;
	udal_t Wow64VaSpace4Gb: 1;
	udal_t AddressSpaceInitialized: 2;
	udal_t SetTimerResolution: 1;
	udal_t BreakOnTermination: 1;
	udal_t DeprioritizeViews: 1;
	udal_t WriteWatch: 1;
	udal_t ProcessInSession: 1;
	udal_t OverrideAddressSpace: 1;
	udal_t HasAddressSpace: 1;
	udal_t LaunchPrefetched: 1;
	udal_t InjectInpageErrors: 1;
	udal_t VmTopDown: 1;
	udal_t ImageNotifyDone: 1;
	udal_t PdeUpdateNeeded: 1;
	udal_t VdmAllowed: 1;
	udal_t SmapAllowed: 1;
	udal_t ProcessInserted: 1;
	udal_t DefaultIoPriority: 3;
	udal_t SparePsFlags1: 2;
	idal_t ExitStatus;
	daw_t Spare7;
	union
	{
		struct
		{
			udac_t SubSystemMinorVersion;
			udac_t SubSystemMajorVersion;
		};
		daw_t SubSystemVersion;
	};
	udac_t PriorityClass;
	odas_mm_available_table_t VadRoot;
	udal_t Cookie;
};
#endif
#endif
