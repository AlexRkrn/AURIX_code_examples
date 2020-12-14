/**
 * \file IfxDsadc.h
 * \brief DSADC  basic functionality
 * \ingroup IfxLld_Dsadc
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
 * \defgroup IfxLld_Dsadc_Std_Enum Enumerations
 * \ingroup IfxLld_Dsadc_Std
 * \defgroup IfxLld_Dsadc_Std_Operative Operative Functions
 * \ingroup IfxLld_Dsadc_Std
 * \defgroup IfxLld_Dsadc_Std_Support Support Functions
 * \ingroup IfxLld_Dsadc_Std
 * \defgroup IfxLld_Dsadc_Std_Interrupt Interrupt Functions
 * \ingroup IfxLld_Dsadc_Std
 * \defgroup IfxLld_Dsadc_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Dsadc_Std
 */

#ifndef IFXDSADC_H
#define IFXDSADC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxDsadc_cfg.h"
#include "Src/Std/IfxSrc.h"
#include "Scu/Std/IfxScuCcu.h"
#include "_PinMap/IfxDsadc_PinMap.h"
#include "IfxDsadc_reg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Dsadc_Std_Enum
 * \{ */
/** \brief Comb Filter (auxiliary) shift control\n
 * Definition in Ifx_DSADC.FCFGA.B.AFSC
 */
typedef enum
{
    IfxDsadc_AuxCombFilterShift_noShift  = 0,  /**< \brief no shift, use full range */
    IfxDsadc_AuxCombFilterShift_shiftBy1 = 1,  /**< \brief Shift by 1 */
    IfxDsadc_AuxCombFilterShift_shiftBy2 = 2,  /**< \brief Shift by 2 */
    IfxDsadc_AuxCombFilterShift_shiftBy3 = 3   /**< \brief Shift by 3 */
} IfxDsadc_AuxCombFilterShift;

/** \brief Comb Filter (auxiliary) configuration/type\n
 * Definition in Ifx_DSADC.FCFGA.B.CFAC
 */
typedef enum
{
    IfxDsadc_AuxCombFilterType_comb1 = 0,  /**< \brief CIC1 */
    IfxDsadc_AuxCombFilterType_comb2 = 1,  /**< \brief CIC2 */
    IfxDsadc_AuxCombFilterType_comb3 = 2,  /**< \brief CIC3 */
    IfxDsadc_AuxCombFilterType_combF = 3   /**< \brief CICF */
} IfxDsadc_AuxCombFilterType;

/** \brief Service request generation (auxiliary)\n
 * Definition in Ifx_DSADC.FCFGA.B.ESEL
 */
typedef enum
{
    IfxDsadc_AuxEvent_everyNewResult  = 0, /**< \brief Always, for each new result value */
    IfxDsadc_AuxEvent_insideBoundary  = 1, /**< \brief If result is inside the boundary band */
    IfxDsadc_AuxEvent_outsideBoundary = 2  /**< \brief If result is outside the boundary band */
} IfxDsadc_AuxEvent;

/** \brief Service request generation (auxiliary)\n
 * Definition in Ifx_DSADC.FCFGA.B.EGT
 */
typedef enum
{
    IfxDsadc_AuxGate_definedByESEL       = 0, /**< \brief Separate: generate events according to ESEL */
    IfxDsadc_AuxGate_coupledToIntegrator = 1  /**< \brief Coupled: generate events only when the integrator is enabled and after the discard phase defined by bitfield NVALDIS */
} IfxDsadc_AuxGate;

/** \brief Service request generation (auxiliary)\n
 * Definition in Ifx_DSADC.FCFGA.B.SRGA
 */
typedef enum
{
    IfxDsadc_AuxServiceRequest_never     = 0,  /**< \brief Never, service requests disabled */
    IfxDsadc_AuxServiceRequest_auxFilter = 1,  /**< \brief Auxiliary filter: As selected by bitfield ESEL (\ref IfxDsadc_AuxEvent) */
    IfxDsadc_AuxServiceRequest_altSource = 2   /**< \brief Alternate source: Capturing of a sign delay value to register CGSYNCx (x = 0 - 5) */
} IfxDsadc_AuxServiceRequest;

/** \brief Carrier generation mode\n
 * Definition in Ifx_DSADC.CGCFG.B.CGMOD
 */
typedef enum
{
    IfxDsadc_CarrierWaveformMode_stopped  = 0,  /**< \brief Carrier Generator stopped */
    IfxDsadc_CarrierWaveformMode_square   = 1,  /**< \brief Carrier Generator generates square wave */
    IfxDsadc_CarrierWaveformMode_triangle = 2,  /**< \brief Carrier Generator generates triangle wave */
    IfxDsadc_CarrierWaveformMode_sine     = 3   /**< \brief Carrier Generator generates sine wave */
} IfxDsadc_CarrierWaveformMode;

/** \brief Specifies the channel Index
 */
typedef enum
{
    IfxDsadc_ChannelId_0 = 0,  /**< \brief Specifies the channel Index 0 */
    IfxDsadc_ChannelId_1 = 1,  /**< \brief Specifies the channel Index 1 */
    IfxDsadc_ChannelId_2 = 2,  /**< \brief Specifies the channel Index 2 */
    IfxDsadc_ChannelId_3 = 3,  /**< \brief Specifies the channel Index 3 */
    IfxDsadc_ChannelId_4 = 4,  /**< \brief Specifies the channel Index 4 */
    IfxDsadc_ChannelId_5 = 5,  /**< \brief Specifies the channel Index 5 */
    IfxDsadc_ChannelId_6 = 6,  /**< \brief Specifies the channel Index 6 */
    IfxDsadc_ChannelId_7 = 7,  /**< \brief Specifies the channel Index 7 */
    IfxDsadc_ChannelId_8 = 8,  /**< \brief Specifies the channel Index 8 */
    IfxDsadc_ChannelId_9 = 9   /**< \brief Specifies the channel Index 9 */
} IfxDsadc_ChannelId;

/** \brief Modulator common mode voltage selection\n
 * Definition in Ifx_DSADC.MODCFGx.B.CMVS
 */
typedef enum
{
    IfxDsadc_CommonModeVoltage_a = 0,  /**< \brief VCM = VAREF / 3.03 (1.65 V for VAREF = 5.0 V), recommended for VDDM = 3.3 V1.65V */
    IfxDsadc_CommonModeVoltage_b = 1,  /**< \brief VCM = VAREF / 2.27 (2.2 V for VAREF = 5.0 V), recommended for low distortion of AC-coupled signals */
    IfxDsadc_CommonModeVoltage_c = 2   /**< \brief VCM = VAREF / 2.0 (2.5 V for VAREF = 5.0 V), recommended for DC-coupled signals */
} IfxDsadc_CommonModeVoltage;

/** \brief FIR data shift control\n
 * Selects the displacement caused by the data shifter at the FIR filter output\n
 * Definition in Ifx_DSADC.FCFGM.B.DSH
 */
typedef enum
{
    IfxDsadc_FirDataShift_noShift  = 0,  /**< \brief no shift, use full range */
    IfxDsadc_FirDataShift_shiftBy1 = 1,  /**< \brief Shift by 1 */
    IfxDsadc_FirDataShift_shiftBy2 = 2,  /**< \brief Shift by 2 */
    IfxDsadc_FirDataShift_shiftBy3 = 3   /**< \brief Shift by 3 */
} IfxDsadc_FirDataShift;

/** \brief FIR shift control\n
 * Selects the displacement caused by the data shifter inbetween the FIR filter blocks.\n
 * Definition in Ifx_DSADC.FCFGM.B.FSH
 */
typedef enum
{
    IfxDsadc_FirInternalShift_noShift  = 0, /**< \brief no shift, use full range */
    IfxDsadc_FirInternalShift_shiftBy1 = 1  /**< \brief Shift by 1 */
} IfxDsadc_FirInternalShift;

/** \brief Modulator configuration of positive/negative input line\n
 * Definition in Ifx_DSADC.MODCFGx.B.INCFGP and Ifx_DSADC.MODCFGx.B.INCFGN
 */
typedef enum
{
    IfxDsadc_InputConfig_inputPin          = 0,  /**< \brief Modulator input connected to external pin */
    IfxDsadc_InputConfig_supplyVoltage     = 1,  /**< \brief Modulator input connected to supply voltage V_ddm */
    IfxDsadc_InputConfig_commonModeVoltage = 2,  /**< \brief Modulator input connected to common mode voltage V_cm */
    IfxDsadc_InputConfig_referenceGround   = 3   /**< \brief Modulator input connected to reference ground V_ref */
} IfxDsadc_InputConfig;

/** \brief Demodulator input data source selection\n
 * Definition in Ifx_DSADC.DICFG.B.DSRC
 */
typedef enum
{
    IfxDsadc_InputDataSource_onChipStandAlone = 0,  /**< \brief On-chip modulator, standalone (3rd order) */
    IfxDsadc_InputDataSource_onChipCombined   = 1,  /**< \brief On-chip modulator, yield (2nd order) */
    IfxDsadc_InputDataSource_directInputA     = 2,  /**< \brief External, from input A, direct */
    IfxDsadc_InputDataSource_invertedInputA   = 3,  /**< \brief External, from input A, inverted */
    IfxDsadc_InputDataSource_directInputB     = 4,  /**< \brief External, from input B, direct */
    IfxDsadc_InputDataSource_invertedInputB   = 5   /**< \brief External, from input B, inverted */
} IfxDsadc_InputDataSource;

/** \brief Modulator gain select of analog input path\n
 * Definition in Ifx_DSADC.MODCFGx.B.GAINSEL
 */
typedef enum
{
    IfxDsadc_InputGain_factor1  = 0, /**< \brief Input gain factor: 1 */
    IfxDsadc_InputGain_factor2  = 1, /**< \brief Input gain factor: 2 */
    IfxDsadc_InputGain_factor4  = 2, /**< \brief Input gain factor: 4 */
    IfxDsadc_InputGain_factor8  = 3, /**< \brief Input gain factor: 8 */
    IfxDsadc_InputGain_factor16 = 4  /**< \brief Input gain factor: 16 */
} IfxDsadc_InputGain;

/** \brief Modulator input pin selection\n
 * Definition in Ifx_DSADC.MODCFGx.B.INMUX
 */
typedef enum
{
    IfxDsadc_InputPin_a = 0,  /**< \brief Pin A connected to modulator input */
    IfxDsadc_InputPin_b = 1,  /**< \brief Pin B connected to modulator input */
    IfxDsadc_InputPin_c = 2,  /**< \brief Pin C connected to modulator input */
    IfxDsadc_InputPin_d = 3   /**< \brief Pin D connected to modulator input */
} IfxDsadc_InputPin;

/** \brief Integrator window size\n
 * Definition in Ifx_DSADC.IWCTR.B.IWS
 */
typedef enum
{
    IfxDsadc_IntegrationWindowSize_internalControl = 0,  /**< \brief Internal control: stop integrator after REPVAL+1 integration cycles */
    IfxDsadc_IntegrationWindowSize_externalControl = 1   /**< \brief External control: stop integrator when bit INTEN becomes 0 */
} IfxDsadc_IntegrationWindowSize;

/** \brief Integrator trigger mode\n
 * NOTE: switch-first to bypassed before using other mode\n
 * Definition in Ifx_DSADC.DICFG.B.ITRMODE
 */
typedef enum
{
    IfxDsadc_IntegratorTrigger_bypassed     = 0, /**< \brief No integration trigger, integrator bypassed */
    IfxDsadc_IntegratorTrigger_fallingEdge  = 1, /**< \brief Trigger event upon a falling edge */
    IfxDsadc_IntegratorTrigger_risingEdge   = 2, /**< \brief Trigger event upon a rising edge */
    IfxDsadc_IntegratorTrigger_alwaysActive = 3  /**< \brief No trigger, integrator active all the time */
} IfxDsadc_IntegratorTrigger;

/** \brief Low power supply voltage select\n
 * Definition in Ifx_DSADC.GLOBCFG.B.LOSUP
 */
typedef enum
{
    IfxDsadc_LowPowerSupply_5V   = 0, /**< \brief Supply Voltage for Analog Circuitry set to 5V */
    IfxDsadc_LowPowerSupply_3_3V = 1  /**< \brief Supply Voltage for Analog Circuitry set to 3.3V */
} IfxDsadc_LowPowerSupply;

/** \brief Comb Filter (Main Chain) shift control\n
 * Definition in Ifx_DSADC.FCFGC.B.MFSC
 */
typedef enum
{
    IfxDsadc_MainCombFilterShift_noShift  = 0,  /**< \brief no shift, use full range */
    IfxDsadc_MainCombFilterShift_shiftBy1 = 1,  /**< \brief Shift by 1 */
    IfxDsadc_MainCombFilterShift_shiftBy2 = 2,  /**< \brief Shift by 2 */
    IfxDsadc_MainCombFilterShift_shiftBy3 = 3   /**< \brief Shift by 3 */
} IfxDsadc_MainCombFilterShift;

/** \brief Comb Filter (Main Chain) configuration/type\n
 * Definition in Ifx_DSADC.FCFGC.B.CFMC
 */
typedef enum
{
    IfxDsadc_MainCombFilterType_comb1 = 0,  /**< \brief CIC1 */
    IfxDsadc_MainCombFilterType_comb2 = 1,  /**< \brief CIC2 */
    IfxDsadc_MainCombFilterType_comb3 = 2,  /**< \brief CIC3 */
    IfxDsadc_MainCombFilterType_combF = 3   /**< \brief CICF */
} IfxDsadc_MainCombFilterType;

/** \brief Service request generation (main chain)\n
 * Definition in Ifx_DSADC.FCFGC.B.SRGM
 */
typedef enum
{
    IfxDsadc_MainServiceRequest_never          = 0,  /**< \brief Never, service requests disabled */
    IfxDsadc_MainServiceRequest_highGateSignal = 1,  /**< \brief While gate (selected trigger signal) is high */
    IfxDsadc_MainServiceRequest_lowGateSignal  = 2,  /**< \brief While gate (selected trigger signal) is low */
    IfxDsadc_MainServiceRequest_everyNewResult = 3   /**< \brief Always, for each new result value */
} IfxDsadc_MainServiceRequest;

/** \brief Modulator clock select\n
 * Definition in Ifx_DSADC.GLOBCFG.B.MCSEL
 */
typedef enum
{
    IfxDsadc_ModulatorClock_off   = 0,  /**< \brief Internal clock off, no source selected */
    IfxDsadc_ModulatorClock_fDSD  = 1,  /**< \brief f_dsd clock selected */
    IfxDsadc_ModulatorClock_fERAY = 2,  /**< \brief f_eray clock selected */
    IfxDsadc_ModulatorClock_fOSC0 = 3   /**< \brief f_osc0 clock selected */
} IfxDsadc_ModulatorClock;

/** \brief Modulator divider factor for modulator clock\n
 * Definition in Ifx_DSADC.MODCFGx.B.DIVM
 */
typedef enum
{
    IfxDsadc_ModulatorClockDivider_div2 = 0,      /**< \brief f_mod = f_clk / 2  */
    IfxDsadc_ModulatorClockDivider_div4,          /**< \brief f_mod = f_clk / 4  */
    IfxDsadc_ModulatorClockDivider_div6,          /**< \brief f_mod = f_clk / 6  */
    IfxDsadc_ModulatorClockDivider_div8,          /**< \brief f_mod = f_clk / 8  */
    IfxDsadc_ModulatorClockDivider_div10,         /**< \brief f_mod = f_clk / 10  */
    IfxDsadc_ModulatorClockDivider_div12,         /**< \brief f_mod = f_clk / 12  */
    IfxDsadc_ModulatorClockDivider_div14,         /**< \brief f_mod = f_clk / 14  */
    IfxDsadc_ModulatorClockDivider_div16,         /**< \brief f_mod = f_clk / 16  */
    IfxDsadc_ModulatorClockDivider_div18,         /**< \brief f_mod = f_clk / 18  */
    IfxDsadc_ModulatorClockDivider_div20,         /**< \brief f_mod = f_clk / 20  */
    IfxDsadc_ModulatorClockDivider_div22,         /**< \brief f_mod = f_clk / 22  */
    IfxDsadc_ModulatorClockDivider_div24,         /**< \brief f_mod = f_clk / 24  */
    IfxDsadc_ModulatorClockDivider_div26,         /**< \brief f_mod = f_clk / 26  */
    IfxDsadc_ModulatorClockDivider_div28,         /**< \brief f_mod = f_clk / 28  */
    IfxDsadc_ModulatorClockDivider_div30,         /**< \brief f_mod = f_clk / 30  */
    IfxDsadc_ModulatorClockDivider_div32          /**< \brief f_mod = f_clk / 32  */
} IfxDsadc_ModulatorClockDivider;

/** \brief Rectifier sign source\n
 * Selects the sign signal that is to be delayed.\n
 * Definition in Ifx_DSADC.RECT.B.SSRC
 */
typedef enum
{
    IfxDsadc_RectifierSignSource_onChipGenerator = 0,  /**< \brief On-chip carrier generator */
    IfxDsadc_RectifierSignSource_nextChannel     = 1,  /**< \brief Sign of result of next channel */
    IfxDsadc_RectifierSignSource_externalA       = 2,  /**< \brief External sign signal A */
    IfxDsadc_RectifierSignSource_externalB       = 3   /**< \brief External sign signal B */
} IfxDsadc_RectifierSignSource;

/** \brief Demodulator sample clock source select\n
 * Definition in Ifx_DSADC.DICFG.B.CSRC
 */
typedef enum
{
    IfxDsadc_SampleClockSource_internal = 0,  /**< \brief Internal clock */
    IfxDsadc_SampleClockSource_inputA   = 1,  /**< \brief External clock, from Input A */
    IfxDsadc_SampleClockSource_inputB   = 2,  /**< \brief External clock, from Input B */
    IfxDsadc_SampleClockSource_inputC   = 3   /**< \brief External clock, from Input C */
} IfxDsadc_SampleClockSource;

/** \brief Demodulator data strobe generation mode\n
 * Definition in Ifx_DSADC.DICFG.B.STROBE
 */
typedef enum
{
    IfxDsadc_SampleStrobe_noDataStrobe            = 0, /**< \brief No data strobe */
    IfxDsadc_SampleStrobe_sampleOnRisingEdge      = 1, /**< \brief Direct clock, a sample trigger is generated at each rising clock edge */
    IfxDsadc_SampleStrobe_sampleOnFallingEdge     = 2, /**< \brief Direct clock, a sample trigger is generated at each falling clock edge */
    IfxDsadc_SampleStrobe_sampleOnBothEdges       = 3, /**< \brief Double data, a sample trigger is generated at each rising and falling clock edge */
    IfxDsadc_SampleStrobe_reserved                = 4, /**< \brief don't use */
    IfxDsadc_SampleStrobe_sampleOnTwoRisingEdges  = 5, /**< \brief Double clock, a sample trigger is generated at every 2nd rising clock edge */
    IfxDsadc_SampleStrobe_sampleOnTwoFallingEdges = 6  /**< \brief Double clock, a sample trigger is generated at every 2nd falling clock edge */
} IfxDsadc_SampleStrobe;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_DSADC.CLC.B.EDIS
 */
typedef enum
{
    IfxDsadc_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxDsadc_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxDsadc_SleepMode;

/** \brief Timestamp trigger mode\n
 * Definition in Ifx_DSADC.DICFG.B.TSTRMODE
 */
typedef enum
{
    IfxDsadc_TimestampTrigger_noTrigger   = 0,  /**< \brief No timestamp trigger */
    IfxDsadc_TimestampTrigger_fallingEdge = 1,  /**< \brief Trigger event upon a falling edge */
    IfxDsadc_TimestampTrigger_risingEdge  = 2,  /**< \brief Trigger event upon a rising edge */
    IfxDsadc_TimestampTrigger_eachEdge    = 3   /**< \brief Trigger event upon each edge */
} IfxDsadc_TimestampTrigger;

/** \brief Trigger select\n
 * Definition in Ifx_DSADC.DICFG.B.TRSEL
 */
typedef enum
{
    IfxDsadc_TriggerInput_a = 0,  /**< \brief dsadc trig 0 */
    IfxDsadc_TriggerInput_b = 1,  /**< \brief dsadc trig 1 */
    IfxDsadc_TriggerInput_c = 2,  /**< \brief vadc trig 0 */
    IfxDsadc_TriggerInput_d = 3,  /**< \brief vadc trig 1 */
    IfxDsadc_TriggerInput_e = 4,  /**< \brief external pin e */
    IfxDsadc_TriggerInput_f = 5,  /**< \brief external pin f */
    IfxDsadc_TriggerInput_g = 6,
    IfxDsadc_TriggerInput_h = 7
} IfxDsadc_TriggerInput;

/** \} */

/** \addtogroup IfxLld_Dsadc_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the sensitivity of the module to sleep signal
 * \param dsadc pointer to DSADC registers
 * \param mode mode selection (enable/disable)
 * \return None
 */
IFX_INLINE void IfxDsadc_setSleepMode(Ifx_DSADC *dsadc, IfxDsadc_SleepMode mode);

/** \brief Enables the conversion of multiple channels
 * \param dsadc Pointer to the DSADC register space
 * \param modulatorMask the modulator which should be running (bitwise selection)
 * \param channelMask the channels which should be scanned (bitwise selection)
 * \return None
 *
 * \code
 *     // enable the conversion of all 6 DSADC channels
 *     IfxDsadc_startScan(&MODULE_DSADC, 0x3FU, 0x3FU);
 *     // results are now available in IFXDSADC(ds).CH[x].RESM.B.RESULT (x=0..5)
 * \endcode
 *
 */
IFX_INLINE void IfxDsadc_startScan(Ifx_DSADC *dsadc, uint32 modulatorMask, uint32 channelMask);

/** \brief Disables the conversion of multiple channels
 * \param dsadc Pointer to the DSADC register space
 * \param modulatorMask the modulator which should be disabled (bitwise selection)
 * \return None
 *
 * \code
 *     // disable the modulators of all 6 DSADC channels
 *     IfxDsadc_stopScan(&MODULE_DSADC, 0x3FU);
 * \endcode
 *
 */
IFX_INLINE void IfxDsadc_stopScan(Ifx_DSADC *dsadc, uint32 modulatorMask);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief resets the DSADC kernel
 * \param dsadc pointer to DSADC registers
 * \return None
 */
IFX_EXTERN void IfxDsadc_resetModule(Ifx_DSADC *dsadc);

/** \} */

/** \addtogroup IfxLld_Dsadc_Std_Support
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Get result from the auxiliary chain
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return result from the auxiliary chain
 */
IFX_INLINE sint16 IfxDsadc_getAuxResult(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get the main comb decimation factor
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return the main comb decimation factor
 */
IFX_INLINE uint16 IfxDsadc_getMainCombDecimation(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get result from the main chain
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return result from the main chain
 */
IFX_INLINE sint16 IfxDsadc_getMainResult(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Return TRUE if DSADC module is enabled
 * \param dsadc Pointer to the DSADC register space
 * \return TRUE if DSADC module is enabled
 */
IFX_INLINE boolean IfxDsadc_isModuleEnabled(Ifx_DSADC *dsadc);

/** \brief Set the carrier waveform mode
 * \param dsadc Pointer to the DSADC register space
 * \param waveformMode the waveform mode
 * \return None
 */
IFX_INLINE void IfxDsadc_setCarrierMode(Ifx_DSADC *dsadc, IfxDsadc_CarrierWaveformMode waveformMode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Get the sample frequency of the integrator output in Hz
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return frequency in Hz
 */
IFX_EXTERN float32 IfxDsadc_getIntegratorOutFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get the sample frequency of the main COMB filter output in Hz
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return frequency in Hz
 */
IFX_EXTERN float32 IfxDsadc_getMainCombOutFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Estimate the group delay of main-chain filters in seconds
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return delay in seconds
 */
IFX_EXTERN float32 IfxDsadc_getMainGroupDelay(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get the modulator clock frequency in Hz
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return frequency in Hz
 */
IFX_EXTERN float32 IfxDsadc_getModulatorClockFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get the input frequency of DSADC in Hz
 * \param dsadc Pointer to the DSADC register space
 * \return frequency in Hz
 */
IFX_EXTERN float32 IfxDsadc_getModulatorInputClockFreq(Ifx_DSADC *dsadc);

/** \} */

/** \addtogroup IfxLld_Dsadc_Std_Interrupt
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Address/pointer to the interrupt source register
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return Address/pointer to the interrupt source register
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxDsadc_getAuxSrc(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \brief Get the interrupt source register for a Main event
 * \param dsadc Pointer to the DSADC register space
 * \param channel Channel Id
 * \return Address/pointer to the interrupt source register
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxDsadc_getMainSrc(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel);

/** \} */

/** \addtogroup IfxLld_Dsadc_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes a CGPWM output
 * \param cgPwm the CGPWM Pin which should be configured
 * \param pinMode the pin output mode which should be configured
 * \param padDriver the pad driver mode which should be configured
 * \return None
 */
IFX_INLINE void IfxDsadc_initCgPwmPin(const IfxDsadc_Cgpwm_Out *cgPwm, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a CIN input
 * \param cIn the CIN Pin which should be configured
 * \param cInMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initCinPin(const IfxDsadc_Cin_In *cIn, IfxPort_InputMode cInMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a COUT output
 * \param cout the COUT Pin which should be configured
 * \param pinMode the pin output mode which should be configured
 * \param padDriver the pad driver mode which should be configured
 * \return None
 */
IFX_INLINE void IfxDsadc_initCoutPin(const IfxDsadc_Cout_Out *cout, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a DIN input
 * \param dIn the DIN Pin which should be configured
 * \param dInMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initDinPin(const IfxDsadc_Din_In *dIn, IfxPort_InputMode dInMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a DS input
 * \param dsn the DSN Pin which should be configured
 * \param pinMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initDsnPin(const IfxDsadc_Dsn_In *dsn, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a DS input
 * \param dsp the DSP Pin which should be configured
 * \param pinMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initDspPin(const IfxDsadc_Dsp_In *dsp, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a ITR input
 * \param itr the ITR Pin which should be configured
 * \param itrMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initItrPin(const IfxDsadc_Itr_In *itr, IfxPort_InputMode itrMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a SG input
 * \param sg the SG Pin which should be configured
 * \param pinMode the pin input mode which should be configured
 * \param padDriver Pad Driver Configuration
 * \return None
 */
IFX_INLINE void IfxDsadc_initSgPin(const IfxDsadc_Sg_In *sg, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE sint16 IfxDsadc_getAuxResult(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    return (sint16)(dsadc->CH[channel].RESA.B.RESULT);
}


IFX_INLINE uint16 IfxDsadc_getMainCombDecimation(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    return (uint16)(1U + dsadc->CH[channel].FCFGC.B.CFMDF);
}


IFX_INLINE sint16 IfxDsadc_getMainResult(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    return (sint16)(dsadc->CH[channel].RESM.B.RESULT);
}


IFX_INLINE void IfxDsadc_initCgPwmPin(const IfxDsadc_Cgpwm_Out *cgPwm, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(cgPwm->pin.port, cgPwm->pin.pinIndex, pinMode, cgPwm->select);
    IfxPort_setPinPadDriver(cgPwm->pin.port, cgPwm->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxDsadc_initCinPin(const IfxDsadc_Cin_In *cIn, IfxPort_InputMode cInMode, IfxPort_PadDriver padDriver)
{
    if (cIn->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(cIn->pin.port, cIn->pin.pinIndex, cInMode);
        IfxPort_setPinPadDriver(cIn->pin.port, cIn->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initCoutPin(const IfxDsadc_Cout_Out *cout, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (cout->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(cout->pin.port, cout->pin.pinIndex, pinMode, cout->select);
        IfxPort_setPinPadDriver(cout->pin.port, cout->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initDinPin(const IfxDsadc_Din_In *dIn, IfxPort_InputMode dInMode, IfxPort_PadDriver padDriver)
{
    if (dIn->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(dIn->pin.port, dIn->pin.pinIndex, dInMode);
        IfxPort_setPinPadDriver(dIn->pin.port, dIn->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initDsnPin(const IfxDsadc_Dsn_In *dsn, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (dsn->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(dsn->pin.port, dsn->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(dsn->pin.port, dsn->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initDspPin(const IfxDsadc_Dsp_In *dsp, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (dsp->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(dsp->pin.port, dsp->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(dsp->pin.port, dsp->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initItrPin(const IfxDsadc_Itr_In *itr, IfxPort_InputMode itrMode, IfxPort_PadDriver padDriver)
{
    if (itr->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(itr->pin.port, itr->pin.pinIndex, itrMode);
        IfxPort_setPinPadDriver(itr->pin.port, itr->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxDsadc_initSgPin(const IfxDsadc_Sg_In *sg, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (sg->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(sg->pin.port, sg->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(sg->pin.port, sg->pin.pinIndex, padDriver);
    }
}


IFX_INLINE boolean IfxDsadc_isModuleEnabled(Ifx_DSADC *dsadc)
{
    return dsadc->CLC.B.DISS == 0;
}


IFX_INLINE void IfxDsadc_setCarrierMode(Ifx_DSADC *dsadc, IfxDsadc_CarrierWaveformMode waveformMode)
{
    dsadc->CGCFG.B.CGMOD = waveformMode;
}


IFX_INLINE void IfxDsadc_setSleepMode(Ifx_DSADC *dsadc, IfxDsadc_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    dsadc->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxDsadc_startScan(Ifx_DSADC *dsadc, uint32 modulatorMask, uint32 channelMask)
{
    dsadc->GLOBRC.U = dsadc->GLOBRC.U | ((modulatorMask << 16) | (channelMask));
}


IFX_INLINE void IfxDsadc_stopScan(Ifx_DSADC *dsadc, uint32 modulatorMask)
{
    dsadc->GLOBRC.U &= ~(modulatorMask << 16);
}


#endif /* IFXDSADC_H */
