#ifndef INC_ODAS_HANDLESENT
#define INC_ODAS_HANDLESENT
#include "odas.h"
#include "odas_handlesent_info.h"
#ifndef DA_OS_MSWIN
struct odas_handlesent {
	union
	{
		void *Object;
		udal_t ObAttributes;
		odas_handlesent_info_t *InfoTable;
		udal_t Value;
	};
	union
	{
		udal_t GrantedAccess;
		struct
		{
			daw_t GrantedAccessIndex;
			daw_t CreatorBackTraceIndex;
		};
		idal_t NextFreeTableEntry;
	};
};
#endif
#endif
