#ifndef INC_ODAS_XPUSHLOCK
#define INC_ODAS_XPUSHLOCK
#ifndef DA_OS_MSWIN
struct odas_xpushlock {
	union
	{
		udal_t Locked: 1;
		udal_t Waiting: 1;
		udal_t Waking: 1;
		udal_t MultipleShared: 1;
		udal_t Shared: 28;
		udal_t Value;
		void *Ptr;
	};
};
#endif
#endif
