PREFIX=arm-linux-gnueabihf-
CC=$(PREFIX)gcc
LD=$(PREFIX)ld
AR=$(PREFIX)ar
OBJCOPY=$(PREFIX)objcopy
OBJDUMP=$(PREFIX)objdump

CFLAGS =  -nostdinc

objs = start.o uart.o string.o init.o exception.o gic.o main.o

dep_files := $(patsubst %,.%.d, $(objs))
dep_files := $(wildcard $(dep_files))

uart.img : $(objs)
	$(LD) -T imx6ull.lds -g $^ -o uart.elf 
	$(OBJCOPY) -O binary -S uart.elf  uart.bin
	$(OBJDUMP) -D -m arm  uart.elf  > uart.dis	
	./tools/mkimage -n ./tools/imximage.cfg.cfgtmp -T imximage -e 0x80100000 -d uart.bin uart.imx
	dd if=/dev/zero of=1k.bin bs=1024 count=1
	cat 1k.bin uart.imx > uart.img

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o : %.c
	$(PREFIX)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d -fno-builtin-FUNCTION

%.o : %.S
	$(PREFIX)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d -fno-builtin-FUNCTION

clean:
	rm -f uart.dis  uart.bin uart.elf uart.imx uart.img *.o .*.d


	
