
#include "key.h"

static volatile unsigned int *CCM_CCGR1                              ;
static volatile unsigned int *IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1;
static volatile unsigned int *GPIO5_GDIR                             ;
static volatile unsigned int *GPIO5_DR                               ;

void key_init(void)
{
	unsigned int val;
	
	CCM_CCGR1                               = (volatile unsigned int *)(0x20C406C);
	IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1 = (volatile unsigned int *)(0x229000C);
	GPIO5_GDIR                              = (volatile unsigned int *)(0x020AC000 + 0x4);
	GPIO5_DR                                = (volatile unsigned int *)(0x020AC000);

	/* b. 设置GPIO5_IO01用于GPIO
	 */
	val = *IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1;
	val &= ~(0xf);
	val |= (5);
	*IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1 = val;
	
	
	/* c. 设置GPIO5_IO01作为input引脚
	 */
	*GPIO5_GDIR &= ~(1<<1);
}

int key_ctl(void)
{
	int ret = 0;
	ret = *GPIO5_DR;
	return ret;
}




	
	
