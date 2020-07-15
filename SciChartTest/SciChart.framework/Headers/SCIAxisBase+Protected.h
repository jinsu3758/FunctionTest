//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIAxisBase+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIAxisCore+Protected.h"
#import "ISCIRangeCalculationHelper.h"
#import "ISCICoordinateCalculator.h"
#import "ISCIAxisLayoutManager.h"
#import "ISCIAxisGridLinesRenderer.h"
#import "ISCIAxisInteractivityHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCIAxisBase ()

@property (strong, nonatomic) id<ISCICoordinateCalculator> internalCoordinateCalculator;
@property (strong, nonatomic) id<ISCIAxisInteractivityHelper> internalInteractivityHelper;

@property (nonatomic) BOOL isRenderersDirty;
@property (nonatomic) BOOL isProvidersDirty;
@property (nonatomic) BOOL isLayoutRectDirty;

@property (strong, nonatomic) SCISmartPropertyBool *isLabelCullingEnabledProperty;
@property (strong, nonatomic) SCISmartPropertyBool *autoFitMarginalLabelsProperty;

@property (strong, nonatomic) SCISmartProperty *axisTickLabelStyleProperty;
@property (strong, nonatomic) SCISmartPropertyInt *axisTitlePlacementProperty;
@property (strong, nonatomic) SCISmartPropertyInt *axisTitleOrientationProperty;
@property (strong, nonatomic) SCISmartPropertyInt *axisTitleAlignmentProperty;
@property (strong, nonatomic) SCISmartPropertyBool *isPrimaryAxisProperty;

/**
 * Creates a new instance of `SCIAxisBase` class.
 * @param defaultNonZeroRange The default non zero ISCIRange` instance for this axis.
 * @param axisModifierSurface The `ISCIAxisModifierSurface` for this this axis.
 */
- (instancetype)initWithDefaultRange:(id<ISCIRange>)defaultNonZeroRange andAxisModifierSurface:(id<ISCIAxisModifierSurface>)axisModifierSurface NS_DESIGNATED_INITIALIZER;

@end

/**
 * The extensions in this header are to be used only by subclasses of `SCIAxisBase`.
 */
@interface SCIAxisBase (Protected)

/**
 * Sets `SCIRangeCalculationHelperProtocol` instance which will be used for range calculations in this axis.
 * @param rangeCalculationHelper New `SCIRangeCalculationHelperProtocol` instance.
 */
- (void)setRangeCalculationHelper:(id<ISCIRangeCalculationHelper>)rangeCalculationHelper;

/**
 * Sets `ISCIAxisRenderer` instance which will be used for rendering of this axis.
 * @param axisRenderer New `ISCIAxisRenderer` instance.
 */
- (void)setAxisRenderer:(id<ISCIAxisRenderer>)axisRenderer;

/**
 * Sets `ISCIAxisGridLinesRenderer` instance which will be used for rendering of grid lines for this axis.
 * @param gridLinesRenderer New `ISCIAxisGridLinesRenderer` instance.
 */
- (void)setGridLinesRenderer:(id<ISCIAxisGridLinesRenderer>)gridLinesRenderer;

/**
 * Sets `ISCIAxisTitleRenderer` instance which will be used for rendering of axis title.
 * @param axisTitleRenderer New `ISCIAxisTitleRenderer` instance.
 */
- (void)setAxisTitleRenderer:(id<ISCIAxisTitleRenderer>)axisTitleRenderer;

/**
 * Sets `ISCIAxisLayoutManager` instance which will be used for layour of this axis.
 * @param axisLayoutManager New `ISCIAxisLayoutManager` instance.
 */
- (void)setAxisLayoutManager:(id<ISCIAxisLayoutManager>)axisLayoutManager;

/**
 * Creates new `ISCICoordinateCalculator` based on axis params values and double representation of visible range.
 * @param axisParams Axis params to create calculator from.
 * @param visibleRangeMin The double representation of min value for visible range to create calculator from.
 * @param visibleRangeMax The double representation of max value for visible range to create calculator from.
 * @return New `ISCICoordinateCalculator` instance.
 */
- (id<ISCICoordinateCalculator>)createCoordinateCalculatorFromParams:(SCIAxisParams *)axisParams visibleRangeMin:(double)visibleRangeMin visibleRangeMax:(double)visibleRangeMax;

/**
 * Creates a new `ISCIAxisInteractivityHelper` instance for this axis.
 * @param coordinateCalculator The current coordinate calculator for this axis.
 * @return The new axis interactivity helper.
 */
- (id<ISCIAxisInteractivityHelper>)createInteractivityHelper:(id<ISCICoordinateCalculator>)coordinateCalculator;

/**
 * Updates axis params according to current state of axis.
 * @param axisParams Axis params to update.
 */
- (void)updateAxisParams:(SCIAxisParams *)axisParams;

/**
 * Calculates axis viewport dimension in pixels.
 * @return Viewport dimension in pixels.
 */
- (int)calculateAxisViewportDimension;

/**
 * Calculates axis offset relative to renderableSeries Area in pixels.
 * @return Axis offset in pixels.
 */
- (int)calculateAxisOffset;

/**
 * Updates axis parts which should be updated before measure.
 */
- (void)onUpdateMeasure;

/**
 * This method is called when axis size has changed during its layout.
 * @param size New size of axis in pixels.
 * @param oldSize Old size of axis in pixels.
 */
- (void)onSizeChanged:(CGSize)size oldSize:(CGSize)oldSize;

@end

NS_ASSUME_NONNULL_END
