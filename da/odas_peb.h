#ifndef INC_ODAS_PEB
#define INC_ODAS_PEB
#include "odas.h"
#include "odas_lli.h"
#include "odas_llu.h"
#include "odas_ucs.h"
#include "odas_listent.h"
#include "odas_peb_loader_data.h"
#include "odas_rtl_proc_param.h"
#include "odas_rtl_crit_sect.h"
#ifndef DA_OS_MSWIN
struct odas_peb {
	udac_t InheritedAddressSpace;
	udac_t ReadImageFileExecOptions;
	udac_t BeingDebugged;
	udac_t BitField;
	udal_t ImageUsesLargePages: 1;
	udal_t IsProtectedProcess: 1;
	udal_t IsLegacyProcess: 1;
	udal_t IsImageDynamicallyRelocated: 1;
	udal_t SpareBits: 4;
	void *Mutant;
	void *ImageBaseAddress;
	odas_peb_loader_data_t *Ldr;
	odas_rtl_proc_param_t *ProcessParameters;
	void *SubSystemData;
	void *ProcessHeap;
	odas_rtl_crit_sect_t *FastPebLock;
	void *AtlThunkSListPtr;
	void *IFEOKey;
	udal_t CrossProcessFlags;
	udal_t ProcessInJob: 1;
	udal_t ProcessInitializing: 1;
	udal_t ReservedBits0: 30;
	union
	{
		void *KernelCallbackTable;
		void *UserSharedInfoPtr;
	};
	udal_t SystemReserved[1];
	udal_t SpareUlong;
	odas_peb_free_block_t *FreeList;
	udal_t TlsExpansionCounter;
	void *TlsBitmap;
	udal_t TlsBitmapBits[2];
	void *ReadOnlySharedMemoryBase;
	void *HotpatchInformation;
	void * * ReadOnlyStaticServerData;
	void *AnsiCodePageData;
	void *OemCodePageData;
	void *UnicodeCaseTableData;
	udal_t NumberOfProcessors;
	udal_t NtGlobalFlag;
	odas_lli_t CriticalSectionTimeout;
	udal_t HeapSegmentReserve;
	udal_t HeapSegmentCommit;
	udal_t HeapDeCommitTotalFreeThreshold;
	udal_t HeapDeCommitFreeBlockThreshold;
	udal_t NumberOfHeaps;
	udal_t MaximumNumberOfHeaps;
	void * * ProcessHeaps;
	void *GdiSharedHandleTable;
	void *ProcessStarterHelper;
	udal_t GdiDCAttributeList;
	odas_rtl_crit_sect_t *LoaderLock;
	udal_t OSMajorVersion;
	udal_t OSMinorVersion;
	daw_t OSBuildNumber;
	daw_t OSCSDVersion;
	udal_t OSPlatformId;
	udal_t ImageSubsystem;
	udal_t ImageSubsystemMajorVersion;
	udal_t ImageSubsystemMinorVersion;
	udal_t ImageProcessAffinityMask;
	udal_t GdiHandleBuffer[34];
	void *PostProcessInitRoutine;
	void *TlsExpansionBitmap;
	udal_t TlsExpansionBitmapBits[32];
	udal_t SessionId;
	odas_llu_t AppCompatFlags;
	odas_llu_t AppCompatFlagsUser;
	void *pShimData;
	void *AppCompatInfo;
	odas_ucs_t CSDVersion;
	da_activation_ctx_data_t * ActivationContextData;
	da_asm_storage_map_t * ProcessAssemblyStorageMap;
	da_activation_ctx_data_t * SystemDefaultActivationContextData;
	da_asm_storage_map_t * SystemAssemblyStorageMap;
	udal_t MinimumStackCommit;
	da_fls_callback_info_t * FlsCallback;
	odas_listent_t FlsListHead;
	void *FlsBitmap;
	udal_t FlsBitmapBits[4];
	udal_t FlsHighIndex;
	void *WerRegistrationData;
	void *WerShipAssertPtr;
};
#endif
#endif
