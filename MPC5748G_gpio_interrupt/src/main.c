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

#define SW1_PA3_PIN     3U
#define SW1_PA3_EIRQ    0U
#define SW1_PA3_SSS     144U

#define SW2_PE12_PIN    76U
#define SW2_PE12_EIRQ   11U
#define SW2_PE12_SSS    155U

void delay(volatile uint32_t time)
{
    while (time--)
        ;
}

void writeLeds(uint8_t data)
{
    GPIO_WritePin(&SIUL2, USR_LED1_PIN, !(data & 0x01U));
    GPIO_WritePin(&SIUL2, USR_LED2_PIN, !(data & 0x02U));
    GPIO_WritePin(&SIUL2, USR_LED3_PIN, !(data & 0x04U));
    GPIO_WritePin(&SIUL2, USR_LED4_PIN, !(data & 0x08U));
    GPIO_WritePin(&SIUL2, USR_LED5_PIN, !(data & 0x10U));
    GPIO_WritePin(&SIUL2, USR_LED6_PIN, !(data & 0x20U));
    GPIO_WritePin(&SIUL2, USR_LED7_PIN, !(data & 0x40U));
    GPIO_WritePin(&SIUL2, USR_LED8_PIN, !(data & 0x80U));
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

    /* Input */
    PORT_SetMuxSel(&SIUL2, SW2_PE12_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, SW2_PE12_PIN, GPIO_INPUT);
    PORT_SetPullSel(&SIUL2, SW2_PE12_PIN, PORT_PULL_DOWN);
    PORT_SetIntSel(&SIUL2, PORT_INT_RISING_EDGE, true, SW2_PE12_EIRQ,
    SW2_PE12_SSS);

    PORT_SetMuxSel(&SIUL2, SW1_PA3_PIN, PORT_MUX_AS_GPIO);
    GPIO_SetPinDirection(&SIUL2, SW1_PA3_PIN, GPIO_INPUT);
    PORT_SetPullSel(&SIUL2, SW1_PA3_PIN, PORT_PULL_DOWN);
    PORT_SetIntSel(&SIUL2, PORT_INT_FALLING_EDGE, true, SW1_PA3_EIRQ,
    SW1_PA3_SSS);
}

void SW1_ISR(void)
{
    static uint8_t flag = 0;

    if (PORT_GetIntFlag(&SIUL2, SW1_PA3_EIRQ))
    {
        PORT_ClearIntFlag(&SIUL2, SW1_PA3_EIRQ);

        flag++;
        switch (flag)
        {
        case 1:
            time = 100000;
            break;
        case 2:
            time = 400000;
            break;
        case 3:
            time = 600000;
            break;
        default:
            flag = 0;
            break;
        }
    }
}

void SW2_ISR(void)
{
    static uint8_t flag2 = 0;

    if (PORT_GetIntFlag(&SIUL2, SW2_PE12_EIRQ))
    {
        PORT_ClearIntFlag(&SIUL2, SW2_PE12_EIRQ);

        flag2++;
        switch (flag2)
        {
        case 1:
            time = 100000;
            break;
        case 2:
            time = 500000;
            break;
        default:
            flag2 = 0;
            break;
        }
    }
}

int main(void)
{
    uint8_t i;

    xcptn_xmpl(); /* Configure and Enable Interrupts */
    initPin();

    /* Set priority for Core 0 */
    INTC.PSR[243].R = 0x8001;  //Set priority for SW1 interrupt
    INTC.PSR[244].R = 0x8001;  //Set priority for SW2 interrupt

    /* Loop forever */
    for (;;)
    {
        for (i = 0; i < 256; i++)
        {
            delay(time);
            writeLeds(i);
        }
    }
}
