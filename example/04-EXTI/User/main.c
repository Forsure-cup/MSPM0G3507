#include "ti_msp_dl_config.h"

int main(void)
{
	SYSCFG_DL_init();
	NVIC_EnableIRQ(KEY_INT_IRQN); // 开启GPIOA中断
	
	while(1)
	{
		
	}
}

void GROUP1_IRQHandler(void)
{
	// 读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        // 检查是否是KEY的GPIOA端口中断，注意是INT_IIDX，不是PIN_18_IIDX
        case KEY_INT_IIDX:
            // 如果按键按下变为高电平
            if (DL_GPIO_readPins(KEY_PORT, KEY_PIN_2_PIN) > 0)
            {
                // 设置LED引脚状态翻转
                DL_GPIO_togglePins(LED_PORT, LED_GREEN_PIN);
				delay_cycles(1000000); // 延时一段时间，防止按键抖动
            }
        break;
    }
}
