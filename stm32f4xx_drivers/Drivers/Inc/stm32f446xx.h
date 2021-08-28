/*
 * stm32f446xx.h
 *
 *  Created on: May 2, 2021
 *      Author: rgp03
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/***** Processor Specific Details *****/
/* ARM Cortex Mx Processor NVIC ISERx Register Addresses */
#define NVIC_ISER0                             ((volatile uint32_t *)0xE000E100)
#define NVIC_ISER1                             ((volatile uint32_t *)0xE000E104)
#define NVIC_ISER2                             ((volatile uint32_t *)0xE000E108)
#define NVIC_ISER3                             ((volatile uint32_t *)0xE000E10C)
#define NVIC_ISER4                             ((volatile uint32_t *)0xE000E110)
#define NVIC_ISER5                             ((volatile uint32_t *)0xE000E114)
#define NVIC_ISER6                             ((volatile uint32_t *)0xE000E118)
#define NVIC_ISER7                             ((volatile uint32_t *)0xE000E11C)

/* ARM Cortex Mx Processor NVIC ICERx Register Addresses */
#define NVIC_ICER0                             ((volatile uint32_t *)0xE000E180)
#define NVIC_ICER1                             ((volatile uint32_t *)0xE000E184)
#define NVIC_ICER2                             ((volatile uint32_t *)0xE000E188)
#define NVIC_ICER3                             ((volatile uint32_t *)0xE000E18C)
#define NVIC_ICER4                             ((volatile uint32_t *)0xE000E190)
#define NVIC_ICER5                             ((volatile uint32_t *)0xE000E194)
#define NVIC_ICER6                             ((volatile uint32_t *)0xE000E198)
#define NVIC_ICER7                             ((volatile uint32_t *)0xE000E19C)

/* Base Addresses of Flash and SRAM memories */
#define FLASH_BASEADDR							0x08000000U		/* 512KB */
#define SRAM1_BASEADDR							0x20000000U		/* 112KB */
#define SRAM2_BASEADDR							0x2001C000U		/* 16KB */
#define ROM										0x1FFF0000U
#define SRAM 									SRAM1_BASEADDR

/* AHBx and APBx Bus Peripheral base addresses*/

#define PERIPH_BASE								0x40000000U
#define APB1PERIPH_BASE							0x40000000U
#define APB2PERIPH_BASE							0x40010000U
#define AHB1PERIPH_BASE							0x40020000U
#define AHB2PERIPH_BASE							0x50000000U
#define AHB3PERIPH_BASE							0xA0000000U

/* AHB1 Peripheral Addresses*/
#define GPIOA_BASEADDR							(AHB1PERIPH_BASE + 0x0000U)	/* 0x40020000U */
#define GPIOB_BASEADDR							(AHB1PERIPH_BASE + 0x0400U)	/* 0x40020400U */
#define GPIOC_BASEADDR							(AHB1PERIPH_BASE + 0x0800U)	/* 0x40020800U */
#define GPIOD_BASEADDR							(AHB1PERIPH_BASE + 0x0C00U)	/* 0x40020C00U */
#define GPIOE_BASEADDR							(AHB1PERIPH_BASE + 0x1000U)	/* 0x40021000U */
#define GPIOF_BASEADDR							(AHB1PERIPH_BASE + 0x1400U)	/* 0x40021400U */
#define GPIOG_BASEADDR							(AHB1PERIPH_BASE + 0x1800U)	/* 0x40021800U */
#define GPIOH_BASEADDR							(AHB1PERIPH_BASE + 0x1C00U)	/* 0x40021C00U */

#define RCC_BASEADDR							(AHB1PERIPH_BASE + 0x3800U)	/* 0x40023800U */

/* APB1 Peripheral Addresses */
#define I2C1_BASEADDR							(APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR							(APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASEADDR							(APB1PERIPH_BASE + 0x5C00U)

#define SPI2_BASEADDR							(APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASEADDR							(APB1PERIPH_BASE + 0x3C00U)

#define USART2_BASEADDR							(APB1PERIPH_BASE + 0x4400U)
#define USART3_BASEADDR							(APB1PERIPH_BASE + 0x4800U)
#define UART4_BASEADDR							(APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASEADDR							(APB1PERIPH_BASE + 0x5000U)

/* APB2 Peripheral Addresses */
#define SPI1_BASEADDR							(APB2PERIPH_BASE + 0x3000)

#define USART1_BASEADDR							(APB2PERIPH_BASE + 0x1000U)
#define USART6_BASEADDR							(APB2PERIPH_BASE + 0x1400U)

#define EXTI_BASEADDR							(APB2PERIPH_BASE + 0x3C00U)

#define SYSCFG_BASEADDR							(APB2PERIPH_BASE + 0x3800U)

