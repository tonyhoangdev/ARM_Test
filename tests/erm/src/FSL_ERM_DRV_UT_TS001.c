/************************************************************************
 (c) Copyright 2016 Freescale Semiconductor, Inc.
 Copyright 2016 NXP
 ALL RIGHTS RESERVED.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 Neither the name of the <organization> nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/**************************************************************************
 *                                                                        *
 *                           ERM Driver For S32SDK                        *
 *                                                                        *
 * FILE NAME     :  FSL_ERM_DRV_UT_TS001.h                                *
 * DATE          :  Aug 31, 2016                                          *
 *                                                                        *
 * AUTHOR        :  Minh Hoang                                            *
 * E-mail        :  minh.hoang@nxp.com                                    *
 *                                                                        *
 *************************************************************************/

/************************** CHANGES ***************************************
 0.1.0       31.08.2016      Minh Hoang        Initial Versions
 *************************************************************************/

#include "FSL_ERM_DRV_UT_TS001.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
static ERM_Type * const g_ermBase[] = ERM_BASE_PTRS;

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Device instance number */
#define FSL_ERM1 (0U)

/* The number of configured channel(s) */
#define ERM_NUM_OF_CFG_CHANNEL  (2U)

/* Interrupt configuration 0 */
const erm_interrupt_config_t erm1_Interrupt1 =
{
    .enableSingleCorrection = false,        /*!< Single correction interrupt disabled        */
    .enableNonCorrectable   = true,         /*!< Non-correctable error interrupt enabled     */
};

/* Interrupt configuration 1 */
const erm_interrupt_config_t erm1_Interrupt3 =
{
    .enableSingleCorrection = true,         /*!< Single correction interrupt enabled         */
    .enableNonCorrectable   = true,         /*!< Non-correctable error interrupt enabled     */
};

/* User configuration */
const erm_user_config_t erm1_InitConfig[] =
{
    /* Channel 0U */
    {
        .channel      = 0U,
        .interruptCfg = &erm1_Interrupt1,
    },

    /* Channel 1U */
    {
        .channel      = 1U,
        .interruptCfg = &erm1_Interrupt3,
    }
};

/*******************************************************************************
 * Local functions
 ******************************************************************************/
/* Test function for ERM_DRV_Init and ERM_DRV_SetInterruptConfig */
erm_drv_test_result_t ERM_DRV_TEST_Init()
{
    uint8_t i;

    /* Call function */
    ERM_DRV_Init(FSL_ERM1, ERM_NUM_OF_CFG_CHANNEL, erm1_InitConfig);

    /* Check result */
    for (i = 0U; i < ERM_NUM_OF_CFG_CHANNEL; i++)
    {
        if (ERM_IsEventInterruptEnabled(g_ermBase[FSL_ERM1], erm1_InitConfig[i].channel, ERM_EVENT_SINGLE_BIT) !=
            ((*erm1_InitConfig[i].interruptCfg).enableSingleCorrection))
        {
            return ERM_DRV_TEST_FAILED;
        }

        if (ERM_IsEventInterruptEnabled(g_ermBase[FSL_ERM1], erm1_InitConfig[i].channel, ERM_EVENT_NON_CORRECTABLE) !=
            ((*erm1_InitConfig[i].interruptCfg).enableNonCorrectable))
        {
            return ERM_DRV_TEST_FAILED;
        }
    }

    return ERM_DRV_TEST_PASSED;
}

/* Test function for ERM_DRV_Deinit */
erm_drv_test_result_t ERM_DRV_TEST_Deinit()
{
    /* Call function */
    ERM_DRV_Deinit(FSL_ERM1);

    /* Check registers */
    if (g_ermBase[FSL_ERM1]->CR0 != 0UL)
    {
        return ERM_DRV_TEST_FAILED;
    }

    if (g_ermBase[FSL_ERM1]->SR0 != 0UL)
    {
        return ERM_DRV_TEST_FAILED;
    }

    return ERM_DRV_TEST_PASSED;
}

