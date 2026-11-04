#include "ti_msp_dl_config.h"

int main(void)
{
	SYSCFG_DL_init();
	NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
	
	while(1)
	{
		
	}
}

void TIMER_0_INST_IRQHandler(void)
{
	switch (DL_Timer_getPendingInterrupt(TIMER_0_INST))
	{
	case DL_TIMER_IIDX_ZERO:
		DL_GPIO_togglePins(LED_PORT, LED_GREEN_PIN);
		break;
	
	default:
		break;
	}
}