/* Peripheral Definition */
#define GPIOA									((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB									((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC									((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD									((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE									((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF									((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG									((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH									((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC										((RCC_RegDef_t *)RCC_BASEADDR)

#define EXTI									((EXTI_RegDef_t *)EXTI_BASEADDR)

#define SYSCFG                                  ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

/* IRQ number of all interrupts */
#define IRQn_WWDG                               0U
#define IRQn_PVD                                1U
#define IRQn_TAMP_STAMP                         2U
#define IRQn_RTC_WKUP                           3U
#define IRQn_FLASH                              4U
#define IRQn_RCC                                5U
#define IRQn_EXTI0                              6U
#define IRQn_EXTI1                              7U
#define IRQn_EXTI2                              8U
#define IRQn_EXTI3                              9U
#define IRQn_EXTI4                              10U
#define IRQn_DMA1_Stream0                       11U
#define IRQn_DMA1_Stream1                       12U
#define IRQn_DMA1_Stream2                       13U
#define IRQn_DMA1_Stream3                       14U
#define IRQn_DMA1_Stream4                       15U
#define IRQn_DMA1_Stream5                       16U
#define IRQn_DMA1_Stream6                       17U
#define IRQn_ADC                                18U
#define IRQn_CAN1_TX                            19U
#define IRQn_CAN1_RX0                           20U
#define IRQn_CAN1_RX1                           21U
#define IRQn_CAN1_SCE                           22U
#define IRQn_EXTI9_5                            23U
#define IRQn_TIM1_BRK_TIM9                      24U
#define IRQn_TIM1_UP_TIM10                      25U
#define IRQn_TIM1_TRG_COM_TIM11                 26U
#define IRQn_TIM1_CC                            27U
#define IRQn_TIM2                               28U
#define IRQn_TIM3                               29U
#define IRQn_TIM4                               30U
#define IRQn_I2C1_EV                            31U
#define IRQn_I2C1_ER                            32U
#define IRQn_I2C2_EV                            33U
#define IRQn_I2C2_ER                            34U
#define IRQn_SPI1                               35U
#define IRQn_SPI2                               36U
#define IRQn_USART1                             37U
#define IRQn_USART2                             38U
#define IRQn_USART3                             39U
#define IRQn_EXTI15_10                          40U
#define IRQn_RTC_Alarm                          41U
#define IRQn_OTG_FS_WKUP                        42U
#define IRQn_TIM8_BRK_TIM12                     43U
#define IRQn_TIM8_UP_TIM13                      44U
#define IRQn_TIM8_TRG_COM_TIM14                 45U
#define IRQn_TIM8_CC                            46U
#define IRQn_DMA1_Stream7                       47U
#define IRQn_FMC                                48U
#define IRQn_SDIO                               49U
#define IRQn_TIM5                               50U
#define IRQn_SPI3                               51U
#define IRQn_UART4                              52U
#define IRQn_UART5                              53U
#define IRQn_TIM6_DAC                           54U
#define IRQn_TIM7                               55U
#define IRQn_DMA2_Stream0                       56U
#define IRQn_DMA2_Stream1                       57U
#define IRQn_DMA2_Stream2                       58U
#define IRQn_DMA2_Stream3                       59U
#define IRQn_DMA2_Stream4                       60U
#define IRQn_CAN2_TX                            63U
#define IRQn_CAN2_RX0                           64U
#define IRQn_CAN2_RX1                           65U
#define IRQn_CAN2_SCE                           66U
#define IRQn_OTG_FS                             67U
#define IRQn_DMA2_Stream5                       68U
#define IRQn_DMA2_Stream6                       69U
#define IRQn_DMA2_Stream7                       70U
#define IRQn_USART6                             71U
#define IRQn_I2C3_EV                            72U
#define IRQn_I2C3_ER                            73U
#define IRQn_OTG_HS_EP1_OUT                     74U
#define IRQn_OTG_HS_EP1_IN                      75U
#define IRQn_OTG_HS_WKUP                        76U
#define IRQn_OTG_HS                             77U
#define IRQn_DCMI                               78U
#define IRQn_FPU                                81U
#define IRQn_SPI4                               84U
#define IRQn_SAI1                               87U
#define IRQn_SAI2                               91U
#define IRQn_QuadSPI                            92U
#define IRQn_HDMI_CEC                           93U
#define IRQn_SPDIF_Rx                           94U
#define IRQn_FMPI2C1                            95U
#define IRQn_FMPI2C1_ERROR                      96U

/* Bare Metal Includes */
#include "gpio.h"
#include "rcc.h"
#include "exti.h"
#include "syscfg.h"

/* Generic Macros*/
#define ENABLE									1U
#define DISABLE									0U
#define SET										ENABLE
#define RESET									DISABLE
#define GPIO_PIN_SET							SET
#define GPIO_PIN_RESET							RESET

#endif /* INC_STM32F446XX_H_ */
