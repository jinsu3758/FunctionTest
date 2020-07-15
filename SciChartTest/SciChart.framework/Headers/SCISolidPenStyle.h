//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCISolidPenStyle.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIPenStyle.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines a style class for lines with solid color which is used to draw 2D lines on the `ISCIRenderSurface`
 */
@interface SCISolidPenStyle : SCIPenStyle

/**
 * Provides default instance of `SCISolidPenStyle`.
 */
@property (class, nonatomic, readonly) SCISolidPenStyle *defaultPenStyle;

/**
 * Creates a new `SCIPenStyle` instance.
 * @param colorCode The stroke `ARGB` color code.
 * @param thickness The stroke thickness in pixels.
 */
- (instancetype)initWithColorCode:(unsigned int)colorCode thickness:(float)thickness;

/**
 * Creates a new `SCIPenStyle` instance.
 * @param color The stroke `ARGB` color.
 * @param thickness The stroke thickness in pixels.
 */
- (instancetype)initWithColor:(UIColor *)color thickness:(float)thickness;

/**
 * Creates a new `SCIPenStyle` instance.
 * @param color The stroke `ARGB` color.
 * @param thickness The stroke thickness in pixels.
 * @param strokeDashArray The stroke dash pattern.
 */
- (instancetype)initWithColor:(UIColor *)color thickness:(float)thickness strokeDashArray:(nullable NSArray<NSNumber *> *)strokeDashArray;

/**
 * Creates a new `SCIPenStyle` instance.
 * @param colorCode The stroke `ARGB` color code.
 * @param thickness The stroke thickness in pixels.
 * @param antiAliasing The value indicating whether the pen should use antialiasing or not.
 * @param strokeDashArray The stroke dash pattern.
 */
- (instancetype)initWithColorCode:(unsigned int)colorCode thickness:(float)thickness strokeDashArray:(nullable NSArray<NSNumber *> *)strokeDashArray antiAliasing:(BOOL)antiAliasing NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
