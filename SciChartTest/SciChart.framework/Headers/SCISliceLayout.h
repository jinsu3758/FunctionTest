//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCISliceLayout.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIViewContainer.h"

@class SCIVerticalSliceBehaviorBase;

/**
 * A default layout which is used to place `SCISlice`.
 */
@interface SCISliceLayout : SCIViewContainer

/**
 * Creates a new instance of `SCISliceLayout` class.
 * @param behavior The `SCIVerticalSliceBehaviorBase` instance to be used in this `SCISliceLayout` instance.
 */
- (instancetype)initWithBehavior:(SCIVerticalSliceBehaviorBase *)behavior;

/**
 * Arranges child `SCISlice`s.
 */
- (void)arrangeSubviews;

@end
