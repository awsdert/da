#ifndef INC_ODAS_CLIENT_ID
#define INC_ODAS_CLIENT_ID
#ifndef DA_OS_MSWIN
struct odas_client_id {
	void *UniqueProcess;
	void *UniqueThread;
};
#endif
#endif
