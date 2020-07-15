//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIPieRenderableSeriesCollection.h is part of SCICHART®, High Performance Scientific Charts
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
#import "ISCIPieRenderableSeries.h"

/**
 * Contains a collection of `ISCIPieRenderableSeries`
 */
@interface SCIPieRenderableSeriesCollection : SCIObservableCollection<id<ISCIPieRenderableSeries>>

/// :nodoc:
- (instancetype)initWithParent:(SCIPieChartSurface *)parent;
/// :nodoc:
- (instancetype)initWithCollection:(NSArray<id<ISCIPieRenderableSeries>> *)collection parent:(SCIPieChartSurface *)parent;

@end
