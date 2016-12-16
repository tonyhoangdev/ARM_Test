/*
** ###################################################################
**     Processors:          MKL46Z256VLH4
**                          MKL46Z128VLH4
**                          MKL46Z256VLL4
**                          MKL46Z128VLL4
**                          MKL46Z256VMC4
**                          MKL46Z128VMC4
**                          MKL46Z256VMP4
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    KL46P121M48SF4RM, Rev.2, Dec 2012
**     Version:             rev. 2.2, 2013-08-15
**     Build:               b151023
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKL46Z4
**
**     Copyright (c) 1997 - 2015 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2012-10-16)
**         Initial version.
**     - rev. 2.0 (2012-12-12)
**         Update to reference manual rev. 1.
**     - rev. 2.1 (2013-04-05)
**         Changed start of doxygen comment.
**     - rev. 2.2 (2013-08-15)
**         Update of I2S register TCR2.
**
** ###################################################################
*/

/*!
 * @file MKL46Z4.h
 * @version 2.2
 * @date 2013-08-15
 * @brief CMSIS Peripheral Access Layer for MKL46Z4
 *
 * CMSIS Peripheral Access Layer for MKL46Z4
 */

#ifndef MKL46Z4_H
#define MKL46Z4_H                              /**< Symbol preventing repeated inclusion */

#include <stdint.h>
/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002U

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum
{
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete and error interrupt */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete and error interrupt */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete and error interrupt */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete and error interrupt */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt */
  FTFA_IRQn                    = 5,                /**< FTFA command complete and read collision */
  LVD_LVW_IRQn                 = 6,                /**< Low-voltage detect, low-voltage warning */
  LLWU_IRQn                    = 7,                /**< Low Leakage Wakeup */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  I2C1_IRQn                    = 9,                /**< I2C1 interrupt */
  SPI0_IRQn                    = 10,               /**< SPI0 single interrupt vector for all sources */
  SPI1_IRQn                    = 11,               /**< SPI1 single interrupt vector for all sources */
  UART0_IRQn                   = 12,               /**< UART0 status and error */
  UART1_IRQn                   = 13,               /**< UART1 status and error */
  UART2_IRQn                   = 14,               /**< UART2 status and error */
  ADC0_IRQn                    = 15,               /**< ADC0 interrupt */
  CMP0_IRQn                    = 16,               /**< CMP0 interrupt */
  TPM0_IRQn                    = 17,               /**< TPM0 single interrupt vector for all sources */
  TPM1_IRQn                    = 18,               /**< TPM1 single interrupt vector for all sources */
  TPM2_IRQn                    = 19,               /**< TPM2 single interrupt vector for all sources */
  RTC_IRQn                     = 20,               /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 21,               /**< RTC seconds interrupt */
  PIT_IRQn                     = 22,               /**< PIT single interrupt vector for all channels */
  I2S0_IRQn                    = 23,               /**< I2S0 Single interrupt vector for all sources */
  USB0_IRQn                    = 24,               /**< USB0 OTG */
  DAC0_IRQn                    = 25,               /**< DAC0 interrupt */
  TSI0_IRQn                    = 26,               /**< TSI0 interrupt */
  MCG_IRQn                     = 27,               /**< MCG interrupt */
  LPTMR0_IRQn                  = 28,               /**< LPTMR0 interrupt */
  LCD_IRQn                     = 29,               /**< Segment LCD interrupt */
  PORTA_IRQn                   = 30,               /**< PORTA pin detect */
  PORTC_PORTD_IRQn             = 31                /**< Single interrupt vector for PORTC and PORTD pin detect */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control 1 Register, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control 2 Register, offset: 0x1 */
  __IO uint8_t C3;                                 /**< MCG Control 3 Register, offset: 0x2 */
  __IO uint8_t C4;                                 /**< MCG Control 4 Register, offset: 0x3 */
  __IO uint8_t C5;                                 /**< MCG Control 5 Register, offset: 0x4 */
  __IO uint8_t C6;                                 /**< MCG Control 6 Register, offset: 0x5 */
  __IO uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_0[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_1[1];
  __IO uint8_t ATCVH;                              /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  __IO uint8_t ATCVL;                              /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
       uint8_t RESERVED_2[1];
  __IO uint8_t C8;                                 /**< MCG Control 8 Register, offset: 0xD */
  __I  uint8_t C9;                                 /**< MCG Control 9 Register, offset: 0xE */
  __I  uint8_t C10;                                /**< MCG Control 10 Register, offset: 0xF */
} MCG_Type;

/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/*! @name C1 - MCG Control 1 Register */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)
#define MCG_C1_IREFSTEN_SHIFT                    (0U)
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFSTEN_SHIFT)) & MCG_C1_IREFSTEN_MASK)
#define MCG_C1_IRCLKEN_MASK                      (0x2U)
#define MCG_C1_IRCLKEN_SHIFT                     (1U)
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C1_IRCLKEN_SHIFT)) & MCG_C1_IRCLKEN_MASK)
#define MCG_C1_IREFS_MASK                        (0x4U)
#define MCG_C1_IREFS_SHIFT                       (2U)
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFS_SHIFT)) & MCG_C1_IREFS_MASK)
#define MCG_C1_FRDIV_MASK                        (0x38U)
#define MCG_C1_FRDIV_SHIFT                       (3U)
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C1_FRDIV_SHIFT)) & MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         (0xC0U)
#define MCG_C1_CLKS_SHIFT                        (6U)
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C1_CLKS_SHIFT)) & MCG_C1_CLKS_MASK)

/*! @name C2 - MCG Control 2 Register */
#define MCG_C2_IRCS_MASK                         (0x1U)
#define MCG_C2_IRCS_SHIFT                        (0U)
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C2_IRCS_SHIFT)) & MCG_C2_IRCS_MASK)
#define MCG_C2_LP_MASK                           (0x2U)
#define MCG_C2_LP_SHIFT                          (1U)
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x)) << MCG_C2_LP_SHIFT)) & MCG_C2_LP_MASK)
#define MCG_C2_EREFS0_MASK                       (0x4U)
#define MCG_C2_EREFS0_SHIFT                      (2U)
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C2_EREFS0_SHIFT)) & MCG_C2_EREFS0_MASK)
#define MCG_C2_HGO0_MASK                         (0x8U)
#define MCG_C2_HGO0_SHIFT                        (3U)
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C2_HGO0_SHIFT)) & MCG_C2_HGO0_MASK)
#define MCG_C2_RANGE0_MASK                       (0x30U)
#define MCG_C2_RANGE0_SHIFT                      (4U)
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C2_RANGE0_SHIFT)) & MCG_C2_RANGE0_MASK)
#define MCG_C2_FCFTRIM_MASK                      (0x40U)
#define MCG_C2_FCFTRIM_SHIFT                     (6U)
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C2_FCFTRIM_SHIFT)) & MCG_C2_FCFTRIM_MASK)
#define MCG_C2_LOCRE0_MASK                       (0x80U)
#define MCG_C2_LOCRE0_SHIFT                      (7U)
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C2_LOCRE0_SHIFT)) & MCG_C2_LOCRE0_MASK)

/*! @name C3 - MCG Control 3 Register */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)
#define MCG_C3_SCTRIM_SHIFT                      (0U)
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C3_SCTRIM_SHIFT)) & MCG_C3_SCTRIM_MASK)

/*! @name C4 - MCG Control 4 Register */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)
#define MCG_C4_SCFTRIM_SHIFT                     (0U)
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C4_SCFTRIM_SHIFT)) & MCG_C4_SCFTRIM_MASK)
#define MCG_C4_FCTRIM_MASK                       (0x1EU)
#define MCG_C4_FCTRIM_SHIFT                      (1U)
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C4_FCTRIM_SHIFT)) & MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     (0x60U)
#define MCG_C4_DRST_DRS_SHIFT                    (5U)
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C4_DRST_DRS_SHIFT)) & MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        (0x80U)
#define MCG_C4_DMX32_SHIFT                       (7U)
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C4_DMX32_SHIFT)) & MCG_C4_DMX32_MASK)

/*! @name C5 - MCG Control 5 Register */
#define MCG_C5_PRDIV0_MASK                       (0x1FU)
#define MCG_C5_PRDIV0_SHIFT                      (0U)
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C5_PRDIV0_SHIFT)) & MCG_C5_PRDIV0_MASK)
#define MCG_C5_PLLSTEN0_MASK                     (0x20U)
#define MCG_C5_PLLSTEN0_SHIFT                    (5U)
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLSTEN0_SHIFT)) & MCG_C5_PLLSTEN0_MASK)
#define MCG_C5_PLLCLKEN0_MASK                    (0x40U)
#define MCG_C5_PLLCLKEN0_SHIFT                   (6U)
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLCLKEN0_SHIFT)) & MCG_C5_PLLCLKEN0_MASK)

/*! @name C6 - MCG Control 6 Register */
#define MCG_C6_VDIV0_MASK                        (0x1FU)
#define MCG_C6_VDIV0_SHIFT                       (0U)
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C6_VDIV0_SHIFT)) & MCG_C6_VDIV0_MASK)
#define MCG_C6_CME0_MASK                         (0x20U)
#define MCG_C6_CME0_SHIFT                        (5U)
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C6_CME0_SHIFT)) & MCG_C6_CME0_MASK)
#define MCG_C6_PLLS_MASK                         (0x40U)
#define MCG_C6_PLLS_SHIFT                        (6U)
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C6_PLLS_SHIFT)) & MCG_C6_PLLS_MASK)
#define MCG_C6_LOLIE0_MASK                       (0x80U)
#define MCG_C6_LOLIE0_SHIFT                      (7U)
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C6_LOLIE0_SHIFT)) & MCG_C6_LOLIE0_MASK)

