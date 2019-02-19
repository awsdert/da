#ifndef INC_ODAS_IRP
#define INC_ODAS_IRP
#include "odas.h"
#include "odas_ios_block.h"
#ifndef DA_OS_MSWIN
struct odas_irp {
	odas_mdl_t	*MdlAddress;
  udal_t		Flags;
  union {
    odas_irp_t	*MasterIrp;
    void			*SystemBuffer;
  } AssociatedIrp;
  odas_ios_block_t IoStatus;
  dakprocmode_t RequestorMode;
  udab_t		PendingReturned;
  udab_t		Cancel;
  dakirq_t	CancelIrql;
  da_cancel_ft	CancelRoutine;
  void			*UserBuffer;
  union {
    struct {
      union {
        odas_kdentry_t	DeviceQueueEntry;
        struct {
          void	*DriverContext[4];
        };
      };
      odas_ethread_t   *Thread;
      odas_listent_t ListEntry;
    } Overlay;
  } Tail;
};
#endif
#endif
