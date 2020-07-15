//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIRadialGradientBrushStyle.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIGradientBrushStyle.h"
#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines brush style which allows to fill shapes with radial gradient.
 */
@interface SCIRadialGradientBrushStyle : SCIGradientBrushStyle

/**
 * Gets the `[x, y]` coordinates of the gradient's center.
 */
@property (nonatomic, readonly) CGPoint center;

/**
 * Gets he radius of the gradient.
 */
@property (nonatomic, readonly) CGFloat radius;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param centerColor The center color of the gradient.
 * @param edgeColor The edge color of the gradient.
 */
- (instancetype)initWithCenterColor:(UIColor *)centerColor edgeColor:(UIColor *)edgeColor;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param center The `[x, y]` coordinates of the gradient's center.
 * @param radius The radius of the gradient.
 * @param centerColor The center color of the gradient.
 * @param edgeColor The edge color of the gradient.
 */
- (instancetype)initWithCenter:(CGPoint)center radius:(CGFloat)radius centerColor:(UIColor *)centerColor edgeColor:(UIColor *)edgeColor;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param centerColor The center color code of the gradient.
 * @param edgeColor The edge color code of the gradient.
 */
- (instancetype)initWithCenterColorCode:(unsigned int)centerColor edgeColorCode:(unsigned int)edgeColor;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param center The `[x, y]` coordinates of the gradient's center.
 * @param radius The radius of the gradient.
 * @param centerColor The center color code of the gradient.
 * @param edgeColor The edge color code of the gradient.
 */
- (instancetype)initWithCenter:(CGPoint)center radius:(CGFloat)radius centerColorCode:(unsigned int)centerColor edgeColorCode:(unsigned int)edgeColor;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param colors The array with gradient colors.
 * @param stops The array with gradient stops.
 */
- (instancetype)initWithColors:(unsigned int *)colors stops:(float *)stops count:(int)count;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param center The `[x, y]` coordinates of the gradient's center.
 * @param radius The radius of the gradient.
 * @param colors The array with gradient colors.
 * @param stops The array with gradient stops.
 */
- (instancetype)initWithCenter:(CGPoint)center radius:(CGFloat)radius colors:(unsigned int *)colors stops:(float *)stops count:(int)count;

/**
 * Creates a new instance of `SCIRadialGradientBrushStyle`.
 * @param center The `[x, y]` coordinates of the gradient's center.
 * @param radius The radius of the gradient.
 * @param colors The `SCIFloatValues` with gradient colors.
 * @param stops The `SCIUnsignedIntegerValues` with gradient stops.
 */
- (instancetype)initWithCenter:(CGPoint)center radius:(CGFloat)radius colorValues:(SCIUnsignedIntegerValues *)colors stopValues:(SCIFloatValues *)stops;

@end

NS_ASSUME_NONNULL_END
