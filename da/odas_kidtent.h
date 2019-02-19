#ifndef INC_ODAS_KIDTENT
#define INC_ODAS_KIDTENT
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_kidtent
{
	daw_t Offset;
	daw_t Selector;
	daw_t Access;
	daw_t ExtendedOffset;
};
#endif
#endif
