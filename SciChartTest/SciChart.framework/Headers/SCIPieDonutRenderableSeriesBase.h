//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIPieDonutRenderableSeriesBase.h is part of SCICHART®, High Performance Scientific Charts
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

#import <Foundation/Foundation.h>
#import "SCIPieSegment.h"
#import "ISCIPieRenderableSeries.h"

/**
 * Defines the Base class for for renderable series which are used within `SCIPieChartSurface`.
 */
@interface SCIPieDonutRenderableSeriesBase : NSObject <ISCIPieRenderableSeries> {
@protected
    /// :nodoc:
    float _animationProgress;
    /// :nodoc:
    double _totalValue;
}

/**
 Duration of appear animation in seconds.
 */
@property (nonatomic) double appearAnimationDuration;

/**
 * Draw labels if true.
 */
@property (nonatomic) BOOL drawLabels;

/**
 * Gets or sets distance between segments in circle
 */
@property (nonatomic) float segmentSpacing;

/**
 * Draws segment for pie or donut renderable series.
 */
- (void)internalDrawSegment:(SCIPieSegment *)segment withStartAngle:(double)startAngle segmentAngle:(double)segmentAngle;

/**
 * Gets  he segment pathfor pie or donut renderable series.
 * Must be inmpelemted in the subclass.
 */
- (CGMutablePathRef)getSegmentPath:(SCIPieSegment *)segment center:(CGPoint)center startAngle:(double)startAngle endAngle:(double)endAngle segmentSpacing:(double)segmentSpacing;

/**
 * Draws segment label for pie or donut renderable series.
 * Must be inmpelemted in the subclass.
 */
- (void)drawSegmentLabel:(SCIPieSegment *)segment center:(CGPoint)center startAngle:(double)startAngle endAngle:(double)endAngle;

/**
 * Draws segment label for pie or donut renderable series.
 */
- (void)drawSegmentLabel:(SCIPieSegment *)segment center:(CGPoint)center textPlacementAngle:(double)textPlacementAngle distanceFromCenter:(double)distanceFromCenter;

/**
 * Return text to be placed on segment. By default it's % from total value
 * @param segment SCIPieSegment segment for which text is generated
 * @param value total value of all segments in series
 */
- (NSString*)getLabelTextForSegment:(SCIPieSegment *)segment totalValue:(double)value;

/**
 * Start appear animation.
 */
- (void)startAnimation;

/**
 * Method called internally to calculate current animation state.
 */
- (BOOL)updateAnimationState:(CFTimeInterval)timeInterval;

/**
 * Check's if pie or donut series are hit using radius. Returns -1 if false.
 * Must be inmpelemted in the subclass.
 */
- (BOOL)isSegmentInRadius:(double)radius withCenter:(CGPoint)center atPoint:(CGPoint)point;

@end
