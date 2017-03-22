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

#ifndef FSL_ERM_DRV_UT_TS001_H
#define FSL_ERM_DRV_UT_TS001_H

#include "erm_hw_access.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern const erm_interrupt_config_t erm1_Interrupt1;
extern const erm_interrupt_config_t erm1_Interrupt3;
extern const erm_user_config_t erm1_InitConfig[];

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Test result type definition */
typedef enum
{
    ERM_DRV_TEST_PASSED = 0U,
    ERM_DRV_TEST_FAILED = 1U
} erm_drv_test_result_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/* Test function for ERM_DRV_Init and ERM_DRV_SetInterruptConfig */
erm_drv_test_result_t ERM_DRV_TEST_Init();

/* Test function for ERM_DRV_Deinit */
erm_drv_test_result_t ERM_DRV_TEST_Deinit();

/* Test function for ERM_DRV_GetInterruptConfig */
erm_drv_test_result_t ERM_DRV_TEST_GetInterruptConfig();

/* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Single-bit correction */
erm_drv_test_result_t ERM_DRV_TEST_GetErrorDetail_SEC();

/* Test function for ERM_DRV_GetErrorDetail and ERM_DRV_ClearEvent with Non-correctable */
erm_drv_test_result_t ERM_DRV_TEST_GetErrorDetail_DEC();

#ifdef __cplusplus
}
#endif

#endif /* FSL_ERM_DRV_UT_TS001_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
