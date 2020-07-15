//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIChartModifierCollectionCore.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIObservableCollection.h"
#import "ISCIAttachable.h"
#import "ISCIServiceProvider.h"
#import "ISCICommonInitializer.h"
#import "ISCIChartModifierCore.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the core implementation of a collection of `ISCIChartModifier`.
 */
@interface SCIChartModifierCollectionCore<T : id<ISCIChartModifierCore>> : SCIObservableCollection<T><ISCIAttachable, ISCIServiceProvider, ISCICommonInitializer>

/**
 * Initializes a new instance of `SCIChartModifierCollection` class.
 * @param collection The collections with items to add.
 */
- (instancetype)initWithCollection:(NSArray<T> *)collection;

/**
 * Attaches this instance to `ISCIServiceContainer` instance.
 * @param services The target `ISCIServiceContainer` instance.
 * @param subscribeToEvents Specifies whether to subscribe to the event services of `services`.
 */
- (void)attachToServices:(id<ISCIServiceContainer>)services subscribeToEvents:(BOOL)subscribeToEvents;

@end

NS_ASSUME_NONNULL_END
