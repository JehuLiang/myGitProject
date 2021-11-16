#include "uart.h"
#include "string.h"
#include "gic.h"



int main(void)
{
	unsigned char c;
	uart_init();
	gic_init();
	do_irq_c();
	


	puts("uart irq test\r\n");
	while(1)
	{
		c = getchar();
		if (c == '\r')
		{
			putchar('\n');
		}

		if (c == '\n')
		{
			putchar('\r');
		}

		putchar(c);

	}
	
	return 0;
}



