//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIRenderContext2D.h is part of SCICHART®, High Performance Scientific Charts
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

#import <CoreGraphics/CoreGraphics.h>
#import "ISCIDisposable.h"
#import "ISCIPen2D.h"
#import "ISCIBrush2D.h"
#import "ISCITexture2D.h"
#import "ISCIPathDrawingContext.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the protocol to a 2D RenderContext, allowing rendering of pens, brushes, sprites and textures on the `ISCIRenderSurface`.
 */
@protocol ISCIRenderContext2D <ISCIDisposable>

/**
 * The viewport size in user space coordinate system.
 */
@property (nonatomic, readonly) CGSize viewportSize;

#pragma mark - Draw Lines

/**
 * Draws a single line on the `ISCIRenderSurface` using the specified `ISCIPen2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw line with.
 * @param start The start point coordinates.
 * @param end The end point coordinates.
 */
- (void)drawLineWithPen:(id<ISCIPen2D>)pen atStart:(CGPoint)start end:(CGPoint)end;

/**
 * Begins a line segment, returning the `ISCIPathDrawingContext`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen for line segment.
 * @param point The point coordinates.
 * @return The `ISCIPathDrawingContext` to continue the line.
 */
- (id<ISCIPathDrawingContext>)beginLineWithPen:(id<ISCIPen2D>)pen at:(CGPoint)point;

/**
 * Draws a series of lines. Each line is taken from 4 consecutive values in the points array.
 * Thus to draw 1 line, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw lines with.
 * @param points Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawLinesWithPen:(id<ISCIPen2D>)pen points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Draws a lines strip. Each line is taken from 4 consecutive values in the points array.
 * Thus to draw 1 line, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw lines with.
 * @param points Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawLinesStripWithPen:(id<ISCIPen2D>)pen points:(float *)points startIndex:(int)startIndex count:(int)count;

#pragma mark - Draw Triangles Strip

/**
 * Draws a triangle strip. Each line is taken from 6 consecutive values in the points array.
 * Thus to draw 1 triangle, the array must contain at least 6 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param brush The brush to fill triangles with.
 * @param points Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawTrianglesStripWithBrush:(id<ISCIBrush2D>)brush points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Begins a filled triangle strips segment, returning the `ISCIPathDrawingContext`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param brush The brush for triangle strips segment.
 * @param point The point coordinates.
 * @return The `ISCIPathDrawingContext` to continue the line.
 */
- (id<ISCIPathDrawingContext>)beginTrianglesStripWithBrush:(id<ISCIBrush2D>)brush at:(CGPoint)point;

#pragma mark - Draw Rects

/**
 * Draws a single rectangle on the `ISCIRenderSurface` using the specified `ISCIPen2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param rect The CGRect coordinates.
 * @param pen The pen to draw rect with.
 */
- (void)drawRect:(CGRect)rect withPen:(id<ISCIPen2D>)pen;

/**
 * Fills a single rectangle on the `ISCIRenderSurface` using the specified `ISCIBrush2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param rect The CGRect coordinates.
 * @param brush The brush to fill rectangle with.
 */
- (void)fillRect:(CGRect)rect withBrush:(id<ISCIBrush2D>)brush;

/**
 * Draws a series of rectangles. Each point for sprite is taken from 4 consecutive values in the points array.
 * Thus to draw 1 rectangle, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw rectangles with.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawRectsWithPen:(id<ISCIPen2D>)pen points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Fills a series of rectangles. Each point for sprite is taken from 4 consecutive values in the points array.
 * Thus to draw 1 rectangle, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param brush The brush to fill rectangles with.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)fillRectsWithBrush:(id<ISCIBrush2D>)brush points:(float *)points startIndex:(int)startIndex count:(int)count;

#pragma mark - Draw Ellipses

/**
 * Draws a single ellipse on the `ISCIRenderSurface` using the specified `ISCIPen2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw ellipse stroke with.
 * @param size The size of ellipse.
 * @param center The center coordinates. 
 */
