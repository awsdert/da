#ifndef INC_ODAS_MMADDR_NODE
#define INC_ODAS_MMADDR_NODE
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_mmaddr_node {
	udal_t u1;
	odas_mmaddr_node_t *LeftChild;
	odas_mmaddr_node_t *RightChild;
	udal_t StartingVpn;
	udal_t EndingVpn;
};
#endif
