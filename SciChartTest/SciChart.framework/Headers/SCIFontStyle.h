//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIFontStyle.h is part of SCICHART®, High Performance Scientific Charts
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
#import "SCIStyle.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines a class for specifying of 2D font style used to draw text on the `ISCIRenderSurface`.
 */
@interface SCIFontStyle : SCIStyle

/**
 * Defines the default font style.
 */
@property (class, nonatomic, readonly) SCIFontStyle *defaultFontStyle;

/**
 * Defines the descriptor for the font.
 */
@property (nonatomic, readonly) UIFontDescriptor *fontDescriptor;

/**
 * Gets text color as hex color code in the following color format `0xAARRGGBB`.
 */
@property (nonatomic, readonly) unsigned int colorCode;

/**
 * Gets text color as UIColor.
 */
@property (nonatomic, readonly) UIColor *color;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param textColor The text color.
 */
- (instancetype)initWithTextColor:(UIColor *)textColor;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param textColor The text color.
 */
- (instancetype)initWithTextColorCode:(unsigned int)textColor;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param fontSize The value which determines the font size.
 * @param textColor The text color code.
 */
- (instancetype)initWithFontSize:(float)fontSize andTextColor:(UIColor *)textColor;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param fontSize The value which determines the font size.
 * @param textColor The text color.
 */
- (instancetype)initWithFontSize:(float)fontSize andTextColorCode:(unsigned int)textColor;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param fontDescriptor The font descriptor value.
 * @param textColor The text color.
 */
- (instancetype)initWithFontDescriptor:(UIFontDescriptor *)fontDescriptor andTextColor:(UIColor *)textColor;

/**
 * Creates an instance of `SCIFontStyle` with specified arguments.
 * @param fontDescriptor The font descriptor value.
 * @param textColor The text color code.
 */
- (instancetype)initWithFontDescriptor:(UIFontDescriptor *)fontDescriptor andTextColorCode:(unsigned int)textColor;

#pragma mark - Apply this style on

/**
 * Initialises a `UILabel` with this `SCIFontStyle` values.
 * @param label The UILabel to init.
 */
- (void)initUILabel:(UILabel *)label;

@end

NS_ASSUME_NONNULL_END
