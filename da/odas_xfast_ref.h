#ifndef INC_ODAS_XFAST_REF
#define INC_ODAS_XFAST_REF
#ifndef DA_OS_MSWIN
struct odas_xfast_ref {
	union
	{
		void *Object;
		udal_t RefCnt: 3;
		udal_t Value;
	};
};
#endif
#endif
