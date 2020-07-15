//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCIChartModifierCore.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIServiceProvider.h"
#import "ISCIReceiveEvents.h"
#import "ISCIThemeable.h"
#import "ISCIAttachable.h"
#import "ISCIRenderableSeriesChangeListener.h"
#import "ISCIChartModifierSurface.h"

/**
 * Definces the protocol to a core chart modifier `SCIChartModifierCore`, which can be used to extend the interactivity or rendering of the surface throughout SciChart.
 */
@protocol ISCIChartModifierCore <ISCIServiceProvider, ISCIReceiveEvents, ISCIThemeable, ISCIAttachable, ISCIRenderableSeriesChangeListener>

/**
 * Get or sets whether this `ISCIChartModifierCore` instance is enabled for interaction.
 */
@property (nonatomic) BOOL isEnabled;

/**
 * Gets a string ID used for propagating motion events from the master chart.
 * @note Returns the class name by default.
 */
@property (nonatomic, readonly) NSString *eventsGroupTag;

/**
 * Gets the parent `ISCIChartSurface.modifierSurface`.
 */
@property (weak, nonatomic, readonly) id<ISCIChartModifierSurface> modifierSurface;

@end
