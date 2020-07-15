//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIThemeProvider.h is part of SCICHART®, High Performance Scientific Charts
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

@protocol ISCIResizingGrip;
@class SCIFontStyle, SCIPenStyle, SCIBrushStyle;
@class SCILegendCellStyle;

/**
 * Defines the interface to a SciChart Theme, which provides theme colors for `SCIChartSurface`.
 * @note You may implement `ISCIThemeProvider` yourself and pass it to `SCIThemeManager` to set the global theme for all `SCIChartSurface` views.
 */
@protocol ISCIThemeProvider <NSObject>

#pragma mark - SCIChartSurface Areas

/**
 * Gets the id of the current theme.
 */
@property (nonatomic, readonly) NSString *themeId;

/**
 * Gets the `NSDictionary` of the params which will be used as background of `SCIChartSurface`.
 */
@property (nonatomic, readonly) NSDictionary *sciChartSurfaceBackground;

/**
 * Gets the `NSDictionary` of the params which will be used as background of `SCILegendModifier`
 */
@property (nonatomic, readonly) NSDictionary *legendBackground;

/**
 * Gets the `SCIBrushStyle` which will be used as style for `ISCIChartSurface.renderableSeriesArea` background.
 */
@property (nonatomic, readonly) SCIBrushStyle *renderableSeriesAreaFillStyle;

/**
 * Gets the `SCIPenStyle` which will be used as style for for `ISCIChartSurface.renderableSeriesArea` border.
 */
@property (nonatomic, readonly) SCIPenStyle *renderableSeriesAreaBorderStyle;

#pragma mark - Axes

/**
 * Gets the `SCIFontStyle` which will be used for rendering of `SCIAxisBase` tick labels.
 */
@property (nonatomic, readonly) SCIFontStyle *tickTextStyle;

/**
 * Gets the `SCIFontStyle` which will be used for rendering of `SCIAxisBase` title.
 */
@property (nonatomic, readonly) SCIFontStyle *axisTitleTextStyle;

/**
 * Gets the `SCIBrushStyle` which will be used for rendering of `SCIAxisBase` major bands.
 */
@property (nonatomic, readonly) SCIBrushStyle *axisBandsStyle;

/**
 * Gets the `SCIPenStyle` which will be used for rendering of `SCIAxisBase` major grid lines.
 */
@property (nonatomic, readonly) SCIPenStyle *majorGridLinesStyle;

/**
 * Gets the `SCIPenStyle` which will be used for rendering of `SCIAxisBase` minor grid lines.
 */
@property (nonatomic, readonly) SCIPenStyle *minorGridLinesStyle;

/**
 * Gets the length of major tick lines which are rendered by `SCIAxisBase` instance.
 */
@property (nonatomic, readonly) float majorTickLineLength;

/**
 * Gets the length of minor tick lines which are rendered by `SCIAxisBase` instance.
 */
@property (nonatomic, readonly) float minorTickLineLength;

/**
 * Gets the default background for `SCIAxisBase` tooltips.
 */
@property (nonatomic, readonly) NSDictionary *axisTooltipBackground;

#pragma mark - Renderable Series

