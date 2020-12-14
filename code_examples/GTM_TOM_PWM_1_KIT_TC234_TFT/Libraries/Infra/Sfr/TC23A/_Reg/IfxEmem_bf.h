/**
 * \file IfxEmem_bf.h
 * \brief
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Version: TC23XADAS_UM_V1.1.R0
 * Specification: tc23xadas_um_sfrs_MCSFR.xml (Revision: UM_V1.1)
 * MAY BE CHANGED BY USER [yes/no]: No
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
 * \defgroup IfxLld_Emem_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxLld_Emem
 *
 */
#ifndef IFXEMEM_BF_H
#define IFXEMEM_BF_H                 1
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Emem_BitfieldsMask
 * \{  */

/** \brief  Length for Ifx_EMEM_CLC_Bits.DISR */
#define IFX_EMEM_CLC_DISR_LEN        (1u)

/** \brief  Mask for Ifx_EMEM_CLC_Bits.DISR */
#define IFX_EMEM_CLC_DISR_MSK        (0x1u)

/** \brief  Offset for Ifx_EMEM_CLC_Bits.DISR */
#define IFX_EMEM_CLC_DISR_OFF        (0u)

/** \brief  Length for Ifx_EMEM_CLC_Bits.DISS */
#define IFX_EMEM_CLC_DISS_LEN        (1u)

/** \brief  Mask for Ifx_EMEM_CLC_Bits.DISS */
#define IFX_EMEM_CLC_DISS_MSK        (0x1u)

/** \brief  Offset for Ifx_EMEM_CLC_Bits.DISS */
#define IFX_EMEM_CLC_DISS_OFF        (1u)

/** \brief  Length for Ifx_EMEM_ID_Bits.MODNUMBER */
#define IFX_EMEM_ID_MODNUMBER_LEN    (16u)

/** \brief  Mask for Ifx_EMEM_ID_Bits.MODNUMBER */
#define IFX_EMEM_ID_MODNUMBER_MSK    (0xffffu)

/** \brief  Offset for Ifx_EMEM_ID_Bits.MODNUMBER */
#define IFX_EMEM_ID_MODNUMBER_OFF    (16u)

/** \brief  Length for Ifx_EMEM_ID_Bits.MODREV */
#define IFX_EMEM_ID_MODREV_LEN       (8u)

/** \brief  Mask for Ifx_EMEM_ID_Bits.MODREV */
#define IFX_EMEM_ID_MODREV_MSK       (0xffu)

/** \brief  Offset for Ifx_EMEM_ID_Bits.MODREV */
#define IFX_EMEM_ID_MODREV_OFF       (0u)

/** \brief  Length for Ifx_EMEM_ID_Bits.MODTYPE */
#define IFX_EMEM_ID_MODTYPE_LEN      (8u)

/** \brief  Mask for Ifx_EMEM_ID_Bits.MODTYPE */
#define IFX_EMEM_ID_MODTYPE_MSK      (0xffu)

/** \brief  Offset for Ifx_EMEM_ID_Bits.MODTYPE */
#define IFX_EMEM_ID_MODTYPE_OFF      (8u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGEN */
#define IFX_EMEM_SBRCTR_ACGEN_LEN    (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGEN */
#define IFX_EMEM_SBRCTR_ACGEN_MSK    (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGEN */
#define IFX_EMEM_SBRCTR_ACGEN_OFF    (12u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST0 */
#define IFX_EMEM_SBRCTR_ACGST0_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST0 */
#define IFX_EMEM_SBRCTR_ACGST0_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST0 */
#define IFX_EMEM_SBRCTR_ACGST0_OFF   (16u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST1 */
#define IFX_EMEM_SBRCTR_ACGST1_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST1 */
#define IFX_EMEM_SBRCTR_ACGST1_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST1 */
#define IFX_EMEM_SBRCTR_ACGST1_OFF   (17u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST2 */
#define IFX_EMEM_SBRCTR_ACGST2_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST2 */
#define IFX_EMEM_SBRCTR_ACGST2_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST2 */
#define IFX_EMEM_SBRCTR_ACGST2_OFF   (18u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST3 */
#define IFX_EMEM_SBRCTR_ACGST3_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST3 */
#define IFX_EMEM_SBRCTR_ACGST3_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST3 */
#define IFX_EMEM_SBRCTR_ACGST3_OFF   (19u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST4 */
#define IFX_EMEM_SBRCTR_ACGST4_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST4 */
#define IFX_EMEM_SBRCTR_ACGST4_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST4 */
#define IFX_EMEM_SBRCTR_ACGST4_OFF   (20u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST5 */
#define IFX_EMEM_SBRCTR_ACGST5_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST5 */
#define IFX_EMEM_SBRCTR_ACGST5_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST5 */
#define IFX_EMEM_SBRCTR_ACGST5_OFF   (21u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST6 */
#define IFX_EMEM_SBRCTR_ACGST6_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST6 */
#define IFX_EMEM_SBRCTR_ACGST6_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST6 */
#define IFX_EMEM_SBRCTR_ACGST6_OFF   (22u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.ACGST7 */
#define IFX_EMEM_SBRCTR_ACGST7_LEN   (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.ACGST7 */
#define IFX_EMEM_SBRCTR_ACGST7_MSK   (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.ACGST7 */
#define IFX_EMEM_SBRCTR_ACGST7_OFF   (23u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.STBLOCK */
#define IFX_EMEM_SBRCTR_STBLOCK_LEN  (1u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.STBLOCK */
#define IFX_EMEM_SBRCTR_STBLOCK_MSK  (0x1u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.STBLOCK */
#define IFX_EMEM_SBRCTR_STBLOCK_OFF  (0u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.STBSLK */
#define IFX_EMEM_SBRCTR_STBSLK_LEN   (4u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.STBSLK */
#define IFX_EMEM_SBRCTR_STBSLK_MSK   (0xfu)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.STBSLK */
#define IFX_EMEM_SBRCTR_STBSLK_OFF   (4u)

/** \brief  Length for Ifx_EMEM_SBRCTR_Bits.STBULK */
#define IFX_EMEM_SBRCTR_STBULK_LEN   (3u)

/** \brief  Mask for Ifx_EMEM_SBRCTR_Bits.STBULK */
#define IFX_EMEM_SBRCTR_STBULK_MSK   (0x7u)

/** \brief  Offset for Ifx_EMEM_SBRCTR_Bits.STBULK */
#define IFX_EMEM_SBRCTR_STBULK_OFF   (1u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T0 */
#define IFX_EMEM_TILECONFIG_T0_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T0 */
#define IFX_EMEM_TILECONFIG_T0_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T0 */
#define IFX_EMEM_TILECONFIG_T0_OFF   (0u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T1 */
#define IFX_EMEM_TILECONFIG_T1_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T1 */
#define IFX_EMEM_TILECONFIG_T1_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T1 */
#define IFX_EMEM_TILECONFIG_T1_OFF   (2u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T2 */
#define IFX_EMEM_TILECONFIG_T2_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T2 */
#define IFX_EMEM_TILECONFIG_T2_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T2 */
#define IFX_EMEM_TILECONFIG_T2_OFF   (4u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T3 */
#define IFX_EMEM_TILECONFIG_T3_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T3 */
#define IFX_EMEM_TILECONFIG_T3_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T3 */
#define IFX_EMEM_TILECONFIG_T3_OFF   (6u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T4 */
#define IFX_EMEM_TILECONFIG_T4_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T4 */
#define IFX_EMEM_TILECONFIG_T4_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T4 */
#define IFX_EMEM_TILECONFIG_T4_OFF   (8u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T5 */
#define IFX_EMEM_TILECONFIG_T5_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T5 */
#define IFX_EMEM_TILECONFIG_T5_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T5 */
#define IFX_EMEM_TILECONFIG_T5_OFF   (10u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T6 */
#define IFX_EMEM_TILECONFIG_T6_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T6 */
#define IFX_EMEM_TILECONFIG_T6_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T6 */
#define IFX_EMEM_TILECONFIG_T6_OFF   (12u)

/** \brief  Length for Ifx_EMEM_TILECONFIG_Bits.T7 */
#define IFX_EMEM_TILECONFIG_T7_LEN   (2u)

/** \brief  Mask for Ifx_EMEM_TILECONFIG_Bits.T7 */
#define IFX_EMEM_TILECONFIG_T7_MSK   (0x3u)

/** \brief  Offset for Ifx_EMEM_TILECONFIG_Bits.T7 */
#define IFX_EMEM_TILECONFIG_T7_OFF   (14u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE0 */
#define IFX_EMEM_TILESTATE_TILE0_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE0 */
#define IFX_EMEM_TILESTATE_TILE0_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE0 */
#define IFX_EMEM_TILESTATE_TILE0_OFF (0u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE1 */
#define IFX_EMEM_TILESTATE_TILE1_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE1 */
#define IFX_EMEM_TILESTATE_TILE1_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE1 */
#define IFX_EMEM_TILESTATE_TILE1_OFF (2u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE2 */
#define IFX_EMEM_TILESTATE_TILE2_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE2 */
#define IFX_EMEM_TILESTATE_TILE2_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE2 */
#define IFX_EMEM_TILESTATE_TILE2_OFF (4u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE3 */
#define IFX_EMEM_TILESTATE_TILE3_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE3 */
#define IFX_EMEM_TILESTATE_TILE3_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE3 */
#define IFX_EMEM_TILESTATE_TILE3_OFF (6u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE4 */
#define IFX_EMEM_TILESTATE_TILE4_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE4 */
#define IFX_EMEM_TILESTATE_TILE4_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE4 */
#define IFX_EMEM_TILESTATE_TILE4_OFF (8u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE5 */
#define IFX_EMEM_TILESTATE_TILE5_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE5 */
#define IFX_EMEM_TILESTATE_TILE5_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE5 */
#define IFX_EMEM_TILESTATE_TILE5_OFF (10u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE6 */
#define IFX_EMEM_TILESTATE_TILE6_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE6 */
#define IFX_EMEM_TILESTATE_TILE6_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE6 */
#define IFX_EMEM_TILESTATE_TILE6_OFF (12u)

/** \brief  Length for Ifx_EMEM_TILESTATE_Bits.TILE7 */
#define IFX_EMEM_TILESTATE_TILE7_LEN (2u)

/** \brief  Mask for Ifx_EMEM_TILESTATE_Bits.TILE7 */
#define IFX_EMEM_TILESTATE_TILE7_MSK (0x3u)

/** \brief  Offset for Ifx_EMEM_TILESTATE_Bits.TILE7 */
#define IFX_EMEM_TILESTATE_TILE7_OFF (14u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXEMEM_BF_H */
