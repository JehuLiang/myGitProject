#include "led.h"
#include "uart.h"
                        

void delay(volatile unsigned int d)
{
	while(d--);
}

/**string compare **/
int strcmp (const unsigned char *src, const unsigned char *dst)
{
        int ret = 0 ;
        while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
        {
                ++src;
                ++dst;
        }
        if ( ret < 0 )
                ret = -1 ;
        else if ( ret > 0 )
                ret = 1 ;
        return( ret );
}

unsigned char* GetString(void)
{
	char c;
	int i = 20;
	unsigned char str1[i] ;
	unsigned char* str = str1;
	while (*str != '\0')
	{
		if ((c = GetChar()) != '\r')
		{
			*str = c ;
			str++;
			PutChar(c)	;				/*从串口发送数据*/
		}
		else 
		{
			PutChar('\n');
			*str = c ;
			str++;
			PutChar(c)	;				/*从串口发送数据*/
		}

	}
	return str ;
}

int  main()
{
	Uart_Init()	;
	led_init()	;

	unsigned char* state_1 = "on";
	unsigned char* state_2 = "off";

	unsigned char* cTestData ;    			 /*用于测试发送的数据*/

	PutStr("please input 'on' turn on led or 'off' turn off led \n\r");	/*发送字符串*/


	while(1)
	{
		
		cTestData = GetString();


		// if (cTestData == state_1)
		// {
		// 	led_ctl(0);
		// 	delay(1000000);

		// }

		// if (cTestData == state_2)
		// {
		// 	led_ctl(1);
		// 	delay(1000000);
		// }

		if (strcmp(cTestData, state_1)==0)
		{
			led_ctl(0);
			delay(1000000);

		}

		if (strcmp(cTestData, state_2)==0)
		{
			led_ctl(1);
			delay(1000000);
		}

	}
					
	return 0;
}
