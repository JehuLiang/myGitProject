#include "key.h"

static volatile unsigned int *CCM_CCGR3                              ;
static volatile unsigned int *SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control;
static volatile unsigned int *GPIO4_GDIR                             ;

void key_init(void)
{
	CCM_CCGR3                               = (volatile unsigned int *)(0x020C4074);
	SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control = (volatile unsigned int *)(0x020E01B0);
	GPIO4_GDIR                              = (volatile unsigned int *)(0x020A8000 + 0x4);

	unsigned int val;
	
	/* GPIO4_IO14 */
	/* a. 使能GPIO5
	 * set CCM to enable GPIO5
	 * CCM_CCGR1[CG15] 0x20C4074
	 * bit[13:12] = 0b11
	 */
	*CCM_CCGR3 |= (3<<12);
	
	/* b. 设置GPIO4_IO14用于GPIO
	 * set SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control
	 *      to configure GPIO4_IO14 as GPIO
	 * SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control  0x20E01B0
	 * bit[3:0] = 0b0101 alt5
	 */
	val = *SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control;
	val &= ~(0xf);
	val |= (0x5);
	*SW_MUX_CTL_PAD_NAND_CE1_B_SW_MUX_Control = val;
	
	
	/* c. 设置GPIO4_IO14作为input引脚
	 * set GPIO5_GDIR to configure GPIO4_IO14 as output
	 * GPIO5_GDIR  0x020A8000 + 0x4
	 * bit[3] = 0b1
	 */
	*GPIO4_GDIR &= (1<<14);
}




	
	
