#ifndef INC_ODAS_KTRAP_FRAME
#define INC_ODAS_KTRAP_FRAME
#include "odas.h"
#ifndef DA_OS_MSWIN
struct odas_ktrap_frame {
	udal_t DbgEbp;
	udal_t DbgEip;
	udal_t DbgArgMark;
	udal_t DbgArgPointer;
	daw_t TempSegCs;
	udac_t Logging;
	udac_t Reserved;
	udal_t TempEsp;
	udal_t Dr0;
	udal_t Dr1;
	udal_t Dr2;
	udal_t Dr3;
	udal_t Dr6;
	udal_t Dr7;
	udal_t SegGs;
	udal_t SegEs;
	udal_t SegDs;
	udal_t Edx;
	udal_t Ecx;
	udal_t Eax;
	udal_t PreviousPreviousMode;
	odas_exception_reg_rec_t *ExceptionList;
	udal_t SegFs;
	udal_t Edi;
	udal_t Esi;
	udal_t Ebx;
	udal_t Ebp;
	udal_t ErrCode;
	udal_t Eip;
	udal_t SegCs;
	udal_t EFlags;
	udal_t HardwareEsp;
	udal_t HardwareSegSs;
	udal_t V86Es;
	udal_t V86Ds;
	udal_t V86Fs;
	udal_t V86Gs;
};
#endif
#endif
