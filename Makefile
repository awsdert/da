ifneq ($(KERNELRELEASE),)

obj-m	:= entry.o das.o

else

default:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

endif
