#ifndef INC_ODAS_DEV
#define INC_ODAS_DEV
#include "odas.h"
#include "odas_irp.h"
#include "odas_tmr.h"
#include "odas_kevent.h"
#include "odas_kdque.h"
#ifndef DA_OS_MSWIN
struct odas_dev {
	idas_t		Type;
  idas_t		Size;
  idal_t		ReferenceCount;
  odas_dev_t	*DriverObject;
  odas_dev_t	*NextDevice;
  odas_dev_t	*AttachedDevice;
  odas_irp_t  *CurrentIrp;
  odas_tmr_t	*Timer;
  udal_t		Flags;
  udal_t		Characteristics;
  __volatile PVPB             Vpb;
  void			*DeviceExtension;
  DEVICE_TYPE                 DeviceType;
  mswin_dacchar_t             StackSize;
  union {
    odas_listent_t	ListEntry;
    WAIT_CONTEXT_BLOCK Wcb;
  } Queue;
  udal_t		AlignmentRequirement;
  odas_kdque_t               DeviceQueue;
  odas_kdpc_t                 Dpc;
  udal_t		ActiveThreadCount;
  da_access_desc_t	*SecurityDescriptor;
  odas_kevent_t                      DeviceLock;
  udas_t		SectorSize;
  udas_t		Spare1;
  struct _DEVOBJ_EXTENSION  *  DeviceObjectExtension;
  void			*Reserved;
};
#endif
#endif
