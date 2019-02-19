#ifndef INC_ODAS_XRUNDOWN_REF
#define INC_ODAS_XRUNDOWN_REF
#ifndef DA_OS_WIN
struct odas_xrundown_ref {
	union
	{
		udal_t Count;
		void *Ptr;
	};
};
#endif
#endif
