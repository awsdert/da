#ifndef INC_DA_DA_H
#define INC_DA_DA_H
#include "os.h"
#include "ida.h"
#include "das.h"

#ifdef DA_MSWIN
#include <initguid.h>
#include <ntddk.h>
#include <ntintsafe.h>
#include <wdf.h>
#include <wdfusb.h>
#define DA_LICENSE(str)
#define DA_AUTHOR(str)
#define DA_DESC(str)
typedef SCHAR		idac_t;
typedef UCHAR		udac_t;
typedef SHORT		idas_t;
typedef USHORT	udas_t;
typedef INT			idai_t;
typedef UINT		udai_t;
typedef LONG		idal_t;
typedef ULONG		udal_t;
typedef BOOLEAN	dabl_t;
typedef MDL			da_mdl_t;
typedef IRP			da_irp_t;
typedef DEVICE_OBJECT		da_dev_t;
typedef DEVICE_STARTIO	da_run_ft;
typedef DEVICE_UNLOAD		da_end_ft;
typedef DRIVEROBJECT		da_t;
#else
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#define DA_LICENSE(str) MODULE_LICENSE(str);
#define DA_AUTHOR(str) MODULE_AUTHOR(str);
#define DA_DESC(str) MODULE_DESCRIPTION(str);
typedef _Bool dabl_t;
typedef struct da_dev da_dev_t;
typedef struct da_irp da_irp_t;
typedef struct da_mdl da_mdl_t;
struct da_mdl {
	da_mdl_t	*Next;
  idas_t		Size;
  idas_t		MdlFlags;
  struct _EPROCESS *Process;
  void			*MappedSystemVa;
  void			*StartVa;
  udal_t		ByteCount;
  udal_t		ByteOffset;
};
struct da_irp {
	da_mdl_t	*MdlAddress;
  udal_t		Flags;
  union {
    da_irp_t	*MasterIrp;
    void			*SystemBuffer;
  } AssociatedIrp;
  IO_STATUS_BLOCK IoStatus;
  KPROCESSOR_MODE RequestorMode;
  dabl_t		PendingReturned;
  dabl_t		Cancel;
  KIRQL           CancelIrql;
  PDRIVER_CANCEL  CancelRoutine;
  void			*UserBuffer;
  union {
    struct {
      union {
        KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
        struct {
          void	*DriverContext[4];
        };
      };
      PETHREAD   Thread;
      LIST_ENTRY ListEntry;
    } Overlay;
  } Tail;
};
typedef struct da_tmr da_tmr_t;
struct da_dev {
	idas_t		Type;
  idas_t		Size;
  idal_t		ReferenceCount;
  da_dev_t	*DriverObject;
  da_dev_t	*NextDevice;
  da_dev_t	*AttachedDevice;
  da_irp_t  *CurrentIrp;
  da_tmr_t	*Timer;
  udal_t		Flags;
  udal_t		Characteristics;
  __volatile PVPB             Vpb;
  void			*DeviceExtension;
  DEVICE_TYPE                 DeviceType;
  CCHAR                       StackSize;
  union {
    LIST_ENTRY         ListEntry;
    WAIT_CONTEXT_BLOCK Wcb;
  } Queue;
  udal_t		AlignmentRequirement;
  KDEVICE_QUEUE               DeviceQueue;
  KDPC                        Dpc;
  udal_t		ActiveThreadCount;
  PSECURITY_DESCRIPTOR        SecurityDescriptor;
  KEVENT                      DeviceLock;
  udas_t		SectorSize;
  udas_t		Spare1;
  struct _DEVOBJ_EXTENSION  *  DeviceObjectExtension;
  void			*Reserved;
}
typedef struct da_ext {
} da_ext_t;
typedef struct da_ini {
} da_ini_t;
typedef void (*da_run_ft)( da_dev_t *dev, da_irp_t *irp );
typedef void (*da_end_ft)( da_t *da );
typedef struct da_snd {
} da_snd_t;
typedef struct da_spd {
} da_spd_t;
typedef struct da {
	short			Type;
  short			Size;
  da_dev_t*	DeviceObject;
  udal_t		Flags;
  void*			DriverStart;
  udal_t		DriverSize;
  void*			DriverSection;
  da_ext_t*	DriverExtension;
	wchar_t*	DriverName;
	wchar_t**	HardwareDatabase;
  da_spd_t*	FastIoDispatch;
  da_ini_t*	DriverInit;
  da_run_t*	DriverStartIo;
  da_end_ft	DriverUnload;
  da_snd_t*	MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];
} da_t;
#endif

long da_entry( da_t *da, wchar_t **reg );

#endif
