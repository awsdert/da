#ifndef INC_ODAS_OWNERENT
#define INC_ODAS_OWNERENT
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_ownerent
	udal_t OwnerThread;
	union
	{
		idal_t OwnerCount;
		udal_t TableSize;
	};
};
#endif
#endif
