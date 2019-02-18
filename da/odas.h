#ifndef INC_ODAS
#define INC_ODAS
#include "das.h"
#ifdef DA_OS_MSWIN
#include <ntddk.h>
#include <wdf.h>
typedef CSHORT		mswin_dacshort_t;
typedef NTSTATUS	mswin_dastatus_t;
typedef KIRQL dakirq_t;
typedef UNICODE_STRING odas_ucs_t;
typedef MDL			odas_mdl_t;
typedef IRP			da_irp_t;
typedef IO_STATUS_BLOCK odas_ios_block_t;
typedef DEVICE_OBJECT		odas_dev_t;
typedef DEVICE_STARTIO	da_run_ft;
typedef DEVICE_UNLOAD		da_end_ft;
typedef DRIVER_OBJECT		odas_t;
typedef PDRIVER_CANCEL	da_cancel_ft;
typedef SECURITY_DESCRIPTOR da_access_desc_t;
typedef KPROCESSOR_MODE	dakprocmode_t;
typedef KDEVICE_QUEUE_ENTRY odas_kdentry_t;
typedef ETHREAD odas_ethread_t;
typedef LARGE_INTEGER odas_lli_t;
typedef PTERMINATION_PORT odas_termport_t;
typedef CLIENT_ID odas_client_id_t;
typedef PS_CLIENT_SECURITY_CONTEXT odas_ps_client_sctx_t;
typedef EX_RUNDOWN_REF odas_xrundown_ref_t;
typedef EX_PUSH_LOCK dax_pushlock_t;
typedef KPRCB mswin_odas_kprcb_t;
typedef MDL odas_mdl_t;
typedef DISPATCHER_HEADER odas_sender_header_t;
typedef KEVENT odas_kevent_t;
typedef KDPC odas_kdpc_t;
#else
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
typedef short dacshort_t;
typedef int dastatus_t;
typedef int dakprocmode_t;
typedef int dakirq_t;
typedef struct odas_dev odas_dev_t;
typedef struct odas_irp odas_irp_t;
typedef struct odas_mdl odas_mdl_t;
typedef struct odas_tmr odas_tmr_t;
typedef struct odas_eproc odas_eproc_t;
typedef struct odas_ethread odas_ethread_t;
typedef struct odas_kthread odas_kthread_t;
typedef struct odas_termport odas_termport_t;
typedef struct odas_cid odas_cid_t;
typedef struct odas_lli odas_lli_t;
typedef struct mswin_odas_kprcb mswin_odas_kprcb_t; 
typedef struct odas_mdl odas_mdl_t;
typedef struct odas_sender_header odas_sender_header_t;
typedef struct odas_kevent odas_kevent_t;
typedef struct odas_kdentry odas_kdentry_t;
typedef struct odas_kdpc odas_kdpc_t;
#endif
#endif
