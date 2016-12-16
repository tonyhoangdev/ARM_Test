/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * LOSS OF USE, DATA, OR PROFITS, OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "FSL_ERM_DRV_UT_TS001.h"
#include "FSL_ERM_HAL_UT_TS001.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NUMBER_OF_TEST_CASE_DRV 5U
#define NUMBER_OF_TEST_CASE_HAL 4U

/*******************************************************************************
 * erm_test
 ******************************************************************************/
int erm_test_start(void)
{
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
    PORTD->PCR[15] |= PORT_PCR_MUX(1);
    PORTD->PCR[16] |= PORT_PCR_MUX(1);
    PTD->PDDR |= 1 << 15 | 1 << 16;
    PTD->PCOR |= 1 << 15;
    PTD->PSOR |= 1 << 16;

    /* Index 0 for final result */
    /* Index form 1 to end for each test case */
    erm_hal_test_result_t result_hal[NUMBER_OF_TEST_CASE_HAL + 1U] = { ERM_HAL_TEST_PASSED };
    erm_drv_test_result_t result_drv[NUMBER_OF_TEST_CASE_DRV + 1U] = { ERM_DRV_TEST_PASSED };
    /* Variable count */
    uint32_t i = 1U;
    uint32_t j = 1U;

    /******************************** Test for HAL ****************************/
    /* Test for initialize the ERM module */
    result_hal[1U] = ERM_HAL_TEST_Init();
    /* Test for enable Memory n interrupt event and check it */
    result_hal[2U] = ERM_HAL_TEST_EventInterrupt();
    // /* Test for get the address of the last ECC event in Memory n and ECC event with Single-bit correction */
    // result_hal[3U] = ERM_HAL_TEST_GetErrorDetail_SEC();
    // /* Test for get the address of the last ECC event in Memory n and ECC event with Non-correctable */
    // result_hal[4U] = ERM_HAL_TEST_GetErrorDetail_DEC();

    /******************************** Test for DRV ****************************/
    /* Test function for ERM_DRV_Init and ERM_DRV_SetInterruptConfig */
    result_drv[1U] |= ERM_DRV_TEST_Init();
    /* Test function for ERM_DRV_Deinit */
    result_drv[2U] |= ERM_DRV_TEST_Deinit();
    /* Test function for ERM_DRV_GetInterruptConfig */
    result_drv[3U] |= ERM_DRV_TEST_GetInterruptConfig();
    // /* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Single-bit correction */
    // result_drv[4U] |= ERM_DRV_TEST_GetErrorDetail_SEC();
    // /* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Non-correctable */
    // result_drv[5U] |= ERM_DRV_TEST_GetErrorDetail_DEC();

    /******************************** Check result ****************************/
    /* Check HAL result */
    for (i = 1U; i <= NUMBER_OF_TEST_CASE_HAL; i++)
    {
        if (result_hal[i] == ERM_HAL_TEST_FAILED)
        {
            result_hal[0] = ERM_HAL_TEST_FAILED;
            break;
        }
    }

    /* Check DRV result */
    for (j = 1U; j <= NUMBER_OF_TEST_CASE_DRV; j++)
    {
        if (result_drv[j] == ERM_DRV_TEST_FAILED)
        {
            result_drv[0] = ERM_DRV_TEST_FAILED;
            break;
        }
    }

    /* Exit condition */
    if (result_hal[0] | result_drv[0])
    {
        return 1U; /* FAIL */
    }
    else
    {
        PTD->PCOR |= 1 << 16;
        return 0U; /* PASS */
    }
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
