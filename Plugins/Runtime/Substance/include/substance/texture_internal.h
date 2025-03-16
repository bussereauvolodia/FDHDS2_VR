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

#ifndef _SUBSTANCE_TEXTURE_INTERNAL_H
#define _SUBSTANCE_TEXTURE_INTERNAL_H

/** @brief Substance engine texture (results) structure

	SAL version.
	@note Only first member 'handle' is used for texture input. Other members are discarded. */
typedef struct SubstanceTexture_
{
	/** @brief SAL texture handle,
	If used as INPUT: access must be SREResourceAccess_PixelShaderRead,
	pixel read ready again after use.
	If used as OUTPUT: access is SREResourceAccess_PixelShaderRead */
	SRETexture handle;

	/** @brief Width of the texture base level */
	unsigned short level0Width;

	/** @brief Height of the texture base level */
	unsigned short level0Height;

	/** @brief SAL pixel format of the texture */
	SREPixelFormat pixelFormat;

	/** @brief Depth of the mipmap pyramid: number of levels */
	unsigned char mipmapCount;

} SubstanceTexture;

#endif // _SUBSTANCE_TEXTURE_INTERNAL_H
