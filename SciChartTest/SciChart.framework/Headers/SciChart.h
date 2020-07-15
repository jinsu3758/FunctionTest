//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SciChart.h is part of SCICHART®, High Performance Scientific Charts
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

/// Project version number for SciChart.
FOUNDATION_EXPORT double SciChartVersionNumber;
/// Project version string for SciChart.
FOUNDATION_EXPORT const unsigned char SciChartVersionString[];

// MARK: Pie Chart

#import <SciChart/SCIPieRenderableSeriesCollection.h>
#import <SciChart/SCIPieLayoutManager.h>
#import <SciChart/SCIPieSegmentCollection.h>
#import <SciChart/SCIPieHitTestInfo.h>
#import <SciChart/SCIPieHitTestProvider.h>
#import <SciChart/SCIPieSeriesInfo.h>
#import <SciChart/SCIPieSeriesDataView.h>
#import <SciChart/SCIPieDonutRenderableSeriesBase.h>
#import <SciChart/SCIPieSegment.h>
#import <SciChart/SCIPieChartSurface.h>
#import <SciChart/ISCIPieRenderableSeries.h>
#import <SciChart/SCIPieRenderableSeries.h>
#import <SCIChart/SCIDonutRenderableSeries.h>
#import <SciChart/SCIPieLayoutPassData.h>
#import <SciChart/SCIPieRenderPassData.h>
#import <SciChart/SCIPieSelectionModifier.h>
#import <SciChart/SCIPieGestureModifierBase.h>
#import <SciChart/SCIStyleProtocol.h>
#import <SciChart/SCITooltipModifierStyleBase.h>
#import <SciChart/SCITooltipModifierStyle.h>
#import <SciChart/SCIPieTooltipView.h>
#import <SciChart/SCIPieTooltipModifier.h>
#import <SciChart/SCIPieLegendModifier.h>
#import <SciChart/SCIPieSegmentsLegendDataSource.h>
#import <SciChart/SCIDefaultPieLegendItem.h>

// MARK: - <--- SORTED PART OF UMBRELLA ---> -

// MARK: Blocks
#import <SciChart/SCIPredicate.h>
#import <SciChart/SCIAction.h>
#import <SciChart/SCIAction1.h>
#import <SciChart/SCIAction2.h>
#import <SciChart/SCIFunc1.h>
#import <SciChart/SCIFactory.h>

// MARK: Native types categories\extensions
#import <SciChart/NSNumber+ISCIComparable.h>
#import <SciChart/NSNumber+Extensions.h>
#import <SciChart/NSDate+ISCIComparable.h>
#import <SciChart/NSDate+MissingMethods.h>
#import <SciChart/NSDateFormatter+Util.h>
#import <SciChart/NSNumberFormatter+Util.h>
#import <SciChart/NSString+ISCIString.h>
#import <SciChart/NSAttributedString+ISCIString.h>
#import <SciChart/NSString+Util.h>
#import <SciChart/NSArray+Extensions.h>
#import <SciChart/UIColor+Util.h>
#import <SciChart/CoreGraphicsExtensions.h>
#import <SciChart/UIKitExtensions.h>

// MARK: - Core -

#import <SciChart/SCIResamplingMode.h>
#import <SciChart/SCISearchMode.h>
#import <SciChart/SCIDirection2D.h>
#import <SciChart/SCIAlignment.h>

// MARK: Core Protocols
#import <SciChart/ISCIComparable.h>
#import <SciChart/ISCIString.h>
#import <SciChart/SCIComparableUtil.h>
#import <SciChart/ISCIAttachable.h>
#import <SciChart/ISCICleanable.h>
#import <SciChart/ISCIUpdatable.h>
#import <SciChart/ISCISuspendable.h>
#import <SciChart/ISCIUpdateSuspender.h>
#import <SciChart/ISCIReadWriteLock.h>
#import <SciChart/ISCIDisposable.h>
#import <SciChart/SCIDisposableBase.h>
#import <SciChart/SCIUpdateSuspender.h>
#import <SciChart/ISCIInvalidatableElement.h>
#import <SciChart/ISCIChartSurfaceProvider.h>
#import <SciChart/ISCIRenderSurfaceChangedListener.h>
#import <SciChart/SCIRenderPassState.h>

#import <SciChart/ISCIBezierControlPointsProvider.h>
#import <SciChart/SCIDefaultBezierControlPointsProvider.h>
#import <SciChart/SCIBezierCurveInterpolator.h>

#import <SciChart/ISCIHitTestable.h>
#import <SciChart/ISCIView.h>
#import <SciChart/ISCIViewContainer.h>
#import <SciChart/UIView+Util.h>
#import <SciChart/UIView+ISCIHitTestable.h>
#import <SciChart/SCIDateIntervalUtil.h>
#import <SciChart/SCIDateUtil.h>

// MARK: AssetManager
#import <SciChart/ISCIAssetManager2D.h>
#import <SciChart/SCIAssetManagerUtil.h>

// MARK: ServiceContainer
#import <SciChart/SCIAttachableServiceContainer.h>
#import <SciChart/SCIServiceContainer.h>
#import <SciChart/ISCIServiceContainer.h>

// MARK: Smart Properties
#import <SciChart/SCISmartProperty.h>
#import <SciChart/SCISmartPropertyBool.h>
#import <SciChart/SCISmartPropertyDouble.h>
#import <SciChart/SCISmartPropertyFloat.h>
#import <SciChart/SCISmartPropertyInt.h>
#import <SciChart/SCISmartPropertyLong.h>

// MARK: Mathematics
#import <SciChart/SCIGenericMathFactory.h>
#import <SciChart/ISCIMath.h>

// MARK: Messaging, events
#import <SciChart/SCIChartDebugLogger.h>
#import <SciChart/ISCIMessageSubscription.h>
#import <SciChart/SCIMessageSubscriptionToken.h>
#import <SciChart/ISCIEventAggregator.h>
#import <SciChart/SCIEventManager.h>
#import <SciChart/SCIObjectPool.h>

// MARK: - Drawing -
#import <SciChart/SCIBitmap+UIImage.h>
#import <SciChart/SCIMSAAMode.h>
#import <SciChart/SCIDrawingContextFactory.h>