/*! @name S - MCG Status Register */
#define MCG_S_IRCST_MASK                         (0x1U)
#define MCG_S_IRCST_SHIFT                        (0U)
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_IRCST_SHIFT)) & MCG_S_IRCST_MASK)
#define MCG_S_OSCINIT0_MASK                      (0x2U)
#define MCG_S_OSCINIT0_SHIFT                     (1U)
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_S_OSCINIT0_SHIFT)) & MCG_S_OSCINIT0_MASK)
#define MCG_S_CLKST_MASK                         (0xCU)
#define MCG_S_CLKST_SHIFT                        (2U)
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_CLKST_SHIFT)) & MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        (0x10U)
#define MCG_S_IREFST_SHIFT                       (4U)
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_S_IREFST_SHIFT)) & MCG_S_IREFST_MASK)
#define MCG_S_PLLST_MASK                         (0x20U)
#define MCG_S_PLLST_SHIFT                        (5U)
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_PLLST_SHIFT)) & MCG_S_PLLST_MASK)
#define MCG_S_LOCK0_MASK                         (0x40U)
#define MCG_S_LOCK0_SHIFT                        (6U)
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_LOCK0_SHIFT)) & MCG_S_LOCK0_MASK)
#define MCG_S_LOLS0_MASK                         (0x80U)
#define MCG_S_LOLS0_SHIFT                        (7U)
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_LOLS0_SHIFT)) & MCG_S_LOLS0_MASK)

/*! @name SC - MCG Status and Control Register */
#define MCG_SC_LOCS0_MASK                        (0x1U)
#define MCG_SC_LOCS0_SHIFT                       (0U)
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_SC_LOCS0_SHIFT)) & MCG_SC_LOCS0_MASK)
#define MCG_SC_FCRDIV_MASK                       (0xEU)
#define MCG_SC_FCRDIV_SHIFT                      (1U)
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_SC_FCRDIV_SHIFT)) & MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_SC_FLTPRSRV_SHIFT)) & MCG_SC_FLTPRSRV_MASK)
#define MCG_SC_ATMF_MASK                         (0x20U)
#define MCG_SC_ATMF_SHIFT                        (5U)
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMF_SHIFT)) & MCG_SC_ATMF_MASK)
#define MCG_SC_ATMS_MASK                         (0x40U)
#define MCG_SC_ATMS_SHIFT                        (6U)
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMS_SHIFT)) & MCG_SC_ATMS_MASK)
#define MCG_SC_ATME_MASK                         (0x80U)
#define MCG_SC_ATME_SHIFT                        (7U)
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATME_SHIFT)) & MCG_SC_ATME_MASK)

/*! @name ATCVH - MCG Auto Trim Compare Value High Register */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_ATCVH_ATCVH_SHIFT)) & MCG_ATCVH_ATCVH_MASK)

/*! @name ATCVL - MCG Auto Trim Compare Value Low Register */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_ATCVL_ATCVL_SHIFT)) & MCG_ATCVL_ATCVL_MASK)

/*! @name C8 - MCG Control 8 Register */
#define MCG_C8_LOLRE_MASK                        (0x40U)
#define MCG_C8_LOLRE_SHIFT                       (6U)
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C8_LOLRE_SHIFT)) & MCG_C8_LOLRE_MASK)


/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE                                 (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG                                      ((MCG_Type *)MCG_BASE)
/** Array initializer of MCG peripheral base addresses */
#define MCG_BASE_ADDRS                           { MCG_BASE }
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG }
/** Interrupt vectors for the MCG peripheral type */
#define MCG_IRQS                                 { MCG_IRQn }
/* MCG C2[EREFS] backward compatibility */
#define MCG_C2_EREFS_MASK         (MCG_C2_EREFS0_MASK)
#define MCG_C2_EREFS_SHIFT        (MCG_C2_EREFS0_SHIFT)
#define MCG_C2_EREFS_WIDTH        (MCG_C2_EREFS0_WIDTH)
#define MCG_C2_EREFS(x)           (MCG_C2_EREFS0(x))

/* MCG C2[HGO] backward compatibility */
#define MCG_C2_HGO_MASK         (MCG_C2_HGO0_MASK)
#define MCG_C2_HGO_SHIFT        (MCG_C2_HGO0_SHIFT)
#define MCG_C2_HGO_WIDTH        (MCG_C2_HGO0_WIDTH)
#define MCG_C2_HGO(x)           (MCG_C2_HGO0(x))

/* MCG C2[RANGE] backward compatibility */
#define MCG_C2_RANGE_MASK         (MCG_C2_RANGE0_MASK)
#define MCG_C2_RANGE_SHIFT        (MCG_C2_RANGE0_SHIFT)
#define MCG_C2_RANGE_WIDTH        (MCG_C2_RANGE0_WIDTH)
#define MCG_C2_RANGE(x)           (MCG_C2_RANGE0(x))


/*!
 * @}
 */ /* end of group MCG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */


/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8_t RESERVED_0[24];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
} PORT_Type;

/** Number of instances of the PORT module. */
#define PORT_INSTANCE_COUNT                      (5u)


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, NotAvail_IRQn, PORTC_PORTD_IRQn, PORTC_PORTD_IRQn, NotAvail_IRQn }

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name PCR - Pin Control Register n */
#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
#define PORT_PCR_PS_WIDTH                        1u
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
#define PORT_PCR_PE_WIDTH                        1u
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)
#define PORT_PCR_SRE_MASK                        (0x4U)
#define PORT_PCR_SRE_SHIFT                       (2U)
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)
#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)
#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
#define PORT_PCR_DSE_WIDTH                       1u
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
#define PORT_PCR_MUX_WIDTH                       3u
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)
#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_IRQC_WIDTH                      4u
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        (0x1000000U)
#define PORT_PCR_ISF_SHIFT                       (24U)
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ISF_SHIFT)) & PORT_PCR_ISF_MASK)
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
#define PORT_GPCLR_GPWD_WIDTH                    16u
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCLR_GPWE_SHIFT                    (16U)
#define PORT_GPCLR_GPWE_WIDTH                    16u
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE_SHIFT)) & PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
#define PORT_GPCHR_GPWD_WIDTH                    16u
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCHR_GPWE_SHIFT                    (16U)
#define PORT_GPCHR_GPWE_WIDTH                    16u
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE_SHIFT)) & PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
#define PORT_ISFR_ISF_SHIFT                      (0U)
#define PORT_ISFR_ISF_WIDTH                      32u
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */


/** GPIO - Size of Registers Arrays */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} GPIO_Type;

/** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT                      (5u)


/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base address */
#define PTA_BASE                                 (0x400FF000u)
/** Peripheral PTA base pointer */
#define PTA                                      ((GPIO_Type *)PTA_BASE)
/** Peripheral PTB base address */
#define PTB_BASE                                 (0x400FF040u)
/** Peripheral PTB base pointer */
#define PTB                                      ((GPIO_Type *)PTB_BASE)
/** Peripheral PTC base address */
#define PTC_BASE                                 (0x400FF080u)
/** Peripheral PTC base pointer */
#define PTC                                      ((GPIO_Type *)PTC_BASE)
/** Peripheral PTD base address */
#define PTD_BASE                                 (0x400FF0C0u)
/** Peripheral PTD base pointer */
#define PTD                                      ((GPIO_Type *)PTD_BASE)
/** Peripheral PTE base address */
#define PTE_BASE                                 (0x400FF100u)
/** Peripheral PTE base pointer */
#define PTE                                      ((GPIO_Type *)PTE_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { PTA_BASE, PTB_BASE, PTC_BASE, PTD_BASE, PTE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { PTA, PTB, PTC, PTD, PTE }

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0u
#define GPIO_PDOR_PDO_WIDTH                      32u
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0u
#define GPIO_PSOR_PTSO_WIDTH                     32u
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0u
#define GPIO_PCOR_PTCO_WIDTH                     32u
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0u
#define GPIO_PTOR_PTTO_WIDTH                     32u
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0u
#define GPIO_PDIR_PDI_WIDTH                      32u
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0u
#define GPIO_PDDR_PDD_WIDTH                      32u
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */



/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1CFG;                          /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t SOPT2;                             /**< System Options Register 2, offset: 0x1004 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SOPT4;                             /**< System Options Register 4, offset: 0x100C */
  __IO uint32_t SOPT5;                             /**< System Options Register 5, offset: 0x1010 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOPT7;                             /**< System Options Register 7, offset: 0x1018 */
       uint8_t RESERVED_3[8];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
       uint8_t RESERVED_6[4];
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
       uint8_t RESERVED_7[156];
  __IO uint32_t COPC;                              /**< COP Control Register, offset: 0x1100 */
  __O  uint32_t SRVCOP;                            /**< Service COP, offset: 0x1104 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SOPT1 - System Options Register 1 */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)
