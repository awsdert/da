#ifndef INC_ODAS_KDENTRY
#define INC_ODAS_KDENTRY
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kdentry {
	odas_listent_t DeviceListEntry;
	udal_t SortKey;
	udac_t Inserted;
};
#endif
#endif
