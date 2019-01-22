/* Our entry points file */
#include <types.h>
#include <stdbool.h>
typedef struct da_atomic {
	bool (*is0)( const atomic_t *v );
	int (*get)( const atomic_t *v );
	void (*set)( atomic_t *v, int i );
	void (*add)( atomic_t *v, int i );
	void (*mul)( atomic_t *v, int i );
	void (*sub)( atomic_t *v, int i );
	void (*div)( atomic_t *v, int i );
} da_atomic_t;
#ifdef DA_WIN32
#include <windows.h>
#else
#define _In_
#define _Out_
typedef long NTSTATUS;
typedef wchar_t *PUNICODE_STRING;
typedef struct _DRIVER_OBJECT {
	size_t cbSize;
} DRIVER_OBJECT, *PDRIVER_OBJECT;
#endif
/*
These are what the developer must define the contents of, failure
to do so will result in undefined references, as for what they do
use the following link as a guide:
https://www.kernel.org/doc/html/v4.11/driver-api/basics.html
*/
extern da_atomic_t da_atomic_object;
NTSTATUS da_open( PDRIVER_OBJECT obj, PUNICODE_STRING reg );
NTSTATUS da_shut( PDRIVER_OBJECT obj, PUNICODE_STRING reg );
#ifdef DA_WIN32
NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
) {
	WDF_DRIVER_CONFIG config;
	/* We made need to expand this function later
	so code sensibly in light of that */
	NTSTATUS status = 0;
#ifdef DA_BUILD_USBSAMP
	WDF_DRIVER_CONFIG_INIT(
		&config,
		UsbSamp_EvtDeviceAdd
	);
#endif
	status = WdfDriverCreate(
		DriverObject,
		RegistryPath,
		WDF_NO_OBJECT_ATTRIBUTES, /* Driver Attributes */
		&config, /* Driver Config Info */
		WDF_NO_HANDLE /* hDriver */
	); return status;
}
#else
int atomic_read(const atomic_t * v
) { da_atomic_object.get( v ); }
void atomic_set(const atomic_t * v, int i
) { da_atomic_object.set( v, i ); }
void atomic_add(int i, const atomic_t * v
) { da_atomic_object.add( v, i ); }
void atomic_mul(int i, const atomic_t * v
) { da_atomic_object.mul( v, i ); }
void atomic_sub(int i, const atomic_t * v
) { da_atomic_object.sub( v, i ); }
void atomic_div(int i, const atomic_t * v
) { da_atomic_object.div( v, i ); }
bool atomic_add_and_test(int i, const atomic_t * v
) { da_atomic_object.add( v, i ); return da_atomic_object.is0( v ); }
bool atomic_mul_and_test(int i, const atomic_t * v
) { da_atomic_object.mul( v, i ); return da_atomic_object.is0( v ); }
bool atomic_sub_and_test(int i, const atomic_t * v
) { da_atomic_object.sub( v, i ); return da_atomic_object.is0( v ); }
bool atomic_div_and_test(int i, const atomic_t * v
) { da_atomic_object.div( v, i ); return da_atomic_object.is0( v ); }
#endif