// MARK: Pens
#import <SciChart/ISCIPathColor.h>
#import <SciChart/ISCIPen2D.h>
#import <SciChart/ISCIBrush2D.h>
#import <SciChart/SCICompositePathColor.h>

#import <SciChart/SCIPenStyle.h>
#import <SciChart/SCISolidPenStyle.h>
#import <SciChart/SCILinearGradientPenStyle.h>
#import <SciChart/SCIRadialGradientPenStyle.h>
#import <SciChart/SCIRadialGradientBrushStyle.h>
#import <SciChart/SCITexturePenStyle.h>

// MARK: Brushes
#import <SciChart/SCIBrushStyle.h>
#import <SciChart/SCISolidBrushStyle.h>
#import <SciChart/SCILinearGradientBrushStyle.h>
#import <SciChart/SCIRadialGradientBrushStyle.h>
#import <SciChart/SCITextureBrushStyle.h>

// MARK: StyleBase + FontStyle
#import <SciChart/SCIStyleBase.h>
#import <SciChart/ISCIStyle.h>
#import <SciChart/SCIFontStyle.h>

// MARK: Themeable
#import <SciChart/ISCIThemeable.h>
#import <SciChart/ISCIThemeProvider.h>
#import <SciChart/SCIThemeColorProvider.h>
#import <SciChart/SCIThemeManager.h>

// MARK: Render Surface
#import <SciChart/ISCIRenderSurface.h>
#import <SciChart/SCIMetalRenderSurface.h>
#import <SciChart/SCIOpenGLRenderSurface.h>

// MARK: RenderContext
#import <SciChart/ISCIRenderContext2D.h>
#import <SciChart/ISCIRenderSurfaceRenderer.h>
#import <SciChart/SCIChartSurfaceRenderedListener.h>

// MARK: Dynamic color providers
#import <SciChart/ISCICandlestickDynamicPathColorProvider.h>
#import <SciChart/ISCIDynamicPathColorProvider.h>

// MARK: - Data -
#import <SciChart/SCIDataType.h>

// MARK: Ranges
#import <SciChart/SCIRangeClipMode.h>
#import <SciChart/SCIRangeChangeObserver.h>
#import <SciChart/SCIRangeFactory.h>
#import <SciChart/ISCIRange.h>
#import <SciChart/SCIRangeBase.h>
#import <SciChart/SCINumberRange.h>
#import <SciChart/SCIByteRange.h>
#import <SciChart/SCIShortRange.h>
#import <SciChart/SCIIndexRange.h>
#import <SciChart/SCIIntegerRange.h>
#import <SciChart/SCILongRange.h>
#import <SciChart/SCIFloatRange.h>
#import <SciChart/SCIDoubleRange.h>
#import <SciChart/SCIDateRange.h>

// MARK: Values (DoubleValues, FloatValues, etc...)
#import <SciChart/ISCIValues.h>
#import <SciChart/SCIByteValues.h>
#import <SciChart/SCIBoolValues.h>
#import <SciChart/SCIShortValues.h>
#import <SciChart/SCIIntegerValues.h>
#import <SciChart/SCILongValues.h>
#import <SciChart/SCIUnsignedByteValues.h>
#import <SciChart/SCIUnsignedShortValues.h>
#import <SciChart/SCIUnsignedIntegerValues.h>
#import <SciChart/SCIUnsignedLongValues.h>
#import <SciChart/SCIFloatValues.h>
#import <SciChart/SCIDoubleValues.h>
#import <SciChart/SCIDateValues.h>

#import <SciChart/SCIPoint2DSeries.h>

// MARK: Data Distribution calculators
#import <SciChart/ISCIDataDistributionProvider.h>
#import <SciChart/ISCIBaseDataDistributionCalculator.h>
#import <SciChart/ISCIDataDistributionCalculator.h>
#import <SciChart/SCIBaseDataDistributionCalculator.h>
#import <SciChart/SCIUserDefinedDistributionCalculator.h>
#import <SciChart/SCIDefaultDataDistributionCalculator.h>

// MARK: SCILists protocols and Utils
#import <SciChart/ISCIDoubleValuesProvider.h>
#import <SciChart/ISCIList.h>
#import <SciChart/ISCIListShort.h>
#import <SciChart/ISCIListInt.h>
#import <SciChart/ISCIListDouble.h>
#import <SciChart/ISCIListFloat.h>
#import <SciChart/ISCIListLong.h>
#import <SciChart/ISCIListChar.h>
#import <SciChart/ISCIListDate.h>
#import <SciChart/SCIFifoBufferFactory.h>

#import <SciChart/SCIListFactory.h>
#import <SciChart/ISCIListUtilProvider.h>
#import <SciChart/SCIListUtil.h>

// MARK: Observable collections
#import <SciChart/SCICollectionObserver.h>
#import <SciChart/SCIObservableCollection.h>
#import <SciChart/SCICollectionChangedEventArgs.h>
#import <SciChart/SCIAxisCollection.h>
#import <SciChart/SCIRenderableSeriesCollection.h>
#import <SciChart/SCIChartModifierCollectionCore.h>
#import <SciChart/SCIChartModifierCollectionBase.h>
#import <SciChart/SCIChartModifierCollection.h>

// MARK: Listeners and Property Helpers
#import <SciChart/ISCIChartListener.h>
#import <SciChart/ISCIChartListenerService.h>
#import <SciChart/SCIChartChangeServiceBase.h>
#import <SciChart/ISCIPropertyHolder.h>

// MARK: - SciChartSurface -
#import <SciChart/ISCIChartSurface.h>
#import <SciChart/SCIChartSurface.h>
#import <SciChart/SCIChartVerticalGroup.h>
#import <SciChart/ISCISeriesDrawingManager.h>
#import <SciChart/SCISeriesDrawingManager.h>

