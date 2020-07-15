//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIEvent.h is part of SCICHART®, High Performance Scientific Charts
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
#import <UIKit/UIKit.h>

/**
 * Defines the type of the event.
 */
typedef NS_ENUM(NSUInteger, SCIEventType) {
    /// Defines the `Touch` event.
    SCIEventTypeTouch
};

/**
 * Defines the event state.
 */
typedef NS_ENUM(NSUInteger, SCIEventState) {
    /// Began  `ISCIEvent` State.
    SCIEventStateBegan,
    /// Moved  `ISCIEvent` State.
    SCIEventStateMoved,
    /// Ended  `ISCIEvent` State.
    SCIEventStateEnded,
    /// Cancelled `ISCIEvent` State.
    SCIEventStateCancelled
};

/**
 * Defines protocol, which is used to report movement events.
 */
@protocol ISCIEvent<NSObject>

/**
 * Defines the type of this event.
 * @see `SCIEventType`.
 */
@property (nonatomic, readonly) SCIEventType type;

/**
 * Get the location where this event occured.
 */
@property (nonatomic, readonly) CGPoint location;

/**
 * Gets number of pointers which used to generate this `ISCIEvent`.
 */
@property (nonatomic, readonly) int pointersCount;

@end
