PREFIX=arm-linux-gnueabihf-
CC=$(PREFIX)gcc
LD=$(PREFIX)ld
AR=$(PREFIX)ar
OBJCOPY=$(PREFIX)objcopy
OBJDUMP=$(PREFIX)objdump

CFLAGS =  -nostdinc

objs = start.o main.o led.o key.o

dep_files := $(patsubst %,.%.d, $(objs))
dep_files := $(wildcard $(dep_files))

asm_led_ctl.img : $(objs)
	$(LD) -T imx6ull.lds -g $^ -o asm_led_ctl.elf 
	$(OBJCOPY) -O binary -S asm_led_ctl.elf  asm_led_ctl.bin
	$(OBJDUMP) -D -m arm  asm_led_ctl.elf  > asm_led_ctl.dis	
	./tools/mkimage -n ./tools/imximage.cfg.cfgtmp -T imximage -e 0x80100000 -d asm_led_ctl.bin asm_led_ctl.imx
	dd if=/dev/zero of=1k.bin bs=1024 count=1
	cat 1k.bin asm_led_ctl.imx > asm_led_ctl.img

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o : %.c
	$(PREFIX)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d -fno-builtin-FUNCTION

%.o : %.S
	$(PREFIX)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d -fno-builtin-FUNCTION

clean:
	rm -f asm_led_ctl.dis  asm_led_ctl.bin asm_led_ctl.elf asm_led_ctl.imx asm_led_ctl.img *.o *d 1k.bin