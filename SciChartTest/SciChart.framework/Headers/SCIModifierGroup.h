//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIModifierGroup.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIChartModifierBase.h"
#import "ISCIReceiveEventGroup.h"
#import "ISCIChartModifier.h"
#import "SCIChartModifierCollection.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Allows a collection of modifiers to be added to the `ISCIChartSurface.chartModifiers`.
 * @note Child modifiers are stored in the `childModifiers` collection.
 */
@interface SCIModifierGroup : SCIChartModifierBase<ISCIReceiveEventGroup>

/**
 * Defines the ID of the motion event group, which is used to share motion events across multiple targets.
*/
@property (nonatomic) NSString *eventGroup;

/**
 * Gets the collection of the `ISCIChartModifier` in this group.
 */
@property (nonatomic, readonly) SCIChartModifierCollection *childModifiers;

/**
 * Creates a new `SCIModifierGroup` instance with childModifiers collection.
 * @param childModifiers The child modifiers.
 */
- (instancetype)initWithChildModifiers:(NSArray<id<ISCIChartModifier>> *)childModifiers;

/**
 * Looks for a `ISCIChartModifier` with the specified eventsGroupTag in the collection of child modifiers.
 * @param eventGroupTag Tag of the event group.
 * @return The `ISCIChartModifier` instance associated with eventsGroupTag.
 */
- (nullable id<ISCIChartModifier>)getChildModifierByTag:(NSString *)eventGroupTag;

@end

NS_ASSUME_NONNULL_END
