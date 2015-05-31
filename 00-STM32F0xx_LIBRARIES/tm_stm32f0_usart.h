/**
 * @author  Tilen Majerle
 * @email   tilen@majerle.eu
 * @website http://stm32f4-discovery.com
 * @link    
 * @version v1.0
 * @ide     Keil uVision
 * @license GNU GPL v3
 * @brief   Library template 
 *	
@verbatim
   ----------------------------------------------------------------------
    Copyright (C) Tilen Majerle, 2015
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
@endverbatim
 */
#ifndef TM_LIBRARY_H
#define TM_LIBRARY_H 100

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

/**
 * @addtogroup TM_STM32F0xx_Libraries
 * @{
 */

/**
 * @defgroup TM_LIBNAME
 * @brief    Library description here
 * @{
 *
 * \par Changelog
 *
@verbatim
 Version 1.0
  - First release
@endverbatim
 *
 * \par Dependencies
 *
@verbatim
 - STM32F0xx
 - STM32F0xx RCC
 - defines.h
@endverbatim
 */

#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_usart.h"
#include "defines.h"

/**
 * @defgroup TM_LIB_Macros
 * @brief    Library defines
 * @{
 */
  
/* #define STM32F031 */ 
/* #define STM32F091 */
/* #define STM32F030xC */  

/* All devices have USART1 */
#define USART1_IRQ          USART1_IRQn
#define USART1_IRQHANDLER   USART1_IRQHandler

/* Get all available USARTs */
#if defined(STM32F030) || defined(STM32F051) || defined(STM32F042) || defined(STM32F070x6)
	#define USART2_IRQ          USART2_IRQn
	#define USART2_IRQHANDLER   USART2_IRQHandler
#elif defined(STM32F031)
#elif defined(STM32F072) || defined(STM32F070xB)
	#define USART2_IRQ          USART2_IRQn
	#define USART2_IRQHANDLER   USART2_IRQHandler
	#define USART3_IRQ          USART3_4_IRQn
	#define USART3_IRQHANDLER   USART3_4_IRQHandler
	#define USART4_IRQ          USART3_4_IRQn
	#define USART4_IRQHANDLER   USART3_4_IRQHandler
#elif defined(STM32F091)
	#define USART2_IRQ          USART2_IRQn
	#define USART2_IRQHANDLER   USART2_IRQHandler
	#define USART3_IRQ          USART3_8_IRQn
	#define USART3_IRQHANDLER   USART3_8_IRQHandler
	#define USART4_IRQ          USART3_8_IRQn
	#define USART4_IRQHANDLER   USART3_8_IRQHandler
	#define USART5_IRQ          USART3_8_IRQn
	#define USART5_IRQHANDLER   USART3_8_IRQHandler
	#define USART6_IRQ          USART3_8_IRQn
	#define USART6_IRQHANDLER   USART3_8_IRQHandler
	#define USART7_IRQ          USART3_8_IRQn
	#define USART7_IRQHANDLER   USART3_8_IRQHandler
	#define USART8_IRQ          USART3_8_IRQn
	#define USART8_IRQHANDLER   USART3_8_IRQHandler
#elif defined(STM32F030xC)
	#define USART2_IRQ          USART2_IRQn
	#define USART2_IRQHANDLER   USART2_IRQHandler
	#define USART3_IRQ          USART3_6_IRQn
	#define USART3_IRQHANDLER   USART3_6_IRQHandler
	#define USART4_IRQ          USART3_6_IRQn
	#define USART4_IRQHANDLER   USART3_6_IRQHandler
	#define USART5_IRQ          USART3_6_IRQn
	#define USART5_IRQHANDLER   USART3_6_IRQHandler
	#define USART6_IRQ          USART3_6_IRQn
	#define USART6_IRQHANDLER   USART3_6_IRQHandler
#else
	#error "Device not recognized!"
#endif

/* Default buffer sizes */
#ifndef TM_USART_BUFFER_SIZE
#define TM_USART_BUFFER_SIZE    32
#endif

/* Buffer size for each USART */
#ifndef TM_USART1_BUFFER_SIZE
#define TM_USART1_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART2_BUFFER_SIZE
#define TM_USART2_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART3_BUFFER_SIZE
#define TM_USART3_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART4_BUFFER_SIZE
#define TM_USART4_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART5_BUFFER_SIZE
#define TM_USART5_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART6_BUFFER_SIZE
#define TM_USART6_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART7_BUFFER_SIZE
#define TM_USART7_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif
#ifndef TM_USART8_BUFFER_SIZE
#define TM_USART8_BUFFER_SIZE   TM_USART_BUFFER_SIZE
#endif

/**
 * @brief  Wait till USART finishes transmission
 */
#define USART_WAIT(USARTx)      while (!((USARTx)->ISR & USART_ISR_TXE))
	
/**
 * @brief  Default string delimiter for USART
 */
#define USART_STRING_DELIMITER  '\n'

/**
 * @}
 */
 
/**
 * @defgroup TM_LIB_Typedefs
 * @brief    Library Typedefs
 * @{
 */

typedef enum {
	TM_USART_PinsPack_1,
	TM_USART_PinsPack_2,
	TM_USART_PinsPack_Custom
} TM_USART_PinsPack_t;

/**
 * @}
 */

/**
 * @defgroup TM_LIB_Functions
 * @brief    Library Functions
 * @{
 */

void TM_USART_Init(USART_TypeDef* USARTx, TM_USART_PinsPack_t PinsPack, uint32_t baudrate);
void TM_USART_Putc(USART_TypeDef* USARTx, char c);

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
