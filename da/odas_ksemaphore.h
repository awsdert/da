#ifndef INC_ODAS_KSEMAPHORE
#define INC_ODAS_KSEMAPHORE
#include "odas_sender_header.h"
#ifndef DA_OS_MSWIN
struct odas_ksemaphore {
	odas_sender_header_t Header;
	idal_t Limit;
};
#endif
#endif