/* Test function for ERM_DRV_GetInterruptConfig */
erm_drv_test_result_t ERM_DRV_TEST_GetInterruptConfig()
{
    uint8_t i;
    erm_interrupt_config_t interruptPtr;

    /* Call function */
    ERM_DRV_Init(FSL_ERM1, ERM_NUM_OF_CFG_CHANNEL, erm1_InitConfig);

    /* Check result */
    for (i = 0U; i < ERM_NUM_OF_CFG_CHANNEL; i++)
    {
        ERM_DRV_GetInterruptConfig(FSL_ERM1, erm1_InitConfig[i].channel, &interruptPtr);

        if (interruptPtr.enableNonCorrectable != (*erm1_InitConfig[i].interruptCfg).enableNonCorrectable)
        {
            return ERM_DRV_TEST_FAILED;
        }

        if (interruptPtr.enableSingleCorrection != (*erm1_InitConfig[i].interruptCfg).enableSingleCorrection)
        {
            return ERM_DRV_TEST_FAILED;
        }
    }

    return ERM_DRV_TEST_PASSED;
}

/* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Single-bit correction */
erm_drv_test_result_t ERM_DRV_TEST_GetErrorDetail_SEC()
{
    uint32_t address;
    uint32_t read;
    volatile uint32_t testAddress = 0x55U;
    erm_ecc_event_t eccEvent;

    /* Call function */
    ERM_DRV_Init(FSL_ERM1, ERM_NUM_OF_CFG_CHANNEL, erm1_InitConfig);

    /* Call EIM */
    EIM->EICHEN = EIM_EICHEN_EICH1EN(0U);
    EIM->EICHDn[1].WORD0 = EIM_EICHDn_WORD0_CHKBIT_MASK(0U);
    EIM->EICHDn[1].WORD1 = 1U;
    EIM->EICHEN = EIM_EICHEN_EICH1EN(1U);
    EIM->EIMCR = EIM_EIMCR_GEIEN(1U);

    /* Read memory RAM */
    read = testAddress;
    (void)read;

    /* Disable */
    EIM->EIMCR = EIM_EIMCR_GEIEN(0U);

    /* Get detail */
    eccEvent = ERM_DRV_GetErrorDetail(FSL_ERM1, 1U, &address);

    if (eccEvent != ERM_EVENT_SINGLE_BIT)
    {
        return ERM_DRV_TEST_FAILED;
    }

    if (address != (uint32_t)&testAddress)
    {
        return ERM_DRV_TEST_FAILED;
    }

    /* Clears the event for channel 1 */
    ERM_DRV_ClearEvent(FSL_ERM1, 1U, ERM_EVENT_SINGLE_BIT);

    if (ERM_IsEventDetected(g_ermBase[FSL_ERM1], 1U, ERM_EVENT_SINGLE_BIT) != false)
    {
        return ERM_DRV_TEST_FAILED;
    }

    return ERM_DRV_TEST_PASSED;
}

/* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Non-correctable */
erm_drv_test_result_t ERM_DRV_TEST_GetErrorDetail_DEC()
{
    uint32_t address;
    uint32_t read;
    volatile uint32_t testAddress = 0x55U;
    erm_ecc_event_t eccEvent;

    /* Call function */
    ERM_DRV_Init(FSL_ERM1, ERM_NUM_OF_CFG_CHANNEL, erm1_InitConfig);

    /* Call EIM */
    EIM->EICHEN = EIM_EICHEN_EICH1EN(0U);
    EIM->EICHDn[1].WORD0 = EIM_EICHDn_WORD0_CHKBIT_MASK(0U);
    EIM->EICHDn[1].WORD1 = 3U;
    EIM->EICHEN = EIM_EICHEN_EICH1EN(1U);
    EIM->EIMCR = EIM_EIMCR_GEIEN(1U);

    /* Read memory RAM */
    read = testAddress;
    (void)read;

    /* Disable */
    EIM->EIMCR = EIM_EIMCR_GEIEN(0U);

    /* Get detail */
    eccEvent = ERM_DRV_GetErrorDetail(FSL_ERM1, 1U, &address);

    if (eccEvent != ERM_EVENT_NON_CORRECTABLE)
    {
        return ERM_DRV_TEST_FAILED;
    }

    if (address != (uint32_t)&testAddress)
    {
        return ERM_DRV_TEST_FAILED;
    }

    /* Clears the event for channel 1 */
    ERM_DRV_ClearEvent(FSL_ERM1, 1U, ERM_EVENT_NON_CORRECTABLE);

    if (ERM_IsEventDetected(g_ermBase[FSL_ERM1], 1U, ERM_EVENT_NON_CORRECTABLE) != false)
    {
        return ERM_DRV_TEST_FAILED;
    }

    return ERM_DRV_TEST_PASSED;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
