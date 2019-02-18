#ifndef INC_ODAS_SND_HEADER
#define INC_ODAS_SND_HEADER
#include "odas_listent.h"
#ifndef DA_OS_MSWIN
struct odas_sender_header {
	union
	{
		struct
		{
			udac_t Type;
			union
			{
				udac_t Abandoned;
				udac_t Absolute;
				udac_t NpxIrql;
				udac_t Signalling;
			};
			union
			{
				udac_t Size;
				udac_t Hand;
			};
			union
			{
				udac_t Inserted;
				udac_t DebugActive;
				udac_t DpcActive;
			};
		};
		idal_t Lock;
	};
	idal_t SignalState;
	odas_listent_t WaitListHead;
};
#endif
#endif
