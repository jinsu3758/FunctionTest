//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// CoreGraphicsExtensions.h is part of SCICHART®, High Performance Scientific Charts
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
#import <CoreText/CoreText.h>

/**
 * :nodoc:
 */
CG_INLINE CGSize CGSizeMakeScaled(CGSize size, CGFloat scale) {
    CGSize result;
    result.width = size.width * scale;
    result.height = size.height * scale;
    
    return result;
}

/**
 * :nodoc:
 */
CG_INLINE CGSize MeasureAttributedString(NSAttributedString *string) {
    CTFramesetterRef frameSetter = CTFramesetterCreateWithAttributedString((CFAttributedStringRef)string);
    
    CGSize size = CTFramesetterSuggestFrameSizeWithConstraints(frameSetter, CFRangeMake(0, 0),  nil, CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX), nil);
    
    CFRelease(frameSetter);
    
    return CGSizeMake(ceil(size.width), ceil(size.height));
}

/**
 * :nodoc:
 */
CG_INLINE void DrawAttributedString(CGContextRef context, NSAttributedString *string, CGRect rect) {
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, nil, rect);
    CTFramesetterRef frameSetter = CTFramesetterCreateWithAttributedString((CFAttributedStringRef)string);
    CTFrameRef frame = CTFramesetterCreateFrame(frameSetter, CFRangeMake(0, string.length), path, nil);
    
    CTFrameDraw(frame, context);
    
    CGPathRelease(path);
    CFRelease(frameSetter);
    CFRelease(frame);
}

/**
 * :nodoc:
 */
CG_INLINE CGPoint ToPointRelativeToBounds(CGPoint point, CGRect bounds) {
    CGPoint result = { point.x - bounds.origin.x, point.y - bounds.origin.y };
    
    return result;
}

/**
 * :nodoc:
 */
CG_INLINE CGPoint FromPointRelaviveToBounds(CGPoint point, CGRect bounds) {
    CGPoint result = { point.x + bounds.origin.x, point.y + bounds.origin.y };
    return result;
}
