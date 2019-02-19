#ifndef INC_ODAS
#define INC_ODAS
#include "das.h"
#ifdef DA_OS_MSWIN
#include <ntddk.h>
#include <wdf.h>
typedef CCHAR		mswin_dacchar_t;
typedef CSHORT		mswin_dacshort_t;
typedef NTSTATUS	dastatus_t;
typedef SIZE_T dasize_t;
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
typedef EX_FAST_REF odas_xfast_ref_t;
typedef EX_PUSH_LOCK odas_xpushlock_t;
typedef KPRCB mswin_odas_kprcb_t;
typedef MDL odas_mdl_t;
typedef KIDTENTRY odas_kidtent_t;
typedef KGDTENTRY odas_kgdtent_t;
typedef DISPATCHER_HEADER odas_sender_header_t;
typedef KEVENT odas_kevent_t;
typedef KDPC odas_kdpc_t;
typedef KDQUEUE odas_kdque_t;
typedef KEXECUTE_OPTIONS odas_kexec_options_t;
typedef KAPC_STATE odas_kapc_state_t;
typedef SINGLE_LIST_ENTRY odas_single_listent_t;
typedef MMADDRESS_NODE odas_mmaddr_node_t;
typedef MM_AVL_TABLE odas_mm_available_table_t;
typedef _EPROCESS_QUOTA_BLOCK odas_eproc_quota_block_t;
typedef _EPROCESS_QUOTA_ENTRY odas_eproc_quota_entry_t;
typedef PEB odas_peb_t;
typedef KSPIN_LOCK da_kspin_lock_t;
typedef _PAGEFAULT_HISTORY odas_pagefault_history_t;
typedef RTL_CRITICAL_SECTION odas_rtl_crit_sect_t;
typedef RTL_CRITICAL_SECTION_DEBUG odas_rtl_crit_sect_dbg_t;
#else
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
typedef char mswin_dacchar_t;
typedef idas_t mswin_dacshort_t;
typedef udal_t da_kspin_lock_t;
typedef int dastatus_t;
typedef size_t dasize_t;
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
typedef struct odas_client_id odas_client_id_t;
typedef struct odas_lli odas_lli_t;
typedef struct mswin_odas_kprcb mswin_odas_kprcb_t; 
typedef struct odas_mdl odas_mdl_t;
typedef struct odas_sender_header odas_sender_header_t;
typedef struct odas_kevent odas_kevent_t;
typedef struct odas_kdentry odas_kdentry_t;
typedef struct odas_kdpc odas_kdpc_t;
typedef struct odas_kprcb odas_kprcb_t;
typedef struct odas_kapc_state odas_kapc_state_t;
typedef struct odas_xpushlock odas_xpushlock_t;
typedef struct odas_xfast_ref odas_xfast_ref_t;
typedef struct odas_xrundown_ref odas_xrundown_ref_t;
typedef struct odas_listent odas_listent_t;
typedef struct odas_single_listent odas_single_listent_t;
typedef struct odas_kproc odas_kproc_t;
typedef struct odas_kdque odas_kdque_t;
typedef struct odas_kgdtent odas_kgdtent_t;
typedef struct odas_kidtent odas_kidtent_t;
typedef struct odas_kexec_options odas_kexec_options_t;
typedef struct odas_mmaddr_node odas_mmaddr_node_t;
typedef struct odas_mm_available_table odas_mm_available_table_t;
typedef struct odas_eproc_quota_block odas_eproc_quota_block_t;
typedef struct odas_eproc_quota_entry odas_eproc_quota_entry_t;
typedef struct odas_peb odas_peb_t;
typedef struct odas_proc_ws_watch_info odas_proc_ws_watch_info_t;
typedef struct odas_pagefault_history odas_pagefault_history_t;
typedef struct odas_rtl_crit_sect odas_rtl_crit_sect_t;
typedef struct odas_rtl_crit_sect_dbg odas_rtl_crit_sect_dbg_t;
typedef struct odas_ucs odas_ucs_t;
#endif
#endif
