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
 *                           ERM HAL For S32SDK                           *
 *                                                                        *
 * FILE NAME     :  FSL_ERM_HAL_UT_TS001.c                                *
 * DATE          :  Aug 31, 2016                                          *
 *                                                                        *
 * AUTHOR        :  Minh Hoang                                            *
 * E-mail        :  minh.hoang@nxp.com                                    *
 *                                                                        *
 *************************************************************************/

/************************** CHANGES ***************************************
 0.1.0       31.08.2016      Minh Hoang        Initial Versions
 *************************************************************************/

#include "FSL_ERM_HAL_UT_TS001.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
ERM_Type * const g_ermBase0 = ERM;

/*******************************************************************************
 * Local functions
 ******************************************************************************/
/* Test for initialize the ERM module */
erm_hal_test_result_t ERM_HAL_TEST_Init(void)
{
    /* Call function */
    ERM_HAL_Init(g_ermBase0);

    /* Check registers */
    if (g_ermBase0->CR0 != 0UL)
    {
        return ERM_HAL_TEST_FAILED;
    }

    if (g_ermBase0->SR0 != 0UL)
    {
        return ERM_HAL_TEST_FAILED;
    }

    return ERM_HAL_TEST_PASSED;
}

/* Test for enable Memory n interrupt event and check it */
erm_hal_test_result_t ERM_HAL_TEST_EventInterrupt(void)
{
    uint8_t i, j;
    uint8_t channels = 2U;
    uint8_t enables = 2U;

    for (i = 0; i < channels; i++)
    {
        for (j = 0; j < enables; j++)
        {
            /* Call function with ERM_EVENT_SINGLE_BIT */
            ERM_HAL_EnableEventInterrupt(g_ermBase0, i, ERM_EVENT_SINGLE_BIT, (bool)j);
            /* Check result */
            if ((g_ermBase0->CR0 & ERM_SBC(i, j)) != ERM_SBC(i, j))
            {
                return ERM_HAL_TEST_FAILED;
            }
            /* Check is enable */
            if (ERM_HAL_IsEventInterruptEnabled(g_ermBase0, i, ERM_EVENT_SINGLE_BIT) != (bool)j)
            {
                return ERM_HAL_TEST_FAILED;
            }

            /* Call function with ERM_EVENT_NON_CORRECTABLE */
            ERM_HAL_EnableEventInterrupt(g_ermBase0, i, ERM_EVENT_NON_CORRECTABLE, (bool)j);
            /* Check result */
            if ((g_ermBase0->CR0 & ERM_NCE(i, j)) != ERM_NCE(i, j))
            {
                return ERM_HAL_TEST_FAILED;
            }
            /* Check is enable  */
            if (ERM_HAL_IsEventInterruptEnabled(g_ermBase0, i, ERM_EVENT_NON_CORRECTABLE) != (bool)j)
            {
                return ERM_HAL_TEST_FAILED;
            }
        }
    }

    return ERM_HAL_TEST_PASSED;
}

/* Test for get the address of the last ECC event in Memory n and ECC event with Single-bit correction */
erm_hal_test_result_t ERM_HAL_TEST_GetErrorDetail_SEC(void)
{
    uint32_t address;
    uint32_t read;
    uint32_t testAddress = 0x55U;
    erm_ecc_event_t eccEvent;

    /* Call function */
    ERM_HAL_Init(g_ermBase0);

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
    eccEvent = ERM_HAL_GetErrorDetail(g_ermBase0, 1U, &address);

    if (eccEvent != ERM_EVENT_SINGLE_BIT)
    {
        return ERM_HAL_TEST_FAILED;
    }

    if (address != (uint32_t)&testAddress)
    {
        return ERM_HAL_TEST_FAILED;
    }

    /* Clears the event for channel 1 */
    ERM_HAL_ClearEvent(g_ermBase0, 1U, ERM_EVENT_SINGLE_BIT);

    if (ERM_HAL_IsEventDetected(g_ermBase0, 1U, ERM_EVENT_SINGLE_BIT) != false)
    {
        return ERM_HAL_TEST_FAILED;
    };

    return ERM_HAL_TEST_PASSED;
}

/* Test for get the address of the last ECC event in Memory n and ECC event with Non-correctable */
erm_hal_test_result_t ERM_HAL_TEST_GetErrorDetail_DEC(void)
{
    uint32_t address;
    uint32_t read;
    uint32_t testAddress = 0x55U;
    erm_ecc_event_t eccEvent;

    /* Call function */
    ERM_HAL_Init(g_ermBase0);

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
    eccEvent = ERM_HAL_GetErrorDetail(g_ermBase0, 1U, &address);

    if (eccEvent != ERM_EVENT_NON_CORRECTABLE)
    {
        return ERM_HAL_TEST_FAILED;
    }

    if (address != (uint32_t)&testAddress)
    {
        return ERM_HAL_TEST_FAILED;
    }

    /* Clears the event for channel 1 */
    ERM_HAL_ClearEvent(g_ermBase0, 1U, ERM_EVENT_NON_CORRECTABLE);

    if (ERM_HAL_IsEventDetected(g_ermBase0, 1U, ERM_EVENT_NON_CORRECTABLE) != false)
    {
        return ERM_HAL_TEST_FAILED;
    };

    return ERM_HAL_TEST_PASSED;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
