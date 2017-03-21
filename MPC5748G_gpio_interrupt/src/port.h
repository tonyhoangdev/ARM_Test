#ifndef PORT_H
#define PORT_H

#include <stdbool.h>
#include "derivative.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief Pin mux selection
 */
typedef enum
{
    PORT_MUX_AS_GPIO  = 0U,
    PORT_MUX_ALT1     = 1U,
    PORT_MUX_ALT2     = 2U,
    PORT_MUX_ALT3     = 3U,
    PORT_MUX_WKPU     = 4U,
} port_mux_t;

/*!
 * @brief Internal resistor pull feature selection
 */
typedef enum
{
    PORT_PULL_DISABLED  = 0U,
    PORT_PULL_DOWN      = 1U,
    PORT_PULL_UP        = 2U
} port_pull_t;

/*!
 * @brief Configures the interrupt generation condition.
 */
typedef enum
{
    PORT_DMA_INT_DISABLED = 0x0U,
    PORT_INT_LOGIC_ZERO   = 0x8U,
    PORT_INT_RISING_EDGE  = 0x9U,
    PORT_INT_FALLING_EDGE = 0xAU,
    PORT_INT_EITHER_EDGE  = 0xBU,
    PORT_INT_LOGIC_ONE    = 0xCU
} port_interrupt_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/* Configures the pin muxing. */
static inline void PORT_SetMuxSel(volatile struct SIUL2_tag * const base,
                                  uint32_t pin,
                                  port_mux_t config)
{
    SIUL2.MSCR[pin].B.SSS = config;
}

/* Configures the internal resistor. */
static inline void PORT_SetPullSel(volatile struct SIUL2_tag * const base,
                                   uint32_t pin,
                                   port_pull_t config)
{
    /* Clear PULL select and not enable */
    base->MSCR[pin].B.PUS = 0U;
    base->MSCR[pin].B.PUE = 0U;

    switch (config)
    {
        case PORT_PULL_DOWN:
            base->MSCR[pin].B.PUE = 1U;
            break;
        case PORT_PULL_UP:
            base->MSCR[pin].B.PUS = 1U;
            base->MSCR[pin].B.PUE = 1U;
            break;
        default:
            /* do nothing */
            break;
    }
}

/* Configures the port pin interrupt/DMA request. */
static inline void PORT_SetIntSel(volatile struct SIUL2_tag * const base,
                                  port_interrupt_t config,
                                  bool isFilterEn,
                                  uint8_t eIRQNum,
                                  uint16_t sourceSingalSelect)
{
    if (config == PORT_INT_FALLING_EDGE)
    {
        base->IFEER0.R |= 1UL << eIRQNum;
    }
    else if (config == PORT_INT_RISING_EDGE)
    {
        base->IREER0.R |= 1UL << eIRQNum;
    }
    else
    {
        /* do nothing */
    }

    base->IFER0.R |= 1UL << eIRQNum;
    base->IRER0.R |= 1UL << eIRQNum;
    base->IMCR[sourceSingalSelect].R |= 1UL;
}

//static inline port_interrupt_t PORT_GetIntSel(PORT_Type * base,
//                                              uint32_t pin)
//{
//    return (port_interrupt_t)((base->PCR[pin] & PORT_PCR_IRQC_MASK) >> PORT_PCR_IRQC_SHIFT);
//}
//
static inline bool PORT_GetIntFlag(volatile struct SIUL2_tag * const base,
                                   uint8_t eIRQNum)
{
    return (base->ISR0.R & (1U << eIRQNum)) != 0U;
}

static inline void PORT_ClearIntFlag(volatile struct SIUL2_tag * const base,
                                     uint8_t eIRQNum)
{
    base->ISR0.R = 1U << eIRQNum;
}

#if defined(__cplusplus)
}
#endif

#endif /* PORT_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
