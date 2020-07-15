//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIStackedRenderableSeries.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIRenderableSeries.h"

/**
 * Defines the interface for all Stacked RenderableSeries within SciChart.
 * @see `ISCIStackedColumnRenderableSeries`.
 * @see `SCIStackedColumnRenderableSeries`.
 * @see `SCIStackedMountainRenderableSeries`.
 * @see `SCIVerticallyStackedSeriesCollection`.
 * @see `SCIVerticallyStackedMountainsCollection`.
 * @see `SCIVerticallyStackedColumnsCollection`.
 */
@protocol ISCIStackedRenderableSeries <ISCIRenderableSeries>

/**
 * Checks whether this stacked renderable series has valid render pass data.
 */
@property (nonatomic, readonly) BOOL hasValidRenderPassData;

/**
 * Checks whether this stacked renderable series need to update its render pass data.
 * @param xCoordCalc The current coordinate calculator for `X-Axis`.
 * @param yCoordCalc The current coordinate calculator for `Y-Axis`.
 * @param viewportSize The current viewport manager.
 * @return If YES - update is required and `-[SCIStackedSeriesCollectionBase updateStackedRenderPassDataValuesWithXAxis:yAxis:]` should be called.
 */
- (BOOL)isUpdateOfStackedRenderPassDataRequired:(id<ISCICoordinateCalculator>)xCoordCalc yCoordCalc:(id<ISCICoordinateCalculator>)yCoordCalc viewportSize:(CGSize)viewportSize;

@end
