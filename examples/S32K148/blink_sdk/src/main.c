/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "S32K148.h" /* include peripheral declarations S32K144 */

#define UT_FAILED_RESULT (0xFFFF)

uint32_t g_ut_result = UT_FAILED_RESULT;

void end_of_test_hook()
{
    /* This is actually a dummy code as the GDB will break at start of this function
    *  and will dump the value of g_ut_result global variable.
    */
    if (g_ut_result == UT_FAILED_RESULT)
        g_ut_result = 1;
}

/* Defines */
#define LED_ON      0U
#define LED_OFF     1U

#define EVB 0U

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

#define LED0_PCC_CLOCK  PCC_PORTB_INDEX
#define LED0_GPIO       PTB
#define LED0_PORT       PORTB
#define LED0_GPIO_PIN   22U
#define LED0_MASK       1U << LED0_GPIO_PIN
#define LED0_OFF        LED0_GPIO->PSOR |= LED0_MASK
#define LED0_ON         LED0_GPIO->PCOR |= LED0_MASK
#define LED0_TOOGLE     LED0_GPIO->PTOR |= LED0_MASK

#define LED1_GPIO       PTB
#define LED1_PORT       PORTB
#define LED1_GPIO_PIN   23U
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

#define LED1_TOUCH_PCC_CLOCK    PCC_PORTE_INDEX
#define LED1_TOUCH_GPIO         PTE
#define LED1_TOUCH_PORT         PORTE
#define LED1_TOUCH_GPIO_PIN     20U
#define LED1_TOUCH_MASK         1U << LED1_TOUCH_GPIO_PIN
#define LED1_TOUCH_ON           LED1_TOUCH_GPIO->PSOR |= LED1_TOUCH_MASK
#define LED1_TOUCH_OFF          LED1_TOUCH_GPIO->PCOR |= LED1_TOUCH_MASK
#define LED1_TOUCH_TOOGLE       LED1_TOUCH_GPIO->PTOR |= LED1_TOUCH_MASK

#define LED2_TOUCH_PCC_CLOCK    PCC_PORTB_INDEX
#define LED2_TOUCH_GPIO         PTB
#define LED2_TOUCH_PORT         PORTB
#define LED2_TOUCH_GPIO_PIN     17U
#define LED2_TOUCH_MASK         1U << LED2_TOUCH_GPIO_PIN
#define LED2_TOUCH_ON           LED2_TOUCH_GPIO->PSOR |= LED2_TOUCH_MASK
#define LED2_TOUCH_OFF          LED2_TOUCH_GPIO->PCOR |= LED2_TOUCH_MASK
#define LED2_TOUCH_TOOGLE       LED2_TOUCH_GPIO->PTOR |= LED2_TOUCH_MASK

#define LED3_TOUCH_PCC_CLOCK    PCC_PORTC_INDEX
#define LED3_TOUCH_GPIO         PTC
#define LED3_TOUCH_PORT         PORTC
#define LED3_TOUCH_GPIO_PIN     29U
#define LED3_TOUCH_MASK         1U << LED3_TOUCH_GPIO_PIN
#define LED3_TOUCH_ON           LED3_TOUCH_GPIO->PSOR |= LED3_TOUCH_MASK
#define LED3_TOUCH_OFF          LED3_TOUCH_GPIO->PCOR |= LED3_TOUCH_MASK
#define LED3_TOUCH_TOOGLE       LED3_TOUCH_GPIO->PTOR |= LED3_TOUCH_MASK

#define LED4_TOUCH_PCC_CLOCK    PCC_PORTC_INDEX
#define LED4_TOUCH_GPIO         PTC
#define LED4_TOUCH_PORT         PORTC
#define LED4_TOUCH_GPIO_PIN     28U
#define LED4_TOUCH_MASK         1U << LED4_TOUCH_GPIO_PIN
#define LED4_TOUCH_ON           LED4_TOUCH_GPIO->PSOR |= LED4_TOUCH_MASK
#define LED4_TOUCH_OFF          LED4_TOUCH_GPIO->PCOR |= LED4_TOUCH_MASK
#define LED4_TOUCH_TOOGLE       LED4_TOUCH_GPIO->PTOR |= LED4_TOUCH_MASK

#endif

static inline void WritePin(GPIO_Type * base,
                            uint32_t pin,
                            uint8_t value)
{
    if (value != 0)
    {
        base->PDOR |= (1UL << pin);
    }
    else
    {
        base->PDOR &= ~(1UL << pin);
    }
}

static inline void TogglePin(GPIO_Type * base,
                             uint32_t pinMask)
{
    base->PTOR = pinMask;
}

void delay(volatile uint32_t time)
{
    while (time--)
        ;
}

void led_shift(uint8_t data)
{
    WritePin(LED0_TOUCH_GPIO, LED0_TOUCH_GPIO_PIN, data & 0x01U);
    WritePin(LED1_TOUCH_GPIO, LED1_TOUCH_GPIO_PIN, data & 0x02U);
    WritePin(LED2_TOUCH_GPIO, LED2_TOUCH_GPIO_PIN, data & 0x04U);
    WritePin(LED3_TOUCH_GPIO, LED3_TOUCH_GPIO_PIN, data & 0x08U);
    WritePin(LED4_TOUCH_GPIO, LED4_TOUCH_GPIO_PIN, data & 0x10U);
}

