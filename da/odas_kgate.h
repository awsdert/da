#ifndef INC_ODAS_KGATE
#define INC_ODAS_KGATE
#include "odas.h"
#include "odas_sender_header.h"
#ifndef DA_OS_MSWIN
struct odas_kgate {
	odas_sender_header_t Header;
};
#endif
#endif
