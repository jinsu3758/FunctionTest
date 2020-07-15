//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIPieSegment.h is part of SCICHART®, High Performance Scientific Charts
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
#import "ISCIInvalidatableElement.h"
#import "ISCIPieRenderableSeries.h"

@class SCIBrushStyle;
@class SCIPenStyle;
@class SCIFontStyle;

/**
 Segment of Pie or Donut renderable series
 @see SCIPieRenderableSeries
 @see SCIDonutRenderableSeries
 */
@interface SCIPieSegment : NSObject<ISCIInvalidatableElement>

/**
 Gets or sets fill style for segment
 @see SCIBrushStyle
 */
@property (nonatomic, nullable) SCIBrushStyle * fillStyle;
/**
 Gets or sets selected fill style for segment
 @see SCIBrushStyle
 */
@property (nonatomic, nullable) SCIBrushStyle * selectedFillStyle;

/**
 Gets or sets stroke style for segment
 @see SCIPenStyle
 */
@property (nonatomic, nullable) SCIPenStyle * strokeStyle;
/**
 Gets or sets selected stroke style for segment
 @see SCIPenStyle
 */
@property (nonatomic, nullable) SCIPenStyle * selectedStrokeStyle;

/**
 Gets or sets text style for segment
 @see SCIFontStyle
 */
@property (nonatomic, nullable) SCIFontStyle * titleStyle;
/**
 Gets or sets selected text style for segment
 @see SCIFontStyle
 */
@property (nonatomic, nullable) SCIFontStyle * selectedTitleStyle;

/**
 offset in points for segment from center of series
 */
@property (nonatomic) double centerOffset;

/**
 Gets or sets selected state for segment
 */
@property (nonatomic) BOOL isSelected;

/**
 Value for segment. Has influence on relative size of segment in renderable series
 */
@property (nonatomic) double value;
/**
 Title associated with segment.
 */
@property (nonatomic, strong, nullable) NSString * title;

/**
 Returns fill style depending on selected state
 */
-(SCIBrushStyle * _Nullable) getFillStyle;
/**
 Returns stroke style depending on selected state
 */
-(SCIPenStyle * _Nullable) getStrokeStyle;
/**
 Returns text style depending on selected state
 */
-(SCIFontStyle * _Nullable) getTextStyle;

/**
 Returns color associated with segment. By default it is taken from fill style
 */
-(UIColor * _Nullable)segmentColor;

/**
 * Attaches this instance to the instance of `ISCIPieRenderableSeries`.
 */
- (void)attachTo:(nonnull id<ISCIPieRenderableSeries>)series;

/**
 * Detaches this instance from currently `ISCIPieRenderableSeries` instance.
 */
- (void)detach;

/**
 * Gets whether this instance is attached on not.
 */
@property (nonatomic, readonly) BOOL isAttached;

@end
