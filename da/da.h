#ifndef INC_DA_DA_H
#define INC_DA_DA_H
#include "os.h"
#include "ida.h"
#include "das.h"

#ifdef DA_OS_MSWIN
#define DA_LICENSE(str)
#define DA_AUTHOR(str)
#define DA_DESC(str)
#else
#define DA_LICENSE(str) MODULE_LICENSE(str);
#define DA_AUTHOR(str) MODULE_AUTHOR(str);
#define DA_DESC(str) MODULE_DESCRIPTION(str);
#define IRP_MJ_MAXIMUM_FUNCTION 512
typedef struct odas_pscsctx odas_pscsctx_t;
typedef struct odas_xrundown_ref odas_xrundown_ref_t;
struct odas_lli {
	union
	{
		struct
		{
			udal_t LowPart;
			idal_t HighPart;
		};
		idall_t QuadPart;
	};
};
#include "odas.h"
#include "odas_listent.h"
#include "odas_sender_header.h"
#include "odas_kevent.h"
#include "odas_ksemaphore.h"
#include "odas_kthread.h"

struct odas_pscsctx {
	union
	{
		udal_t ImpersonationData;
		void *ImpersonationToken;
		udal_t ImpersonationLevel: 2;
		udal_t EffectiveOnly: 1;
	};
};
struct odas_termport {
	odas_termport_t *Next;
	void *Port;
};
struct odas_cid {
	void *UniqueProcess;
	void *UniqueThread;
};
struct odas_xrundown_ref {
	union
	{
		udal_t Count;
		void *Ptr;
	};
};
typedef struct dax_pushlock {
	union
	{
		udal_t Locked: 1;
		udal_t Waiting: 1;
		udal_t Waking: 1;
		udal_t MultipleShared: 1;
		udal_t Shared: 28;
		udal_t Value;
		void *Ptr;
	};
} dax_pushlock_t;
struct da_ethread {
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
	odas_cid_t Cid;
	union
	{
		odas_ksemaphore_t KeyedWaitSemaphore;
		odas_ksemaphore_t AlpcWaitSemaphore;
	};
	odas_pscsctx_t ClientSecurity;
	odas_listent_t IrpList;
	udal_t TopLevelIrp;
	odas_dev_t *DeviceToVerify;
	_PSP_RATE_APC *RateControlApc;
	void *Win32StartAddress;
	void *SparePtr0;
	odas_listent_t ThreadListEntry;
	odas_xrundown_ref_t RundownProtect;
	dax_pushlock_t ThreadLock;
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
typedef struct odas_ext {
} odas_ext_t;
typedef struct odas_ini {
} odas_ini_t;
typedef struct odas_snd {
} odas_snd_t;
typedef struct odas_spd {
} odas_spd_t;
typedef struct odas odas_t;
typedef void (*da_cancel_ft)( odas_t *da );
typedef void (*da_run_ft)( odas_dev_t *dev, odas_irp_t *irp );
typedef void (*da_end_ft)( odas_t *da );
typedef struct odas_ucs odas_ucs_t;
struct odas_ucs {
	udas_t	Length;
  udas_t	MaximumLength;
  cdaw_t	*Buffer;
};
struct odas_eproc {
};
struct odas_mdl {
	odas_mdl_t	*Next;
  idas_t		Size;
  idas_t		MdlFlags;
  odas_eproc_t *Process;
  void			*MappedSystemVa;
  void			*StartVa;
  udal_t		ByteCount;
  udal_t		ByteOffset;
};
typedef struct odas_ios_block {
	union {
		dastatus_t	Status;
		void	*Pointer;
	} DUMMYUNIONNAME;
	udalp_t Information;
} odas_ios_block_t;
struct da_irp {
	odas_mdl_t	*MdlAddress;
  udal_t		Flags;
  union {
    odas_irp_t	*MasterIrp;
    void			*SystemBuffer;
  } AssociatedIrp;
  odas_ios_block_t IoStatus;
  dakprocmode_t RequestorMode;
  udab_t		PendingReturned;
  udab_t		Cancel;
  dakirq_t	CancelIrql;
  da_cancel_ft	CancelRoutine;
  void			*UserBuffer;
  union {
    struct {
      union {
        odas_kdentry_t	DeviceQueueEntry;
        struct {
          void	*DriverContext[4];
        };
      };
      odas_ethread_t   *Thread;
      odas_listent_t ListEntry;
    } Overlay;
  } Tail;
};
struct odas_dev {
	idas_t		Type;
  idas_t		Size;
  idal_t		ReferenceCount;
  odas_dev_t	*DriverObject;
  odas_dev_t	*NextDevice;
  odas_dev_t	*AttachedDevice;
  odas_irp_t  *CurrentIrp;
  odas_tmr_t	*Timer;
  udal_t		Flags;
  udal_t		Characteristics;
  __volatile PVPB             Vpb;
  void			*DeviceExtension;
  DEVICE_TYPE                 DeviceType;
  CCHAR                       StackSize;
  union {
    odas_listent_t	ListEntry;
    WAIT_CONTEXT_BLOCK Wcb;
  } Queue;
  udal_t		AlignmentRequirement;
  KDEVICE_QUEUE               DeviceQueue;
  KDPC                        Dpc;
  udal_t		ActiveThreadCount;
  da_access_desc_t	*SecurityDescriptor;
  odas_kevent_t                      DeviceLock;
  udas_t		SectorSize;
  udas_t		Spare1;
  struct _DEVOBJ_EXTENSION  *  DeviceObjectExtension;
  void			*Reserved;
};
struct oda {
	dacshort_t		Type;
  dacshort_t		Size;
  odas_dev_t*	DeviceObject;
  udal_t		Flags;
  void*			DriverStart;
  udal_t		DriverSize;
  void*			DriverSection;
  odas_ext_t*	DriverExtension;
	cdaw_t*	DriverName;
	cdaw_t**	HardwareDatabase;
  odas_spd_t*	FastIoDispatch;
  odas_ini_t*	DriverInit;
  da_run_ft	DriverStartIo;
  da_end_ft	DriverUnload;
  odas_snd_t*	MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];
};
#endif

long da_entry( odas_t *da, cdaw_t **reg );

#endif
