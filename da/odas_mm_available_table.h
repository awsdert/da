#ifndef INC_ODAS_MM_AVAILABLE_TABLE
#define INC_ODAS_MM_AVAILABLE_TABLE
#include "odas.h"
#include "odas_mmaddr_node.h"
#ifndef DA_OS_MSWIN
struct odas_mm_available_table {
	odas_mmaddr_node_t BalancedRoot;
	udal_t DepthOfTree: 5;
	udal_t Unused: 3;
	udal_t NumberGenericTableElements: 24;
	void *NodeHint;
	void *NodeFreeHint;
};
#endif
#endif
