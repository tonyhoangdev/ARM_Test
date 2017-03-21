/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "S32K144.h" /* include peripheral declarations S32K144 */

#define COUNTER_LIMIT 1000000

int foo (int a)
{
    int b = 10;
    a= 20;

    __asm__("mov %1, %0" : "=r" (a) : "r" (b));

    return a;
}

int main(void)
{
    //__asm volatile ("cpsid i" : : : "memory");

    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
    PORTD->PCR[15] |= PORT_PCR_MUX(1);
    PTD->PDDR |= 1 << 15;
    PTD->PSOR |= 1 << 15;
    int counter = foo(30);

    //__asm volatile ("wfi");
    //__asm volatile ("cpsie i" : : : "memory");

    uint32_t arr[] = {200};
    uint32_t num  = (uint32_t)arr[0];
    uint32_t soLuong = num / sizeof(uint32_t);
    (void)soLuong;


    for (;;)
    {
        counter++;

        if (counter > COUNTER_LIMIT)
        {
            counter = 0;
            PTD->PTOR |= 1 << 15;
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
