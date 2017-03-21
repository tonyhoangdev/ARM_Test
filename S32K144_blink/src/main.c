/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "S32K144.h" /* include peripheral declarations S32K144 */

/* Defines */
#define LED_ON      0U
#define LED_OFF     1U

#define EVB 1U

#if defined(EVB) && EVB
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

#else /* not EVB */

#endif

void delay(volatile uint32_t time)
{
    while (time--)
        ;
}

uint32_t arr[] = {2,4,3,4};
uint32_t b = 3;

int main()
{
    volatile int a = arr[0];
    (void)a;
    int b2 = b;
    (void)b2;

    /* Setting clock gate for LEDs */
    PCC->PCCn[LED0_PCC_CLOCK] = PCC_PCCn_CGC_MASK;

    /* Mux to gpio for LEDs */
    PORTD->PCR[LED0_GPIO_PIN] |= PORT_PCR_MUX(1);
    PORTD->PCR[LED1_GPIO_PIN] |= PORT_PCR_MUX(1);

    /* Output direction for LEDs */
    PTD->PDDR |= LED0_MASK | LED1_MASK;

    /* Initializes values */
    LED0_ON;
    LED1_OFF;

    /* Infinite loop */
    for (;;)
    {
        delay(5000000);

        LED0_TOOGLE;
        LED1_TOOGLE;
    }

    return 0;
}
