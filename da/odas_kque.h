#ifndef INC_ODAS_KQUE
#define INC_ODAS_KQUE
#include "odas.h"
#include "odas_sender_header.h"
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_kque {
	odas_sender_header_t Header;
	odas_listent_t EntryListHead;
	udal_t CurrentCount;
	udal_t MaximumCount;
	odas_listent_t ThreadListHead;
};
#endif
#endif
