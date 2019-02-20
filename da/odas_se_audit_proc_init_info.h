#ifndef INC_ODAS_SE_AUDIT_PROC_INIT_INFO
#define INC_ODAS_SE_AUDIT_PROC_INIT_INFO
#include "odas.h"
#include "odas_name_info.h"
#ifndef DA_OS_MSWIN
struct odas_se_audit_proc_init_info {
	odas_name_info_t *ImageFileName;
};
#endif
#endif
