#define DA_REG "da/test"
DA_LICENSE("MIT")
DA_AUTHOR("da and gb2985@gmail.com")
DA_DESCRIPTION("da (driver api) test")
long da_entry( da_t *da, wchar_t **reg ) {
	*reg = DA_REG;
	/* Intentionally fail */
	return EXIT_FAILURE;
}
