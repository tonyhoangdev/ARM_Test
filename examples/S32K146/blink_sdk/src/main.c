/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "S32K146.h" /* include peripheral declarations S32K144 */

/* Defines */
#define LED_ON      0U
#define LED_OFF     1U

#define EVB 1U

#if EVB
#define LED0_PCC_CLOCK  PCC_PORTD_INDEX
#define LED0_GPIO       PTD
#define LED0_PORT       PORTD
#define LED0_GPIO_PIN   15U
#define LED0_MASK       1U << LED0_GPIO_PIN
#define LED0_OFF        LED0_GPIO->PSOR |= LED0_MASK
#define LED0_ON         LED0_GPIO->PCOR |= LED0_MASK
#define LED0_TOOGLE     LED0_GPIO->PTOR |= LED0_MASK

#define LED1_GPIO       PTD
#define LED1_PORT       PORTD
#define LED1_GPIO_PIN   16U
#define LED1_MASK       1U << LED1_GPIO_PIN
#define LED1_OFF        LED1_GPIO->PSOR |= LED1_MASK
#define LED1_ON         LED1_GPIO->PCOR |= LED1_MASK
#define LED1_TOOGLE     LED1_GPIO->PTOR |= LED1_MASK

#define LED0_TOUCH_PCC_CLOCK    PCC_PORTA_INDEX
#define LED0_TOUCH_GPIO         PTA
#define LED0_TOUCH_PORT         PORTA
#define LED0_TOUCH_GPIO_PIN     16U
#define LED0_TOUCH_MASK         1U << LED0_TOUCH_GPIO_PIN
#define LED0_TOUCH_ON           LED0_TOUCH_GPIO->PSOR |= LED0_TOUCH_MASK
#define LED0_TOUCH_OFF          LED0_TOUCH_GPIO->PCOR |= LED0_TOUCH_MASK
#define LED0_TOUCH_TOOGLE       LED0_TOUCH_GPIO->PTOR |= LED0_TOUCH_MASK

#else /* not EVB */

#endif

void delay(volatile uint32_t time)
{
    while (time--);
}

int main()
{
    /* Setting clock gate for LEDs */
    PCC->PCCn[LED0_PCC_CLOCK] |= PCC_PCCn_CGC_MASK;
    PCC->PCCn[LED0_TOUCH_PCC_CLOCK] |= PCC_PCCn_CGC_MASK;

    /* Mux to gpio for LEDs */
    LED0_PORT->PCR[LED0_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED1_PORT->PCR[LED1_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED0_TOUCH_PORT->PCR[LED0_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);

    /* Output direction for LEDs */
    LED0_GPIO->PDDR |= LED0_MASK;
    LED1_GPIO->PDDR |= LED1_MASK;
    LED0_TOUCH_GPIO->PDDR |= LED0_TOUCH_MASK;

    /* Initializes values */
    LED0_ON;
    LED1_OFF;

    /* Infinite loop */
    for (;;)
    {
        delay(2000000);

        LED0_TOOGLE;
        LED1_TOOGLE;
        LED0_TOUCH_TOOGLE;
    }

    return 0;
}
