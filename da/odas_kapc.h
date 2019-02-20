#ifndef INC_ODAS_KAPC
#define INC_ODAS_KAPC
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kapc {
	udac_t Type;
	udac_t SpareByte0;
	udac_t Size;
	udac_t SpareByte1;
	udal_t SpareLong0;
	odas_kthread_t *Thread;
	odas_listent_t ApcListEntry;
	void *KernelRoutine;
	void *RundownRoutine;
	void *NormalRoutine;
	void *NormalContext;
	void *SystemArgument1;
	void *SystemArgument2;
	cdac_t ApcStateIndex;
	cdac_t ApcMode;
	udac_t Inserted;
};
#endif
#endif
