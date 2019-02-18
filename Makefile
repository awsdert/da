ifneq ($(KERNELRELEASE),)

obj-m	:= da_main.o entry.o da/das.o

else

default:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

endif