// MARK: Layout Managers
#import <SciChart/ISCILayoutable.h>
#import <SciChart/SCIChartLayoutState.h>
#import <SciChart/ISCIAxisLayoutChangeListener.h>
#import <SciChart/ISCIAxisLayoutManager.h>
#import <SciChart/ISCILayoutManager.h>
#import <SciChart/SCILayoutManagerBase.h>
#import <SciChart/SCIDefaultLayoutManager.h>
#import <SciChart/SCILayoutableView.h>
#import <SciChart/SCIViewContainer.h>
#import <SciChart/SCILayoutableViewContainer.h>
#import <SciChart/ISCIRenderableSeriesArea.h>
#import <SciChart/SCIRenderableSeriesArea.h>
#import <SciChart/ISCIChartModifierSurface.h>
#import <SciChart/SCIChartModifierSurface.h>
#import <SciChart/SCIAdornerLayer.h>

// MARK: Viewport Manager
#import <SciChart/ISCIViewportManager.h>
#import <SciChart/SCIViewportManagerBase.h>
#import <SciChart/SCIDefaultViewportManager.h>

// MARK: - Series -

// MARK: Data Series
#import <SciChart/SCIDataSeriesObserver.h>
#import <SciChart/SCIDataSeriesType.h>
#import <SciChart/SCIDataSeriesUpdateCore.h>
#import <SciChart/SCIDataSeriesUpdate.h>
#import <SciChart/SCIRenderableSeriesChangeListener.h>
#import <SciChart/SCIDataRangeChangeListener.h>
#import <SciChart/SCIVisibleRangeChangeListener.h>

#import <SciChart/SCIDataSeries.h>
#import <SciChart/ISCIDataSeries.h>
#import <SciChart/ISCIDataSeriesCore.h>
#import <SciChart/ISCIXDataSeries.h>
#import <SciChart/ISCIXDataSeriesValues.h>
#import <SciChart/SCIXDataSeries.h>
#import <SciChart/ISCIXyDataSeries.h>
#import <SciChart/ISCIXyDataSeriesValues.h>
#import <SciChart/SCIXyDataSeries.h>
#import <SciChart/ISCIXyyDataSeries.h>
#import <SciChart/ISCIXyyDataSeriesValues.h>
#import <SciChart/SCIXyyDataSeries.h>
#import <SciChart/ISCIXyzDataSeries.h>
#import <SciChart/ISCIXyzDataSeriesValues.h>
#import <SciChart/SCIXyzDataSeries.h>
#import <SciChart/ISCIHlDataSeries.h>
#import <SciChart/ISCIHlDataSeriesValues.h>
#import <SciChart/SCIHlDataSeries.h>
#import <SciChart/ISCIOhlcDataSeries.h>
#import <SciChart/ISCIOhlcDataSeriesValues.h>
#import <SciChart/SCIOhlcDataSeries.h>
#import <SciChart/ISCIUniformHeatmapDataSeries.h>
#import <SciChart/ISCIUniformHeatmapDataSeriesValues.h>
#import <SciChart/SCIUniformHeatmapDataSeries.h>

// MARK: Renderable Series
#import <SciChart/SCIErrorDirection.h>
#import <SciChart/SCIErrorMode.h>
#import <SciChart/SCIErrorType.h>
#import <SciChart/SCITextureMappingMode.h>
#import <SciChart/SCISpacingMode.h>

#import <SciChart/ISCIRenderableSeriesCore.h>
#import <SciChart/SCIRenderableSeriesCore.h>
#import <SciChart/ISCIRenderableSeries.h>
#import <SciChart/SCIRenderableSeriesBase.h>
#import <SciChart/SCIXyRenderableSeriesBase.h>
#import <SciChart/SCIFastFixedErrorBarsRenderableSeries.h>
#import <SciChart/SCIBaseColumnRenderableSeries.h>
#import <SciChart/SCIFastColumnRenderableSeries.h>
#import <SciChart/SCIFastLineRenderableSeries.h>
#import <SciChart/SCIFastImpulseRenderableSeries.h>
#import <SciChart/SCIBaseMountainRenderableSeries.h>
#import <SciChart/SCIFastMountainRenderableSeries.h>
#import <SciChart/SCIXyScatterRenderableSeries.h>
#import <SciChart/SCIXyyRenderableSeriesBase.h>
#import <SciChart/SCIFastBandRenderableSeries.h>
#import <SciChart/SCIXyzRenderableSeriesBase.h>
#import <SciChart/SCIFastBubbleRenderableSeries.h>
#import <SciChart/SCIHlRenderableSeriesBase.h>
#import <SciChart/SCIFastErrorBarsRenderableSeries.h>
#import <SciChart/SCIOhlcRenderableSeriesBase.h>
#import <SciChart/SCIFastOhlcRenderableSeries.h>
#import <SciChart/SCIFastCandlestickRenderableSeries.h>
#import <SciChart/SCIFastUniformHeatmapRenderableSeries.h>
#import <SciChart/SCIChartHeatmapColourMap.h>
#import <SciChart/SCISplineLineRenderableSeries.h>
#import <SciChart/SCISplineMountainRenderableSeries.h>
#import <SciChart/SCISplineBandRenderableSeries.h>

// MARK: Stacked Renderable Series
#import <SciChart/ISCIStackedRenderableSeries.h>
#import <SciChart/ISCIStackedColumnRenderableSeries.h>
#import <SciChart/SCIStackedColumnRenderableSeries.h>
#import <SciChart/SCIStackedMountainRenderableSeries.h>
#import <SciChart/SCIStackedSeriesCollectionBase.h>
#import <SciChart/SCIHorizontallyStackedColumnsCollection.h>
#import <SciChart/SCIVerticallyStackedSeriesCollection.h>
#import <SciChart/SCIVerticallyStackedColumnsCollection.h>
#import <SciChart/SCIVerticallyStackedMountainsCollection.h>

