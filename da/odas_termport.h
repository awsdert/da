#ifndef INC_ODAS_TERMPORT
#define INC_ODAS_TERMPORT
#ifndef DA_OS_MSWIN
struct odas_termport {
	odas_termport_t *Next;
	void *Port;
};
#endif
#endif