void BlinkALL2(uint32_t time)
{
    LED0_TOUCH_TOOGLE;
    LED1_TOUCH_TOOGLE;
    LED2_TOUCH_TOOGLE;
    LED3_TOUCH_TOOGLE;
    LED4_TOUCH_TOOGLE;
    delay(time);
    LED0_TOUCH_TOOGLE;
    LED1_TOUCH_TOOGLE;
    LED2_TOUCH_TOOGLE;
    LED3_TOUCH_TOOGLE;
    LED4_TOUCH_TOOGLE;
    delay(time);
    LED0_TOUCH_TOOGLE;
    LED1_TOUCH_TOOGLE;
    LED2_TOUCH_TOOGLE;
    LED3_TOUCH_TOOGLE;
    LED4_TOUCH_TOOGLE;
    delay(time);
    LED0_TOUCH_TOOGLE;
    LED1_TOUCH_TOOGLE;
    LED2_TOUCH_TOOGLE;
    LED3_TOUCH_TOOGLE;
    LED4_TOUCH_TOOGLE;
    delay(time);
}

void BlinkLeft(uint32_t time)
{
    uint8_t i;

    for (i = 0U; i < 5U; i++)
    {
        led_shift(1U << i);
        delay(time);
    }
}

void BlinkRight(uint32_t time)
{
    uint8_t i;

    for (i = 0U; i < 5U; i++)
    {
        led_shift(0x10U >> i);
        delay(time);
    }
}

void BlinkRaiseOut(uint32_t time)
{
    uint8_t i;
    uint8_t data;

    for (i = 3U; i > 0U; i--)
    {
        data = (0x04U >> (3 - i)) | (0x04U << (3 - i));
        led_shift(data);
        delay(time);
    }
}

void BlinkRaiseIn(uint32_t time)
{
    uint8_t i;
    uint8_t data;

    for (i = 0U; i < 3U; i++)
    {
        data = (0x10U >> i) | (0x01U << i);
        led_shift(data);
        delay(time);
    }
}

// uint32_t arr[] = {2,4,3,4};
const uint32_t b = 3;
uint32_t arr;

int main()
{
    //volatile int a = arr[0];
    (void)arr;
    int b2 = b;
    (void)b2;

    /* Setting clock gate for LEDs */
    PCC->PCCn[LED0_PCC_CLOCK] = PCC_PCCn_CGC_MASK;

    PCC->PCCn[LED0_TOUCH_PCC_CLOCK] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[LED1_TOUCH_PCC_CLOCK] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[LED2_TOUCH_PCC_CLOCK] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[LED3_TOUCH_PCC_CLOCK] = PCC_PCCn_CGC_MASK;

    /* Mux to gpio for LEDs */
    LED0_PORT->PCR[LED0_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED1_PORT->PCR[LED1_GPIO_PIN] |= PORT_PCR_MUX(1);

    LED0_TOUCH_PORT->PCR[LED0_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED1_TOUCH_PORT->PCR[LED1_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED2_TOUCH_PORT->PCR[LED2_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED3_TOUCH_PORT->PCR[LED3_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);
    LED4_TOUCH_PORT->PCR[LED4_TOUCH_GPIO_PIN] |= PORT_PCR_MUX(1);

    /* Output direction for LEDs */
    LED0_GPIO->PDDR |= LED0_MASK;
    LED0_GPIO->PDDR |= LED1_MASK;

    LED0_TOUCH_GPIO->PDDR |= LED0_TOUCH_MASK;
    LED1_TOUCH_GPIO->PDDR |= LED1_TOUCH_MASK;
    LED2_TOUCH_GPIO->PDDR |= LED2_TOUCH_MASK;
    LED3_TOUCH_GPIO->PDDR |= LED3_TOUCH_MASK;
    LED4_TOUCH_GPIO->PDDR |= LED4_TOUCH_MASK;


    /* Initializes values */
    LED0_ON;
    LED1_OFF;

    LED0_TOUCH_OFF;
    LED1_TOUCH_OFF;
    LED2_TOUCH_OFF;
    LED3_TOUCH_OFF;
    LED4_TOUCH_OFF;

    int i = 3;

    if (i == 2)
    {
        end_of_test_hook();
        return 1;
    }

    i = 4;
    if (i == 2)
    {
        end_of_test_hook();
        return 1;
    }

    g_ut_result = 5;
    end_of_test_hook();

    /* Infinite loop */
    for (;;)
    {
        BlinkLeft(1000000);
        BlinkLeft(1000000);
        BlinkLeft(1000000);
        BlinkRight(1000000);
        BlinkRight(1000000);
        BlinkRight(1000000);
        BlinkRaiseOut(1000000);
        BlinkRaiseOut(1000000);
        BlinkRaiseOut(1000000);
        BlinkRaiseIn(1000000);
        BlinkRaiseIn(1000000);
        BlinkRaiseIn(1000000);
        BlinkALL2(1000000);
        BlinkALL2(1000000);
        BlinkALL2(1000000);
    }

    return 0;
}
