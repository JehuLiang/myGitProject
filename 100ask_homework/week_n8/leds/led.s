/***
*作者：梁招华
*日期：2021年10月9日
***/


.global _start  /* 全局标号 */

/***
功能描述：	_staRt函数，程序从此函数开始执行此函数完成时钟使能、
		  GPIO初始化、最终控制GPIO输出高低电平来点亮熄灭LED灯。
***/
_start:
	/* 例程代码 */
	/* 1、使能CCGR1时钟 */
	@ LDR R0, =0x020C406C 	/* CCGR1 */
	

	/* 2、设置GPIO5_IO03复用为GPIO5_IO03 */
	LDR R0, =(0x2290000 + 0x14)	/* 将寄存器IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1加载到R0中 */
	LDR R1, [R0]
	ORR R1, R1, #0x5		/* 设置寄存器IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1的MUX_MODE为5 */
	STR R1, [R0]


	/* 3、设置GPIO5_IO03为输出 */
    LDR R0, =0x020AC004	/*寄存器GPIO5_GDIR */
	LDR R1, [R0]
    ORR R1, R1, #(1<<3)		
    STR R1, [R0]


	/* 4、打开LED0
	 * 设置GPIO5_IO03输出低电平
	 */
	LDR R2, =0x020AC000	/*寄存器GPIO5_DR */

/*
 * 描述：	loop死循环
 */
Loop:

	LDR R1, [R2]	
	ORR R1, R1, #(1<<3)	
	STR R1,[R2]
			
	LDR R0, =1000000
	BL Delay

	LDR R1, [R2]	
	BIC R1, R1, #(1<<3)	
	STR R1,[R2]

	LDR R0, =1000000
	BL Delay


	b Loop
	
Delay:
	SUBS R0, R0, #1
	BNE Delay	
	MOV PC, LR
	
	


