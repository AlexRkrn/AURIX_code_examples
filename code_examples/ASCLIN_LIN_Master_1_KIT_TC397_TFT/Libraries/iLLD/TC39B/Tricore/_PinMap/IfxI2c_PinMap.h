/**
 * \file IfxI2c_PinMap.h
 * \brief I2C I/O map
 * \ingroup IfxLld_I2c
 *
 * \version iLLD_1_0_1_12_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxLld_I2c_pinmap I2C Pin Mapping
 * \ingroup IfxLld_I2c
 */

#ifndef IFXI2C_PINMAP_H
#define IFXI2C_PINMAP_H

#include <IfxI2c_reg.h>
#include <_Impl/IfxI2c_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_I2c_pinmap
 * \{ */

/** \brief SCL input mapping structure */
typedef const struct
{
    Ifx_I2C*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         inSelect;  /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect; /**< \brief Port control code */
} IfxI2c_Scl_InOut;

/** \brief SDA input mapping structure */
typedef const struct
{
    Ifx_I2C*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         inSelect;  /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect; /**< \brief Port control code */
} IfxI2c_Sda_InOut;

IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P11_14_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P13_9_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P11_13_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P13_12_INOUT;  /**< \brief Serial Data Output and input */

/** \brief Table dimensions */
#define IFXI2C_PINMAP_NUM_MODULES 2
#define IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS 3
#define IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS 3


/** \brief IfxI2c_Scl_InOut table */
IFX_EXTERN const IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS];

/** \brief IfxI2c_Sda_InOut table */
IFX_EXTERN const IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXI2C_PINMAP_H */
