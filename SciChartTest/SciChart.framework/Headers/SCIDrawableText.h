//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIDrawableText.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIInvalidatableElement.h"
#import "ISCICleanable.h"
#import "ISCIAssetManager2D.h"
#import "ISCIRenderContext2D.h"
#import "CoreGraphicsExtensions.h"
#import "SCIFontStyle.h"
#import "SCIAlignment.h"
#import "ISCIString.h"

/**
 * Provides a class whicih can draw `NSAttributedString` onto `CGContextRef`.
 */
@interface SCIDrawableText : NSObject<ISCIInvalidatableElement, ISCICleanable>

/**
 * Defines the string with label value for this annotation.
 */
@property (copy, nonatomic) NSString *text;

/**
 * Defines the attributed string with label value for this annotation.
 * @warning If set - Ignores the `labelValue`.
 */
@property (copy, nonatomic) NSAttributedString *attributedText;

/**
 * Defines the font style for text.
 */
@property (strong, nonatomic) SCIFontStyle *fontStyle;

/**
 * Gets or sets the rotation angle for this text in degrees.
 */
@property (nonatomic) float rotationAngle;

/**
 * Returns TickLabel size in `Pixels`.
 */
@property (nonatomic, readonly) CGSize drawableSize;

/**
 * The default spacing used when laying out internal text.
 * @note Sizes are in `Points`.
 */
@property (nonatomic) UIEdgeInsets padding;

/**
 * Returns DrawableText size including margins in `Points`.
 */
@property (nonatomic, readonly) CGSize sizeWithMargins;

#pragma mark - Draw

/**
 * Tries to draw this DrawableText instance onto `CGContextRef` at specified `CGPoint`.
 * @param context The `CGContextRef` instance to draw text on.
 */
- (void)tryDrawToCGContext:(CGContextRef)context;

/**
 * Draws this text instance inside passed in frame.
 * @param renderContext The render context instance to draw on.
 * @param assetManager The asset manager associated with render context.
 * @param frame The frame to draw text in.
 */
- (void)onDrawTextWithContext:(id<ISCIRenderContext2D>)renderContext assetManager:(id<ISCIAssetManager2D>)assetManager inFrame:(CGRect)frame;

@end
