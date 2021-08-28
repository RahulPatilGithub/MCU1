/*
 * gpio.c
 *
 *  Created on: 08-May-2021
 *      Author: rgp03
 */
#include "gpio_driver.h"

/* Peripheral Clock Init */

/************************************************************
 * @Function Name : GPIO_PeriClkCntrl
 * @Description : Enable or disable the Clock for peripheral.
 * @Param[in] : *pGPIOx
 * @Param[in] : EnorDi
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_PeriClkCntrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(ENABLE == EnorDi)
	{
		if(GPIOA == pGPIOx)
		{
			GPIOA_PCLK_EN();
		}
		else if(GPIOB == pGPIOx)
		{
			GPIOB_PCLK_EN();
		}
		else if(GPIOC == pGPIOx)
		{
			GPIOC_PCLK_EN();
		}
		else if(GPIOD == pGPIOx)
		{
			GPIOD_PCLK_EN();
		}
		else if(GPIOE == pGPIOx)
		{
			GPIOE_PCLK_EN();
		}
		else if(GPIOF == pGPIOx)
		{
			GPIOF_PCLK_EN();
		}
		else if(GPIOG == pGPIOx)
		{
			GPIOG_PCLK_EN();
		}
		else if(GPIOH == pGPIOx)
		{
			GPIOH_PCLK_EN();
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		if(GPIOA == pGPIOx)
		{
			GPIOA_PCLK_DI();
		}
		else if(GPIOB == pGPIOx)
		{
			GPIOB_PCLK_DI();
		}
		else if(GPIOC == pGPIOx)
		{
			GPIOC_PCLK_DI();
		}
		else if(GPIOD == pGPIOx)
		{
			GPIOD_PCLK_DI();
		}
		else if(GPIOE == pGPIOx)
		{
			GPIOE_PCLK_DI();
		}
		else if(GPIOF == pGPIOx)
		{
			GPIOF_PCLK_DI();
		}
		else if(GPIOG == pGPIOx)
		{
			GPIOG_PCLK_DI();
		}
		else if(GPIOH == pGPIOx)
		{
			GPIOH_PCLK_DI();
		}
		else
		{
			/* Do Nothing */
		}
	}
}

/* Init and De-Init */
/************************************************************
 * @Function Name : GPIO_Init
 * @Description : Initialize the GPIO.
 * @Param[in] : *pGPIOHandle
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	/* Configure GPIO Mode */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_FT)
		{
			/* Configure the FTSR */
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RT)
		{
			/* Configure the RTSR */
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else
		{
			/* COnfigure both FTSR and STSR */
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

		/* Config the GPIO port in selection in SYSCFG_EXTICR */
		uint8_t Element = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t Section = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t PortCode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[Element] = PortCode << (Section * 4);

		/* Enable the EXTI Interrupt delivery using IMR */
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}

	temp = 0;

	/* Configure Speed */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDER |= temp;

	temp = 0;

	/*Configure PUPD*/
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR  |= temp;

	temp = 0;

	/* Configure Output type */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp = 0;

	/* Configure Alt Functionality */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}
}

/************************************************************
 * @Function Name : GPIO_DeInit
 * @Description : De-initialize the GPIO.
 * @Param[in] : *pGPIOx
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(GPIOA == pGPIOx)
	{
		GPIOA_REG_RESET();
	}
	else if(GPIOB == pGPIOx)
	{
		GPIOB_REG_RESET();
	}
	else if(GPIOC == pGPIOx)
	{
		GPIOC_REG_RESET();
	}
	else if(GPIOD == pGPIOx)
	{
		GPIOD_REG_RESET();
	}
	else if(GPIOE == pGPIOx)
	{
		GPIOE_REG_RESET();
	}
	else if(GPIOF == pGPIOx)
	{
		GPIOF_REG_RESET();
	}
	else if(GPIOG == pGPIOx)
	{
		GPIOG_REG_RESET();
	}
	else if(GPIOH == pGPIOx)
	{
		GPIOH_REG_RESET();
	}
	else
	{
		/* Do Nothing */
	}
}

/* Data Read & Write */
/************************************************************
 * @Function Name : GPIO_ReadInPin
 * @Description : Read data from Pin.
 * @Param[in] : *pGPIOx
 * @Param[in] : PinNumber
 * @return : Value
 *
 * @Note :
 *
 ************************************************************/
uint8_t GPIO_ReadInPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t Value;
	
	Value = (uint8_t)(0x00000001 & (pGPIOx->IDR >> PinNumber));
	
	return Value;
}

/************************************************************
 * @Function Name : GPIO_ReadInPort
 * @Description : Read data from Port.
 * @Param[in] : *pGPIOx
 * @return : Value
 *
 * @Note :
 *
 ************************************************************/
uint16_t GPIO_ReadInPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t Value;
	
	Value = (uint16_t)pGPIOx->IDR;
	
	return Value;
}

/************************************************************
 * @Function Name : GPIO_WriteOutPin
 * @Description : Write data on Pin.
 * @Param[in] : *pGPIOx
 * @Param[in] : PinNumber
 * @Param[in] : Value
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_WriteOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(GPIO_PIN_SET == Value)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/************************************************************
 * @Function Name : GPIO_WriteOutPort
 * @Description : Write data on PORT.
 * @Param[in] : *pGPIOx
 * @Param[in] : Value
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_WriteOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR &= 0x00;
	pGPIOx->ODR |= Value;
}

/************************************************************
 * @Function Name : GPIO_PeriClkCntrl
 * @Description : Toggle data on pin.
 * @Param[in] : *pGPIOx
 * @Param[in] : PinNumber
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/* IRQ Configuration & ISR Handling */
/************************************************************
 * @Function Name : GPIO_IRQInterruptConfig
 * @Description : Configure interrupt routine control.
 * @Param[in] : IRQNumber
 * @Param[in] : IRQPriority
 * @Param[in] : EnorDi
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ISER0 |= (1 << IRQNumber);
		}
		else if((IRQNumber > 31) && (IRQNumber < 64))
		{
			*NVIC_ISER1 |= (1 << IRQNumber % 32);
		}
		else if((IRQNumber >= 64) && (IRQNumber < 97))
		{
			*NVIC_ISER3 |= (1 << IRQNumber % 64);
		}
	}
	else
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ICER0 |= (1 << IRQNumber);
		}
		else if((IRQNumber > 31) && (IRQNumber < 64))
		{
			*NVIC_ICER1 |= (1 << IRQNumber % 32);
		}
		else if((IRQNumber >= 64) && (IRQNumber < 97))
		{
			*NVIC_ICER3 |= (1 << IRQNumber % 64);
		}
	}
}

/************************************************************
 * @Function Name : GPIO_IRQPriorityConfig
 * @Description : Set IRQ Priority.
 * @Param[in] : Priority
 * @Param[in] : IRQNumber
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
	uint8_t IPRx = IRQNumber / 4;
	uint8_t Section = IRQNumber % 4;
	*(NVIC_IPR + (IPRx * 4)) |= (IRQPriority << (8 * Section));
}

/************************************************************
 * @Function Name : GPIO_IRQHandling
 * @Description : Handle IRQ on Pin.
 * @Param[in] : PinNumber
 * @return : none
 *
 * @Note :
 *
 ************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{

}
