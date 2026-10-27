#include "ti_msp_dl_config.h"

int main(void)
{
	SYSCFG_DL_init();
	
	while(1)
	{
		// DL_GPIO_clearPins(LED_PORT, LED_GREEN_PIN);
		// delay_cycles(40000000);
		// DL_GPIO_setPins(LED_PORT, LED_GREEN_PIN);
		// delay_cycles(40000000);

		DL_GPIO_clearPins(LED_PORT, LED_WHITE_PIN);
		delay_cycles(40000000);
		DL_GPIO_setPins(LED_PORT, LED_WHITE_PIN);
		delay_cycles(40000000);
	}
}
