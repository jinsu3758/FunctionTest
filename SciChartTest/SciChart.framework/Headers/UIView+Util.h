//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// UIView+Util.h is part of SCICHART®, High Performance Scientific Charts
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

/**
 * :nodoc:
 */
@interface UIView (Util)

/**
 * Adds a child if the `child` is not nil and if the `UIView` does not contain the `child`.
 * @param child The child to be added into the `UIView`.
 */
- (void)safeAddSubview:(UIView *)child;

/**
 * Adds a child at specified index if the `child` is not nil and if the `UIView` does not contain the `child`.
 * @param child The child to be added into the `UIView`.
 * @param index The position at which to add the child.
 */
- (void)safeInsertSubview:(UIView *)child atIndex:(int)index;

/**
 * Remove a child if the `child` is not nil and if `UIView` contains the `child`.
 * @param child The child to be removed from the `UIView`.
 */
- (void)safeRemoveFromSuperview:(NSObject *)child;

@end
