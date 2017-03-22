/*
** ###################################################################
**     Abstract:
**         Common include file for CMSIS register access layer headers.
**
**     Copyright (c) 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**
**     Permission to use, copy, modify, and/or distribute this software for any
**     purpose with or without fee is hereby granted, provided that the above
**     copyright notice and this permission notice appear in all copies.
**
**     THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
**     WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  WARRANTIES OF
**     MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
**     SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
**     RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
**     CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
**     CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
** ###################################################################
*/

#ifndef DEVICE_REGISTERS_H
#define DEVICE_REGISTERS_H

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced.
* The macro defines the device currently in use and may be used by components for specific checks.
*
*/


/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */

#if (defined(CPU_S32K144HFT0VLLT) || defined(CPU_S32K144LFT0MLLT) || defined(CPU_S32K148) || defined(CPU_S32K142))

    #define S32K14x_SERIES

    /* Specific core definitions */
    #include "s32_core_cm4.h"

    #if (defined(CPU_S32K144HFT0VLLT) || defined(CPU_S32K144LFT0MLLT))

        #define S32K144_SERIES

        /* Register definitions */
        #include "S32K144.h"
        /* CPU specific feature definitions */
        #include "S32K144_features.h"

    #elif defined(CPU_S32K148)

        #define S32K148_SERIES

        /* Register definitions */
        #include "S32K148.h"
        /* CPU specific feature definitions */
        #include "S32K148_features.h"

    #elif defined(CPU_S32K142)

        #define S32K142_SERIES

        /* Register definitions */
        #include "S32K142.h"
        /* CPU specific feature definitions */
        #include "S32K142_features.h"

    #endif

#elif defined(CPU_S32V234)

    #define S32V234_SERIES

    /* Specific core definitions */
    #include "s32_core_cm4.h"
    /* Register definitions */
    #include "S32V234.h"
    /* CPU specific feature definitions */
    #include "S32V234_features.h"

#elif (defined(CPU_MPC5748G) || defined(CPU_MPC5746C))

    #define MPC574x_SERIES

    /* Specific core definitions */
    #include "s32_core_e200.h"

    #if (defined(CPU_MPC5748G))

        #define MPC5748G_SERIES

        /* Register definitions */
        #include "MPC5748G.h"
        /* CPU specific feature definitions */
        #include "MPC5748G_features.h"

    #elif defined(CPU_MPC5746C)

        #define MPC5746C_SERIES

        /* Register definitions */
        #include "MPC5746C.h"
        /* CPU specific feature definitions */
        #include "MPC5746C_features.h"

    #endif
#else
    #error "No valid CPU defined!"
#endif

#include "devassert.h"

#endif /* DEVICE_REGISTERS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
