#ifndef INC_ODAS_STR
#define INC_ODAS_STR
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_str {
	daw_t	Length;
  daw_t	MaximumLength;
  daw_t	*Buffer;
};
#endif
#endif
