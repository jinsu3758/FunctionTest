//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIMasterSlaveTouchModifierBase3D+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIMasterSlaveTouchModifierBase3D.h"
#import "SCITouchModifierBase3D+Protected.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIMasterSlaveTouchModifierBase3D`.
 */
@interface SCIMasterSlaveTouchModifierBase3D ()

/**
 * When overridden in derived classes, indicates whether touch point is valid for current modifier.
 * @param point The touch point to check.
 * @param isMaster Indicates whether this check is performed on the master `SCIChartSurface` instance.
 * @return YES if this modifier is enabled at the point, else - NO.
 */
- (BOOL)isEnabledAt:(CGPoint)point withIsMaster:(BOOL)isMaster;

/**
 * Updates the passed in current point when one of the following methods was called:
 * - `-handleTouchesBeganAt:withIsMaster:`
 * - `-handleTouchesMovedAt:withIsMaster:`
 * - `-handleTouchesEndedAt:withIsMaster:`
 * @param args The `SCIModifierEventArgs` which is used to update the passed in currentPoint.
 * @return The point where the above methods where performed.
 */
- (CGPoint)getCurrentPointWithArgs:(SCIModifierEventArgs *)args;

/**
 * When overridden in a derived class, this method should clear all markers and tooltips from the `SCIChartSurface.chartModifierSurface`.
 */
- (void)clearAll;

/**
 * When overridden in a derived class, called to handle the Masert or Slave `SCIChartModifierBase` `SCIEventStateBegan`.
 * @param point The current touch point
 * @param isMaster Indicates whether this check is performed on the master `SCIChartSurface` instance.
 */
- (void)handleTouchesBeganAt:(CGPoint)point withIsMaster:(BOOL)isMaster;

/**
 * When overridden in a derived class, called to handle the Masert or Slave `SCIChartModifierBase` `SCIEventStateMoved`.
 * @param point The current touch point
 * @param isMaster Indicates whether this check is performed on the master `SCIChartSurface` instance.
 */
- (void)handleTouchesMovedAt:(CGPoint)point withIsMaster:(BOOL)isMaster;
/**
 * When overridden in a derived class, called to handle the Masert or Slave `SCIChartModifierBase` `SCIEventStateEnded`.
 * @param point The current touch point
 * @param isMaster Indicates whether this check is performed on the master `SCIChartSurface` instance.
 */
- (void)handleTouchesEndedAt:(CGPoint)point withIsMaster:(BOOL)isMaster;

@end
