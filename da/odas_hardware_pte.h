#ifndef INC_ODAS_HARDWARE_PTE
#define INC_ODAS_HARDWARE_PTE
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_hardware_pte {
	union
	{
		udal_t Valid: 1;
		udal_t Write: 1;
		udal_t Owner: 1;
		udal_t WriteThrough: 1;
		udal_t CacheDisable: 1;
		udal_t Accessed: 1;
		udal_t Dirty: 1;
		udal_t LargePage: 1;
		udal_t Global: 1;
		udal_t CopyOnWrite: 1;
		udal_t Prototype: 1;
		udal_t reserved0: 1;
		udal_t PageFrameNumber: 26;
		udal_t reserved1: 26;
		udal_t LowPart;
	};
	udal_t HighPart;
};
#endif
#endif
