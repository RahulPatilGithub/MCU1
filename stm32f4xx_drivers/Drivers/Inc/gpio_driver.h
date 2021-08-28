/*
 * gpio_driver.h
 *
 *  Created on: 08-May-2021
 *      Author: rgp03
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

#include "stm32f446xx.h"

/* GPIO API */
/* Peripheral Clock Init */
void GPIO_PeriClkCntrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/* Init and De-Init */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* Data Read & Write */
uint8_t GPIO_ReadInPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadInPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* IRQ Configuration & ISR Handling */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_GPIO_DRIVER_H_ */
