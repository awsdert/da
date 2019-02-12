/* Our entry points file */
#include "da/da.h"
#ifdef DA_MSWIN
NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
) {
	return da_entry( DriverObject, RegistryPath );
}
#else
da_t da = {0};
wchar_t *reg = DA_REG;
static int __init insert_mod(void)
{
	if ( da_entry( &da, &reg ) == EXIT_SUCCESS ) {
		printk("da driver loaded");
		return EXIT_SUCCESS;
	} printk("da driver failed to load");
	return EXIT_FAILURE;
}
static void __exit remove_mod(void)
{
	da.DriverUnload( &da );
	printk("da driver unloaded");
}
module_init(insert_mod);
module_exit(remove_mod);
#endif
