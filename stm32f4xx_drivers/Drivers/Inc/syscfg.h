#ifndef INC_SYSCFG_H_
#define INC_SYSCFG_H_

#define EXTICR_PORTA_PIN_SEL                  0U    /* 0000: PA[x] pin */
#define EXTICR_PORTB_PIN_SEL                  1U    /* 0001: PB[x] pin */
#define EXTICR_PORTC_PIN_SEL                  2U    /* 0010: PC[x] pin */
#define EXTICR_PORTD_PIN_SEL                  3U    /* 0011: PD[x] pin */
#define EXTICR_PORTE_PIN_SEL                  4U    /* 0100: PE[x] pin */
#define EXTICR_PORTF_PIN_SEL                  5U    /* 0101: PF[x] pin */
#define EXTICR_PORTG_PIN_SEL                  6U    /* 0110: PG[x] pin */
#define EXTICR_PORTH_PIN_SEL                  7U    /* 0111: PH[x] pin */

#define GPIO_BASEADDR_TO_CODE(x)            ( (x == GPIOA) ? EXTICR_PORTA_PIN_SEL :\
                                              (x == GPIOB) ? EXTICR_PORTB_PIN_SEL :\
                                              (x == GPIOC) ? EXTICR_PORTC_PIN_SEL :\
                                              (x == GPIOD) ? EXTICR_PORTD_PIN_SEL :\
                                              (x == GPIOE) ? EXTICR_PORTE_PIN_SEL :\
                                              (x == GPIOF) ? EXTICR_PORTF_PIN_SEL :\
                                              (x == GPIOG) ? EXTICR_PORTG_PIN_SEL : EXTICR_PORTH_PIN_SEL )

/* Peripheral register defination structure */
typedef struct
{
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];
    volatile uint32_t reserved1[2];
    volatile uint32_t CMPCR;
    volatile uint32_t reserved2[2];
    volatile uint32_t CFGR;
}SYSCFG_RegDef_t;

#endif