#ifndef INC_ODAS_MDL
#define INC_ODAS_MDL
#include "odas.h"
#include "odas_eproc.h"
#ifndef DA_OS_MSWIN
struct odas_mdl {
	odas_mdl_t	*Next;
  idas_t		Size;
  idas_t		MdlFlags;
  odas_eproc_t *Process;
  void			*MappedSystemVa;
  void			*StartVa;
  udal_t		ByteCount;
  udal_t		ByteOffset;
};
#endif
#endif