- (void)drawEllipseWithPen:(id<ISCIPen2D>)pen andSize:(CGSize)size at:(CGPoint)center;

/**
 * Draws a single ellipse on the `ISCIRenderSurface` using the specified `ISCIBrush2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param brush The brush to fill ellipse with.
 * @param size The size of ellipse.
 * @param center The center coordinates.
 */
- (void)fillEllipseWithBrush:(id<ISCIBrush2D>)brush andSize:(CGSize)size at:(CGPoint)center;

/**
 * Draws a single ellipse on the `ISCIRenderSurface` using the specified `ISCIBrush2D` and `ISCIPen2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw ellipse stroke with.
 * @param brush The brush to fill ellipse with.
 * @param size The size of ellipse.
 * @param center The center coordinates.
 */
- (void)drawEllipseWithPen:(id<ISCIPen2D>)pen brush:(id<ISCIBrush2D>)brush andSize:(CGSize)size at:(CGPoint)center;

/**
 * Draws a series of ellipses. Each point for sprite is taken from 4 consecutive values in the points array representing rectangle in which each ellipse will be drawn.
 * Thus to draw 1 ellipse, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw ellipse stroke with.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawEllipsesWithPen:(id<ISCIPen2D>)pen points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Draws a series of ellipses. Each point for sprite is taken from 4 consecutive values in the points array representing rectangle in which each ellipse will be drawn.
 * Thus to draw 1 ellipse, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.*
 * @param brush The brush to fill ellipses with.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)fillEllipsesWithBrush:(id<ISCIBrush2D>)brush points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Draws a series of ellipses. Each point for sprite is taken from 4 consecutive values in the points array representing rectangle in which each ellipse will be drawn.
 * Thus to draw 1 ellipse, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param pen The pen to draw ellipse stroke with.
 * @param brush The brush to fill ellipses with.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawEllipsesWithPen:(id<ISCIPen2D>)pen brush:(id<ISCIBrush2D>)brush points:(float *)points startIndex:(int)startIndex count:(int)count;

#pragma mark - Draw Textures

/**
 * Fills a single rectangle on the `ISCIRenderSurface` using the specified `ISCITexture2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param texture The texture to draw.
 * @param rect The rect coordinates to draw texture in.
 */
- (void)drawTexture:(id<ISCITexture2D>)texture inRect:(CGRect)rect;

/**
 * Fills a single rectangle on the `ISCIRenderSurface` using the specified `ISCITexture2D`.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param texture The texture to draw.
 * @param rect The rect coordinates to draw texture in.
 * @param opacity The opacity to draw texture with.
 */
- (void)drawTexture:(id<ISCITexture2D>)texture inRect:(CGRect)rect withOpacity:(float)opacity;

/**
 * Draws a series of textures. Each point for sprite is taken from 4 consecutive values in the points array.
 * Thus to draw 1 texture, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.*
 * @param texture The texture to draw.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawTextures:(id<ISCITexture2D>)texture points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Draws a series of textures. Each point for sprite is taken from 4 consecutive values in the points array.
 * Thus to draw 1 texture, the array must contain at least 4 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param texture The texture to draw.
 * @param points Array of points to draw `[x0, y0, x1, y1...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 * @param opacity The opacity to draw texture with.
 */
- (void)drawTextures:(id<ISCITexture2D>)texture points:(float *)points startIndex:(int)startIndex count:(int)count opacity:(float)opacity;

/**
 * Sets the texture pixels based on values provided by pixels array.
 * @param texture The texture to set pixels for.
 * @param pixels The array with values of texture pixels.
 */
- (void)updateTexture:(id<ISCITexture2D>)texture withPixels:(unsigned int *)pixels;

/**
 * Sets the region of texture pixels based on values provided by pixels array.
 * @param texture The texture to set pixels for.
 * @param pixels The array with values of texture pixels.
 */
- (void)updateFloatTexture:(id<ISCITexture2D>)texture withPixels:(float *)pixels;

