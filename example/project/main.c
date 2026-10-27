#include "ti_msp_dl_config.h"

int main(void)
{
	SYSCFG_DL_init();
	
	while(1)
	{
		DL_GPIO_clearPins(LED_PORT, LED_GREEN_PIN);
		delay_cycles(80000000);
		DL_GPIO_setPins(LED_PORT, LED_GREEN_PIN);
		delay_cycles(80000000);
	}
}
