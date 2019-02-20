#ifndef INC_ODAS_KWAIT_BLOCK
#define INC_ODAS_KWAIT_BLOCK
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kwait_block {
	odas_listent_t WaitListEntry;
	odas_kthread_t *Thread;
	void *Object;
	odas_kwait_block_t *NextWaitBlock;
	daw_t WaitKey;
	udac_t WaitType;
	udac_t SpareByte;
};
#endif
#endif
