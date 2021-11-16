#include "led.h"
#include "key.h"

static volatile unsigned int *GPIO4_DR                                ;


void delay(volatile unsigned int d)
{
	while(d--);
}


int  main()
{
	GPIO4_DR                                = (volatile unsigned int *)(0x020A8000);
	key_init();
	led_init();

	while(1)
	{
		if((*GPIO4_DR & (1<<14)) == 0)
		{
		
			led_ctl(0);
			delay(100000);

		}
		else 
		{
			led_ctl(1);
			delay(100000);
		}

	}
					
	return 0;
}
