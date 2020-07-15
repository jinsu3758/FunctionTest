//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIChartSurfaceBase.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIPropertyHolder.h"
#import "ISCIThemeable.h"
#import "ISCIPublishEvents.h"
#import "UIView+ISCIHitTestable.h"
#import "ISCIChartModifierSurface.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A base interface for `SCIChartSurface` and `SCIPieChartSurface` classes.
 */
@protocol ISCIChartSurfaceBase <ISCIPropertyHolder, ISCIThemeable, ISCIPublishEvents, ISCIView>

/**
 * Gets the current theme applied to this `SCIChartSurface`.
 */
@property (nonatomic, readonly) NSString *themeId;

/**
 * Gets the background brush style for `SCIChartSurface`.
 */
@property (strong, nonatomic) SCIBrushStyle *backgoundBrushStyle;

/**
 * Gets the `ISCIChartModifierSurface` instance for this `SCIChartSurface`.
 */
@property (strong, nonatomic, readonly) id<ISCIChartModifierSurface> modifierSurface;

/**
 * Export current chart surface into `UIImage` object by capturing the whole screen. It is used for taking screenshots.
 */
- (UIImage *)exportToUIImage;

@end

NS_ASSUME_NONNULL_END