// MARK: Render Pass Data
#import <SciChart/ISCISeriesRenderPassData.h>
#import <SciChart/SCISeriesRenderPassData.h>
#import <SciChart/SCIUniformHeatmapRenderPassData.h>
#import <SciChart/SCIXSeriesRenderPassData.h>
#import <SciChart/SCIOhlcRenderPassData.h>
#import <SciChart/SCIXyRenderPassData.h>
#import <SciChart/SCIColumnRenderPassData.h>
#import <SciChart/SCIXyyRenderPassData.h>
#import <SciChart/SCIBandRenderPassData.h>
#import <SciChart/SCIXyzRenderPassData.h>
#import <SciChart/SCIBubbleRenderPassData.h>
#import <SciChart/SCILineRenderPassData.h>
#import <SciChart/SCIMountainRenderPassData.h>
#import <SciChart/SCIStackedSeriesRenderPassData.h>
#import <SciChart/SCIStackedColumnRenderPassData.h>
#import <SciChart/SCIStackedMountainRenderPassData.h>
#import <SciChart/SCIHlRenderPassData.h>
#import <SciChart/SCIErrorBarsRenderPassData.h>
#import <SciChart/SCIFixedErrorBarsRenderPassData.h>
#import <SciChart/SCIImpulseRenderPassData.h>
#import <SciChart/SCISplineXyRenderPassData.h>
#import <SciChart/SCISplineLineRenderPassData.h>
#import <SciChart/SCISplineMountainRenderPassData.h>
#import <SciChart/SCISplineXyyRenderPassData.h>
#import <SciChart/SCISplineBandRenderPassData.h>

// MARK: Point Markers
#import <SciChart/ISCIPointMarker.h>
#import <SciChart/ISCISpritePointMarkerDrawer.h>
#import <SciChart/SCIPointMarkerBase.h>
#import <SciChart/SCISpritePointMarker.h>
#import <SciChart/SCITrianglePointMarker.h>
#import <SciChart/SCICrossPointMarker.h>
#import <SciChart/SCIEllipsePointMarker.h>
#import <SciChart/SCISquarePointMarker.h>
#import <SciChart/SCIDrawablePointMarker.h>

// MARK: - Animations -

#import <SciChart/SCIAnimations.h>
#import <SciChart/SCIValueAnimator.h>
#import <SciChart/ISCIAnimatorListener.h>

// MARK: RenderPassData Transformations
#import <SciChart/ISCIRenderPassDataTransformation.h>
#import <SciChart/SCIBaseRenderPassDataTransformation.h>
#import <SciChart/SCICompositeTransformation.h>
#import <SciChart/SCITransformationHelpers.h>

// MARK: Scale Transformation
#import <SciChart/SCIScaleTransformationBase.h>
#import <SciChart/SCIScaleXyTransformation.h>
#import <SciChart/SCIScaleXyyTransformation.h>
#import <SciChart/SCIScaleXyzTransformation.h>
#import <SciChart/SCIScaleHlTransformation.h>
#import <SciChart/SCIScaleOhlcTransformation.h>
#import <SciChart/SCIScaleStackedXyTransformation.h>
#import <SciChart/SCISplineScaleXyTransformation.h>
#import <SciChart/SCISplineScaleXyyTransformation.h>

// MARK: Sweep Transformation
#import <SciChart/SCISweepXyTransformation.h>
#import <SciChart/SCISweepXyyTransformation.h>
#import <SciChart/SCISplineSweepXyTransformation.h>
#import <SciChart/SCISplineSweepXyyTransformation.h>

// MARK: Translate Transformation
#import <SciChart/SCITranslateXTransformation.h>
#import <SciChart/SCITranslateXyTransformationBase.h>
#import <SciChart/SCITranslateXyTransformation.h>
#import <SciChart/SCITranslateXyyTransformation.h>
#import <SciChart/SCITranslateHlTransformation.h>
#import <SciChart/SCITranslateOhlcTransformation.h>
#import <SciChart/SCITranslateStackedXyTransformation.h>
#import <SciChart/SCISplineXyTranslateXTransformation.h>
#import <SciChart/SCISplineXyTranslateYTransformation.h>
#import <SciChart/SCISplineXyyTranslateXTransformation.h>
#import <SciChart/SCISplineXyyTranslateYTransformation.h>

// MARK: Wave Transformation
#import <SciChart/SCIWaveTransformationBase.h>
#import <SciChart/SCIWaveXyTransformation.h>
#import <SciChart/SCIWaveXyyTransformation.h>
#import <SciChart/SCIWaveHlTransformation.h>
#import <SciChart/SCIWaveOhlcTransformation.h>
#import <SciChart/SCIWaveStackedXyTransformation.h>
#import <SciChart/SCISplineWaveXyTransformation.h>
#import <SciChart/SCISplineWaveXyyTransformation.h>

// MARK: Easing Functions
#import <SciChart/SCIEasingMode.h>
#import <SciChart/ISCIEasingFunction.h>
#import <SciChart/SCIEasingFunctionBase.h>
#import <SciChart/SCIQuadraticEase.h>
#import <SciChart/SCICubicEase.h>
#import <SciChart/SCIElasticEase.h>
#import <SciChart/SCISineEase.h>
#import <SciChart/SCIExponentialEase.h>
#import <SciChart/SCIBackEase.h>
#import <SciChart/SCIBounceEase.h>

// MARK: - Providers -

// MARK: SeriesInfo's
#import <SciChart/SCISeriesInfoCore.h>
#import <SciChart/SCISeriesInfo.h>
#import <SciChart/SCIXySeriesInfo.h>
#import <SciChart/SCILerpXySeriesInfo.h>
#import <SciChart/SCISplineXySeriesInfo.h>
#import <SciChart/SCIBandSeriesInfo.h>
#import <SciChart/SCILerpBandSeriesInfo.h>
#import <SciChart/SCIXyzSeriesInfo.h>
#import <SciChart/SCIHlSeriesInfo.h>
#import <SciChart/SCIErrorBarsSeriesInfo.h>
#import <SciChart/SCIFixedErrorBarsSeriesInfo.h>
#import <SciChart/SCIOhlcSeriesInfo.h>
#import <SciChart/SCIStackedSeriesInfo.h>
#import <SciChart/SCIUniformHeatmapSeriesInfo.h>

