//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCILegendDataSource.h is part of SCICHART®, High Performance Scientific Charts
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

#import <UIKit/UIKit.h>
#import "SCIObservableCollection.h"
#import "SCIChartLegend.h"
#import "ISCILegendDataSourceObserver.h"
#import "ISCILegendItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the dataSource for `SCIChartLegend`.
 */
@interface SCILegendDataSource : NSObject<UICollectionViewDataSource, ISCILegendDataSourceObserver>

/**
 * Gets or sets the list of series info to display in `SCIChartLegend`.
 */
@property (nonatomic) SCIObservableCollection *dataSet;

/**
 * Gets the xib name which is used to register nib for cell with reuse identifier, which later used to dequeue the legend items.
 */
@property (nonatomic, readonly) NSString *legendItemXibName;

/**
 * Creates a new instance of the `SCILegendDataSource` class.
 * @param legend The `SCIChartLegend` whith which this data source is associated.
 * @param legendItemXibName The xib name which is used to register nib for cell with reuse identifier, which later used to dequeue the legend items.
 * Assosiated class of this view must conform to `ISCILegendItem`.
 */
- (instancetype)initWithLegend:(UICollectionView<ISCIChartLegend> *)legend legendItemXibName:(nullable NSString *)legendItemXibName;

@end

NS_ASSUME_NONNULL_END
