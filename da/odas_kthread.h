#ifndef INC_ODAS_KTHREAD
#define INC_ODAS_KTHREAD
#include "odas.h"
#include "odas_listent.h"
#include "odas_sender_header.h"
#include "odas_kproc.h"
#include "odas_kapc_state.h"
#ifdef DA_OS_MSWIN
typedef KTHREAD odas_kthread_t;
#else
typedef struct odas_kthread odas_kthread_t;
struct odas_kthread {
	odas_sender_header_t Header;
	udal64_t CycleTime;
	udal_t HighCycleTime;
	udal64_t QuantumTarget;
	void* InitialStack;
	void* StackLimit;
	void* KernelStack;
	udal_t ThreadLock;
	union
	{
			odas_kapc_state_t ApcState;
			udac_t ApcStateFill[23];
	};
	cdac_t Priority;
	daw_t NextProcessor;
	daw_t DeferredProcessor;
	udal_t ApcQueueLock;
	udal_t ContextSwitches;
	udac_t State;
	udac_t NpxState;
	udac_t WaitIrql;
	cdac_t WaitMode;
	idal_t WaitStatus;
	union
	{
			PKWAIT_BLOCK WaitBlockList;
			PKGATE GateObject;
	};
	union
	{
			udal_t KernelStackResident: 1;
			udal_t ReadyTransition: 1;
			udal_t ProcessReadyQueue: 1;
			udal_t WaitNext: 1;
			udal_t SystemAffinityActive: 1;
			udal_t Alertable: 1;
			udal_t GdiFlushActive: 1;
			udal_t Reserved: 25;
			idal_t MiscFlags;
	};
	udac_t WaitReason;
	udac_t SwapBusy;
	udac_t Alerted[2];
	union
	{
			odas_listent_t WaitListEntry;
			odas_single_listent_t SwapListEntry;
	};
	PKQUEUE Queue;
	udal_t WaitTime;
	union
	{
			struct
			{
					 idas_t KernelApcDisable;
					 idas_t SpecialApcDisable;
			};
			udal_t CombinedApcDisable;
	};
	void* Teb;
	union
	{
			KTIMER Timer;
			udac_t TimerFill[40];
	};
	union
	{
			udal_t AutoAlignment: 1;
			udal_t DisableBoost: 1;
			udal_t EtwStackTraceApc1Inserted: 1;
			udal_t EtwStackTraceApc2Inserted: 1;
			udal_t CycleChargePending: 1;
			udal_t CalloutActive: 1;
			udal_t ApcQueueable: 1;
			udal_t EnableStackSwap: 1;
			udal_t GuiThread: 1;
			udal_t ReservedFlags: 23;
			idal_t ThreadFlags;
	};
	union
	{
			KWAIT_BLOCK WaitBlock[4];
			struct
			{
					 udac_t WaitBlockFill0[23];
					 udac_t IdealProcessor;
			};
			struct
			{
					 udac_t WaitBlockFill1[47];
					 cdac_t PreviousMode;
			};
			struct
			{
					 udac_t WaitBlockFill2[71];
					 udac_t ResourceIndex;
			};
			udac_t WaitBlockFill3[95];
	};
	udac_t LargeStack;
	odas_listent_t QueueListEntry;
	PKTRAP_FRAME TrapFrame;
	void* FirstArgument;
	union
	{
			void* CallbackStack;
			udal_t CallbackDepth;
	};
	void* ServiceTable;
	udac_t ApcStateIndex;
	cdac_t BasePriority;
	cdac_t PriorityDecrement;
	udac_t Preempted;
	udac_t AdjustReason;
	cdac_t AdjustIncrement;
	udac_t Spare01;
	cdac_t Saturation;
	udal_t SystemCallNumber;
	udal_t Spare02;
	udal_t UserAffinity;
	odas_kproc_t *Process;
	udal_t Affinity;
	odas_kapc_state_t *ApcStatePointer[2];
	union
	{
			odas_kapc_state_t SavedApcState;
			udac_t SavedApcStateFill[23];
	};
	cdac_t FreezeCount;
	cdac_t SuspendCount;
	udac_t UserIdealProcessor;
	udac_t Spare03;
	udac_t Iopl;
	void* Win32Thread;
	void* StackBase;
	union
	{
			KAPC SuspendApc;
			struct
			{
					 udac_t SuspendApcFill0[1];
					 cdac_t Spare04;
			};
			struct
			{
					 udac_t SuspendApcFill1[3];
					 udac_t QuantumReset;
			};
			struct
			{
					 udac_t SuspendApcFill2[4];
					 udal_t KernelTime;
			};
			struct
			{
					 udac_t SuspendApcFill3[36];
					 odas_kprcb_t *WaitPrcb;
			};
			struct
			{
					 udac_t SuspendApcFill4[40];
					 void* LegoData;
			};
			udac_t SuspendApcFill5[47];
	};
	udac_t PowerState;
	udal_t UserTime;
	union
	{
			odas_ksemaphore_t SuspendSemaphore;
			udac_t SuspendSemaphorefill[20];
	};
	udal_t SListFaultCount;
	odas_listent_t ThreadListEntry;
	odas_listent_t MutantListHead;
	void* SListFaultAddress;
	void* MdlForLockedTeb;
};
#endif
#endif