// MARK: SeriesInfo Providers
#import <SciChart/ISCISeriesInfoProvider.h>
#import <SciChart/SCIDefaultBandSeriesInfoProvider.h>
#import <SciChart/SCIDefaultErrorBarsSeriesInfoProvider.h>
#import <SciChart/SCIDefaultFixedErrorBarsSeriesInfoProvider.h>
#import <SciChart/SCIDefaultOhlcSeriesInfoProvider.h>
#import <SciChart/SCIDefaultUniformHeatmapSeriesInfoProvider.h>
#import <SciChart/SCIDefaultXySeriesInfoProvider.h>
#import <SciChart/SCIDefaultXyzSeriesInfoProvider.h>
#import <SciChart/SCIHorizontallyStackedSeriesCollectionInfoProvider.h>
#import <SciChart/SCILerpBandSeriesInfoProvider.h>
#import <SciChart/SCILerpXySeriesInfoProvider.h>
#import <SciChart/SCISplineXySeriesInfoProvider.h>
#import <SciChart/SCISeriesInfoProviderBase.h>
#import <SciChart/SCIStackedSeriesCollectionInfoProviderBase.h>
#import <SciChart/SCIVerticallyStackedSeriesCollectionInfoProvider.h>

// MARK: HitTest
#import <SciChart/SCIHitTestInfo.h>
#import <SciChart/ISCIHitTestInfoUpdatable.h>

// MARK: Hit Providers
#import <SciChart/ISCIHitProvider.h>
#import <SciChart/SCIBandHitProvider.h>
#import <SciChart/SCIBubbleHitProvider.h>
#import <SciChart/SCICandlestickHitProvider.h>
#import <SciChart/SCIColumnHitProvider.h>
#import <SciChart/SCICompositeHitProvider.h>
#import <SciChart/SCIErrorBarsHitProvider.h>
#import <SciChart/SCIHitProviderBase.h>
#import <SciChart/SCIImpulseHitProvider.h>
#import <SciChart/SCILineHitProvider.h>
#import <SciChart/SCIMountainHitProvider.h>
#import <SciChart/SCIPointMarkerHitProvider.h>
#import <SciChart/SCIStackedColumnHitProvider.h>
#import <SciChart/SCIStackedMountainHitProvider.h>
#import <SciChart/SCIUniformHeatmapHitProvider.h>
#import <SciChart/SCISplineLineHitProvider.h>
#import <SciChart/SCISplineMountainHitProvider.h>
#import <SciChart/SCISplineBandHitProvider.h>

// MARK: Nearest Point Providers
#import <SciChart/ISCINearestPointProvider.h>
#import <SciChart/SCINearestBubblePointProvider.h>
#import <SciChart/SCINearestColumnPointProvider.h>
#import <SciChart/SCINearestHorizontalPointProvider.h>
#import <SciChart/SCINearestOhlcPointProvider.h>
#import <SciChart/SCINearestPointProviderBase.h>
#import <SciChart/SCINearestStackedColumnPointProvider.h>
#import <SciChart/SCINearestUniformHeatmapPointProvider.h>
#import <SciChart/SCINearestXPointProviderBase.h>
#import <SciChart/SCINearestXyPointProvider.h>
#import <SciChart/SCINearestXyyPointProvider.h>

// MARK: Palette providers
#import <SciChart/ISCIPaletteProvider.h>
#import <SciChart/ISCIStrokePaletteProvider.h>
#import <SciChart/ISCIFillPaletteProvider.h>
#import <SciChart/ISCIPointMarkerPaletteProvider.h>
#import <SciChart/ISCIUniformHeatmapPaletteProvider.h>
#import <SciChart/SCIPaletteProviderBase.h>

// MARK: LabelProviders
#import <SciChart/ISCILabelProvider.h>
#import <SciChart/SCILabelProviderBase.h>
#import <SciChart/ISCICategoryLabelProvider.h>
#import <SciChart/SCICategoryLabelProviderBase.h>
#import <SciChart/SCIFormatterLabelProviderBase.h>
#import <SciChart/SCINumericLabelProvider.h>
#import <SciChart/SCILogarithmicNumericLabelProvider.h>
#import <SciChart/SCIDateLabelProvider.h>
#import <SciChart/SCITradeChartAxisLabelProvider.h>

#import <SciChart/ISCILabelFormatter.h>
#import <SciChart/SCISimpleNumericLabelFormatter.h>
#import <SciChart/SCIScientificNumericLabelFormatter.h>
#import <SciChart/SCINumericLabelFormatterBase.h>
#import <SciChart/SCINumericLabelFormatter.h>
#import <SciChart/SCILogBaseNumericLabelFormatter.h>
#import <SciChart/SCILogarithmicNumericLabelFormatter.h>
#import <SciChart/SCIDateLabelFormatter.h>
#import <SciChart/SCITradeChartAxisLabelFormatter.h>

// MARK: - Axes -

#import <SciChart/ISCIAxisCore.h>
#import <SciChart/SCIAxisCore.h>
#import <SciChart/ISCIAxis.h>
#import <SciChart/SCIAxisBase.h>
#import <SciChart/SCINumericAxis.h>
#import <SciChart/ISCILogarithmicNumericAxis.h>
#import <SciChart/SCILogarithmicNumericAxis.h>
#import <SciChart/ISCICategoryDateAxis.h>
#import <SciChart/SCICategoryAxisBase.h>
#import <SciChart/SCICategoryDateAxis.h>
#import <SciChart/SCIDateAxis.h>

// MARK: Axis Common
#import <SciChart/SCIScientificNotation.h>
#import <SciChart/SCIAutoRange.h>
#import <SciChart/SCIAxisAlignment.h>
#import <SciChart/SCIAxisTitlePlacement.h>
#import <SciChart/SCIAxisTitleOrientation.h>
#import <SciChart/SCIAxisParams.h>
#import <SciChart/SCIClipMode.h>
#import <SciChart/SCIClipModeTarget.h>
#import <SciChart/SCIAxisLayoutState.h>
#import <SciChart/SCIAxisTickLabelStyle.h>
#import <SciChart/ISCIAxisInteractivityHelper.h>
#import <SciChart/ISCIAxisModifierSurface.h>
#import <SciChart/SCIAxisModifierSurface.h>
#import <SciChart/SCIRenderOperationLayer.h>
#import <SciChart/SCIRenderOperationLayers.h>

