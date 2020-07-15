//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIChartModifierBase+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIChartModifierBase.h"
#import "SCIChartModifierCore+Protected.h"
#import "ISCIRenderableSeriesArea.h"
#import "ISCIReceiveEvents.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIChartModifierBase`.
 */
@interface SCIChartModifierBase()

@property (nonatomic, readonly, nullable) id<ISCIRenderableSeriesArea> renderableSeriesArea;

/**
 * Gets XAxis specified by id if it exists, otherwise returns nil.
 * @param axisId The XAxis id.
 * @return The XAxis instance.
 */
- (nullable id<ISCIAxis>)getXAxisById:(nonnull NSString *)axisId;

/**
 * Gets YAxis specified by id if it exists, otherwise returns nil.
 * @param axisId The YAxis id.
 * @return The YAxis instance.
 */
- (nullable id<ISCIAxis>)getYAxisById:(nonnull NSString *)axisId;

/**
 * Performs a check whether the point is inside the boundaries of the initial `ISCIChartModifierSurface`.
 * @param point The point to check.
 * @param isMaster Indicates whether this check is performed on the master {@link IChartModifierSurface} instance.
 * @param source The {@link IReceiveMotionEvents} instance.
 * @return True if the point is inside the boundaries of the initial {@link IChartModifierSurface}.
 */
- (BOOL)isWithinSourceBounds:(CGPoint)point isMaster:(BOOL)isMaster source:(nonnull id<ISCIReceiveEvents>)source;

/**
 * Get's the master modifier for passed in modifier from source.
 * @param modifier Modifier to get master for.
 * @param source to look master modifier in.
 */
- (nullable id<ISCIChartModifier>)getMasterModifier:(nonnull id<ISCIChartModifier>)modifier source:(nonnull id<ISCIReceiveEvents>)source;

@end
