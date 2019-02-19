#ifndef INC_ODAS_LLI
#define INC_ODAS_LLI
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_lli {
	union
	{
		struct
		{
			udal_t LowPart;
			idal_t HighPart;
		};
		idall_t QuadPart;
	};
};
#endif
#endif