// MARK: Axis Layout Strategies
#import <SciChart/ISCIAxisLayoutStrategy.h>
#import <SciChart/SCIAxisLayoutStrategyBase.h>
#import <SciChart/SCIHorizontalAxisLayoutStrategy.h>
#import <SciChart/SCIVerticalAxisLayoutStrategy.h>
#import <SciChart/SCILeftAlignmentInnerAxisLayoutStrategy.h>
#import <SciChart/SCILeftAlignmentOuterAxisLayoutStrategy.h>
#import <SciChart/SCITopAlignmentInnerAxisLayoutStrategy.h>
#import <SciChart/SCITopAlignmentOuterAxisLayoutStrategy.h>
#import <SciChart/SCIRightAlignmentInnerAxisLayoutStrategy.h>
#import <SciChart/SCIRightAlignmentOuterAxisLayoutStrategy.h>
#import <SciChart/SCIBottomAlignmentInnerAxisLayoutStrategy.h>
#import <SciChart/SCIBottomAlignmentOuterAxisLayoutStrategy.h>

// MARK: AxisInfo Providers
#import <SciChart/ISCIAxisInfoProvider.h>
#import <SciChart/ISCIAxisInfoUpdatable.h>
#import <SciChart/ISCIVisibleRangeAnimator.h>
#import <SciChart/SCIAxisInfo.h>

// MARK: Axes delta's and DeltaCalculators
#import <SciChart/ISCIAxisDelta.h>
#import <SciChart/SCIAxisDelta.h>
#import <SciChart/ISCIDeltaCalculator.h>
#import <SciChart/SCIDateDeltaCalculatorBase.h>
#import <SciChart/SCIDateDeltaCalculator.h>
#import <SciChart/SCILogarithmicDeltaCalculator.h>
#import <SciChart/SCINumericDeltaCalculator.h>
#import <SciChart/SCINumericDeltaCalculatorBase.h>

// MARK: Ticks and TickProviders
#import <SciChart/SCIAxisTicks.h>
#import <SciChart/SCITickCoordinates.h>
#import <SciChart/ISCITickCoordinatesProvider.h>
#import <SciChart/SCIDefaultTickCoordinatesProvider.h>
#import <SciChart/ISCITickProvider.h>
#import <SciChart/SCICategoryTickProvider.h>
#import <SciChart/SCIDateTickProvider.h>
#import <SciChart/SCIDeltaTickProvider.h>
#import <SciChart/SCILogarithmicNumericTickProvider.h>
#import <SciChart/SCINumericTickProvider.h>
#import <SciChart/SCINumericTickProviderBase.h>
#import <SciChart/SCITickProvider.h>

// MARK: Range Calculation Helpers
#import <SciChart/ISCIRangeCalculationHelperBase.h>
#import <SciChart/SCIRangeCalculatorHelperBase.h>
#import <SciChart/SCIRangeCalculationHelper2DBase.h>
#import <SciChart/SCINumericRangeCalculationHelper.h>
#import <SciChart/SCIDateRangeCalculationHelper.h>
#import <SciChart/SCICategoryRangeCalculationHelper.h>
#import <SciChart/SCILogarithmicRangeCalculationHelper.h>

// MARK: Coordinate Calculators
#import <SciChart/SCICoordinateCalculatorFactory.h>
#import <SciChart/ISCICoordinateCalculator.h>
#import <SciChart/ISCILogarithmicCoordinateCalculator.h>

// MARK: Axis Renderers
#import <SciChart/ISCIAxisRendererCore.h>
#import <SciChart/ISCIAxisRenderer.h>
#import <SciChart/ISCIAxisGridLinesRenderer.h>

// MARK: - Chart Modifiers -

#import <SciChart/ISCIChartModifierCore.h>
#import <SciChart/ISCIChartModifier.h>
#import <SciChart/SCIChartModifierBase.h>
#import <SciChart/SCIModifierGroup.h>
#import <SciChart/SCILegendModifier.h>
// #import <SciChart/SCIAnnotationCreationModifier.h>
// #import <SciChart/SCICreationAnnotationFactory.h>

// MARK: Gesture Modifiers
#import <SciChart/SCIZoomExtentsModifier.h>
#import <SciChart/SCIPinchZoomModifier.h>
#import <SciChart/SCIZoomPanModifier.h>
#import <SciChart/SCIAxisDragModifierBase.h>
#import <SciChart/SCIXAxisDragModifier.h>
#import <SciChart/SCIYAxisDragModifier.h>

// MARK: Touch Modifiers
#import <SciChart/SCITouchModifierBase.h>
#import <SciChart/SCIMasterSlaveTouchModifierBase.h>
#import <SciChart/SCITooltipModifierBase.h>
#import <SciChart/SCITooltipModifier.h>
#import <SciChart/SCITooltipModifierWithAxisLabelsBase.h>
#import <SciChart/SCICursorModifier.h>
#import <SciChart/SCIRolloverModifier.h>
#import <SciChart/SCISeriesSelectionModifier.h>

// MARK: Modifier Behaviors
#import <SciChart/SCIModifierBehavior.h>
#import <SciChart/SCITooltipBehaviorBase.h>
#import <SciChart/SCITooltipBehavior.h>
#import <SciChart/SCIAxisTooltipsBehaviorBase.h>
#import <SciChart/SCIAxisTooltipsBehavior.h>
#import <SciChart/SCICursorTooltipBehavior.h>
#import <SciChart/SCIVerticalSliceBehaviorBase.h>
#import <SciChart/SCIRolloverBehavior.h>

// MARK: Drawable Behaviors
#import <SciChart/SCIDrawableBehavior.h>
#import <SciChart/SCICrossDrawableBehavior.h>
#import <SciChart/SCIVerticalLineDrawableBehavior.h>
#import <SciChart/SCICursorCrosshairDrawableBehavior.h>

// MARK: Legend Modifier
#import <SciChart/SCISourceMode.h>
#import <SciChart/SCIDefaultLegendItemBase.h>
#import <SciChart/SCIDefaultLegendItem.h>
#import <SciChart/SCILegendDataSource.h>
#import <SciChart/ISCILegendItem.h>
#import <SciChart/SCIChartLegend.h>
#import <SciChart/SCIChartLegendHorizontalLayout.h>
#import <SciChart/SCIChartLegendVerticalLayout.h>
#import <SciChart/SCISeriesInfoLegendDataSource.h>
#import <SciChart/ISCILegendDataSource.h>

