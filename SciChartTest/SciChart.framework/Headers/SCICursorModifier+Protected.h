//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCICursorModifier+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCICursorModifier.h"
#import "SCITooltipModifierWithAxisLabelsBase+Protected.h"
#import "SCISmartProperty.h"
#import "SCICursorTooltipBehavior.h"
#import "SCIAxisTooltipsBehaviorBase.h"
#import "SCICursorCrosshairDrawableBehavior.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCICursorModifier`.
 */
@interface SCICursorModifier ()

@property (strong, nonatomic) SCISmartProperty *crosshairPenStyleProperty;

/**
 * Creates a new instance of `SCICursorModifier` class.
 * @param cursorTooltipBehavior `SCICursorTooltipBehavior` which will be associated with this modifier.
 * @param axisTooltipsBehavior  `SCIAxisTooltipsBehavior` which will be associated with this modifier.
 * @param crosshairDrawableBehavior `SCICursorCrosshairDrawableBehavior` which will be associated with this modifier.
 */
- (instancetype)initWithCursorBehavior:(SCICursorTooltipBehavior *)cursorTooltipBehavior axisTooltipsBehavior:(SCIAxisTooltipsBehaviorBase *)axisTooltipsBehavior andCrosshairDrawableBehavior:(SCICursorCrosshairDrawableBehavior *)crosshairDrawableBehavior NS_DESIGNATED_INITIALIZER;

@end
