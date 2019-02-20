#ifndef INC_ODAS_KTIMER
#define INC_ODAS_KTIMER
#include "odas.h"
#include "odas_sender_header.h"
#include "odas_llu.h"
#include "odas_listent.h"
#include "odas_kdpc.h"
#ifndef DA_OS_MSWIN
struct odas_ktimer {
	odas_sender_header_t Header;
	odas_llu_t DueTime;
	odas_listent_t TimerListEntry;
	odas_kdpc_t *Dpc;
	idal_t Period;
};
#endif
#endif
