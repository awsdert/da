#ifndef INC_ODAS_KSEMAPHORE
#define INC_ODAS_KSEMAPHORE
#include "odas_sender_header.h"
#ifdef DA_OS_MSWIN
typedef KSEMAPHORE odas_ksemaphore_t;
#else
typedef struct odas_ksemaphore odas_ksemaphore_t;
struct odas_ksemaphore {
	odas_sender_header_t Header;
	idal_t Limit;
};
#endif
#endif