#pragma mark - Draw Sprites

/**
 * Draws a sprite at specified `x, y` coordinate.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param sprite The sprite to draw.
 * @param point The sprite coordinates.
 */
- (void)drawSprite:(id<ISCITexture2D>)sprite at:(CGPoint)point;

/**
 * Draws a sprite at specified `x, y` coordinate.
 * @note Please note, that coordinates should be provided in user space coordinate system.*
 * @param sprite The sprite to draw.
 * @param point The sprite coordinates.
 * @param opacity The opacity to draw sprite with.
 */
- (void)drawSprite:(id<ISCITexture2D>)sprite at:(CGPoint)point withOpacity:(float)opacity;

/**
 * Draws a series of sprites. Each point for sprite is taken from 2 consecutive values in the points array.
 * Thus to draw 1 sprite, the array must contain at least 2 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param sprite The spite to draw.
 * @param points Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 */
- (void)drawSprites:(id<ISCITexture2D>)sprite points:(float *)points startIndex:(int)startIndex count:(int)count;

/**
 * Draws a series of sprites. Each point for sprite is taken from 2 consecutive values in the points array.
 * Thus to draw 1 sprite, the array must contain at least 2 values.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param sprite The spite to draw.
 * @param points Array of points to draw `[x0, y0, x1, y1, x2, y2 ...]`.
 * @param startIndex Start index in points array to start drawing with.
 * @param count The amount of points to draw from points array.
 * @param opacity The opacity to draw sprite with.
 */
- (void)drawSprites:(id<ISCITexture2D>)sprite points:(float *)points startIndex:(int)startIndex count:(int)count opacity:(float)opacity;

#pragma mark - Draw Heatmap

/**
 * Draws a single heatmap on the `ISCIRenderSurface` using the specified float texture and gradient color map.
 * @note Please note, that coordinates should be provided in user space coordinate system.
 * @param heatmap The heatmap texture with normalized float values which will be converted to colors using `colorMap`.
 * @param rect The rect coordinates to draw texture in.
 * @param colorMap The colorMap texture, which will be used to calculate colors for heatmap normalized values.
 */
- (void)drawHeatmapTexure:(id<ISCITexture2D>)heatmap inRect:(CGRect)rect andColorMap:(id<ISCITexture2D>)colorMap;

#pragma mark - Draw Text

// TODO: Implement Text Drawing Context, to be able to draw heatmap with text

#pragma mark - Transformations

/**
 * Saves the current transformation and clip rect onto a private stack.
 */
- (void)save;

/**
 * This call balances a previous call to `-save`.
 * It's used to remove all modifications made by `-translateXBy:yBy:`, `rotateByDegrees:`,  `-scaleXBy:yBy:` and `-setClipRect:` calls since the last save call.
 * @warning Make sure, to synchronize your `-save` and `-restore` calls. It is an error to call `-restore` more times than `-save` was called.
 */
- (void)restore;

/**
 * Translates this `ISCIRenderContext2D` by specified x, y offset.
 * @param deltaX The x offset in pixels.
 * @param deltaY The y offset in pixels.
 */
- (void)translateXBy:(float)deltaX yBy:(float)deltaY;

/**
 * Rotates this `ISCIRenderContext2D` on specified angle.
 * @param angle The amount to rotate, in degrees.
 */
- (void)rotateByDegrees:(float)angle;

/**
 * Scales this `ISCIRenderContext2D` by the provided x, y values.
 * @param scaleX The amount to scale in x direction.
 * @param scaleY The amount to scale in y direction.
 */
- (void)scaleXBy:(float)scaleX yBy:(float)scaleY;

/**
 * Sets clip rect for this `ISCIRenderContext2D` at specified coordinates in pixels.
 * @param clipRect The rect which will be used to clip this render context.
 */
- (void)setClipRect:(CGRect)clipRect;

/**
 * Clears the `ISCIRenderSurface`.
 */
- (void)clear;

@end

NS_ASSUME_NONNULL_END
