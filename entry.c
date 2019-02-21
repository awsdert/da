#define DA_REG da/test
#include "da/da.h"
DA_LICENSE("MIT")
DA_AUTHOR("da and gb2985@gmail.com")
DA_DESC("da (driver api) test")
long da_entry( odas_t *da, cdaw_t **reg ) {
	*reg = DA_TOWCS(DA_REG);
	/* Intentionally fail */
	return 1;
}
DA_INIT(da_entry)
