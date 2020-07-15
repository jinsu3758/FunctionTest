//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCITooltipModifierStyleBase.h is part of SCICHART®, High Performance Scientific Charts
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
#import "SCIStyleProtocol.h"

@class SCIFontStyle;
@protocol SCIPointMarkerProtocol;

@class SCITooltipView;

/**
 * Defnies the block which is used for additional tooltip view setup
 * @note this block will be called after all other style options applied
 * @param view SCITooltipView which displays modifier data
 */
typedef void (^SCITooltipViewSetupBlock) (SCITooltipView * view);

/**
 * Defines the Enum of hit test point offset modes
 *
 * Possible values:
 * - `None` - hit test point will be directly at touch location
 * - `Up` - hit test point will be above touch location
 * - `Down` - hit test point will be below touch location
 * - `Left` - hit test point will be to the left from touch location
 * - `Right` - hit test point will be to the right from touch location
 * - `UpLeft` - hit test point will be to the up-left from touch location
 * - `UpRight` - hit test point will be to the up-right from touch location
 * - `DownLeft` - hit test point will be to the down-left from touch location
 * - `DownRight` - hit test point will be to the down-right from touch location
 */
typedef NS_ENUM(NSUInteger, SCITooltipTargetOffsetMode) {
    /** hit test point will be directly at touch location */
    SCITooltipTargetOffset_None,
    /** hit test point will be above touch location */
    SCITooltipTargetOffset_Up,
    /** hit test point will be below touch location */
    SCITooltipTargetOffset_Down,
    /** hit test point will be to the left from touch location */
    SCITooltipTargetOffset_Left,
    /** hit test point will be to the right from touch location */
    SCITooltipTargetOffset_Right,
    /** hit test point will be to the up-left from touch location */
    SCITooltipTargetOffset_UpLeft,
    /** hit test point will be to the up-right from touch location */
    SCITooltipTargetOffset_UpRight,
    /** hit test point will be to the down-left from touch location */
    SCITooltipTargetOffset_DownLeft,
    /** hit test point will be to the down-right from touch location */
    SCITooltipTargetOffset_DownRight
};

/**
 * Defines the Enum of tooltip view alignment modes.
 * @note View is aligned related to hit test point.
 *
 * Possible values:
 * `TopRight` - view will be displayed to up-right from hit test point
 * `TopLeft` - view will be displayed to up-left from hit test point
 * `BottomRight` - view will be displayed to down-right from hit test point
 * `BottomLeft` - view will be displayed to down-left from hit test point
 */
typedef NS_ENUM(NSUInteger, SCITooltipViewAlignmentMode) {
    /** view will be displayed to up-right from hit test point */
    SCITooltipViewAlignment_TopRight,
    /** view will be displayed to up-left from hit test point */
    SCITooltipViewAlignment_TopLeft,
    /** view will be displayed to down-right from hit test point */
    SCITooltipViewAlignment_BottomRight,
    /** view will be displayed to down-left from hit test point */
    SCITooltipViewAlignment_BottomLeft,
};

/**
 * Defines the Enum of tooltip view coloring modes.
 *
 * Possible values:
 * - `Default` -  view color will be defined by other color properties in style
 * - `SeriesColor` -  view background will be colored according to renderable series color
 * - `SeriesColorToDataView` -  renderable series color will be passed to data views, and by default applied to data series name text
 */
typedef NS_ENUM(NSUInteger, SCITooltipColorMode) {
    /** view color will be defined by other color properties in style */
    SCITooltipColorMode_Default,
    /** view background will be colored according to renderable series color */
    SCITooltipColorMode_SeriesColor,
    /** renderable series color will be passed to data views, and by default applied to data series name text */
    SCITooltipColorMode_SeriesColorToDataView
};

/**
 * The SCITooltipModifierStyleBase protocol.
 * @note Provides common properties for styling tooltip modifiers
 */
@protocol SCITooltipModifierStyleProtocol <SCIStyleProtocol, NSCopying>

