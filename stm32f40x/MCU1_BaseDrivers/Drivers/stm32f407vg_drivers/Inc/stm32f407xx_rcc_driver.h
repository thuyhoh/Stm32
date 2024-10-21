/*
 * stm32f407xx_rcc_driver.h
 *
 *  Created on: Mar 29, 2019
 *      Author: admin
 */

#ifndef INC_STM32F407XX_RCC_DRIVER_H_
#define INC_STM32F407XX_RCC_DRIVER_H_

#include "stm32f407xx.h"

#define RCC_CR_HSION    0
#define RCC_CR_HSIRDY   1
#define RCC_CR_HSITRIM  3
#define RCC_CR_HSICAL   8
#define RCC_CR_HSEON    16
#define RCC_CR_HSERDY		17
#define RCC_CR_HSEBYP		18
#define RCC_CR_CSSON		19
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLI2SON	26
#define RCC_CR_PLLI2SRDY 27

typedef struct
{
	uint8_t PLLState;
	uint8_t PLLSource;
	uint8_t PLLM;
	uint16_t PLLN;
	uint8_t PLLP;
	uint8_t PLLQ;
}RCC_PLLInitTypeDef;
	

typedef struct
{
	uint8_t OSCTYPE; /*!< @ref RCC_Oscillator_Type >!*/
	uint8_t HSEState; /*!< @ref RCC_HSE_Config >!*/
	uint8_t LSEState; /*!<>!*/
	uint8_t HSIState; /*!<>!*/
	uint16_t HSICalibrationValue;  /*!<value : 0x00 - 0x1F default is 0x10>!*/  
	uint8_t LSIState; /*!<>!*/
	RCC_PLLInitTypeDef PLL;
}RCC_OscInit_t;
/*
 *	@ref RCC_Oscillator_Type
 */
#define RCC_OSCTYPE_NONE            0x00000000U
#define RCC_OSCTYPE_HSE             0x00000001U
#define RCC_OSCTYPE_HSI             0x00000002U
#define RCC_OSCTYPE_LSE             0x00000004U
#define RCC_OSCTYPE_LSI             0x00000008U
/*
 *	@ref RCC_Oscillator_Type
 */
#define RCC_HSE_OFF                      0
#define RCC_HSE_ON                       1
#define RCC_HSE_BYPASS                   ((uint32_t)((1<<RCC_CR_HSEBYP) | (1<<RCC_CR_HSEON)))
/*
 *	@ref RCC_LSE_Config
 */
#define RCC_LSE_OFF                    0x00000000U
#define RCC_LSE_ON                     RCC_BDCR_LSEON
#define RCC_LSE_BYPASS                 ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))
/*
 *	@ref RCC_LSE_Config
 */
#define RCC_HSI_OFF                    0x00000000U
#define RCC_HSI_ON                     RCC_BDCR_LSEON
#define RCC_HSI_BYPASS                 ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))

/*
 *	@ref RCC_LSE_Config
 */
#define RCC_LSI_OFF                    0x00000000U
#define RCC_LSI_ON                     RCC_BDCR_LSEON
#define RCC_LSI_BYPASS                 ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))

void RCC_OscConfig(RCC_OscInit_t *posc);

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);
#endif /* INC_STM32F407XX_RCC_DRIVER_H_ */
