#ifndef ODAS_PEB_FREE_BLOCK
#define ODAS_PEB_FREE_BLOCK
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_peb_free_block {
	odas_peb_free_block_t *Next;
	udal_t Size;
};
#endif
#endif
