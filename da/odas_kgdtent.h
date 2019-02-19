#ifndef INC_ODAS_KGDTENT
#define INC_ODAS_KGDTENT
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_kgdtent
{
     daw_t LimitLow;
     daw_t BaseLow;
     udal_t HighWord;
};
#endif
#endif
