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
typedef STRING odas_str_t;
typedef UNICODE_STRING odas_ucs_t;
typedef CURDIR odas_curdir_t;
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
typedef KTHREAD odas_kthread_t;
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
typedef MMADDRESS_NODE odas_mm_addr_node_t;
typedef MM_AVL_TABLE odas_mm_available_table_t;
typedef _EPROCESS_QUOTA_BLOCK odas_eproc_quota_block_t;
typedef _EPROCESS_QUOTA_ENTRY odas_eproc_quota_entry_t;
typedef PEB odas_peb_t;
typedef KAPC odas_kapc_t;
typedef KTRAP_FRAME odas_ktrap_frame_t;
typedef KSPIN_LOCK da_kspin_lock_t;
typedef _PAGEFAULT_HISTORY odas_pagefault_history_t;
typedef RTL_CRITICAL_SECTION odas_rtl_crit_sect_t;
typedef RTL_CRITICAL_SECTION_DEBUG odas_rtl_crit_sect_dbg_t;
typedef PEB_LDR_DATA odas_peb_loader_data_t;
typedef PEB_FREE_BLOCK odas_peb_free_block_t;
typedef RTL_USER_PROCESS_PARAMETERS odas_rtl_proc_param_t;
typedef RTL_DRIVE_LETTER_CURDIR odas_rtl_drive_letter_curdir_t;
typedef EXCEPTION_REGISTRATION_RECORD odas_exception_reg_rec_t;
typedef EXCEPTION_DISPOSITION eda_exception_disposition_t;
typedef KWAIT_BLOCK odas_kwait_block_t;
typedef KTIMER odas_ktimer_t;
typedef KQUEUE odas_kque_t;
typedef KGATE odas_kgate_t;
typedef MMWSL odas_mm_working_set_list_t;
typedef MMWSLE odas_mm_working_set_liste_t;
typedef MMWSLE_NONDIRECT_HASH odas_mm_working_set_listeptr_t;
typedef MMWSLE_HASH odas_mm_working_set_listepos_t;
typedef MMSUPPORT odas_mm_support_t;
typedef MMSUPPORT_FLAGS odas_mm_support_flags_t;
typedef SE_AUDIT_PROCESS_CREATION_INFO odas_se_audit_proc_init_info_t;
typedef OBJECT_NAME_INFORMATION odas_name_info_t;
typedef HARDWARE_PTE odas_hardware_pte_t;
typedef _JOB_ACCESS_STATE da_job_access_state_t;
typedef KSEMAPHORE odas_ksemaphore_t;
typedef OWNER_ENTRY odas_ownerent_t;
typedef ERESOURCE odas_eresource_t;
typedef EJOB odas_ejob_t;
typedef HANDLE_TABLE odas_handles_t;
typedef HANDLE_TABLE_ENTRY odas_handlesent_t;
typedef HANDLE_TABLE_ENTRY_INFO odas_handlesent_info_t;
typedef HANDLE_TRACE_DEBUG_INFO odas_handle_trace_dbginf_t;
typedef HANDLE_TRACE_DB_ENTRY odas_handle_trace_dbgent_t;
typedef FAST_MUTEX odas_fast_mutex_t;
typedef _ACTIVATION_CONTEXT_DATA da_activation_ctx_data_t;
typedef _ASSEMBLY_STORAGE_MAP da_asm_storage_map_t;
typedef _FLS_CALLBACK_INFO da_fls_callback_info_t;
#else
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
typedef enum eda_exception_disposition {
	ExceptionContinueExecution = 0,
	ExceptionContinueSearch = 1,
	ExceptionNestedException = 2,
	ExceptionCollidedUnwind	= 3
} eda_exception_disposition_t;
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
typedef struct odas_llu odas_llu_t;
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
typedef struct odas_mm_addr_node odas_mm_addr_node_t;
typedef struct odas_mm_available_table odas_mm_available_table_t;
typedef struct odas_mm_support odas_mm_support_t;
typedef struct odas_mm_support_flags odas_mm_support_flags_t;
typedef struct odas_eproc_quota_block odas_eproc_quota_block_t;
typedef struct odas_eproc_quota_entry odas_eproc_quota_entry_t;
typedef struct odas_peb odas_peb_t;
typedef struct odas_proc_ws_watch_info odas_proc_ws_watch_info_t;
typedef struct odas_pagefault_history odas_pagefault_history_t;
typedef struct odas_rtl_crit_sect odas_rtl_crit_sect_t;
typedef struct odas_rtl_crit_sect_dbg odas_rtl_crit_sect_dbg_t;
typedef struct odas_str odas_str_t;
typedef struct odas_ucs odas_ucs_t;
typedef struct odas_curdir odas_curdir_t;
typedef struct odas_peb_loader_data odas_peb_loader_data_t;
typedef struct odas_peb_free_block odas_peb_free_block_t;
typedef struct odas_rtl_proc_param odas_rtl_proc_param_t;
typedef struct odas_rtl_drive_letter_curdir odas_rtl_drive_letter_curdir_t;
typedef struct odas_kapc odas_kapc_t;
typedef struct odas_ktrap_frame odas_ktrap_frame_t;
typedef struct odas_exception_reg_rec odas_exception_reg_rec_t;
typedef struct odas_kwait_block odas_kwait_block_t;
typedef struct odas_ktimer odas_ktimer_t;
typedef struct odas_kque odas_kque_t;
typedef struct odas_kgate odas_kgate_t;
typedef struct odas_mm_working_set_list odas_mm_working_set_list_t;
typedef struct odas_mm_working_set_liste odas_mm_working_set_listent_t;
typedef struct odas_mm_working_set_listeptr odas_mm_working_set_listeptr_t;
typedef struct odas_mm_working_set_listepos odas_mm_working_set_listepos_t;
typedef struct odas_se_audit_proc_init_info odas_se_audit_proc_init_info_t;
typedef struct odas_name_info odas_name_info_t;
typedef struct odas_hardware_pte odas_hardware_pte_t;
typedef struct odas_ksemaphore odas_ksemaphore_t;
typedef struct odas_ownerent odas_ownerent_t;
typedef struct odas_eresource odas_eresource_t;
typedef struct odas_ejob odas_ejob_t;
typedef struct odas_fast_mutex odas_fast_mutex_t;
typedef struct odas_handles odas_handles_t;
typedef struct odas_handlesent odas_handlesent_t;
typedef struct odas_handlesent_info odas_handlesent_info_t;
typedef struct odas_handle_trace_dbgent odas_handle_trace_dbgent_t;
typedef struct odas_handle_trace_dbginf odas_handle_trace_dbginf_t;
/* TODO: Find out what _JOB_ACCESS_STATE truly is
http://msdn.mirt.net/win7rtm_x64.html#_JOB_ACCESS_STATE shows empty struct
https://share.neodarz.net/archive/ntoskrnl.org/index.html shows pointer
*/
typedef struct da_job_access_state {} da_job_access_state_t;
/* TODO: similar situation as above most likely */
typedef struct da_activation_ctx_data {} da_activation_ctx_data_t;
typedef struct da_asm_storage_map {} da_asm_storage_map_t;
typedef struct da_fls_callback_info {} da_fls_callback_info_t;
#endif
#endif