#define SIM_SOPT1_USBVSTBY_MASK                  (0x20000000U)
#define SIM_SOPT1_USBVSTBY_SHIFT                 (29U)
#define SIM_SOPT1_USBVSTBY(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBVSTBY_SHIFT)) & SIM_SOPT1_USBVSTBY_MASK)
#define SIM_SOPT1_USBSSTBY_MASK                  (0x40000000U)
#define SIM_SOPT1_USBSSTBY_SHIFT                 (30U)
#define SIM_SOPT1_USBSSTBY(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBSSTBY_SHIFT)) & SIM_SOPT1_USBSSTBY_MASK)
#define SIM_SOPT1_USBREGEN_MASK                  (0x80000000U)
#define SIM_SOPT1_USBREGEN_SHIFT                 (31U)
#define SIM_SOPT1_USBREGEN(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBREGEN_SHIFT)) & SIM_SOPT1_USBREGEN_MASK)

/*! @name SOPT1CFG - SOPT1 Configuration Register */
#define SIM_SOPT1CFG_URWE_MASK                   (0x1000000U)
#define SIM_SOPT1CFG_URWE_SHIFT                  (24U)
#define SIM_SOPT1CFG_URWE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_URWE_SHIFT)) & SIM_SOPT1CFG_URWE_MASK)
#define SIM_SOPT1CFG_UVSWE_MASK                  (0x2000000U)
#define SIM_SOPT1CFG_UVSWE_SHIFT                 (25U)
#define SIM_SOPT1CFG_UVSWE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_UVSWE_SHIFT)) & SIM_SOPT1CFG_UVSWE_MASK)
#define SIM_SOPT1CFG_USSWE_MASK                  (0x4000000U)
#define SIM_SOPT1CFG_USSWE_SHIFT                 (26U)
#define SIM_SOPT1CFG_USSWE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_USSWE_SHIFT)) & SIM_SOPT1CFG_USSWE_MASK)

/*! @name SOPT2 - System Options Register 2 */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_RTCCLKOUTSEL_SHIFT)) & SIM_SOPT2_RTCCLKOUTSEL_MASK)
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_CLKOUTSEL_SHIFT)) & SIM_SOPT2_CLKOUTSEL_MASK)
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x10000U)
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_PLLFLLSEL_SHIFT)) & SIM_SOPT2_PLLFLLSEL_MASK)
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_USBSRC_SHIFT)) & SIM_SOPT2_USBSRC_MASK)
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TPMSRC_SHIFT)) & SIM_SOPT2_TPMSRC_MASK)
#define SIM_SOPT2_UART0SRC_MASK                  (0xC000000U)
#define SIM_SOPT2_UART0SRC_SHIFT                 (26U)
#define SIM_SOPT2_UART0SRC(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_UART0SRC_SHIFT)) & SIM_SOPT2_UART0SRC_MASK)

/*! @name SOPT4 - System Options Register 4 */
#define SIM_SOPT4_TPM1CH0SRC_MASK                (0xC0000U)
#define SIM_SOPT4_TPM1CH0SRC_SHIFT               (18U)
#define SIM_SOPT4_TPM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM1CH0SRC_SHIFT)) & SIM_SOPT4_TPM1CH0SRC_MASK)
#define SIM_SOPT4_TPM2CH0SRC_MASK                (0x100000U)
#define SIM_SOPT4_TPM2CH0SRC_SHIFT               (20U)
#define SIM_SOPT4_TPM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM2CH0SRC_SHIFT)) & SIM_SOPT4_TPM2CH0SRC_MASK)
#define SIM_SOPT4_TPM0CLKSEL_MASK                (0x1000000U)
#define SIM_SOPT4_TPM0CLKSEL_SHIFT               (24U)
#define SIM_SOPT4_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM0CLKSEL_SHIFT)) & SIM_SOPT4_TPM0CLKSEL_MASK)
#define SIM_SOPT4_TPM1CLKSEL_MASK                (0x2000000U)
#define SIM_SOPT4_TPM1CLKSEL_SHIFT               (25U)
#define SIM_SOPT4_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM1CLKSEL_SHIFT)) & SIM_SOPT4_TPM1CLKSEL_MASK)
#define SIM_SOPT4_TPM2CLKSEL_MASK                (0x4000000U)
#define SIM_SOPT4_TPM2CLKSEL_SHIFT               (26U)
#define SIM_SOPT4_TPM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM2CLKSEL_SHIFT)) & SIM_SOPT4_TPM2CLKSEL_MASK)

/*! @name SOPT5 - System Options Register 5 */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0TXSRC_SHIFT)) & SIM_SOPT5_UART0TXSRC_MASK)
#define SIM_SOPT5_UART0RXSRC_MASK                (0x4U)
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0RXSRC_SHIFT)) & SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1TXSRC_SHIFT)) & SIM_SOPT5_UART1TXSRC_MASK)
#define SIM_SOPT5_UART1RXSRC_MASK                (0x40U)
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1RXSRC_SHIFT)) & SIM_SOPT5_UART1RXSRC_MASK)
#define SIM_SOPT5_UART0ODE_MASK                  (0x10000U)
#define SIM_SOPT5_UART0ODE_SHIFT                 (16U)
#define SIM_SOPT5_UART0ODE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0ODE_SHIFT)) & SIM_SOPT5_UART0ODE_MASK)
#define SIM_SOPT5_UART1ODE_MASK                  (0x20000U)
#define SIM_SOPT5_UART1ODE_SHIFT                 (17U)
#define SIM_SOPT5_UART1ODE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1ODE_SHIFT)) & SIM_SOPT5_UART1ODE_MASK)
#define SIM_SOPT5_UART2ODE_MASK                  (0x40000U)
#define SIM_SOPT5_UART2ODE_SHIFT                 (18U)
#define SIM_SOPT5_UART2ODE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART2ODE_SHIFT)) & SIM_SOPT5_UART2ODE_MASK)

/*! @name SOPT7 - System Options Register 7 */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0TRGSEL_SHIFT)) & SIM_SOPT7_ADC0TRGSEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0PRETRGSEL_SHIFT)) & SIM_SOPT7_ADC0PRETRGSEL_MASK)
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0ALTTRGEN_SHIFT)) & SIM_SOPT7_ADC0ALTTRGEN_MASK)

/*! @name SDID - System Device Identification Register */
#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)
#define SIM_SDID_DIEID_MASK                      (0xF80U)
#define SIM_SDID_DIEID_SHIFT                     (7U)
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)
#define SIM_SDID_SRAMSIZE_MASK                   (0xF0000U)
#define SIM_SDID_SRAMSIZE_SHIFT                  (16U)
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SRAMSIZE_SHIFT)) & SIM_SDID_SRAMSIZE_MASK)
#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMID_MASK                      (0xF0000000U)
#define SIM_SDID_FAMID_SHIFT                     (28U)
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)

/*! @name SCGC4 - System Clock Gating Control Register 4 */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)
#define SIM_SCGC4_I2C0_SHIFT                     (6U)
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C0_SHIFT)) & SIM_SCGC4_I2C0_MASK)
#define SIM_SCGC4_I2C1_MASK                      (0x80U)
#define SIM_SCGC4_I2C1_SHIFT                     (7U)
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C1_SHIFT)) & SIM_SCGC4_I2C1_MASK)
#define SIM_SCGC4_UART0_MASK                     (0x400U)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)
#define SIM_SCGC4_UART1_MASK                     (0x800U)
#define SIM_SCGC4_UART1_SHIFT                    (11U)
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART1_SHIFT)) & SIM_SCGC4_UART1_MASK)
#define SIM_SCGC4_UART2_MASK                     (0x1000U)
#define SIM_SCGC4_UART2_SHIFT                    (12U)
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART2_SHIFT)) & SIM_SCGC4_UART2_MASK)
#define SIM_SCGC4_USBOTG_MASK                    (0x40000U)
#define SIM_SCGC4_USBOTG_SHIFT                   (18U)
#define SIM_SCGC4_USBOTG(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_USBOTG_SHIFT)) & SIM_SCGC4_USBOTG_MASK)
#define SIM_SCGC4_CMP_MASK                       (0x80000U)
#define SIM_SCGC4_CMP_SHIFT                      (19U)
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP_SHIFT)) & SIM_SCGC4_CMP_MASK)
#define SIM_SCGC4_SPI0_MASK                      (0x400000U)
#define SIM_SCGC4_SPI0_SHIFT                     (22U)
#define SIM_SCGC4_SPI0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI0_SHIFT)) & SIM_SCGC4_SPI0_MASK)
#define SIM_SCGC4_SPI1_MASK                      (0x800000U)
#define SIM_SCGC4_SPI1_SHIFT                     (23U)
#define SIM_SCGC4_SPI1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI1_SHIFT)) & SIM_SCGC4_SPI1_MASK)

/*! @name SCGC5 - System Clock Gating Control Register 5 */
#define SIM_SCGC5_LPTMR_MASK                     (0x1U)
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_LPTMR_SHIFT)) & SIM_SCGC5_LPTMR_MASK)
#define SIM_SCGC5_TSI_MASK                       (0x20U)
#define SIM_SCGC5_TSI_SHIFT                      (5U)
#define SIM_SCGC5_TSI(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TSI_SHIFT)) & SIM_SCGC5_TSI_MASK)
#define SIM_SCGC5_PORTA_MASK                     (0x200U)
#define SIM_SCGC5_PORTA_SHIFT                    (9U)
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)
#define SIM_SCGC5_PORTB_MASK                     (0x400U)
#define SIM_SCGC5_PORTB_SHIFT                    (10U)
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)
#define SIM_SCGC5_PORTC_MASK                     (0x800U)
#define SIM_SCGC5_PORTC_SHIFT                    (11U)
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT                    (12U)
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT                    (13U)
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)
#define SIM_SCGC5_SLCD_MASK                      (0x80000U)
#define SIM_SCGC5_SLCD_SHIFT                     (19U)
#define SIM_SCGC5_SLCD(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_SLCD_SHIFT)) & SIM_SCGC5_SLCD_MASK)

