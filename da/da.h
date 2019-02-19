#ifndef INC_DA_DA_H
#define INC_DA_DA_H
#include "os.h"
#include "ida.h"
#include "das.h"

#ifdef DA_OS_MSWIN
#define DA_LICENSE(str)
#define DA_AUTHOR(str)
#define DA_DESC(str)
#else
#define DA_LICENSE(str) MODULE_LICENSE(str);
#define DA_AUTHOR(str) MODULE_AUTHOR(str);
#define DA_DESC(str) MODULE_DESCRIPTION(str);
#define IRP_MJ_MAXIMUM_FUNCTION 512
#include "odas.h"
#include "odas_lli.h"
#include "odas_listent.h"
#include "odas_sender_header.h"
#include "odas_client_id.h"
#include "odas_ps_client_sctx.h"
#include "odas_xrundown_ref.h"
#include "odas_kevent.h"
#include "odas_kproc.h"
#include "odas_eproc.h"
#include "odas_ksemaphore.h"
#include "odas_kthread.h"
typedef struct odas_ext {
} odas_ext_t;
typedef struct odas_ini {
} odas_ini_t;
typedef struct odas_snd {
} odas_snd_t;
typedef struct odas_spd {
} odas_spd_t;
typedef struct odas odas_t;
typedef void (*da_cancel_ft)( odas_t *da );
typedef void (*da_run_ft)( odas_dev_t *dev, odas_irp_t *irp );
typedef void (*da_end_ft)( odas_t *da );
typedef struct odas_ucs odas_ucs_t;
struct odas_ucs {
	daw_t	Length;
  daw_t	MaximumLength;
  daw_t	*Buffer;
};
struct odas {
	mswin_dacshort_t		Type;
  mswin_dacshort_t		Size;
  odas_dev_t*	DeviceObject;
  udal_t		Flags;
  void*			DriverStart;
  udal_t		DriverSize;
  void*			DriverSection;
  odas_ext_t*	DriverExtension;
	cdaw_t*	DriverName;
	cdaw_t**	HardwareDatabase;
  odas_spd_t*	FastIoDispatch;
  odas_ini_t*	DriverInit;
  da_run_ft	DriverStartIo;
  da_end_ft	DriverUnload;
  odas_snd_t*	MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];
};
#endif

long da_entry( odas_t *da, cdaw_t **reg );

#endif
