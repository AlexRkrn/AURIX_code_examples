/**
 * \file IfxVadc_PinMap.h
 * \brief VADC I/O map
 * \ingroup IfxLld_Vadc
 *
 * \version iLLD_1_0_1_12_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Vadc_pinmap VADC Pin Mapping
 * \ingroup IfxLld_Vadc
 */

#ifndef IFXVADC_PINMAP_H
#define IFXVADC_PINMAP_H

#include <IfxVadc_reg.h>
#include <_Impl/IfxVadc_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Vadc_pinmap
 * \{ */

/** \brief VADC Boundary Flag pin mapping structure */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxVadc_GroupId   groupId;   /**< \brief Group ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxVadc_GxBfl_Out;

/** \brief VADC External Mux pin mapping structure */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxVadc_Emux_Out;

/** \brief VADC Analog Input */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxVadc_GroupId   groupId;   /**< \brief Group ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    uint8             channelId; /**< \brief Channel ID */
} IfxVadc_Vadcg_In;

IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX00_P02_6_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX00_P33_3_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX01_P02_7_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX01_P33_2_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX02_P02_8_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX02_P33_1_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX10_P00_6_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX10_P33_6_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX11_P00_7_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX11_P33_5_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX12_P00_8_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX12_P33_4_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL0_P33_4_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL1_P33_5_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL2_P33_6_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL3_P33_7_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL0_P00_4_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL0_P33_0_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL1_P00_5_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL1_P33_1_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL2_P00_6_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL2_P33_2_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL3_P00_7_OUT;  /**< \brief VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL3_P33_3_OUT;  /**< \brief VADC output */

/** \brief Table dimensions */
#define IFXVADC_PINMAP_NUM_MODULES 1
#define IFXVADC_PINMAP_NUM_GROUPS 2
#define IFXVADC_PINMAP_EMUX_OUT_NUM_ITEMS 12
#define IFXVADC_PINMAP_GXBFL_OUT_NUM_ITEMS 8


/** \brief IfxVadc_Emux_Out table */
IFX_EXTERN const IfxVadc_Emux_Out *IfxVadc_Emux_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_EMUX_OUT_NUM_ITEMS];

/** \brief IfxVadc_GxBfl_Out table */
IFX_EXTERN const IfxVadc_GxBfl_Out *IfxVadc_GxBfl_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_NUM_GROUPS][IFXVADC_PINMAP_GXBFL_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXVADC_PINMAP_H */