/**
 * Gets the default `ISCIRenderableSeries.strokeStyle` for `SCIFastLineRenderableSeries`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultLineSeriesStyle;

/**
 * Gets the default `ISCIRenderableSeries.strokeStyle` for `SCIBaseMountainRenderableSeries`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultMountainLineStyle;

/**
 * Gets the default `SCIBaseMountainRenderableSeries.areaStyle` for `SCIBaseMountainRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultMountainFillStyle;

/**
 * Gets the default `ISCIRenderableSeries.strokeStyle` for `SCIFastColumnRenderableSeries`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultColumnLineStyle;

/**
 * Gets the default `SCIFastColumnRenderableSeries.fillBrushStyle` for `SCIFastColumnRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultColumnFillStyle;

/**
 * Gets the default `SCIOhlcRenderableSeriesBase.strokeUpStyle` for `SCIOhlcRenderableSeriesBase`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultCandleStrokeUpStyle;

/**
 * Gets the default `SCIOhlcRenderableSeriesBase.strokeDownStyle` for `SCIOhlcRenderableSeriesBase`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultCandleStrokeDownStyle;

/**
 * Gets the default `SCIFastCandlestickRenderableSeries.fillUpBrushStyle` for `SCIFastCandlestickRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultCandleFillUpStyle;

/**
 * Gets the default `SCIFastCandlestickRenderableSeries.fillDownBrushStyle` for `SCIFastCandlestickRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultCandleFillDownStyle;

/**
 * Gets the default `SCIFastBandRenderableSeries.strokeY1Style` for `SCIFastBandRenderableSeries`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultUpBandLineStyle;

/**
 * Gets the default `ISCIRenderableSeries.strokeStyle` for `SCIFastBandRenderableSeries`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultDownBandLineStyle;

/**
 * Gets the default `SCIFastBandRenderableSeries.fillY1BrushStyle` for `SCIFastBandRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultUpBandFillStyle;

/**
 * Gets the default `SCIFastBandRenderableSeries.fillBrushStyle` for `SCIFastBandRenderableSeries`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultDownBandFillStyle;

#pragma mark - Modifiers

/**
 * Gets the `SCIPenStyle` which will be used for rendering of `SCIRolloverModifier` vertical line.
 */
@property (nonatomic, readonly) SCIPenStyle *rolloverLineStyle;

/**
 * Gets the `SCIPenStyle` which will be used for rendering of cross pointer provided by `SCITooltipModifier`.
 */
@property (nonatomic, readonly) SCIPenStyle *crossPointerLineStyle;

/**
 * Gets the `SCIPenStyle` which will be used for rendering of `SCICursorModifier` cross.
 */
@property (nonatomic, readonly) SCIPenStyle *cursorLineStyle;

/**
 * Gets the `SCIBrushStyle` which will be used for rendering of `SCICursorModifier` tooltip background.
 */
@property (nonatomic, readonly) NSDictionary *labelBackground;

/**
 * Gets the `SCIBrushStyle` which will be used to fill `SCIRubberBandXyZoomModifier` reticule.
 */
@property (nonatomic, readonly) SCIBrushStyle *rubberBandFillStyle;

/**
 * Gets the `SCIPenStyle` which will be used to renderer border of `SCIRubberBandXyZoomModifier` reticule.
 */
@property (nonatomic, readonly) SCIPenStyle *rubberBandStrokeStyle;

#pragma mark - Annotations

/**
 * Gets the default line style for `SCILineAnnotation`.
 */
@property (nonatomic, readonly) SCIPenStyle *defaultLineAnnotationStyle;

/**
 * Gets the default text style for `SCITextAnnotation`.
 */
@property (nonatomic, readonly) SCIFontStyle *defaultTextAnnotationStyle;

/**
 * Gets the default background for `SCITextAnnotation`.
 */
@property (nonatomic, readonly) SCIBrushStyle *defaultTextAnnotationBackgroundStyle;

/**
 * Gets the default `ISCIResizingGrip` which will be used for drawing of resizing grips for all `SCIAnnotationBase`.
 */
@property (nonatomic, readonly) id<ISCIResizingGrip> defaultAnnotationGrip;

/**
 * Gets the default text style for `SCIAxisMarkerAnnotation`.
 */
@property (nonatomic, readonly) SCIFontStyle *defaultAxisMarkerAnnotationStyle;

#pragma mark - Fonts

/**
 * Gets the default font style for `SCIAxisBase` tooltips.
 */
@property (nonatomic, readonly) SCIFontStyle *axisTooltipTextStyle;

/**
 * Gets the default font style for `SCILegendModifier` and `SCIChartHeatmapColourMap`.
 */
@property (nonatomic, readonly) SCIFontStyle *defaultLabelTextStyle;

@end
