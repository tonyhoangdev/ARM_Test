/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef STATUS_H
#define STATUS_H

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, Global typedef not referenced.
 * status_t is referenced from all drivers.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Local macro not referenced.
 * The defined macro is used as include guard.
 *
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Status return codes.
 * Common error codes will be a unified enumeration (C enum) that will contain all error codes
 * (common and specific). There will be separate "error values spaces" (or slots), each of 256
 * positions, allocated per functionality.
 */
typedef enum
{
    /* Generic error codes */
    STATUS_SUCCESS                         = 0x0U,    /*!< Generic operation success status */
    STATUS_ERROR                           = 0x1U,    /*!< Generic operation failure status */
    STATUS_BUSY                            = 0x2U,    /*!< Generic operation busy status */
    STATUS_TIMEOUT                         = 0x3U,    /*!< Generic operation timeout status */
    STATUS_UNSUPPORTED                     = 0x4U,    /*!< Generic operation unsupported status */
    /* MCU specific error codes */
    STATUS_MCU_GATED_OFF                   = 0x100U,  /*!< Module is gated off */
    STATUS_MCU_TRANSITION_FAILED           = 0x101U,  /*!< Error occurs during transition. */
    STATUS_MCU_INVALID_STATE               = 0x102U,  /*!< Unsupported in current state. */
    STATUS_MCU_NOTIFY_BEFORE_ERROR         = 0x103U,  /*!< Error occurs during send "BEFORE" notification. */
    STATUS_MCU_NOTIFY_AFTER_ERROR          = 0x104U,  /*!< Error occurs during send "AFTER" notification. */
    /* I2C specific error codes */
    STATUS_I2C_RECEIVED_NACK               = 0x200U,  /*!< NACK signal received  */
    STATUS_I2C_TX_UNDERRUN                 = 0x201U,  /*!< TX underrun error */
    STATUS_I2C_RX_OVERRUN                  = 0x202U,  /*!< RX overrun error */
    STATUS_I2C_ARBITRATION_LOST            = 0x203U,  /*!< Arbitration lost */
    STATUS_I2C_ABORTED                     = 0x204U,  /*!< A transfer was aborted */
    STATUS_I2C_BUS_BUSY                    = 0x205U,  /*!< I2C bus is busy, cannot start transfer */
    /* CAN specific error codes */
    STATUS_FLEXCAN_MB_OUT_OF_RANGE         = 0x300U,  /*!< The specified MB index is out of the configurable range */
    STATUS_FLEXCAN_NO_TRANSFER_IN_PROGRESS = 0x301U,  /*!< There is no transmission or reception in progress */
    /* CSEc specific error codes */
    STATUS_CSEC_SEQUENCE_ERROR             = 0x400U,  /*!< The sequence of commands or subcommands is out of
                                                           sequence */
    STATUS_CSEC_KEY_NOT_AVAILABLE          = 0x401U,  /*!< A key is locked due to failed boot measurement or
                                                           an active debugger */
    STATUS_CSEC_KEY_INVALID                = 0x402U,  /*!< A function is called to perform an operation with
                                                           a key that is not allowed for the given operation */
    STATUS_CSEC_KEY_EMPTY                  = 0x403U,  /*!< Attempt to use a key that has not been initialized yet */
    STATUS_CSEC_NO_SECURE_BOOT             = 0x404U,  /*!< The conditions for a secure boot process are not met */
    STATUS_CSEC_KEY_WRITE_PROTECTED        = 0x405U,  /*!< Request for updating a write protected key slot,
                                                           or activating debugger with write protected key(s) */
    STATUS_CSEC_KEY_UPDATE_ERROR           = 0x406U,  /*!< Key update did not succeed due to errors in
                                                           verification of the messages */
    STATUS_CSEC_RNG_SEED                   = 0x407U,  /*!< Returned by CMD_RND and CMD_DEBUG if the seed has not
                                                           been initialized before */
    STATUS_CSEC_NO_DEBUGGING               = 0x408U,  /*!< DEBUG command authentication failed */
    STATUS_CSEC_MEMORY_FAILURE             = 0x409U,  /*!< General memory technology failure
                                                           (multibit ECC error, common fault detected) */
    /* SPI specific error codes */
    STATUS_SPI_TX_UNDERRUN                 = 0x500U,  /*!< TX underrun error */
    STATUS_SPI_RX_OVERRUN                  = 0x501U,  /*!< RX overrun error */
    STATUS_SPI_ABORTED                     = 0x502U,  /*!< A transfer was aborted */
    /* UART specific error codes */
    STATUS_UART_TX_UNDERRUN                = 0x600U,  /*!< TX underrun error */
    STATUS_UART_RX_OVERRUN                 = 0x601U,  /*!< RX overrun error */
    STATUS_UART_ABORTED                    = 0x602U,  /*!< A transfer was aborted */
    /* I2S specific error codes */
    STATUS_I2S_TX_UNDERRUN                 = 0x700U,  /*!< TX underrun error */
    STATUS_I2S_RX_OVERRUN                  = 0x701U,  /*!< RX overrun error */
    STATUS_I2S_ABORTED                     = 0x702U,  /*!< A transfer was aborted */
    /* SBC specific error codes */
    SBC_NVN_ERROR                          = 0x800U, /*!< Unsuccessful attempt writing to non volatile memory
                                                          (0x73 and 0x74). Set device to factory settings. */
    SBC_COMM_ERROR                         = 0x801U, /*!< Data transfer was aborted */
    SBC_CMD_ERROR                          = 0x802U, /*!< Wrong command. */

    /* FLASH specific error codes */
    STATUS_FLASH_ERROR_ENABLE              = 0x901U, /*!< It's impossible to enable an operation */
    STATUS_FLASH_ERROR_NO_BLOCK            = 0x902U, /*!< No blocks have been enabled for Array Integrity check */
    STATUS_FLASH_INPROGRESS                = 0x903U, /*!< InProgress status */

} status_t;

#endif /* STATUS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
