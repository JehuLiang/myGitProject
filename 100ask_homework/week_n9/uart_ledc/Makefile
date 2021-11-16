PREFIX=arm-linux-gnueabihf-
CC=$(PREFIX)gcc
LD=$(PREFIX)ld
AR=$(PREFIX)ar
OBJCOPY=$(PREFIX)objcopy
OBJDUMP=$(PREFIX)objdump

uart_led.img : start.S  uart.c led.c main.c
	$(CC)  -g -c -o start.o start.S
	$(CC)  -g -c -o uart.o uart.c	
	$(CC)  -g -c -o led.o led.c	
	$(CC)  -g -c -o main.o main.c 
	
	$(LD) -T imx6ull.lds -g start.o uart.o led.o main.o -o uart_led.elf 
	
	$(OBJCOPY) -O binary -S uart_led.elf  uart_led.bin
	$(OBJDUMP) -D -m arm  uart_led.elf  > uart_led.dis	
	./tools/mkimage -n ./tools/imximage.cfg.cfgtmp -T imximage -e 0x80100000 -d uart_led.bin uart_led.imx
	dd if=/dev/zero of=1k.bin bs=1024 count=1
	cat 1k.bin uart_led.imx > uart_led.img

clean:
	rm -f uart_led.dis  uart_led.bin uart_led.elf uart_led.imx uart_led.img *.o


	
