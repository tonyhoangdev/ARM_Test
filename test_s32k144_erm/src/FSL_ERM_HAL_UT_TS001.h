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
 * FILE NAME     :  FSL_ERM_HAL_UT_TS001.h                                *
 * DATE          :  Aug 31, 2016                                          *
 *                                                                        *
 * AUTHOR        :  Minh Hoang                                            *
 * E-mail        :  minh.hoang@nxp.com                                    *
 *                                                                        *
 *************************************************************************/

/************************** CHANGES ***************************************
 0.1.0       31.08.2016      Minh Hoang        Initial Version
 *************************************************************************/

#ifndef FSL_ERM_HAL_UT_TS001_H
#define FSL_ERM_HAL_UT_TS001_H

#include "erm_hal.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define ERM_SBC_MASK(channel)   (1UL << (ERM_SBC_START - (channel * ERM_CHANNELS_OFFSET_SIZE)))
#define ERM_SBC_SHIFT(channel)  (ERM_SBC_START - (channel * ERM_CHANNELS_OFFSET_SIZE))
#define ERM_SBC(channel, x)     (((uint32_t)(((uint32_t)(x))<<ERM_SBC_SHIFT(channel)))&ERM_SBC_MASK(channel))

#define ERM_NCE_MASK(channel)   (1UL << (ERM_NCE_START - (channel * ERM_CHANNELS_OFFSET_SIZE)))
#define ERM_NCE_SHIFT(channel)  (ERM_NCE_START - (channel * ERM_CHANNELS_OFFSET_SIZE))
#define ERM_NCE(channel, x)     (((uint32_t)(((uint32_t)(x))<<ERM_NCE_SHIFT(channel)))&ERM_NCE_MASK(channel))

/* Test result type definition */
typedef enum
{
    ERM_HAL_TEST_PASSED = 0U,
    ERM_HAL_TEST_FAILED = 1U
} erm_hal_test_result_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/* Test for initialize the ERM module */
erm_hal_test_result_t ERM_HAL_TEST_Init(void);

/* Test for enable Memory n interrupt event and check it */
erm_hal_test_result_t ERM_HAL_TEST_EventInterrupt(void);

/* Test for get the address of the last ECC event in Memory n and ECC event with Single-bit correction */
erm_hal_test_result_t ERM_HAL_TEST_GetErrorDetail_SEC(void);

/* Test for get the address of the last ECC event in Memory n and ECC event with Non-correctable */
erm_hal_test_result_t ERM_HAL_TEST_GetErrorDetail_DEC(void);

#ifdef __cplusplus
}
#endif

#endif /* FSL_ERM_HAL_UT_TS001_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
