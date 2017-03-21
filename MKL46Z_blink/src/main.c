/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "MKL46Z4.h" /* include peripheral declarations S32K144 */

/* Defines */
#define LED_ON 0U
#define LED_OFF 1U
#define LED_RED_GPIO PTE
#define LED_RED_GPIO_PPORT PORTE
#define LED_RED_GPIO_PIN 29U
#define LED_GREEN_GPIO PTD
#define LED_GREEN_GPIO_PORT PORTD
#define LED_GREEN_GPIO_PIN 5U

#define COUNTER_LIMIT 1000000

int main(void)
{
    uint32_t counter = 0;
  /* Enable clock for port E and D */
  SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
  SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

  /* Set pin is GPIO */
  LED_RED_GPIO_PPORT->PCR[29] |= PORT_PCR_MUX(1);
  LED_GREEN_GPIO_PORT->PCR[5] |= PORT_PCR_MUX(1);

  /* Set gpio is output */
  LED_RED_GPIO->PDDR |= 1 << LED_RED_GPIO_PIN;
  LED_GREEN_GPIO->PDDR |= 1 << LED_GREEN_GPIO_PIN;

  /* Init value for gpio */
  LED_RED_GPIO->PDOR = LED_OFF << LED_RED_GPIO_PIN;
  LED_GREEN_GPIO->PDOR = LED_ON << LED_GREEN_GPIO_PIN;

    for (;;)
    {
        counter++;

        if (counter > COUNTER_LIMIT)
        {
            counter = 0;
                /* Toggle pin */
            LED_RED_GPIO->PTOR = 1 << LED_RED_GPIO_PIN;
            LED_GREEN_GPIO->PTOR = 1 << LED_GREEN_GPIO_PIN;
        }
    }

    /* to avoid the warning message for GHS and IAR: statement is unreachable*/
#if defined (__ghs__)
#pragma ghs nowarning 111
#endif
#if defined (__ICCARM__)
#pragma diag_suppress=Pe111
#endif
    return 0;
}
