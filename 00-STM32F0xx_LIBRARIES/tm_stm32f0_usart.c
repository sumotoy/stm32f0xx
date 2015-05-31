/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2015
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#include "tm_stm32f0_usart.h"

typedef struct {
	uint8_t* Buffer;
} TM_USART_t;

TM_USART_t TM_USART1;
TM_USART_t TM_USART2;
TM_USART_t TM_USART3;
TM_USART_t TM_USART4;
TM_USART_t TM_USART5;
TM_USART_t TM_USART6;
TM_USART_t TM_USART7;
TM_USART_t TM_USART8;

void TM_USART_Init(USART_TypeDef* USARTx, TM_USART_PinsPack_t PinsPack, uint32_t baudrate) {
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	/* Fill default settings */
#ifdef USART1_IRQHANDLER
	if (USARTx == USART1) {
		/* Enable clock for USART1 */
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		
		/* Init USART1 pins */
		TM_INT_USART1_InitPins(PinsPack)
		
		/* Select NVIC interrupt source */
		NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQ;
	}
#endif
	
}

void TM_USART_Putc(USART_TypeDef* USARTx, char c) {
	/* Check if USART enabled */
	if (USARTx->CR1 & USART_CR1_UE) {
		/* Wait for USART to end */
		while (!(USARTx->ISR & USART_ISR_TXE));
		/* Set data to transmit register */
		USARTx->TDR = c;
		/* Wait for USART to end */
		while (!(USARTx->ISR & USART_ISR_TXE));
	}
}

/* Private functions */
void TM_USART_INT_AddToBuffer(TM_USART_t* USART, char c) {

}

void TM_USART_INT_Init(
	USART_TypeDef* USARTx,
	TM_USART_PinsPack_t PinsPack,
	uint32_t baudrate
) {
	
}

/* USART1 interrupt handler */
void USART1_IRQHANDLER(void) {
	/* Data is ready */
	if (USART1->ISR & USART_ISR_RXNE) {
		/* Get data */
		TM_USART_INT_AddToBuffer(&TM_USART1, USART1->RDR);
	}
}

#ifdef USART2_IRQHANDLER
/* USART2 interrupt handler */
void USART2_IRQHANDLER(void) {
	/* Data is ready */
	if (USART2->ISR & USART_ISR_RXNE) {
		/* Get data */
		TM_USART_INT_AddToBuffer(&TM_USART2, USART2->RDR);
	}
}
#endif

#if defined(USART8_IRQHANDLER) || defined(USART6_IRQHANDLER) || defined(USART4_IRQHANDLER)
#if defined(USART8_IRQHANDLER)
void USART8_IRQHANDLER(void) {
#elif defined(USART6_IRQHANDLER)
void USART6_IRQHANDLER(void) {
#elif defined(USART4_IRQHANDLER)
void USART4_IRQHANDLER(void) {
#endif
	/* Read interrupt statuses here */
	
#ifdef USART3_IRQHANDLER
	/* Check for USART3 */
	if (USART3->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART3, USART3->RDR);
	}	
#endif	
#ifdef USART4_IRQHANDLER
	/* Check for USART4 */
	if (USART4->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART4, USART4->RDR);
	}	
#endif	
#ifdef USART5_IRQHANDLER
	/* Check for USART5 */
	if (USART5->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART5, USART5->RDR);
	}	
#endif	
#ifdef USART6_IRQHANDLER
	/* Check for USART6 */
	if (USART6->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART6, USART6->RDR);
	}	
#endif	
#ifdef USART7_IRQHANDLER
	/* Check for USART7 */
	if (USART7->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART7, USART7->RDR);
	}	
#endif	
#ifdef USART8_IRQHANDLER
	/* Check for USART8 */
	if (USART8->ISR & USART_ISR_RXNE) {
		TM_USART_INT_AddToBuffer(&TM_USART8, USART8->RDR);
	}	
#endif
	
}
#endif

