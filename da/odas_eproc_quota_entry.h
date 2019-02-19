#ifndef INC_ODAS_EPROC_QUOTA_ENTRY
#define INC_ODAS_EPROC_QUOTA_ENTRY
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_eproc_quota_entry {
	dasize_t Usage;
	dasize_t Limit;
	dasize_t Peak;
	dasize_t Return;
};
#endif
#endif
