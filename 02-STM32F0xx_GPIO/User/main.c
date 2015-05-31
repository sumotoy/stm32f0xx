/**
 * Keil project example for GPIO
 *
 * Before you start, select your target, on the right of the "Load" button
 *
 * @author    Tilen Majerle
 * @email     tilen@majerle.eu
 * @website   http://stm32f4-discovery.com
 * @ide       Keil uVision 5
 * @packs     STM32F0xx Keil packs version 1.4.0 or greater required
 * @stdperiph STM32F0xx Standard peripheral drivers version 1.5.0 or greater required
 */
/* Include core modules */
#include "stm32f0xx.h"
/* Include my libraries here */
#include "tm_stm32f0_gpio.h"
#include "defines.h"

int main(void) {
	volatile uint32_t d;
	
	/* Initialize system */
	SystemInit();

	/* Init GPIO, PA5 is LED */
	TM_GPIO_Init(GPIOA, GPIO_PIN_5, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	
	/* Set pin low */
	TM_GPIO_SetPinLow(GPIOA, GPIO_PIN_5);
	
	while (1) {
		/* Toggle LED */
		TM_GPIO_TogglePinValue(GPIOA, GPIO_PIN_5);
		
		/* A little delay */
		d = 1000000;
		while (d--);
	}
}
