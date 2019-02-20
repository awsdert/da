#ifndef INC_ODAS_PEB_LOADER_DATA
#define INC_ODAS_PEB_LOADER_DATA
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_peb_loader_data {
	udal_t Length;
	udac_t Initialized;
	void *SsHandle;
	odas_listent_t InLoadOrderModuleList;
	odas_listent_t InMemoryOrderModuleList;
	odas_listent_t InInitializationOrderModuleList;
	void *EntryInProgress;
};
#endif
#endif
