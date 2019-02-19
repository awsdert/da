#ifndef INC_ODAS_UCS
#define INC_ODAS_UCS
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_ucs {
	daw_t	Length;
  daw_t	MaximumLength;
  daw_t	*Buffer;
};
#endif
#endif
