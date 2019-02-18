#ifndef INC_ODAS_KDPC
#define INC_ODAS_KDPC
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kdpc {
	udac_t Type;
	udac_t Importance;
	daw_t Number;
	odas_listent_t DpcListEntry;
	void* DeferredRoutine;
	void* DeferredContext;
	void* SystemArgument1;
	void* SystemArgument2;
	void* DpcData;
};
#endif
#endif