// MARK: Modifier Tooltips
#import <SciChart/ISCITooltipContainer.h>
#import <SciChart/SCITooltipContainerBase.h>
#import <SciChart/SCITooltipModifierTooltip.h>
#import <SciChart/SCITooltipLayoutHelper.h>
#import <SciChart/SCIShiftTooltipHelper.h>
#import <SciChart/SCISlice.h>
#import <SciChart/SCISliceLayout.h>
#import <SciChart/SCIDefaultAxisInfoProvider.h>
#import <SciChart/SCIAxisTooltip.h>
#import <SciChart/SCICursorTooltipWrapper.h>
#import <SciChart/SCICursorModifierTooltip.h>

// MARK: SeriesTooltips
#import <SciChart/SCISeriesTooltipBase.h>
#import <SciChart/SCISeriesTooltipCore.h>
#import <SciChart/SCIXySeriesTooltip.h>
#import <SciChart/SCIXyzSeriesTooltip.h>
#import <SciChart/SCIBandSeriesRolloverTooltip.h>
#import <SciChart/SCIBandSeriesTooltip.h>
#import <SciChart/SCIFixedErrorBarSeriesTooltip.h>
#import <SciChart/SCIHlSeriesTooltip.h>
#import <SciChart/SCIOhlcSeriesTooltip.h>
#import <SciChart/SCIUniformHeatmapSeriesTooltip.h>
#import <SciChart/SCIStackedSeriesTooltipBase.h>
#import <SciChart/SCIStackedSeriesTooltip.h>
#import <SciChart/SCIHorizontallyStackedSeriesRolloverTooltip.h>
#import <SciChart/SCIVerticallyStackedSeriesRolloverTooltip.h>

// MARK: - Annotations -

#import <SciChart/SCIAnnotationSurfaceEnum.h>
#import <SciChart/ISCIResizingGrip.h>
#import <SciChart/SCIEllipseResizingGrip.h>
#import <SciChart/ISCIAnnotationAdornerAction.h>
#import <SciChart/ISCIAnnotation.h>
#import <SciChart/ISCIFormattedValueProvider.h>
#import <SciChart/SCIDefaultFormattedValueProvider.h>
#import <SciChart/SCIDefaultAnnotationSelectionDrawable.h>

#import <SciChart/SCIAnnotationBase.h>
#import <SciChart/SCILineAnnotationBase.h>
#import <SciChart/SCILineAnnotation.h>
#import <SciChart/SCILineArrowAnnotation.h>
#import <SciChart/SCIAnnotationLabel.h>
#import <SciChart/SCILineAnnotationWithLabelsBase.h>
#import <SciChart/SCIHorizontalLineAnnotation.h>
#import <SciChart/SCIVerticalLineAnnotation.h>
#import <SciChart/SCIAnchorPointAnnotation.h>
#import <SciChart/SCITextAnnotation.h>
#import <SciChart/SCIAxisMarkerAnnotation.h>
#import <SciChart/SCIAxisLabelAnnotation.h>
#import <SciChart/SCICustomAnnotation.h>
#import <SciChart/SCIBoxAnnotation.h>

//@BEGIN3D
// MARK: - <--- SCICHART 3D --->

#import <SciChart/SCIChartSurface3D.h>
#import <SciChart/SCIRenderPassState3D.h>

#import <SciChart/ISCISelectionPassManager.h>
#import <SciChart/SCISelectionPassManager.h>

#import <SciChart/SCIChartModifier3DCollection.h>
#import <SciChart/SCIRenderableSeries3DCollection.h>

#import <SciChart/SCIMath3D.h>
#import <SciChart/SCIMeshIndexCalculator.h>

// MARK: Viewport
#import <SciChart/ISCIViewport3D.h>
#import <SciChart/SCIViewport3D.h>
#import <SciChart/SCIViewportManagerBase3D.h>
#import <SciChart/SCIDefaultViewportManager3D.h>
#import <SciChart/ISCICameraAnimator.h>
#import <SciChart/ISCICameraController.h>
#import <SciChart/SCICamera3D.h>

// MARK: Rendering
#import <SciChart/ISCIRenderSurface3D.h>
#import <SciChart/SCIMetalRenderSurface3D.h>
#import <SciChart/SCIOpenGLRenderSurface3D.h>
#import <SciChart/ISCIRenderSurface3DRenderer.h>
#import <SciChart/SCIChart3DRenderer.h>
#import <SciChart/SCIChartTextureTemplate.h>
#import <SciChart/SCIChartMeshTemplate.h>

// MARK: - Axes 3D

#import <SciChart/SCIAxisCubeEntity.h>
#import <SciChart/SCINumericAxis3D.h>
#import <SCIChart/SCIDateAxis3D.h>
#import <SCIChart/SCILogarithmicNumericAxis3D.h>

// MARK: Range Calculation Helpers 3D
#import <SciChart/ISCIRangeCalculationHelper3D.h>
#import <SciChart/SCIRangeCalculationHelper3DBase.h>
#import <SciChart/SCINumericRangeCalculationHelper3D.h>
#import <SciChart/SCIDateRangeCalculationHelper3D.h>
#import <SciChart/SCILogarithmicRangeCalculationHelper3D.h>

// MARK: Metadata Providers
#import <SciChart/ISCIMetadataProvider3D.h>
#import <SciChart/ISCIPointMetadataProvider3D.h>
#import <SciChart/ISCIStrokeMetadataProvider3D.h>
#import <SciChart/ISCIFillMetadataProvider3D.h>
#import <SciChart/ISCISurfaceMeshMetadataProvider3D.h>
#import <SciChart/SCIMetadataProvider3DBase.h>
#import <SciChart/SCIDefaultSelectableMetadataProvider3D.h>
#import <SciChart/SCIPointMetadataProvider3D.h>
#import <SciChart/SCIPointMetadata3D.h>

