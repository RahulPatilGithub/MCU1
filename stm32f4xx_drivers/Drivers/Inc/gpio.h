#ifndef INC_GPIO_H_
#define INC_GPIO_H_

/* GPIO PIN Number */
#define GPIO_PIN_0				0U
#define GPIO_PIN_1				1U
#define GPIO_PIN_2				2U
#define GPIO_PIN_3				3U
#define GPIO_PIN_4				4U
#define GPIO_PIN_5				5U
#define GPIO_PIN_6				6U
#define GPIO_PIN_7				7U
#define GPIO_PIN_8				8U
#define GPIO_PIN_9				9U
#define GPIO_PIN_10				10U
#define GPIO_PIN_11				11U
#define GPIO_PIN_12				12U
#define GPIO_PIN_13				13U
#define GPIO_PIN_14				14U
#define GPIO_PIN_15				15U

/* GPIO MODE */
#define GPIO_MODE_IN			0U
#define GPIO_MODE_OUT			1U
#define GPIO_MODE_ALTFN			2U
#define GPIO_MODE_ANALOG		3U
#define GPIO_MODE_IT_FT			4U
#define GPIO_MODE_IT_RT			5U
#define GPIO_MODE_IT_RFT		6U

/* GPIO OUTPUT Type */
#define GPIO_OT_PP				0U
#define GPIO_OT_OD				1U

/* GPIO Output Speed Mode */
#define GPIO_SPEED_LOW			0U
#define GPIO_SPEED_MEDIUM		1U
#define GPIO_SPEED_FAST			2U
#define GPIO_SPEED_HIGH			3U

/* GPIO Pin PULL UP & PULL DOWN Configuration */
#define GPIO_NO_PUPD			0U
#define GPIO_PIN_PU				1U
#define GPIO_PIN_PD				2U

/* Peripheral register defination structure */
typedef struct
{
	volatile uint32_t MODER;								/* GPIO port mode register */
	volatile uint32_t OTYPER;								/* GPIO port output type register */
	volatile uint32_t OSPEEDER;								/* GPIO port output speed register */
	volatile uint32_t PUPDR;								/* GPIO port pull-up/pull-down register */
	volatile uint32_t IDR;									/* GPIO port input data register */
	volatile uint32_t ODR;									/* GPIO port output data register */
	volatile uint32_t BSRR;									/* GPIO port bit set/reset register */
	volatile uint32_t LCKR;									/* GPIO port configuration lock register */
	volatile uint32_t AFR[2U];								/* GPIO alternate function high register */
}GPIO_RegDef_t;

/* Configuration structure for GPIO */
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/* Handle structure for GPIO Pin */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

#endif /* INC_GPIO_H_ */