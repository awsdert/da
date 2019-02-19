#ifndef INC_ODAS_KDQUE
#define INC_ODAS_KDQUE
#include "odas.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kdque {
	idas_t Type;
	idas_t Size;
	odas_listent_t DeviceListHead;
	udal_t Lock;
	udac_t Busy;
};
#endif
#endif
