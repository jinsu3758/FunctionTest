//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIModifierEventArgs.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIEvent.h"
#import "ISCICleanable.h"

@protocol ISCIReceiveEvents;

/**
*  Defines a event args, used by various classes within SciChart to process motion events.
*/
@interface SCIModifierEventArgs : NSObject<ISCICleanable>

/**
 * Source of the event.
 */
@property (weak, nonatomic) id<ISCIReceiveEvents> source;

/**
 * If YES - then this event occurred on a master `ISCIPublishEvents`.
 */
@property (nonatomic) BOOL isMaster;

/**
 * If YES - then this  event occurred inside the master `ISCIPublishEvents`.
 */
@property (nonatomic) BOOL isInSourceBounds;

/**
 * Gets or sets whether this event is Handled.
 */
@property (nonatomic) BOOL isHandled;

/**
 * The `ISCIEvent` instance.
 */
@property (strong, nonatomic) id<ISCIEvent> e;

@end
