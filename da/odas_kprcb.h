#ifndef INC_ODAS_KPRCB
#define INC_ODAS_KPRCB
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct mswin_odas_kprcb
{
     daw_t MinorVersion;
     daw_t MajorVersion;
     odas_kthread_t* CurrentThread;
     odas_kthread_t* NextThread;
     odas_kthread_t* IdleThread;
     udac_t Number;
     udac_t NestingLevel;
     daw_t BuildType;
     udal_t SetMember;
     cdac_t CpuType;
     cdac_t CpuID;
     union
     {
          daw_t CpuStep;
          struct
          {
               udac_t CpuStepping;
               udac_t CpuModel;
          };
     };
     KPROCESSOR_STATE ProcessorState;
     udal_t KernelReserved[16];
     udal_t HalReserved[16];
     udal_t CFlushSize;
     udac_t PrcbPad0[88];
     KSPIN_LOCK_QUEUE LockQueue[33];
     odas_kthread_t *NpxThread;
     udal_t InterruptCount;
     udal_t KernelTime;
     udal_t UserTime;
     udal_t DpcTime;
     udal_t DpcTimeCount;
     udal_t InterruptTime;
     udal_t AdjustDpcThreshold;
     udal_t PageColor;
     udac_t SkipTick;
     udac_t DebuggerSavedIRQL;
     udac_t NodeColor;
     udac_t PollSlot;
     udal_t NodeShiftedColor;
     PKNODE ParentNode;
     udal_t MultiThreadProcessorSet;
     mswin_odas_kprcb_t *MultiThreadSetMaster;
     udal_t SecondaryColorMask;
     udal_t DpcTimeLimit;
     udal_t CcFastReadNoWait;
     udal_t CcFastReadWait;
     udal_t CcFastReadNotPossible;
     udal_t CcCopyReadNoWait;
     udal_t CcCopyReadWait;
     udal_t CcCopyReadNoWaitMiss;
     idal_t MmSpinLockOrdering;
     idal_t IoReadOperationCount;
     idal_t IoWriteOperationCount;
     idal_t IoOtherOperationCount;
     odas_lli_t IoReadTransferCount;
     odas_lli_t IoWriteTransferCount;
     odas_lli_t IoOtherTransferCount;
     udal_t CcFastMdlReadNoWait;
     udal_t CcFastMdlReadWait;
     udal_t CcFastMdlReadNotPossible;
     udal_t CcMapDataNoWait;
     udal_t CcMapDataWait;
     udal_t CcPinMappedDataCount;
     udal_t CcPinReadNoWait;
     udal_t CcPinReadWait;
     udal_t CcMdlReadNoWait;
     udal_t CcMdlReadWait;
     udal_t CcLazyWriteHotSpots;
     udal_t CcLazyWriteIos;
     udal_t CcLazyWritePages;
     udal_t CcDataFlushes;
     udal_t CcDataPages;
     udal_t CcLostDelayedWrites;
     udal_t CcFastReadResourceMiss;
     udal_t CcCopyReadWaitMiss;
     udal_t CcFastMdlReadResourceMiss;
     udal_t CcMapDataNoWaitMiss;
     udal_t CcMapDataWaitMiss;
     udal_t CcPinReadNoWaitMiss;
     udal_t CcPinReadWaitMiss;
     udal_t CcMdlReadNoWaitMiss;
     udal_t CcMdlReadWaitMiss;
     udal_t CcReadAheadIos;
     udal_t KeAlignmentFixupCount;
     udal_t KeExceptionDispatchCount;
     udal_t KeSystemCalls;
     udal_t PrcbPad1[3];
     PP_LOOKASIDE_LIST PPLookasideList[16];
     GENERAL_LOOKASIDE_POOL PPNPagedLookasideList[32];
     GENERAL_LOOKASIDE_POOL PPPagedLookasideList[32];
     udal_t PacketBarrier;
     idal_t ReverseStall;
     void* IpiFrame;
     udac_t PrcbPad2[52];
     void * CurrentPacket[3];
     udal_t TargetSet;
     void* WorkerRoutine;
     udal_t IpiFrozen;
     udac_t PrcbPad3[40];
     udal_t RequestSummary;
     mswin_odas_kprcb_t *SignalDone;
     udac_t PrcbPad4[56];
     KDPC_DATA DpcData[2];
     void* DpcStack;
     idal_t MaximumDpcQueueDepth;
     udal_t DpcRequestRate;
     udal_t MinimumDpcRate;
     udac_t DpcInterruptRequested;
     udac_t DpcThreadRequested;
     udac_t DpcRoutineActive;
     udac_t DpcThreadActive;
     udal_t PrcbLock;
     udal_t DpcLastCount;
     udal_t TimerHand;
     udal_t TimerRequest;
     void* PrcbPad41;
     KEVENT DpcEvent;
     udac_t ThreadDpcEnable;
     udac_t QuantumEnd;
     udac_t PrcbPad50;
     udac_t IdleSchedule;
     idal_t DpcSetEventRequest;
     idal_t Sleeping;
     udal_t PeriodicCount;
     udal_t PeriodicBias;
     udac_t PrcbPad5[6];
     idal_t TickOffset;
     KDPC CallDpc;
     idal_t ClockKeepAlive;
     udac_t ClockCheckSlot;
     udac_t ClockPollCycle;
     udac_t PrcbPad6[2];
     idal_t DpcWatchdogPeriod;
     idal_t DpcWatchdogCount;
     idal_t ThreadWatchdogPeriod;
     idal_t ThreadWatchdogCount;
     udal_t PrcbPad70[2];
     odas_listent_t WaitListHead;
     udal_t WaitLock;
     udal_t ReadySummary;
     udal_t QueueIndex;
     SINGLE_LIST_ENTRY DeferredReadyListHead;
     udal64_t StartCycles;
     udal64_t CycleTime;
     udal64_t PrcbPad71[3];
     odas_listent_t DispatcherReadyListHead[32];
     void* ChainedInterruptList;
     idal_t LookasideIrpFloat;
     idal_t MmPageFaultCount;
     idal_t MmCopyOnWriteCount;
     idal_t MmTransitionCount;
     idal_t MmCacheTransitionCount;
     idal_t MmDemandZeroCount;
     idal_t MmPageReadCount;
     idal_t MmPageReadIoCount;
     idal_t MmCacheReadCount;
     idal_t MmCacheIoCount;
     idal_t MmDirtyPagesWriteCount;
     idal_t MmDirtyWriteIoCount;
     idal_t MmMappedPagesWriteCount;
     idal_t MmMappedWriteIoCount;
     udal_t CachedCommit;
     udal_t CachedResidentAvailable;
     void* HyperPte;
     udac_t CpuVendor;
     udac_t PrcbPad9[3];
     udac_t VendorString[13];
     udac_t InitialApicId;
     udac_t CoresPerPhysicalProcessor;
     udac_t LogicalProcessorsPerPhysicalProcessor;
     udal_t MHz;
     udal_t FeatureBits;
     odas_lli_t UpdateSignature;
     udal64_t IsrTime;
     udal64_t SpareField1;
     FX_SAVE_AREA NpxSaveArea;
     PROCESSOR_POWER_STATE PowerState;
     KDPC DpcWatchdogDpc;
     KTIMER DpcWatchdogTimer;
     void* WheaInfo;
     void* EtwSupport;
     SLIST_HEADER InterruptObjectPool;
     odas_lli_t HypercallPagePhysical;
     void* HypercallPageVirtual;
     void* RateControl;
     CACHE_DESCRIPTOR Cache[5];
     udal_t CacheCount;
     udal_t CacheProcessorMask[5];
     udac_t LogicalProcessorsPerCore;
     udac_t PrcbPad8[3];
     udal_t PackageProcessorSet;
     udal_t CoreProcessorSet;
};
#endif
#endif
