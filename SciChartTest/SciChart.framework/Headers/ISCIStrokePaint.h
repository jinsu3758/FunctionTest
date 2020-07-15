//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIStrokePaint.h is part of SCICHART®, High Performance Scientific Charts
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
#import <CoreGraphics/CoreGraphics.h>

@class SCIPenStyle;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines a protocol which provides a way to draw lines, rects, ellipses or `CGPathRef` on `CGContextRef`.
 */
@protocol ISCIStrokePaint <NSObject>

/**
 * Paints a rectangle stroke on passed in `CGContextRef`.
 * @param rect The rectangle, specified in user space coordinates.
 * @param context The graphics context to draw on.
 */
- (void)drawRect:(CGRect)rect inContext:(CGContextRef)context;

/**
 * Paints an ellipse stroke that fits inside the specified rectangle in passed in.
 * @param rect The rectangle that defines the area for the ellipse to fit in.
 * @param context The graphics context to draw on.
 */
- (void)drawEllipseInRect:(CGRect)rect inContext:(CGContextRef)context;

/**
 * Paints a `CGPathRef` stroke on passed in `CGContextRef`.
 * @param path The `CGPathRef` instange to be drawn on the `context`
 * @param context The graphics context to draw on.
 */
- (void)drawPath:(CGPathRef)path inContext:(CGContextRef)context;

/**
 * Paints lines strokes on passed in `CGContextRef`.
 * @param coordinates Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param count The amount of points to draw.
 * @param context The graphics context to draw on.
 */
- (void)drawLines:(CGFloat *)coordinates count:(int)count inContext:(CGContextRef)context;

@end

NS_ASSUME_NONNULL_END
