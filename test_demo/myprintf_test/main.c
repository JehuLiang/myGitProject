#include "my_printf.h"
#include "uart.h"

int  main()
{	Uart_Init();

	unsigned char cTestData ;       /*用于测试发送的数据*/


	PutStr("Hello, world!\n\r");	/*发送字符串*/
	
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
				
		PutChar(cTestData)    ;				/*从串口发送数据*/
		printf("DDDD= %05d", cTestData);	
	}
					
			
	return 0;
}
		  			 		  						  					  				 	   		  	  	 	  