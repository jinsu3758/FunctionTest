//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// UIColor+Util.h is part of SCICHART®, High Performance Scientific Charts
// For full terms and conditions of the license, see http://www.scichart.com/scichart-eula/
//
// This source code is protected by international copyright law. Unauthorized
// reproduction, reverse-engineering, or distribution of all or any portion of
// this source code is strictly prohibited.
//
// This source code contains confidential and proprietary trade secrets of
// SciChart Ltd., and should at no time be copied, transferred, sold,
// distributed or made available without express written permission.
//******************************************************************************

#import <UIKit/UIKit.h>

/**
 * Helper category with some color constants and helper methods to work with `UIColor`.
 */
@interface UIColor (Util)

/**
 * Get hex color code from `UIColor`. Color code bytes order is `0xAABBGGRR`.
 */
- (unsigned int)colorABGRCode;

/**
 * Get hex color code from `UIColor`. Color code bytes order is `0xAARRGGBB`.
 */
- (unsigned int)colorARGBCode;

/**
 * Create `UIColor` from hex color code. Color code bytes order is `0xAABBGGRR`.
 */
+ (UIColor *)fromABGRColorCode:(unsigned int)color;

/**
 * Create `UIColor` from hex color code. Color code bytes order is `0xAARRGGBB`.
 */
+ (UIColor *)fromARGBColorCode:(unsigned int)color;

/**
 * Applies specified opacity value to provided color.
 * @param color The input color.
 * @param opacity The opacity value.
 * @return The output color.
 */
+ (unsigned int)argb:(unsigned int)color withOpacity:(float)opacity;

/**
 * Swap bytes from `ARGB` into `ABGR`.
 */
+ (unsigned int)swapBytesFromARGBIntoABGR:(unsigned int)argb;

/**
 * Gets alpha value from color.
 * @param color The color value.
 * @return The alpha value.
 */
+ (unsigned char)alpha:(unsigned int)color;

/**
 * Gets red value from color.
 * @param color The color value.
 * @return The red value.
 */
+ (unsigned char)red:(unsigned int)color;

/**
 * Gets green value from color.
 * @param color The color value.
 * @return The green value.
 */
+ (unsigned char)green:(unsigned int)color;

/**
 * Gets blue value from color.
 * @param color The color value.
 * @return The blue value.
 */
+ (unsigned char)blue:(unsigned int)color;

/**
 * Gets the inverted color for provided color.
 * @param color The input color.
 * @return The inverted color.
 */
+ (unsigned int)getInvertedColor:(unsigned int)color;

/**
 * Check is the passed in `color` is transparent.
 * @param color The color value.
 * @return YES if the color is transparent, otherwise - NO.
 */
+ (BOOL)isTransparent:(unsigned int)color;

@end
