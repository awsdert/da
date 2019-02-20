#ifndef INC_ODAS_MM_ADDR_NODE
#define INC_ODAS_MM_ADDR_NODE
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_mm_addr_node {
	udal_t u1;
	odas_mm_addr_node_t *LeftChild;
	odas_mm_addr_node_t *RightChild;
	udal_t StartingVpn;
	udal_t EndingVpn;
};
#endif
#endif
