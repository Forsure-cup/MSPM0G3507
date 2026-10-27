#include "ti_msp_dl_config.h"

int main(void)
{
	SYSCFG_DL_init();

	DL_GPIO_setPins(LED_PORT, LED_GREEN_PIN);
	
	while(1)
	{
		if (DL_GPIO_readPins(KEY_PORT, KEY_KEY1_PIN) > 0)
		{
			DL_GPIO_clearPins(LED_PORT, LED_WHITE_PIN);
		}
		else
		{
			DL_GPIO_setPins(LED_PORT, LED_WHITE_PIN);
		}
	}
}
