/*!
 * @brief   : GPIO
 * @version : 1.0
 * @author  : tony hoang
 * @date    : 2016/11/08
 */

#ifndef GPIO_H
#define GPIO_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdbool.h>
#include "derivative.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief GPIO direction definition
 */
typedef enum
{
    GPIO_INPUT  = 0U,
    GPIO_OUTPUT = 1U
} gpio_direction_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Write a pin
 */
static inline void GPIO_WritePin(volatile struct SIUL2_tag * const base,
                                 uint32_t pin,
                                 uint32_t value)
{
    if (value != 0UL)
    {
        base->GPDO[pin].B.PDO_4n = 1UL;
    }
    else
    {
        base->GPDO[pin].B.PDO_4n = 0UL;
    }

}

/*!
 * @brief Write a parallel pin
 */
static inline void GPIO_WriteParallelPin(volatile struct SIUL2_tag * const base,
                                         uint16_t pinX,
                                         uint16_t pinY,
                                         uint16_t value)
{
    if (value != 0UL)
    {
        base->PGPDO[pinX].R = 1U << pinY;
    }
    else
    {
        base->PGPDO[pinX].R = 0U << pinY;
    }
}

///*!
// * @brief Write pins
// */
//static inline void GPIO_WritePins(GPIO_Type* const base,
//                                  uint32_t pins)
//{
//    base->PDOR = GPIO_PDOR_PDO(pins);
//}
//
///*!
// * @brief Write pins high, but affect to other pins low
// */
//static inline void GPIO_WritePinsHigh(GPIO_Type* const base,
//                                      uint32_t pins)
//{
//    uint32_t tmp = base->PDOR;
//    tmp |= pins;
//
//    base->PDOR = tmp;
//}
//
///*!
// * @brief Write pins low, but affect to other pins high
// */
//static inline void GPIO_WritePinsLow(GPIO_Type* const base,
//                                     uint32_t pins)
//{
//    uint32_t tmp = base->PDOR;
//    tmp &= ~pins;
//
//    base->PDOR = tmp;
//}

/*!
 * @brief Set direction for each pin
 */
static inline void GPIO_SetPinDirection(volatile struct SIUL2_tag * const base,
                                        uint32_t pin,
                                        gpio_direction_t dir)
{
    if (dir == GPIO_OUTPUT)
    {
        base->MSCR[pin].B.OBE = 1UL;
        base->MSCR[pin].B.IBE = 0UL;
    }
    else
    {
        base->MSCR[pin].B.OBE = 0UL;
        base->MSCR[pin].B.IBE = 1UL;
    }
}

///*!
// * @brief Set direction for pins
// */
//static inline void GPIO_SetPinsDirection(volatile struct SIUL2_tag * const base,
//                                         uint32_t pins)
//{
//}

///*!
// * @brief Set direction as output for pins
// */
//static inline void GPIO_SetPinsOut(GPIO_Type* const base,
//                                   uint32_t pins)
//{
//    uint32_t tmp = base->PDDR;
//    tmp |= pins;
//
//    base->PDDR = tmp;
//}
//
///*!
// * @brief Set direction as input for pins
// */
//static inline void GPIO_SetPinsIn(GPIO_Type* const base,
//                                  uint32_t pins)
//{
//    uint32_t tmp = base->PDDR;
//    tmp &= ~pins;
//
//    base->PDDR = tmp;
//}
//
///*!
// * @brief Set pins
// */
//static inline void GPIO_SetPins(GPIO_Type* const base,
//                                uint32_t pins)
//{
//    base->PSOR = GPIO_PSOR_PTSO(pins);
//}
//
///*!
// * @brief Clear pins
// */
//static inline void GPIO_ClearPins(GPIO_Type* const base,
//                                  uint32_t pins)
//{
//    base->PCOR = GPIO_PCOR_PTCO(pins);
//}

/*!
 * @brief Toggle pins
 */
static inline void GPIO_TogglePin(volatile struct SIUL2_tag * const base,
                                  uint16_t pin)
{
    base->GPDO[pin].B.PDO_4n ^= 1U;
}

/*!
 * @brief Read pins
 */
static inline uint32_t GPIO_ReadPin(const volatile struct SIUL2_tag * const base,
                                    uint16_t pin)
{
    return SIUL2.GPDI[pin].R;
}

#if defined(__cplusplus)
}
#endif

#endif /* GPIO_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
