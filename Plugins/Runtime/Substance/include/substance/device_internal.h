/*************************************************************************
* ADOBE CONFIDENTIAL
* ___________________ *
*  Copyright 2020-2024 Adobe
*  All Rights Reserved.
* * NOTICE:  All information contained herein is, and remains
* the property of Adobe and its suppliers, if any. The intellectual
* and technical concepts contained herein are proprietary to Adobe
* and its suppliers and are protected by all applicable intellectual
* property laws, including trade secret and copyright laws.
* Dissemination of this information or reproduction of this material
* is strictly forbidden unless prior written permission is obtained
* from Adobe.
**************************************************************************/

#ifndef _SUBSTANCE_DEVICE_INTERNAL_H
#define _SUBSTANCE_DEVICE_INTERNAL_H

/** @brief Substance engine device structure

	SAL abstraction layer. Must be correctly filled when used to initialize the
	SubstanceContext structure. */
typedef struct SubstanceDevice_
{
	const ISREComponentManager* componentManager;
	SRERenderDevice* device;
} SubstanceDevice;

#endif // _SUBSTANCE_DEVICE_INTERNAL_H
