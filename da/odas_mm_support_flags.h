#ifndef INC_ODAS_MM_SUPPORT_FLAGS
#define INC_ODAS_MM_SUPPORT_FLAGS
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_mm_support_flags {
	udal_t SessionSpace: 1;
	udal_t ModwriterAttached: 1;
	udal_t TrimHard: 1;
	udal_t MaximumWorkingSetHard: 1;
	udal_t ForceTrim: 1;
	udal_t MinimumWorkingSetHard: 1;
	udal_t SessionMaster: 1;
	udal_t TrimmerAttached: 1;
	udal_t TrimmerDetaching: 1;
	udal_t Reserved: 7;
	udal_t MemoryPriority: 8;
	udal_t WsleDeleted: 1;
	udal_t VmExiting: 1;
	udal_t Available: 6;
};
#endif
#endif
