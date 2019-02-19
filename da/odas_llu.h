#ifndef INC_ODAS_LLU
#define INC_ODAS_LLU
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_llu {
	union
	{
		struct
		{
			udal_t LowPart;
			udal_t HighPart;
		};
		udal64_t QuadPart;
	};
};
#endif
#endif
