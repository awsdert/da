#ifndef INC_ODAS_MM_WORKING_SET_LIST
#define INC_ODAS_MM_WORKING_SET_LIST
#include "odas.h"
#include "odas_mm_working_set_liste.h"
#include "odas_mm_working_set_listeptr.h"
#include "odas_mm_working_set_listepos.h"
#ifndef DA_OS_MSWIN
struct odas_mm_working_set_list {
	udal_t FirstFree;
	udal_t FirstDynamic;
	udal_t LastEntry;
	udal_t NextSlot;
	odas_mm_working_set_liste_t *Wsle;
	void *LowestPagableAddress;
	udal_t LastInitializedWsle;
	udal_t NextEstimationSlot;
	udal_t NextAgingSlot;
	udal_t EstimatedAvailable;
	udal_t GrowthSinceLastEstimate;
	udal_t NumberOfCommittedPageTables;
	udal_t VadBitMapHint;
	udal_t NonDirectCount;
	odas_mm_working_set_listeptr_t *NonDirectHash;
	odas_mm_working_set_listepos_t *HashTableStart;
	odas_mm_working_set_listepos_t *HighestPermittedHashAddress;
	void *HighestUserAddress;
	daw_t UsedPageTableEntries[1536];
	udal_t CommittedPageTables[48];
};
#endif
#endif