// MARK: Data Series
#import <SciChart/SCIDataSeries3DUpdate.h>
#import <SciChart/SCIXYZDataSeries3D.h>
#import <SciChart/ISCIGridDataSeries3DValues.h>
#import <SciChart/ISCIUniformGridDataSeries3DValues.h>
#import <SciChart/SCIGridData.h>
#import <SciChart/SCIBaseGridDataSeries3D.h>
#import <SciChart/SCIUniformGridDataSeries3D.h>
#import <SciChart/SCICustomSurfaceDataSeries3D.h>
#import <SciChart/SCICylindroidDataSeries3D.h>
#import <SciChart/SCIEllipsoidDataSeries3D.h>
#import <SciChart/SCIPolarDataSeries3D.h>
#import <SciChart/SCIWaterfallDataSeries3D.h>

// MARK: - Renderable Series 3D

#import <SciChart/SCIPointLineRenderableSeries3D.h>
#import <SciChart/SCISCatterRenderableSeries3D.h>
#import <SciChart/SCIImpulseRenderableSeries3D.h>
#import <SciChart/SCIColumnRenderableSeries3D.h>
#import <SciChart/SCISurfaceMeshRenderableSeries3D.h>
#import <SciChart/SCIWaterfallRenderableSeries3D.h>
#import <SciChart/SCIFreeSurfaceRenderableSeries3D.h>

// MARK: Render Pass Data 3D
#import <SciChart/ISCISeriesRenderPassData3D.h>
#import <SciChart/SCISeriesRenderPassData3D.h>
#import <SciChart/SCIGridXyzRenderPassData3D.h>
#import <SciChart/SCIYSeriesRenderPassData3D.h>
#import <SciChart/SCIXyzRenderPassData3D.h>
#import <SciChart/SCIScatterRenderPassData3D.h>
#import <SciChart/SCIPointLineRenderPassData3D.h>
#import <SciChart/SCIColumnRenderPassData3D.h>
#import <SciChart/SCIImpulseRenderPassData3D.h>
#import <SciChart/SCIFreeSurfaceRenderPassData3D.h>
#import <SciChart/SCISurfaceMeshRenderPassData3D.h>
#import <SciChart/SCIWaterfallRenderPassData3D.h>

// MARK: Entities
#import <SciChart/ISCIEntityIdProvider.h>
#import <SciChart/SCIDefaultEntityIdProvider.h>
#import <SciChart/SCIBaseRenderableSeriesSceneEntity3D.h>
#import <SciChart/SCIPoints3DSceneEntity.h>
#import <SciChart/SCIPointLineSceneEntity.h>
#import <SciChart/SCIColumnSceneEntity.h>
#import <SciChart/SCIImpulseSceneEntity.h>
#import <SciChart/SCIContourMeshRenderableSeriesEntityBase.h>
#import <SciChart/SCISurfaceMeshSceneEntity.h>
#import <SciChart/SCIFreeSurfaceSceneEntity.h>
#import <SciChart/SCIWaterfallSceneEntity.h>

// MARK: ColorPalettes
#import <SciChart/SCIMeshColorPalette.h>
#import <SciChart/SCIBrushColorPalette.h>
#import <SciChart/SCISolidColorBrushPalette.h>
#import <SciChart/SCIGradientColorPalette.h>

// MARK: - Chart Modifiers 3D

#import <SciChart/SCILegendModifier3D.h>
#import <SciChart/SCIModifierGroup3D.h>

// MARK: Gesture Modifiers
#import <SciChart/SCIOrbitModifier3D.h>
#import <SciChart/SCIPinchZoomModifier3D.h>
#import <SciChart/SCIZoomExtentsModifier3D.h>
#import <SciChart/SCIFreeLookModifier3D.h>

// MARK: Touch Modifiers
#import <SciChart/SCITooltipModifier3D.h>
#import <SciChart/SCIVertexSelectionModifier3D.h>

// MARK: Modifier Behaviors
#import <SciChart/SCITooltipBehavior3D.h>
#import <SciChart/SCITooltipBehavioWithCrosshairBehavior3D.h>
#import <SciChart/SCICrosshairSceneEntityBase.h>
#import <SciChart/SCICrosshairLinesSceneEntity.h>
#import <SciChart/SCICrosshairPlanesSceneEntity.h>

// MARK: Point markers 3D
#import <SciChart/SCIBasePointMarker3D.h>
#import <SciChart/SCIPixelPointMarker3D.h>
// Mesh Point Markers
#import <SciChart/SCIPyramidPointMarker3D.h>
#import <SciChart/SCISpherePointMarker3D.h>
#import <SciChart/SCICylinderPointMarker3D.h>
#import <SciChart/SCICubePointMarker3D.h>
// Texture Point Markers
#import <SciChart/SCITrianglePointMarker3D.h>
#import <SciChart/SCIQuadPointMarker3D.h>
#import <SciChart/SCIEllipsePointMarker3D.h>
#import <SciChart/SCICustomPointMarker3D.h>

// MARK: Series info 3D
#import <SciChart/SCIHitTestInfo3D.h>
#import <SciChart/SCISeriesInfo3D.h>
#import <SciChart/SCIXyzSeriesInfo3D.h>
#import <SciChart/SCIMeshSeriesInfo3D.h>
#import <SciChart/SCIWaterfallSeriesInfo3D.h>

// MARK: Tooltips 3D
#import <SciChart/ISCISeriesTooltip3D.h>
#import <SciChart/SCISeriesTooltip3DBase.h>
#import <SciChart/SCIMeshSeriesTooltip3D.h>
#import <SciChart/SCIWaterfallSeriesTooltip3D.h>
#import <SciChart/SCIXyzSeriesTooltip3D.h>

// MARK: Series Info providers 3D
#import <SciChart/ISCIHitTestInfoUpdatable3D.h>
#import <SciChart/ISCISeriesInfo3DProvider.h>
#import <SciChart/SCISeriesInfo3DProviderBase.h>
#import <SciChart/SCIDefaultXyzSeriesInfo3DProvider.h>
#import <SciChart/SCIDefaultMeshSeriesInfoProvider3D.h>
#import <SciChart/SCIDefaultWaterfallSeriesInfoProvider.h>

// MARK: Miscellaneous
//@END3D
