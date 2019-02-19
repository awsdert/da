#ifndef INC_ODAS_PS_CLIENT_SCTX
#define INC_ODAS_PS_CLIENT_SCTX
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_ps_client_sctx {
	union
	{
		udal_t ImpersonationData;
		void *ImpersonationToken;
		udal_t ImpersonationLevel: 2;
		udal_t EffectiveOnly: 1;
	};
};
#endif
#endif
