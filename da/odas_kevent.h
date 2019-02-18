#ifndef INC_ODAS_KEVENT
#define INC_ODAS_KEVENT
#include "odas.h"
#include "odas_sender_header.h"
#ifndef DA_OS_MSWIN
struct odas_kevent {
	odas_sender_header_t Header;
};
#endif
#endif