/**
 * Changes style of head text in toolTipView.
 * Head text by default displays data series name
 * @see SCITextFormattingStyle
 */
@property (nonatomic, copy) SCIFontStyle * headLineStyle;
/**
 * Changes style of data text in toolTipView.
 * @note By default data text is hit test results
 * @see SCITextFormattingStyle
 */
@property (nonatomic, copy) SCIFontStyle * dataStyle;
/**
 * Changes number formatter for values. Default is nil.
 */
@property (nonatomic) NSNumberFormatter * numberFormatter __deprecated;

/**
 * Changes date formatter for values. Default is nil.
 */
@property (nonatomic) NSDateFormatter * dateTimeFormatter __deprecated;

/**
 * @abstract This block is used for additional customization of toltip view
 * @note Type: typedef void (^SCITooltipViewSetupBlock) (SCITooltipView * view);
 * @see SCITooltipViewSetupBlock
 */
@property (nonatomic, copy) SCITooltipViewSetupBlock tooltipViewSetup;
/**
 * Changes limit of size of toolTipView.
 * @note Default is CGSizeMake(NaN, NaN) which means size is unlimited and will be based on content
 */
@property (nonatomic) CGSize tooltipSize;
/**
 * Defines distance in pixels from tooltip view border to internal content view (in fact distance from border to text inside tooltip view)
 */
@property (nonatomic) float contentPadding;
/**
 * Changes aligment mode of toolTipView.
 * @note Tooltip alignment defines where tooltip view will be placed relative to hit test point
 * @see `SCITooltipViewAlignmentMode`
 */
@property (nonatomic) SCITooltipViewAlignmentMode tooltipAlignment;
/**
 * Changes distance between targetMarker and toolTipView. Default is 5.0.
 */
@property (nonatomic) float alignmentMargin; // TODO: rename to tooltipAlignmentPadding

/**
 * Changes colour mode of hit test. Default is SCITooltipColorMode_SeriesColorToDataView.
 * @see SCITooltipColorMode
 */
@property (nonatomic) SCITooltipColorMode colorMode; // TODO: rename to tooltipViewColorMode
/**
 * Changes background colour of toolTipView. Default is darkGrayColor.
 * @note If property colorMode = SCITooltipColorMode_SeriesColor this color will be ovewtitten by series color
 * @see `SCITooltipColorMode`
 */
@property (nonatomic, strong) UIColor * tooltipColor;
/**
 * Changes border colour of toolTipView. Default is lightGrayColor.
 * @note If property colorMode = SCITooltipColorMode_SeriesColor this color will be ovewtitten by series color
 * @see `SCITooltipColorMode`
 */
@property (nonatomic, strong) UIColor * tooltipBorderColor;
/**
 * Changes border width of toolTipView. Default is 2.0f.
 */
@property (nonatomic) float tooltipBorderWidth;
/**
 * Changes corner radius of toolTipView. Default is 0.0f.
 */
@property (nonatomic) float tooltipCornerRadius;
/**
 * Changes opacity of toolTipView. Default is 0.7f.
 */
@property (nonatomic) float tooltipOpacity;

/**
 * Changes shadow offset of toolTipView. Default is CGSizeMake(-5, 10).
 */
@property (nonatomic) CGSize tooltipShadowOffset;
/**
 * Changes shadow radius of toolTipView. Default is 3.0f.
 */
@property (nonatomic) float tooltipShadowRadius;
/**
 * Changes shadow opacity of toolTipView. Default is 0.7f.
 */
@property (nonatomic) float tooltipShadowOpacity;

///**
// * Changes mode of hitTest. Default is SCIHitTest_Default.
// * With this property you can make tooltip to make hit test on all series at specific X coordinate or at specific point, with interpolation or without
// * @see SCIHitTestMode
// */
//@property (nonatomic) SCIHitTestMode hitTestMode;

/**
 * Defines is modifier tooltip is visible. Default is true
 */
@property (nonatomic) bool showTooltip;

@end
