#ifndef INC_ODAS_KPROC
#define INC_ODAS_KPROC
#include "odas.h"
#include "odas_listent.h"
#include "odas_single_listent.h"
#include "odas_sender_header.h"
#include "odas_kexec_options.h"
#include "odas_kgdtent.h"
#include "odas_kidtent.h"
#ifndef DA_OS_MSWIN
struct odas_kproc {
	odas_sender_header_t Header;
	odas_listent_t ProfileListHead;
	udal_t DirectoryTableBase;
	udal_t Unused0;
	odas_kgdtent_t LdtDescriptor;
	odas_kidtent_t Int21Descriptor;
	daw_t IopmOffset;
	udac_t Iopl;
	udac_t Unused;
	udal_t ActiveProcessors;
	udal_t KernelTime;
	udal_t UserTime;
	odas_listent_t ReadyListHead;
	odas_single_listent_t SwapListEntry;
	void *VdmTrapcHandler;
	odas_listent_t ThreadListHead;
	udal_t ProcessLock;
	udal_t Affinity;
	union
	{
		udal_t AutoAlignment: 1;
		udal_t DisableBoost: 1;
		udal_t DisableQuantum: 1;
		udal_t ReservedFlags: 29;
		idal_t ProcessFlags;
	};
	cdac_t BasePriority;
	cdac_t QuantumReset;
	udac_t State;
	udac_t ThreadSeed;
	udac_t PowerState;
	udac_t IdealNode;
	udac_t Visited;
	union
	{
		odas_kexec_options_t Flags;
		udac_t ExecuteOptions;
	};
	udal_t StackCount;
	odas_listent_t ProcessListEntry;
	udal64_t CycleTime;
};
#endif
#endif
