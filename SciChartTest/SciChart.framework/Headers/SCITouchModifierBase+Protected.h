//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCITouchModifierBase+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCITouchModifierBase.h"
#import "SCIModifierEventArgs.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCITouchModifierBase`.
 */
@interface SCITouchModifierBase (Protected)

/**
 * Called when `SCIEventStateBegan` event occurs.
 * @param args The touch event args for this event.
 * @return True if the event was handled, false otherwise..
 */
- (BOOL)onTouchesBegan:(SCIModifierEventArgs *)args;

/**
 * Called when `SCIEventStateMoved` event occurs.
 * @param args The touch event args for this event.
 * @return True if the event was handled, false otherwise..
 */
- (BOOL)onTouchesMoved:(SCIModifierEventArgs *)args;

/**
 * Called when `SCIEventStateEnded` event occurs.
 * @param args The touch event args for this event.
 * @return True if the event was handled, false otherwise..
 */
- (BOOL)onTouchesEnded:(SCIModifierEventArgs *)args;

/**
 * Called when `SCIEventStateCancelled` event occurs.
 * @param args The touch event args for this event.
 * @return True if the event was handled, false otherwise..
 */
- (BOOL)onTouchesCancelled:(SCIModifierEventArgs *)args;

@end
