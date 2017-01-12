/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "port.h"
#include "gpio.h"
#include "pin.h"

extern void xcptn_xmpl(void);

volatile uint32_t time = 500000;

#define LED1_PIN        PJ4
#define LED2_PIN        PA0
#define LED3_PIN        PA10
#define LED4_PIN        PA4
#define LED5_PIN        PA7
#define LED6_PIN        PC4
#define LED7_PIN        PH13
#define LED8_PIN        PH5

#define USR_LED1_PIN    LED3_PIN
#define USR_LED2_PIN    LED5_PIN
#define USR_LED3_PIN    LED7_PIN
#define USR_LED4_PIN    LED6_PIN
#define USR_LED5_PIN    LED8_PIN
#define USR_LED6_PIN    LED1_PIN
#define USR_LED7_PIN    LED2_PIN
#define USR_LED8_PIN    LED4_PIN

void delay(volatile uint32_t time)
{
    while (time--)
        ;
}

void initPin()
{
    PORT_SetMuxSel(&SIUL2, USR_LED1_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED1_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED2_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED2_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED3_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED3_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED4_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED4_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED5_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED5_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED6_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED6_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED7_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED7_PIN, GPIO_OUTPUT);

    PORT_SetMuxSel(&SIUL2, USR_LED8_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, USR_LED8_PIN, GPIO_OUTPUT);
}

int main(void)
{
    volatile int counter = 0;

    xcptn_xmpl(); /* Configure and Enable Interrupts */
    initPin(); /* Initialize LEDs */

    /* Loop forever */
    for (;;)
    {
        counter++;

        if (counter > time)
        {
            counter = 0;

            GPIO_TogglePin(&SIUL2, USR_LED1_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED2_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED3_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED4_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED5_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED6_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED7_PIN);
            GPIO_TogglePin(&SIUL2, USR_LED8_PIN);
        }
    }
}

