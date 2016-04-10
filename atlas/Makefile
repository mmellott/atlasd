obj-m += atlas.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

tags:
	make -C /lib/modules/$(shell uname -r)/build O=$(PWD) tags

