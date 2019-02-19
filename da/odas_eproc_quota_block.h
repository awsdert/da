#ifndef INC_EPROC_QUOTA_BLOCK
#define INC_EPROC_QUUTA_BLOCK
#include "odas.h"
#include "odas_eproc_quota_entry.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_eproc_quota_block {
	odas_eproc_quota_entry_t QuotaEntry[3];
	odas_listent_t QuotaList;
	udal_t ReferenceCount;
	udal_t ProcessCount;
};
#endif
#endif
