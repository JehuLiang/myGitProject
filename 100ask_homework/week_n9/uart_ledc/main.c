#include "led.h"
#include "uart.h"
                        

void delay(volatile unsigned int d)
{
	while(d--);
}


int  main()
{
	Uart_Init()	;
	led_init()	;

	int i = 0;
	unsigned char str[i];
	unsigned char cTestData ;    			 /*用于测试发送的数据*/

	PutStr("please input 'on' turn on led or 'off' turn off led \n\r");	/*发送字符串*/


	while(1)
	{
		cTestData = GetChar() ;				/*等待从串口获取数据*/
		
		if (cTestData == '\r')  		/*添加回到行首\r*/
		{ 
			PutChar('\n');
		}

		if (cTestData == '\n')			/*换行\n*/
		{
			PutChar('\r');	
		}

		PutChar(cTestData)	;				/*从串口发送数据*/


		str[i] = cTestData;
		i++;

		if (cTestData == '\r' || cTestData == '\n')
		{
			if (str[0] == 'o' && str[1] == 'n' && (str[2] == '\r' || str[3] == '\n'))
			{
				led_ctl(1);
				delay(1000000);
			}
			else if (str[0] == 'o' && str[1] == 'f' && str[2] == 'f' && (str[3] == '\r' || str[4] == '\n'))
			{
				led_ctl(0);
				delay(1000000);
			}
			i = 0 ;
		}

	}
					
	return 0;
}
