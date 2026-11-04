#include "ti_msp_dl_config.h"
#include <stdio.h>
#include <string.h>

void UART0_SendChar(char ch)
{
	// 当串口0忙时等待
	while (DL_UART_isBusy(UART_0_INST) == true);
	
	// 发送单个字符
	DL_UART_Main_transmitData(UART_0_INST, ch);
}

void UART0_SendString(const char *str)
{
	while (*str != '\0')
	{
		UART0_SendChar(*str);
		str++;
	}
}

int fputc(int ch, FILE *stream)
{
        while( DL_UART_isBusy(UART_0_INST) == true );

        DL_UART_Main_transmitData(UART_0_INST, ch);

        return ch;
}

volatile unsigned char uart_data = 0;
uint8_t RX_Flag = 0;

int main(void)
{
	SYSCFG_DL_init();

	// 清除串口中断标志
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	// 使能串口中断
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
	
	while(1)
	{
		if (RX_Flag == 1)
		{
			if (uart_data == '1')
			{
				UART0_SendString("LED_GREEN_ON\r\n");
				DL_GPIO_setPins(LED_PORT, LED_GREEN_PIN);
			}
			else if (uart_data == '0')
			{
				UART0_SendString("LED_GREEN_OFF\r\n");
				DL_GPIO_clearPins(LED_PORT, LED_GREEN_PIN);
			}

			RX_Flag = 0; // 清除接收标志
		}
		
	}
}

void UART0_IRQHandler(void)
{
	switch (DL_UART_getPendingInterrupt(UART_0_INST))
	{
		case DL_UART_IIDX_RX: // 接收中断
			//接发送过来的数据保存在变量中
            uart_data = DL_UART_Main_receiveData(UART_0_INST);
			
			RX_Flag = 1;
			break;
		default:
			break;
	}
}
