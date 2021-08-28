#ifndef INC_RCC_H_
#define INC_RCC_H_

/* Peripheral register defination structure */
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED1;
	volatile uint32_t RESERVED2;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED3;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED4;
	volatile uint32_t RESERVED5;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t RESERVED6;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED7;
	volatile uint32_t RESERVED8;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED9;
	volatile uint32_t RESERVED10;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t DCKCFGR2;
}RCC_RegDef_t;

/* Clock enable macro for GPIO */
#define GPIOA_PCLK_EN()							(RCC->AHB1ENR |= (1U << 0U))
#define GPIOB_PCLK_EN()							(RCC->AHB1ENR |= (1U << 1U))
#define GPIOC_PCLK_EN()							(RCC->AHB1ENR |= (1U << 2U))
#define GPIOD_PCLK_EN()							(RCC->AHB1ENR |= (1U << 3U))
#define GPIOE_PCLK_EN()							(RCC->AHB1ENR |= (1U << 4U))
#define GPIOF_PCLK_EN()							(RCC->AHB1ENR |= (1U << 5U))
#define GPIOG_PCLK_EN()							(RCC->AHB1ENR |= (1U << 6U))
#define GPIOH_PCLK_EN()							(RCC->AHB1ENR |= (1U << 7U))

/* Clock enable macro for I2C */
#define I2C1_PCLK_EN()							(RCC->APB1ENR |= (1U << 21U))
#define I2C2_PCLK_EN()							(RCC->APB1ENR |= (1U << 22U))
#define I2C3_PCLK_EN()							(RCC->APB1ENR |= (1U << 23U))

/* Clock enable macro for SPI */
#define SPI1_PCLK_EN()							(RCC->APB2ENR |= (1U << 12U))
#define SPI2_PCLK_EN()							(RCC->APB1ENR |= (1U << 14U))
#define SPI3_PCLK_EN()							(RCC->APB1ENR |= (1U << 15U))

/* Clock enable macro for USART */
#define USART1_PCLK_EN()						(RCC->APB2ENR |= (1U << 4U))
#define USART2_PCLK_EN()						(RCC->APB1ENR |= (1U << 17U))
#define USART3_PCLK_EN()						(RCC->APB1ENR |= (1U << 18U))
#define UART4_PCLK_EN()							(RCC->APB1ENR |= (1U << 19U))
#define UART5_PCLK_EN()							(RCC->APB1ENR |= (1U << 20U))
#define USART6_PCLK_EN()						(RCC->APB2ENR |= (1U << 5U))

/* Clock enable macro for SYSCFG */
#define SYSCFG_PCLK_EN()						(RCC->APB2ENR |= (1U << 14U))

/* Clock disable macro for GPIO */
#define GPIOA_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 0U))
#define GPIOB_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 1U))
#define GPIOC_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 2U))
#define GPIOD_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 3U))
#define GPIOE_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 4U))
#define GPIOF_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 5U))
#define GPIOG_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 6U))
#define GPIOH_PCLK_DI()							(RCC->AHB1ENR &= ~(1U << 7U))
															  
/* Clock disable macro for I2C */                             
#define I2C1_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 21U))
#define I2C2_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 22U))
#define I2C3_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 23U))
															  
/* Clock disable macro for SPI */                             
#define SPI1_PCLK_DI()							(RCC->APB2ENR &= ~(1U << 12U))
#define SPI2_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 14U))
#define SPI3_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 15U))
															  
/* Clock disable macro for USART */                           
#define USART1_PCLK_DI()						(RCC->APB2ENR &= ~(1U << 4U))
#define USART2_PCLK_DI()						(RCC->APB1ENR &= ~(1U << 17U))
#define USART3_PCLK_DI()						(RCC->APB1ENR &= ~(1U << 18U))
#define UART4_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 19U))
#define UART5_PCLK_DI()							(RCC->APB1ENR &= ~(1U << 20U))
#define USART6_PCLK_DI()						(RCC->APB2ENR &= ~(1U << 5U))

/*Macros to Reset GPIO*/
#define GPIOA_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 0U)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 1U)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 2U)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 3U)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 4U)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 5U)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 7U)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()						do{ (RCC->AHB1RSTR |= (1U << 8U)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
															  
/* Clock disable macro for SYSCFG */                          
#define SYSCFG_PCLK_DI()						(RCC->APB2ENR &= ~(1U << 14U))

#endif /* INC_RCC_H_ */