#ifndef INC_ODAS_LISTENT
#define INC_ODAS_LISTENT
#include "odas.h"
#ifdef DA_OS_MSWIN
typedef LIST_ENTRY odas_listent_t;
#else
typedef struct odas_listent odas_listent_t;
struct odas_listent {
	odas_listent_t *Flink;
	odas_listent_t *Blink;
};
#endif
#endif
