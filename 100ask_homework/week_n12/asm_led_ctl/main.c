
#include "led.h"
#include "key.h"

void delay(volatile unsigned int d)
{
	while(d--);
}


int  main()
{
	led_init();
	key_init();

	while(1)
	{
		if(key_ctl() & (1 << 1)) {
			__asm__ volatile (
				"LDR R2,=0x020AC000\n\t"
				"LDR R1, [R2]\n\t"
				"BIC R1, R1,#0x8\n\t"
				"STR R1,[R2]\n\t"
			);
		} else {
			__asm__ volatile (
				"LDR R2,=0x020AC000\n\t"
				"LDR R1, [R2]\n\t"
				"ORR R1, R1,#0x8\n\t"
				"STR R1,[R2]\n\t"
			);
		}
	}
					
	return 0;
}


