/**
 * \file IfxEbu_Sram.h
 * \brief EBU SRAM details
 * \ingroup IfxLld_Ebu
 *
 * \version iLLD_1_0_1_12_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Ebu_Sram_Usage How to use the SRAM Driver?
 * \ingroup IfxLld_Ebu
 *
 * The SRAM driver provides a default EBU configuration for communicating with external asynchronous and synchronous SRAM Devices with muxed or demuxed address/data interface.
 *
 * \section IfxLld_Ebu_Sram_Preparation Preparation
 * \subsection IfxLld_Ebu_Sram_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Ebu/Sram/IfxEbu_Sram.h>
 * \endcode
 *
 * \subsection IfxLld_Ebu_Sram_Init_demux32 2bit Demuxed Device
 *
 * This will configure EBU for 32bit demuxed device
 *
 * \code
 *     IfxEbu_Sram_Config cfg;
 *     IfxEbu_Sram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_Sram sram;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * In order to initialize a second Demuxed device on CS1 do the following
 * \code
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * \subsection IfxLld_Ebu_Sram_Init_mux16 16bit muxed Device
 *
 * If you intend to configure a 16bit muxed device here is an example for CS1
 * \code
 *     cfg.device = IfxEbu_Sram_Device_muxedAsynchronousType;
 *     // configuring the device type for read
 *     cfg.readConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_16bitMultiplexed;
 *     // configuring the device type for write
 *     cfg.writeConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_16bitMultiplexed;
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * Following the initialization of EBU reads and writes can be done to the external location
 *
 * \subsection IfxLld_Ebu_Sram_Init_SSRAM Synchronous SRAMs
 *
 * Configuring EBU for Synchronous Srams
 * \code
 *     IfxEbu_Sram_Config cfg;
 *     IfxEbu_Sram_initMemoryConfig(&cfg, &MODULE_EBU0);
 *     cfg.device = IfxEbu_Sram_Device_synchronousSramType;
 *     cfg.memoryRegionConfig.baseAddress = 0xa4000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     IfxEbu_Sram sram;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * In order to configure second SSRAM device on CS1 do the following
 * \code
 *     cfg.memoryRegionConfig.baseAddress = 0xa5000000; // specify noncached segment A, driver will also enable the cached segment 8
 *     cfg.device = IfxEbu_Sram_Device_synchronousSramType;
 *     cfg.chipselect = IfxEbu_ChipSelect_1;
 *     IfxEbu_Sram_initMemory(&sram, &cfg);
 * \endcode
 *
 * \defgroup IfxLld_Ebu_Sram SRAM Driver
 * \ingroup IfxLld_Ebu
 * \defgroup IfxLld_Ebu_Sram_DataStructures Data Structures
 * \ingroup IfxLld_Ebu_Sram
 * \defgroup IfxLld_Ebu_Sram_Module Module Functions
 * \ingroup IfxLld_Ebu_Sram
 * \defgroup IfxLld_Ebu_Sram_Enum Enumerations
 * \ingroup IfxLld_Ebu_Sram
 */

#ifndef IFXEBU_SRAM_H
#define IFXEBU_SRAM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ebu/Std/IfxEbu.h"
#include "Port/Std/IfxPort.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Sram_Enum
 * \{ */
typedef enum
{
    IfxEbu_Sram_Device_deMuxedAsynchronousType,
    IfxEbu_Sram_Device_muxedAsynchronousType,
    IfxEbu_Sram_Device_synchronousSramType
} IfxEbu_Sram_Device;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ebu_Sram_DataStructures
 * \{ */
typedef struct
{
    Ifx_EBU          *ebu;
    IfxEbu_ChipSelect chipSelect;
    uint32            baseAddress;
} IfxEbu_Sram;

typedef struct
{
    Ifx_EBU                    *module;
    IfxEbu_ExternalClockRatio   externalClockRatio;
    IfxEbu_ReadConfig           readConfig;
    IfxEbu_WriteConfig          writeConfig;
    IfxEbu_ReadAccessParameter  readAccessParameter;
    IfxEbu_WriteAccessParameter writeAccessParameter;
    IfxEbu_ChipSelect           chipSelect;
    IfxEbu_ModuleConfig         moduleConfig;
    IfxEbu_MemoryRegionConfig   memoryRegionConfig;
    IfxEbu_Sram_Device          device;
    IfxEbu_ReadConfig           syncReadConfig;
    IfxEbu_WriteConfig          syncWriteConfig;
    IfxEbu_ReadAccessParameter  syncReadAccessParameter;
    IfxEbu_WriteAccessParameter syncWriteAccessParameter;
} IfxEbu_Sram_Config;

/** \} */

/** \addtogroup IfxLld_Ebu_Sram_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return None
 */
IFX_EXTERN void IfxEbu_Sram_initMemory(IfxEbu_Sram *sram, const IfxEbu_Sram_Config *config);

/**
 * \return None
 */
IFX_EXTERN void IfxEbu_Sram_initMemoryConfig(IfxEbu_Sram_Config *config, Ifx_EBU *ebu);

/** \} */

#endif /* IFXEBU_SRAM_H */
