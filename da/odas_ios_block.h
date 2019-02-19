#ifndef INC_ODAS_IOS_BLOCK
#define INC_ODAS_IOS_BLOCK
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_ios_block {
	union {
		dastatus_t	Status;
		void	*Pointer;
	} DUMMYUNIONNAME;
	udalp_t Information;
};
#endif
#endif
