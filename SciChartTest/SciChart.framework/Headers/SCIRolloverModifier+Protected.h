//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIRolloverModifier+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIRolloverModifier.h"
#import "SCIRolloverBehavior.h"
#import "SCISmartProperty.h"
#import "SCIAxisTooltipsBehaviorBase.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIRolloverModifier`.
 */
@interface SCIRolloverModifier ()

@property (strong, nonatomic) SCISmartProperty *verticalLineStyleProperty;

/**
 * Creates a new instance of `SCIRolloverModifier` class.
 * @param rolloverBehavior `SCIRolloverBehavior` which will be associated with this modifier.
 * @param axisTooltipsBehavior  `SCIAxisTooltipsBehavior` which will be associated with this modifier.
 */
- (instancetype)initWithRolloverBehavior:(SCIRolloverBehavior *)rolloverBehavior axisTooltipsBehavior:(SCIAxisTooltipsBehaviorBase *)axisTooltipsBehavior NS_DESIGNATED_INITIALIZER;

@end
