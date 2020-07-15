//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIReceiveEventGroup.h is part of SCICHART®, High Performance Scientific Charts
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
#import "ISCIReceiveEvents.h"
#import "ISCIHitTestable.h"

/**
 * Defines the interface to a group which receives unified events.
 */
@protocol ISCIReceiveEventGroup <ISCIReceiveEvents>

/**
 * Gets the ID of the motion event group, which is used to share motion events across multiple targets.
 */
@property (nonatomic, readonly) NSString *eventGroup;

/**
 * Gets the `ISCIHitTestable` source of motion events.
 */
@property (nonatomic, readonly) id<ISCIHitTestable> eventsSource;

/**
 * Transforms a point relative to the specified `ISCIHitTestable` instance.
 * @param point The point to transform.
 * @param relativeTo The target `ISCIHitTestable` instance.
 * @return The transformed point.
 */
- (CGPoint)getPoint:(CGPoint)point relativeTo:(id<ISCIHitTestable>)relativeTo;

@end
