/**
 * \file IfxSrc.h
 * \brief SRC  basic functionality
 * \ingroup IfxLld_Src
 *
 * \version iLLD_1_0_1_12_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Src SRC
 * \addtogroup IfxLld_Src
 * \{
 * \defgroup IfxLld_Src_Usage How to use Service Request Mechanism?
 * \addtogroup IfxLld_Src_Usage
 * \{
 *
 * For Aurix controller peripherals that can generate service requests is connected to one
 * or more Service Request Nodes (SRNs) in the central Interrupt Router(IR) module. Refer to Controller User Manual for more details\n
 *
 * IfxSrc driver provides the APIs to configure and control service requests. Refer \ref IfxLld_Src_Usage for
 * details of these APIs.
 *
 *
 * \section Ifx_Src_UsageInit Initialize the Service Request Node
 *
 * Service request node is initialized to configure the following,\n
 * 1) Route the interrupt trigger to service provider, which are:\n
 *  __a. One of the available CPUs or\n
 *  __b. DMA controller\n
 *
 * 2) Priority of CPU Interrupt or DMA Trigger.
 *
 * For Interrupt or DMA to be correctly triggered, following steps are to be done in the user code:
 *
 * \subsection Ifx_Src_UsageInitStep1 Step1: Configure the Node
 *
 * User must configure the service request node in the application / driver files.
 *
 * \subsection Ifx_Src_UsageInitStep2 Step2: Enable the Trigger
 *
 * Enable the service request node to connect the trigger event from the hardware to service provider.
 *
 * Example:
 * Following example show the configuration for STM0 Service request 0 trigger configured to trigger
 * CPU1 with the priority specified by IFX_INTPRIO_STM0 (from the example at IfxCpu_Irq)
 *
 * \code
 * //file: myApplication.c
 *
 * #include "Ifx_IntPrioDef.h" // to get the priority numbers
 *
 * void myDriverInitFunction(void)
 * {
 *    // driver init code
 *
 *    // Step1: Call the function to route the trigger from for SRC_STM0_SR0 to CPU1
 *    // and priority specified at Ifx_IntPrioDef.h globally
 *  IfxSrc_init(&MODULE_SRC.STM.STM[0].SR0, IfxSrc_Tos_cpu1, IFX_INTPRIO_STM0);
 *
 *    // Step2: Enable the service request node
 *  IfxSrc_init(&MODULE_SRC.STM.STM[0].SR0);
 * }
 * \endcode
 *
 * \}
 * \}
 *
 * \defgroup IfxLld_Src_Std_Service_Request Service Request Functions
 * \ingroup IfxLld_Src_Std
 * \defgroup IfxLld_Src_Std_Module Module Functions
 * \ingroup IfxLld_Src_Std
 */

#ifndef IFXSRC_H
#define IFXSRC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSrc_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxSrc_reg.h"
/** \addtogroup IfxLld_Src_Std_Service_Request
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Resets the overrun flag of the Service Request.
 * \param src pointer to the Service Request Control register which the overrun flag should be cleared.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_clearOverrun(volatile Ifx_SRC_SRCR *src);

/** \brief Resets a specific interrupt service by software.
 * \param src pointer to the Service Request Control register which the request should be cleared.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_clearRequest(volatile Ifx_SRC_SRCR *src);

/** \brief Gets the current overrun status.
 * \param src pointer to the Service Request Control register for which the overrun status should be returned.
 * \return current service request control overrun status.
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE boolean IfxSrc_isOverrun(volatile Ifx_SRC_SRCR *src);

/** \brief Gets the current request status.
 * \param src pointer to the Service Request Control register for which the request status should be returned.
 * \return current service request control request status.
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE boolean IfxSrc_isRequested(volatile Ifx_SRC_SRCR *src);

/** \brief Requests a specific interrupt service by software
 * \param src pointer to the Service Request Control register which the interrupt has to be requested.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_setRequest(volatile Ifx_SRC_SRCR *src);

/** \} */

/** \addtogroup IfxLld_Src_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief DeInitializes the service request control register.
 * \param src pointer to the Service Request Control register which should be deinitialised.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_deinit(volatile Ifx_SRC_SRCR *src);

/** \brief Disables a specific interrupt service request.
 * \param src pointer to the Service Request Control register for which the interrupt has to be disabled.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_disable(volatile Ifx_SRC_SRCR *src);

/** \brief Enables a specific interrupt service request.
 * \param src pointer to the Service Request Control register for which the interrupt has to be enabled.
 * \return None
 *
 * Usage example: see \ref IfxSrc_init
 *
 */
IFX_INLINE void IfxSrc_enable(volatile Ifx_SRC_SRCR *src);

/** \brief Initializes the service request control register.
 * \param src pointer to the Service Request Control register which should be initialised.
 * \param typOfService type of interrupt service provider.
 * \param priority Interrupt priority.
 * \return None
 *
 * Get the peripheral service control register which request need to be serviced and assign this service to any of service providers.
 * \code
 * //define the interrupt priority
 * #define IFXASCLIN0_TX_INTPRIO 2
 * //get the service request
 * volatile Ifx_SRC_SRCR *src = IfxAsclin_getSrcPointerRx( &MODULE_ASCLIN0 );
 * //initlaise the service request
 * IfxSrc_init( src, IfxSrc_Tos_cpu0, IFXASCLIN0_TX_INTPRIO );
 * // enable the service
 * IfxSrc_enable( src );
 * //check for service request flags and clear if they occur
 * if ( IfxSrc_isRequested( src ) == TRUE )
 * {
 *    IfxSrc_clearRequest( src );
 * }
 * if ( IfxSrc_isOverrun( src ) == TRUE )
 * {
 *      IfxSrc_clearOverrun( src );
 * }
 * // Atlast deinitialise the service control
 * IfxSrc_deinit( src );
 * \endcode
 *
 */
IFX_INLINE void IfxSrc_init(volatile Ifx_SRC_SRCR *src, IfxSrc_Tos typOfService, Ifx_Priority priority);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxSrc_clearOverrun(volatile Ifx_SRC_SRCR *src)
{
    src->B.IOVCLR = 1;
}


IFX_INLINE void IfxSrc_clearRequest(volatile Ifx_SRC_SRCR *src)
{
    src->B.CLRR = 1;
}


IFX_INLINE void IfxSrc_deinit(volatile Ifx_SRC_SRCR *src)
{
    src->U = 0;
}


IFX_INLINE void IfxSrc_disable(volatile Ifx_SRC_SRCR *src)
{
    src->B.SRE = 0;
}


IFX_INLINE void IfxSrc_enable(volatile Ifx_SRC_SRCR *src)
{
    src->B.SRE = 1;
}


IFX_INLINE void IfxSrc_init(volatile Ifx_SRC_SRCR *src, IfxSrc_Tos typOfService, Ifx_Priority priority)
{
    src->B.SRPN = priority;
    src->B.TOS  = typOfService;
    IfxSrc_clearRequest(src);
}


IFX_INLINE boolean IfxSrc_isOverrun(volatile Ifx_SRC_SRCR *src)
{
    return src->B.IOV ? TRUE : FALSE;
}


IFX_INLINE boolean IfxSrc_isRequested(volatile Ifx_SRC_SRCR *src)
{
    return src->B.SRR ? TRUE : FALSE;
}


IFX_INLINE void IfxSrc_setRequest(volatile Ifx_SRC_SRCR *src)
{
    src->B.SETR = 1;
}


#endif /* IFXSRC_H */
