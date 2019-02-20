#ifndef INC_ODAS_EXCEPTION_REG_REC
#define INC_ODAS_EXCEPTION_REG_REC
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_exception_reg_rec {
	odas_exception_reg_rec_t *Next;
	eda_exception_disposition_t *Handler;
};
#endif
#endif