/*! @name SCGC6 - System Clock Gating Control Register 6 */
#define SIM_SCGC6_FTF_MASK                       (0x1U)
#define SIM_SCGC6_FTF_SHIFT                      (0U)
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTF_SHIFT)) & SIM_SCGC6_FTF_MASK)
#define SIM_SCGC6_DMAMUX_MASK                    (0x2U)
#define SIM_SCGC6_DMAMUX_SHIFT                   (1U)
#define SIM_SCGC6_DMAMUX(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX_SHIFT)) & SIM_SCGC6_DMAMUX_MASK)
#define SIM_SCGC6_I2S_MASK                       (0x8000U)
#define SIM_SCGC6_I2S_SHIFT                      (15U)
#define SIM_SCGC6_I2S(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_I2S_SHIFT)) & SIM_SCGC6_I2S_MASK)
#define SIM_SCGC6_PIT_MASK                       (0x800000U)
#define SIM_SCGC6_PIT_SHIFT                      (23U)
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT_SHIFT)) & SIM_SCGC6_PIT_MASK)
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)
#define SIM_SCGC6_TPM0_SHIFT                     (24U)
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM0_SHIFT)) & SIM_SCGC6_TPM0_MASK)
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)
#define SIM_SCGC6_TPM1_SHIFT                     (25U)
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM1_SHIFT)) & SIM_SCGC6_TPM1_MASK)
#define SIM_SCGC6_TPM2_MASK                      (0x4000000U)
#define SIM_SCGC6_TPM2_SHIFT                     (26U)
#define SIM_SCGC6_TPM2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM2_SHIFT)) & SIM_SCGC6_TPM2_MASK)
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)
#define SIM_SCGC6_ADC0_SHIFT                     (27U)
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_ADC0_SHIFT)) & SIM_SCGC6_ADC0_MASK)
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)
#define SIM_SCGC6_RTC_SHIFT                      (29U)
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RTC_SHIFT)) & SIM_SCGC6_RTC_MASK)
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)
#define SIM_SCGC6_DAC0_SHIFT                     (31U)
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DAC0_SHIFT)) & SIM_SCGC6_DAC0_MASK)

/*! @name SCGC7 - System Clock Gating Control Register 7 */
#define SIM_SCGC7_DMA_MASK                       (0x100U)
#define SIM_SCGC7_DMA_SHIFT                      (8U)
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_DMA_SHIFT)) & SIM_SCGC7_DMA_MASK)

/*! @name CLKDIV1 - System Clock Divider Register 1 */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x70000U)
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV4_SHIFT)) & SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV1_SHIFT)) & SIM_CLKDIV1_OUTDIV1_MASK)

/*! @name FCFG1 - Flash Configuration Register 1 */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)

/*! @name FCFG2 - Flash Configuration Register 2 */
#define SIM_FCFG2_MAXADDR1_MASK                  (0x7F0000U)
#define SIM_FCFG2_MAXADDR1_SHIFT                 (16U)
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR1_SHIFT)) & SIM_FCFG2_MAXADDR1_MASK)
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR0_SHIFT)) & SIM_FCFG2_MAXADDR0_MASK)

/*! @name UIDMH - Unique Identification Register Mid-High */
#define SIM_UIDMH_UID_MASK                       (0xFFFFU)
#define SIM_UIDMH_UID_SHIFT                      (0U)
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID_SHIFT)) & SIM_UIDMH_UID_MASK)

/*! @name UIDML - Unique Identification Register Mid Low */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)
#define SIM_UIDML_UID_SHIFT                      (0U)
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID_SHIFT)) & SIM_UIDML_UID_MASK)

/*! @name UIDL - Unique Identification Register Low */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDL_UID_SHIFT                       (0U)
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID_SHIFT)) & SIM_UIDL_UID_MASK)

/*! @name COPC - COP Control Register */
#define SIM_COPC_COPW_MASK                       (0x1U)
#define SIM_COPC_COPW_SHIFT                      (0U)
#define SIM_COPC_COPW(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPW_SHIFT)) & SIM_COPC_COPW_MASK)
#define SIM_COPC_COPCLKS_MASK                    (0x2U)
#define SIM_COPC_COPCLKS_SHIFT                   (1U)
#define SIM_COPC_COPCLKS(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPCLKS_SHIFT)) & SIM_COPC_COPCLKS_MASK)
#define SIM_COPC_COPT_MASK                       (0xCU)
#define SIM_COPC_COPT_SHIFT                      (2U)
#define SIM_COPC_COPT(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPT_SHIFT)) & SIM_COPC_COPT_MASK)

/*! @name SRVCOP - Service COP */
#define SIM_SRVCOP_SRVCOP_MASK                   (0xFFU)
#define SIM_SRVCOP_SRVCOP_SHIFT                  (0U)
#define SIM_SRVCOP_SRVCOP(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SRVCOP_SRVCOP_SHIFT)) & SIM_SRVCOP_SRVCOP_MASK)


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40047000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/*!
 * @}
 */ /* end of group Peripheral_access_layer */




/* ----------------------------------------------------------------------------
   -- FSL_SCB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_SCB_Peripheral_Access_Layer FSL_SCB Peripheral Access Layer
 * @{
 */


/** FSL_SCB - Size of Registers Arrays */

/** FSL_SCB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t ACTLR;                             /**< Auxiliary Control Register,, offset: 0x8 */
       uint8_t RESERVED_1[3316];
  __I  uint32_t CPUID;                             /**< CPUID Base Register, offset: 0xD00 */
  __IO uint32_t ICSR;                              /**< Interrupt Control and State Register, offset: 0xD04 */
  __IO uint32_t VTOR;                              /**< Vector Table Offset Register, offset: 0xD08 */
  __IO uint32_t AIRCR;                             /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  __IO uint32_t SCR;                               /**< System Control Register, offset: 0xD10 */
  __IO uint32_t CCR;                               /**< Configuration and Control Register, offset: 0xD14 */
  __IO uint32_t SHPR1;                             /**< System Handler Priority Register 1, offset: 0xD18 */
  __IO uint32_t SHPR2;                             /**< System Handler Priority Register 2, offset: 0xD1C */
  __IO uint32_t SHPR3;                             /**< System Handler Priority Register 3, offset: 0xD20 */
  __IO uint32_t SHCSR;                             /**< System Handler Control and State Register, offset: 0xD24 */
  __IO uint32_t CFSR;                              /**< Configurable Fault Status Registers, offset: 0xD28 */
  __IO uint32_t HFSR;                              /**< HardFault Status register, offset: 0xD2C */
  __IO uint32_t DFSR;                              /**< Debug Fault Status Register, offset: 0xD30 */
  __IO uint32_t MMFAR;                             /**< MemManage Address Register, offset: 0xD34 */
  __IO uint32_t BFAR;                              /**< BusFault Address Register, offset: 0xD38 */
  __IO uint32_t AFSR;                              /**< Auxiliary Fault Status Register, offset: 0xD3C */
       uint8_t RESERVED_2[72];
  __IO uint32_t CPACR;                             /**< Coprocessor Access Control Register, offset: 0xD88 */
       uint8_t RESERVED_3[424];
  __IO uint32_t FPCCR;                             /**< Floating-point Context Control Register, offset: 0xF34 */
  __IO uint32_t FPCAR;                             /**< Floating-point Context Address Register, offset: 0xF38 */
  __IO uint32_t FPDSCR;                            /**< Floating-point Default Status Control Register, offset: 0xF3C */
} FSL_SCB_Type, *FSL_SCB_MemMapPtr;

 /** Number of instances of the FSL_SCB module. */
#define FSL_SCB_INSTANCE_COUNT                   (1u)


/* FSL_SCB - Peripheral instance base addresses */
/** Peripheral FSL_SCB base address */
#define FSL_SCB_BASE                             (0xE000E000u)
/** Peripheral FSL_SCB base pointer */
#define FSL_SCB                                  ((FSL_SCB_Type *)FSL_SCB_BASE)
/** Array initializer of FSL_SCB peripheral base addresses */
#define FSL_SCB_BASE_ADDRS                       { FSL_SCB_BASE }
/** Array initializer of FSL_SCB peripheral base pointers */
#define FSL_SCB_BASE_PTRS                        { FSL_SCB }

/* ----------------------------------------------------------------------------
   -- FSL_SCB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_SCB_Register_Masks FSL_SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define FSL_SCB_ACTLR_DISMCYCINT_MASK            0x1u
#define FSL_SCB_ACTLR_DISMCYCINT_SHIFT           0u
#define FSL_SCB_ACTLR_DISMCYCINT_WIDTH           1u
#define FSL_SCB_ACTLR_DISMCYCINT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISMCYCINT_SHIFT))&FSL_SCB_ACTLR_DISMCYCINT_MASK)
#define FSL_SCB_ACTLR_DISDEFWBUF_MASK            0x2u
#define FSL_SCB_ACTLR_DISDEFWBUF_SHIFT           1u
#define FSL_SCB_ACTLR_DISDEFWBUF_WIDTH           1u
#define FSL_SCB_ACTLR_DISDEFWBUF(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISDEFWBUF_SHIFT))&FSL_SCB_ACTLR_DISDEFWBUF_MASK)
#define FSL_SCB_ACTLR_DISFOLD_MASK               0x4u
#define FSL_SCB_ACTLR_DISFOLD_SHIFT              2u
#define FSL_SCB_ACTLR_DISFOLD_WIDTH              1u
#define FSL_SCB_ACTLR_DISFOLD(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISFOLD_SHIFT))&FSL_SCB_ACTLR_DISFOLD_MASK)
/* CPUID Bit Fields */
#define FSL_SCB_CPUID_REVISION_MASK              0xFu
#define FSL_SCB_CPUID_REVISION_SHIFT             0u
#define FSL_SCB_CPUID_REVISION_WIDTH             4u
#define FSL_SCB_CPUID_REVISION(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_REVISION_SHIFT))&FSL_SCB_CPUID_REVISION_MASK)
#define FSL_SCB_CPUID_PARTNO_MASK                0xFFF0u
#define FSL_SCB_CPUID_PARTNO_SHIFT               4u
#define FSL_SCB_CPUID_PARTNO_WIDTH               12u
#define FSL_SCB_CPUID_PARTNO(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_PARTNO_SHIFT))&FSL_SCB_CPUID_PARTNO_MASK)
#define FSL_SCB_CPUID_VARIANT_MASK               0xF00000u
#define FSL_SCB_CPUID_VARIANT_SHIFT              20u
#define FSL_SCB_CPUID_VARIANT_WIDTH              4u
#define FSL_SCB_CPUID_VARIANT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_VARIANT_SHIFT))&FSL_SCB_CPUID_VARIANT_MASK)
#define FSL_SCB_CPUID_IMPLEMENTER_MASK           0xFF000000u
#define FSL_SCB_CPUID_IMPLEMENTER_SHIFT          24u
#define FSL_SCB_CPUID_IMPLEMENTER_WIDTH          8u
#define FSL_SCB_CPUID_IMPLEMENTER(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_IMPLEMENTER_SHIFT))&FSL_SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define FSL_SCB_ICSR_VECTACTIVE_MASK             0x1FFu
#define FSL_SCB_ICSR_VECTACTIVE_SHIFT            0u
#define FSL_SCB_ICSR_VECTACTIVE_WIDTH            9u
#define FSL_SCB_ICSR_VECTACTIVE(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_VECTACTIVE_SHIFT))&FSL_SCB_ICSR_VECTACTIVE_MASK)
#define FSL_SCB_ICSR_RETTOBASE_MASK              0x800u
#define FSL_SCB_ICSR_RETTOBASE_SHIFT             11u
#define FSL_SCB_ICSR_RETTOBASE_WIDTH             1u
#define FSL_SCB_ICSR_RETTOBASE(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_RETTOBASE_SHIFT))&FSL_SCB_ICSR_RETTOBASE_MASK)
#define FSL_SCB_ICSR_VECTPENDING_MASK            0x3F000u
#define FSL_SCB_ICSR_VECTPENDING_SHIFT           12u
#define FSL_SCB_ICSR_VECTPENDING_WIDTH           6u
#define FSL_SCB_ICSR_VECTPENDING(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_VECTPENDING_SHIFT))&FSL_SCB_ICSR_VECTPENDING_MASK)
#define FSL_SCB_ICSR_ISRPENDING_MASK             0x400000u
#define FSL_SCB_ICSR_ISRPENDING_SHIFT            22u
#define FSL_SCB_ICSR_ISRPENDING_WIDTH            1u
#define FSL_SCB_ICSR_ISRPENDING(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_ISRPENDING_SHIFT))&FSL_SCB_ICSR_ISRPENDING_MASK)
#define FSL_SCB_ICSR_ISRPREEMPT_MASK             0x800000u
#define FSL_SCB_ICSR_ISRPREEMPT_SHIFT            23u
#define FSL_SCB_ICSR_ISRPREEMPT_WIDTH            1u
#define FSL_SCB_ICSR_ISRPREEMPT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_ISRPREEMPT_SHIFT))&FSL_SCB_ICSR_ISRPREEMPT_MASK)
#define FSL_SCB_ICSR_PENDSTCLR_MASK              0x2000000u
#define FSL_SCB_ICSR_PENDSTCLR_SHIFT             25u
#define FSL_SCB_ICSR_PENDSTCLR_WIDTH             1u
#define FSL_SCB_ICSR_PENDSTCLR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSTCLR_SHIFT))&FSL_SCB_ICSR_PENDSTCLR_MASK)
#define FSL_SCB_ICSR_PENDSTSET_MASK              0x4000000u
#define FSL_SCB_ICSR_PENDSTSET_SHIFT             26u
#define FSL_SCB_ICSR_PENDSTSET_WIDTH             1u
#define FSL_SCB_ICSR_PENDSTSET(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSTSET_SHIFT))&FSL_SCB_ICSR_PENDSTSET_MASK)
#define FSL_SCB_ICSR_PENDSVCLR_MASK              0x8000000u
#define FSL_SCB_ICSR_PENDSVCLR_SHIFT             27u
#define FSL_SCB_ICSR_PENDSVCLR_WIDTH             1u
#define FSL_SCB_ICSR_PENDSVCLR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSVCLR_SHIFT))&FSL_SCB_ICSR_PENDSVCLR_MASK)
#define FSL_SCB_ICSR_PENDSVSET_MASK              0x10000000u
#define FSL_SCB_ICSR_PENDSVSET_SHIFT             28u
#define FSL_SCB_ICSR_PENDSVSET_WIDTH             1u
#define FSL_SCB_ICSR_PENDSVSET(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSVSET_SHIFT))&FSL_SCB_ICSR_PENDSVSET_MASK)
#define FSL_SCB_ICSR_NMIPENDSET_MASK             0x80000000u
#define FSL_SCB_ICSR_NMIPENDSET_SHIFT            31u
#define FSL_SCB_ICSR_NMIPENDSET_WIDTH            1u
#define FSL_SCB_ICSR_NMIPENDSET(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_NMIPENDSET_SHIFT))&FSL_SCB_ICSR_NMIPENDSET_MASK)
/* VTOR Bit Fields */
#define FSL_SCB_VTOR_TBLOFF_MASK                 0xFFFFFF80u
#define FSL_SCB_VTOR_TBLOFF_SHIFT                7u
#define FSL_SCB_VTOR_TBLOFF_WIDTH                25u
#define FSL_SCB_VTOR_TBLOFF(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_VTOR_TBLOFF_SHIFT))&FSL_SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define FSL_SCB_AIRCR_VECTRESET_MASK             0x1u
#define FSL_SCB_AIRCR_VECTRESET_SHIFT            0u
#define FSL_SCB_AIRCR_VECTRESET_WIDTH            1u
#define FSL_SCB_AIRCR_VECTRESET(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTRESET_SHIFT))&FSL_SCB_AIRCR_VECTRESET_MASK)
#define FSL_SCB_AIRCR_VECTCLRACTIVE_MASK         0x2u
#define FSL_SCB_AIRCR_VECTCLRACTIVE_SHIFT        1u
#define FSL_SCB_AIRCR_VECTCLRACTIVE_WIDTH        1u
#define FSL_SCB_AIRCR_VECTCLRACTIVE(x)           (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTCLRACTIVE_SHIFT))&FSL_SCB_AIRCR_VECTCLRACTIVE_MASK)
#define FSL_SCB_AIRCR_SYSRESETREQ_MASK           0x4u
#define FSL_SCB_AIRCR_SYSRESETREQ_SHIFT          2u
#define FSL_SCB_AIRCR_SYSRESETREQ_WIDTH          1u
#define FSL_SCB_AIRCR_SYSRESETREQ(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_SYSRESETREQ_SHIFT))&FSL_SCB_AIRCR_SYSRESETREQ_MASK)
#define FSL_SCB_AIRCR_PRIGROUP_MASK              0x700u
#define FSL_SCB_AIRCR_PRIGROUP_SHIFT             8u
#define FSL_SCB_AIRCR_PRIGROUP_WIDTH             3u
#define FSL_SCB_AIRCR_PRIGROUP(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_PRIGROUP_SHIFT))&FSL_SCB_AIRCR_PRIGROUP_MASK)
#define FSL_SCB_AIRCR_ENDIANNESS_MASK            0x8000u
#define FSL_SCB_AIRCR_ENDIANNESS_SHIFT           15u
#define FSL_SCB_AIRCR_ENDIANNESS_WIDTH           1u
#define FSL_SCB_AIRCR_ENDIANNESS(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_ENDIANNESS_SHIFT))&FSL_SCB_AIRCR_ENDIANNESS_MASK)
#define FSL_SCB_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define FSL_SCB_AIRCR_VECTKEY_SHIFT              16u
#define FSL_SCB_AIRCR_VECTKEY_WIDTH              16u
#define FSL_SCB_AIRCR_VECTKEY(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTKEY_SHIFT))&FSL_SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define FSL_SCB_SCR_SLEEPONEXIT_MASK             0x2u
#define FSL_SCB_SCR_SLEEPONEXIT_SHIFT            1u
#define FSL_SCB_SCR_SLEEPONEXIT_WIDTH            1u
#define FSL_SCB_SCR_SLEEPONEXIT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SLEEPONEXIT_SHIFT))&FSL_SCB_SCR_SLEEPONEXIT_MASK)
#define FSL_SCB_SCR_SLEEPDEEP_MASK               0x4u
#define FSL_SCB_SCR_SLEEPDEEP_SHIFT              2u
#define FSL_SCB_SCR_SLEEPDEEP_WIDTH              1u
#define FSL_SCB_SCR_SLEEPDEEP(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SLEEPDEEP_SHIFT))&FSL_SCB_SCR_SLEEPDEEP_MASK)
#define FSL_SCB_SCR_SEVONPEND_MASK               0x10u
#define FSL_SCB_SCR_SEVONPEND_SHIFT              4u
#define FSL_SCB_SCR_SEVONPEND_WIDTH              1u
#define FSL_SCB_SCR_SEVONPEND(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SEVONPEND_SHIFT))&FSL_SCB_SCR_SEVONPEND_MASK)
/* CCR Bit Fields */
#define FSL_SCB_CCR_NONBASETHRDENA_MASK          0x1u
#define FSL_SCB_CCR_NONBASETHRDENA_SHIFT         0u
#define FSL_SCB_CCR_NONBASETHRDENA_WIDTH         1u
#define FSL_SCB_CCR_NONBASETHRDENA(x)            (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_NONBASETHRDENA_SHIFT))&FSL_SCB_CCR_NONBASETHRDENA_MASK)
#define FSL_SCB_CCR_USERSETMPEND_MASK            0x2u
#define FSL_SCB_CCR_USERSETMPEND_SHIFT           1u
#define FSL_SCB_CCR_USERSETMPEND_WIDTH           1u
#define FSL_SCB_CCR_USERSETMPEND(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_USERSETMPEND_SHIFT))&FSL_SCB_CCR_USERSETMPEND_MASK)
#define FSL_SCB_CCR_UNALIGN_TRP_MASK             0x8u
#define FSL_SCB_CCR_UNALIGN_TRP_SHIFT            3u
#define FSL_SCB_CCR_UNALIGN_TRP_WIDTH            1u
#define FSL_SCB_CCR_UNALIGN_TRP(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_UNALIGN_TRP_SHIFT))&FSL_SCB_CCR_UNALIGN_TRP_MASK)
#define FSL_SCB_CCR_DIV_0_TRP_MASK               0x10u
#define FSL_SCB_CCR_DIV_0_TRP_SHIFT              4u
#define FSL_SCB_CCR_DIV_0_TRP_WIDTH              1u
#define FSL_SCB_CCR_DIV_0_TRP(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_DIV_0_TRP_SHIFT))&FSL_SCB_CCR_DIV_0_TRP_MASK)
#define FSL_SCB_CCR_BFHFNMIGN_MASK               0x100u
#define FSL_SCB_CCR_BFHFNMIGN_SHIFT              8u
#define FSL_SCB_CCR_BFHFNMIGN_WIDTH              1u
#define FSL_SCB_CCR_BFHFNMIGN(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_BFHFNMIGN_SHIFT))&FSL_SCB_CCR_BFHFNMIGN_MASK)
#define FSL_SCB_CCR_STKALIGN_MASK                0x200u
#define FSL_SCB_CCR_STKALIGN_SHIFT               9u
#define FSL_SCB_CCR_STKALIGN_WIDTH               1u
#define FSL_SCB_CCR_STKALIGN(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_STKALIGN_SHIFT))&FSL_SCB_CCR_STKALIGN_MASK)
/* SHPR1 Bit Fields */
#define FSL_SCB_SHPR1_PRI_4_MASK                 0xFFu
#define FSL_SCB_SHPR1_PRI_4_SHIFT                0u
#define FSL_SCB_SHPR1_PRI_4_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_4(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_4_SHIFT))&FSL_SCB_SHPR1_PRI_4_MASK)
#define FSL_SCB_SHPR1_PRI_5_MASK                 0xFF00u
#define FSL_SCB_SHPR1_PRI_5_SHIFT                8u
#define FSL_SCB_SHPR1_PRI_5_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_5(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_5_SHIFT))&FSL_SCB_SHPR1_PRI_5_MASK)
#define FSL_SCB_SHPR1_PRI_6_MASK                 0xFF0000u
#define FSL_SCB_SHPR1_PRI_6_SHIFT                16u
#define FSL_SCB_SHPR1_PRI_6_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_6(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_6_SHIFT))&FSL_SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define FSL_SCB_SHPR2_PRI_11_MASK                0xFF000000u
#define FSL_SCB_SHPR2_PRI_11_SHIFT               24u
#define FSL_SCB_SHPR2_PRI_11_WIDTH               8u
#define FSL_SCB_SHPR2_PRI_11(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR2_PRI_11_SHIFT))&FSL_SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define FSL_SCB_SHPR3_PRI_14_MASK                0xFF0000u
#define FSL_SCB_SHPR3_PRI_14_SHIFT               16u
#define FSL_SCB_SHPR3_PRI_14_WIDTH               8u
#define FSL_SCB_SHPR3_PRI_14(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR3_PRI_14_SHIFT))&FSL_SCB_SHPR3_PRI_14_MASK)
#define FSL_SCB_SHPR3_PRI_15_MASK                0xFF000000u
#define FSL_SCB_SHPR3_PRI_15_SHIFT               24u
#define FSL_SCB_SHPR3_PRI_15_WIDTH               8u
#define FSL_SCB_SHPR3_PRI_15(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR3_PRI_15_SHIFT))&FSL_SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define FSL_SCB_SHCSR_MEMFAULTACT_MASK           0x1u
#define FSL_SCB_SHCSR_MEMFAULTACT_SHIFT          0u
#define FSL_SCB_SHCSR_MEMFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_MEMFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTACT_SHIFT))&FSL_SCB_SHCSR_MEMFAULTACT_MASK)
#define FSL_SCB_SHCSR_BUSFAULTACT_MASK           0x2u
#define FSL_SCB_SHCSR_BUSFAULTACT_SHIFT          1u
#define FSL_SCB_SHCSR_BUSFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_BUSFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTACT_SHIFT))&FSL_SCB_SHCSR_BUSFAULTACT_MASK)
#define FSL_SCB_SHCSR_USGFAULTACT_MASK           0x8u
#define FSL_SCB_SHCSR_USGFAULTACT_SHIFT          3u
#define FSL_SCB_SHCSR_USGFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_USGFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTACT_SHIFT))&FSL_SCB_SHCSR_USGFAULTACT_MASK)
#define FSL_SCB_SHCSR_SVCALLACT_MASK             0x80u
#define FSL_SCB_SHCSR_SVCALLACT_SHIFT            7u
#define FSL_SCB_SHCSR_SVCALLACT_WIDTH            1u
#define FSL_SCB_SHCSR_SVCALLACT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SVCALLACT_SHIFT))&FSL_SCB_SHCSR_SVCALLACT_MASK)
#define FSL_SCB_SHCSR_MONITORACT_MASK            0x100u
#define FSL_SCB_SHCSR_MONITORACT_SHIFT           8u
#define FSL_SCB_SHCSR_MONITORACT_WIDTH           1u
#define FSL_SCB_SHCSR_MONITORACT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MONITORACT_SHIFT))&FSL_SCB_SHCSR_MONITORACT_MASK)
#define FSL_SCB_SHCSR_PENDSVACT_MASK             0x400u
#define FSL_SCB_SHCSR_PENDSVACT_SHIFT            10u
#define FSL_SCB_SHCSR_PENDSVACT_WIDTH            1u
#define FSL_SCB_SHCSR_PENDSVACT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_PENDSVACT_SHIFT))&FSL_SCB_SHCSR_PENDSVACT_MASK)
#define FSL_SCB_SHCSR_SYSTICKACT_MASK            0x800u
#define FSL_SCB_SHCSR_SYSTICKACT_SHIFT           11u
#define FSL_SCB_SHCSR_SYSTICKACT_WIDTH           1u
#define FSL_SCB_SHCSR_SYSTICKACT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SYSTICKACT_SHIFT))&FSL_SCB_SHCSR_SYSTICKACT_MASK)
#define FSL_SCB_SHCSR_USGFAULTPENDED_MASK        0x1000u
#define FSL_SCB_SHCSR_USGFAULTPENDED_SHIFT       12u
#define FSL_SCB_SHCSR_USGFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_USGFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_USGFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_MEMFAULTPENDED_MASK        0x2000u
#define FSL_SCB_SHCSR_MEMFAULTPENDED_SHIFT       13u
#define FSL_SCB_SHCSR_MEMFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_MEMFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_MEMFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_BUSFAULTPENDED_MASK        0x4000u
#define FSL_SCB_SHCSR_BUSFAULTPENDED_SHIFT       14u
#define FSL_SCB_SHCSR_BUSFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_BUSFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_BUSFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_SVCALLPENDED_MASK          0x8000u
#define FSL_SCB_SHCSR_SVCALLPENDED_SHIFT         15u
#define FSL_SCB_SHCSR_SVCALLPENDED_WIDTH         1u
#define FSL_SCB_SHCSR_SVCALLPENDED(x)            (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SVCALLPENDED_SHIFT))&FSL_SCB_SHCSR_SVCALLPENDED_MASK)
#define FSL_SCB_SHCSR_MEMFAULTENA_MASK           0x10000u
#define FSL_SCB_SHCSR_MEMFAULTENA_SHIFT          16u
#define FSL_SCB_SHCSR_MEMFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_MEMFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTENA_SHIFT))&FSL_SCB_SHCSR_MEMFAULTENA_MASK)
#define FSL_SCB_SHCSR_BUSFAULTENA_MASK           0x20000u
#define FSL_SCB_SHCSR_BUSFAULTENA_SHIFT          17u
#define FSL_SCB_SHCSR_BUSFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_BUSFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTENA_SHIFT))&FSL_SCB_SHCSR_BUSFAULTENA_MASK)
#define FSL_SCB_SHCSR_USGFAULTENA_MASK           0x40000u
#define FSL_SCB_SHCSR_USGFAULTENA_SHIFT          18u
#define FSL_SCB_SHCSR_USGFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_USGFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTENA_SHIFT))&FSL_SCB_SHCSR_USGFAULTENA_MASK)
/* CFSR Bit Fields */
#define FSL_SCB_CFSR_IACCVIOL_MASK               0x1u
#define FSL_SCB_CFSR_IACCVIOL_SHIFT              0u
#define FSL_SCB_CFSR_IACCVIOL_WIDTH              1u
#define FSL_SCB_CFSR_IACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IACCVIOL_SHIFT))&FSL_SCB_CFSR_IACCVIOL_MASK)
#define FSL_SCB_CFSR_DACCVIOL_MASK               0x2u
#define FSL_SCB_CFSR_DACCVIOL_SHIFT              1u
#define FSL_SCB_CFSR_DACCVIOL_WIDTH              1u
#define FSL_SCB_CFSR_DACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_DACCVIOL_SHIFT))&FSL_SCB_CFSR_DACCVIOL_MASK)
#define FSL_SCB_CFSR_MUNSTKERR_MASK              0x8u
#define FSL_SCB_CFSR_MUNSTKERR_SHIFT             3u
#define FSL_SCB_CFSR_MUNSTKERR_WIDTH             1u
#define FSL_SCB_CFSR_MUNSTKERR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MUNSTKERR_SHIFT))&FSL_SCB_CFSR_MUNSTKERR_MASK)
#define FSL_SCB_CFSR_MSTKERR_MASK                0x10u
#define FSL_SCB_CFSR_MSTKERR_SHIFT               4u
#define FSL_SCB_CFSR_MSTKERR_WIDTH               1u
#define FSL_SCB_CFSR_MSTKERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MSTKERR_SHIFT))&FSL_SCB_CFSR_MSTKERR_MASK)
#define FSL_SCB_CFSR_MLSPERR_MASK                0x20u
#define FSL_SCB_CFSR_MLSPERR_SHIFT               5u
#define FSL_SCB_CFSR_MLSPERR_WIDTH               1u
#define FSL_SCB_CFSR_MLSPERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MLSPERR_SHIFT))&FSL_SCB_CFSR_MLSPERR_MASK)
#define FSL_SCB_CFSR_MMARVALID_MASK              0x80u
#define FSL_SCB_CFSR_MMARVALID_SHIFT             7u
#define FSL_SCB_CFSR_MMARVALID_WIDTH             1u
#define FSL_SCB_CFSR_MMARVALID(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MMARVALID_SHIFT))&FSL_SCB_CFSR_MMARVALID_MASK)
#define FSL_SCB_CFSR_IBUSERR_MASK                0x100u
#define FSL_SCB_CFSR_IBUSERR_SHIFT               8u
#define FSL_SCB_CFSR_IBUSERR_WIDTH               1u
#define FSL_SCB_CFSR_IBUSERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IBUSERR_SHIFT))&FSL_SCB_CFSR_IBUSERR_MASK)
#define FSL_SCB_CFSR_PRECISERR_MASK              0x200u
#define FSL_SCB_CFSR_PRECISERR_SHIFT             9u
#define FSL_SCB_CFSR_PRECISERR_WIDTH             1u
#define FSL_SCB_CFSR_PRECISERR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_PRECISERR_SHIFT))&FSL_SCB_CFSR_PRECISERR_MASK)
#define FSL_SCB_CFSR_IMPRECISERR_MASK            0x400u
#define FSL_SCB_CFSR_IMPRECISERR_SHIFT           10u
#define FSL_SCB_CFSR_IMPRECISERR_WIDTH           1u
#define FSL_SCB_CFSR_IMPRECISERR(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IMPRECISERR_SHIFT))&FSL_SCB_CFSR_IMPRECISERR_MASK)
#define FSL_SCB_CFSR_UNSTKERR_MASK               0x800u
#define FSL_SCB_CFSR_UNSTKERR_SHIFT              11u
#define FSL_SCB_CFSR_UNSTKERR_WIDTH              1u
#define FSL_SCB_CFSR_UNSTKERR(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNSTKERR_SHIFT))&FSL_SCB_CFSR_UNSTKERR_MASK)
#define FSL_SCB_CFSR_STKERR_MASK                 0x1000u
#define FSL_SCB_CFSR_STKERR_SHIFT                12u
#define FSL_SCB_CFSR_STKERR_WIDTH                1u
#define FSL_SCB_CFSR_STKERR(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_STKERR_SHIFT))&FSL_SCB_CFSR_STKERR_MASK)
#define FSL_SCB_CFSR_LSPERR_MASK                 0x2000u
#define FSL_SCB_CFSR_LSPERR_SHIFT                13u
#define FSL_SCB_CFSR_LSPERR_WIDTH                1u
#define FSL_SCB_CFSR_LSPERR(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_LSPERR_SHIFT))&FSL_SCB_CFSR_LSPERR_MASK)
#define FSL_SCB_CFSR_BFARVALID_MASK              0x8000u
#define FSL_SCB_CFSR_BFARVALID_SHIFT             15u
#define FSL_SCB_CFSR_BFARVALID_WIDTH             1u
#define FSL_SCB_CFSR_BFARVALID(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_BFARVALID_SHIFT))&FSL_SCB_CFSR_BFARVALID_MASK)
#define FSL_SCB_CFSR_UNDEFINSTR_MASK             0x10000u
#define FSL_SCB_CFSR_UNDEFINSTR_SHIFT            16u
#define FSL_SCB_CFSR_UNDEFINSTR_WIDTH            1u
#define FSL_SCB_CFSR_UNDEFINSTR(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNDEFINSTR_SHIFT))&FSL_SCB_CFSR_UNDEFINSTR_MASK)
#define FSL_SCB_CFSR_INVSTATE_MASK               0x20000u
#define FSL_SCB_CFSR_INVSTATE_SHIFT              17u
#define FSL_SCB_CFSR_INVSTATE_WIDTH              1u
#define FSL_SCB_CFSR_INVSTATE(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_INVSTATE_SHIFT))&FSL_SCB_CFSR_INVSTATE_MASK)
#define FSL_SCB_CFSR_INVPC_MASK                  0x40000u
#define FSL_SCB_CFSR_INVPC_SHIFT                 18u
#define FSL_SCB_CFSR_INVPC_WIDTH                 1u
#define FSL_SCB_CFSR_INVPC(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_INVPC_SHIFT))&FSL_SCB_CFSR_INVPC_MASK)
#define FSL_SCB_CFSR_NOCP_MASK                   0x80000u
#define FSL_SCB_CFSR_NOCP_SHIFT                  19u
#define FSL_SCB_CFSR_NOCP_WIDTH                  1u
#define FSL_SCB_CFSR_NOCP(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_NOCP_SHIFT))&FSL_SCB_CFSR_NOCP_MASK)
#define FSL_SCB_CFSR_UNALIGNED_MASK              0x1000000u
#define FSL_SCB_CFSR_UNALIGNED_SHIFT             24u
#define FSL_SCB_CFSR_UNALIGNED_WIDTH             1u
#define FSL_SCB_CFSR_UNALIGNED(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNALIGNED_SHIFT))&FSL_SCB_CFSR_UNALIGNED_MASK)
#define FSL_SCB_CFSR_DIVBYZERO_MASK              0x2000000u
#define FSL_SCB_CFSR_DIVBYZERO_SHIFT             25u
#define FSL_SCB_CFSR_DIVBYZERO_WIDTH             1u
#define FSL_SCB_CFSR_DIVBYZERO(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_DIVBYZERO_SHIFT))&FSL_SCB_CFSR_DIVBYZERO_MASK)
/* HFSR Bit Fields */
#define FSL_SCB_HFSR_VECTTBL_MASK                0x2u
#define FSL_SCB_HFSR_VECTTBL_SHIFT               1u
#define FSL_SCB_HFSR_VECTTBL_WIDTH               1u
#define FSL_SCB_HFSR_VECTTBL(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_VECTTBL_SHIFT))&FSL_SCB_HFSR_VECTTBL_MASK)
#define FSL_SCB_HFSR_FORCED_MASK                 0x40000000u
#define FSL_SCB_HFSR_FORCED_SHIFT                30u
#define FSL_SCB_HFSR_FORCED_WIDTH                1u
#define FSL_SCB_HFSR_FORCED(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_FORCED_SHIFT))&FSL_SCB_HFSR_FORCED_MASK)
#define FSL_SCB_HFSR_DEBUGEVT_MASK               0x80000000u
#define FSL_SCB_HFSR_DEBUGEVT_SHIFT              31u
#define FSL_SCB_HFSR_DEBUGEVT_WIDTH              1u
#define FSL_SCB_HFSR_DEBUGEVT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_DEBUGEVT_SHIFT))&FSL_SCB_HFSR_DEBUGEVT_MASK)
/* DFSR Bit Fields */
#define FSL_SCB_DFSR_HALTED_MASK                 0x1u
#define FSL_SCB_DFSR_HALTED_SHIFT                0u
#define FSL_SCB_DFSR_HALTED_WIDTH                1u
#define FSL_SCB_DFSR_HALTED(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_HALTED_SHIFT))&FSL_SCB_DFSR_HALTED_MASK)
#define FSL_SCB_DFSR_BKPT_MASK                   0x2u
#define FSL_SCB_DFSR_BKPT_SHIFT                  1u
#define FSL_SCB_DFSR_BKPT_WIDTH                  1u
#define FSL_SCB_DFSR_BKPT(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_BKPT_SHIFT))&FSL_SCB_DFSR_BKPT_MASK)
#define FSL_SCB_DFSR_DWTTRAP_MASK                0x4u
#define FSL_SCB_DFSR_DWTTRAP_SHIFT               2u
#define FSL_SCB_DFSR_DWTTRAP_WIDTH               1u
#define FSL_SCB_DFSR_DWTTRAP(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_DWTTRAP_SHIFT))&FSL_SCB_DFSR_DWTTRAP_MASK)
#define FSL_SCB_DFSR_VCATCH_MASK                 0x8u
#define FSL_SCB_DFSR_VCATCH_SHIFT                3u
#define FSL_SCB_DFSR_VCATCH_WIDTH                1u
#define FSL_SCB_DFSR_VCATCH(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_VCATCH_SHIFT))&FSL_SCB_DFSR_VCATCH_MASK)
#define FSL_SCB_DFSR_EXTERNAL_MASK               0x10u
#define FSL_SCB_DFSR_EXTERNAL_SHIFT              4u
#define FSL_SCB_DFSR_EXTERNAL_WIDTH              1u
#define FSL_SCB_DFSR_EXTERNAL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_EXTERNAL_SHIFT))&FSL_SCB_DFSR_EXTERNAL_MASK)
/* MMFAR Bit Fields */
#define FSL_SCB_MMFAR_ADDRESS_MASK               0xFFFFFFFFu
#define FSL_SCB_MMFAR_ADDRESS_SHIFT              0u
#define FSL_SCB_MMFAR_ADDRESS_WIDTH              32u
#define FSL_SCB_MMFAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_MMFAR_ADDRESS_SHIFT))&FSL_SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define FSL_SCB_BFAR_ADDRESS_MASK                0xFFFFFFFFu
#define FSL_SCB_BFAR_ADDRESS_SHIFT               0u
#define FSL_SCB_BFAR_ADDRESS_WIDTH               32u
#define FSL_SCB_BFAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_BFAR_ADDRESS_SHIFT))&FSL_SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define FSL_SCB_AFSR_AUXFAULT_MASK               0xFFFFFFFFu
#define FSL_SCB_AFSR_AUXFAULT_SHIFT              0u
#define FSL_SCB_AFSR_AUXFAULT_WIDTH              32u
#define FSL_SCB_AFSR_AUXFAULT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AFSR_AUXFAULT_SHIFT))&FSL_SCB_AFSR_AUXFAULT_MASK)
/* CPACR Bit Fields */
#define FSL_SCB_CPACR_CP10_MASK                  0x300000u
#define FSL_SCB_CPACR_CP10_SHIFT                 20u
#define FSL_SCB_CPACR_CP10_WIDTH                 2u
#define FSL_SCB_CPACR_CP10(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPACR_CP10_SHIFT))&FSL_SCB_CPACR_CP10_MASK)
#define FSL_SCB_CPACR_CP11_MASK                  0xC00000u
#define FSL_SCB_CPACR_CP11_SHIFT                 22u
#define FSL_SCB_CPACR_CP11_WIDTH                 2u
#define FSL_SCB_CPACR_CP11(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPACR_CP11_SHIFT))&FSL_SCB_CPACR_CP11_MASK)
/* FPCCR Bit Fields */
#define FSL_SCB_FPCCR_LSPACT_MASK                0x1u
#define FSL_SCB_FPCCR_LSPACT_SHIFT               0u
#define FSL_SCB_FPCCR_LSPACT_WIDTH               1u
#define FSL_SCB_FPCCR_LSPACT(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_LSPACT_SHIFT))&FSL_SCB_FPCCR_LSPACT_MASK)
#define FSL_SCB_FPCCR_USER_MASK                  0x2u
#define FSL_SCB_FPCCR_USER_SHIFT                 1u
#define FSL_SCB_FPCCR_USER_WIDTH                 1u
#define FSL_SCB_FPCCR_USER(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_USER_SHIFT))&FSL_SCB_FPCCR_USER_MASK)
#define FSL_SCB_FPCCR_THREAD_MASK                0x8u
#define FSL_SCB_FPCCR_THREAD_SHIFT               3u
#define FSL_SCB_FPCCR_THREAD_WIDTH               1u
#define FSL_SCB_FPCCR_THREAD(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_THREAD_SHIFT))&FSL_SCB_FPCCR_THREAD_MASK)
#define FSL_SCB_FPCCR_HFRDY_MASK                 0x10u
#define FSL_SCB_FPCCR_HFRDY_SHIFT                4u
#define FSL_SCB_FPCCR_HFRDY_WIDTH                1u
#define FSL_SCB_FPCCR_HFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_HFRDY_SHIFT))&FSL_SCB_FPCCR_HFRDY_MASK)
#define FSL_SCB_FPCCR_MMRDY_MASK                 0x20u
#define FSL_SCB_FPCCR_MMRDY_SHIFT                5u
#define FSL_SCB_FPCCR_MMRDY_WIDTH                1u
#define FSL_SCB_FPCCR_MMRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_MMRDY_SHIFT))&FSL_SCB_FPCCR_MMRDY_MASK)
#define FSL_SCB_FPCCR_BFRDY_MASK                 0x40u
#define FSL_SCB_FPCCR_BFRDY_SHIFT                6u
#define FSL_SCB_FPCCR_BFRDY_WIDTH                1u
#define FSL_SCB_FPCCR_BFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_BFRDY_SHIFT))&FSL_SCB_FPCCR_BFRDY_MASK)
#define FSL_SCB_FPCCR_MONRDY_MASK                0x100u
#define FSL_SCB_FPCCR_MONRDY_SHIFT               8u
#define FSL_SCB_FPCCR_MONRDY_WIDTH               1u
#define FSL_SCB_FPCCR_MONRDY(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_MONRDY_SHIFT))&FSL_SCB_FPCCR_MONRDY_MASK)
#define FSL_SCB_FPCCR_LSPEN_MASK                 0x40000000u
#define FSL_SCB_FPCCR_LSPEN_SHIFT                30u
#define FSL_SCB_FPCCR_LSPEN_WIDTH                1u
#define FSL_SCB_FPCCR_LSPEN(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_LSPEN_SHIFT))&FSL_SCB_FPCCR_LSPEN_MASK)
#define FSL_SCB_FPCCR_ASPEN_MASK                 0x80000000u
#define FSL_SCB_FPCCR_ASPEN_SHIFT                31u
#define FSL_SCB_FPCCR_ASPEN_WIDTH                1u
#define FSL_SCB_FPCCR_ASPEN(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_ASPEN_SHIFT))&FSL_SCB_FPCCR_ASPEN_MASK)
/* FPCAR Bit Fields */
#define FSL_SCB_FPCAR_ADDRESS_MASK               0xFFFFFFF8u
#define FSL_SCB_FPCAR_ADDRESS_SHIFT              3u
#define FSL_SCB_FPCAR_ADDRESS_WIDTH              29u
#define FSL_SCB_FPCAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCAR_ADDRESS_SHIFT))&FSL_SCB_FPCAR_ADDRESS_MASK)
/* FPDSCR Bit Fields */
#define FSL_SCB_FPDSCR_RMode_MASK                0xC00000u
#define FSL_SCB_FPDSCR_RMode_SHIFT               22u
#define FSL_SCB_FPDSCR_RMode_WIDTH               2u
#define FSL_SCB_FPDSCR_RMode(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_RMode_SHIFT))&FSL_SCB_FPDSCR_RMode_MASK)
#define FSL_SCB_FPDSCR_FZ_MASK                   0x1000000u
#define FSL_SCB_FPDSCR_FZ_SHIFT                  24u
#define FSL_SCB_FPDSCR_FZ_WIDTH                  1u
#define FSL_SCB_FPDSCR_FZ(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_FZ_SHIFT))&FSL_SCB_FPDSCR_FZ_MASK)
#define FSL_SCB_FPDSCR_DN_MASK                   0x2000000u
#define FSL_SCB_FPDSCR_DN_SHIFT                  25u
#define FSL_SCB_FPDSCR_DN_WIDTH                  1u
#define FSL_SCB_FPDSCR_DN(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_DN_SHIFT))&FSL_SCB_FPDSCR_DN_MASK)
#define FSL_SCB_FPDSCR_AHP_MASK                  0x4000000u
#define FSL_SCB_FPDSCR_AHP_SHIFT                 26u
#define FSL_SCB_FPDSCR_AHP_WIDTH                 1u
#define FSL_SCB_FPDSCR_AHP(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_AHP_SHIFT))&FSL_SCB_FPDSCR_AHP_MASK)

/*!
 * @}
 */ /* end of group FSL_SCB_Register_Masks */



/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#else /* #if !defined(MKL46Z4_H) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0200u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0200u) */
#endif  /* #if !defined(MKL46Z4_H) */

