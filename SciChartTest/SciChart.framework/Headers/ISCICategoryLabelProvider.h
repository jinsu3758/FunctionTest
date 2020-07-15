//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// ISCICategoryLabelProvider.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCILabelProvider.h"
#import "SCISearchMode.h"

/**
 * Protocol to define a `LabelProvider` for category axes
 */
@protocol ISCICategoryLabelProvider <ISCILabelProvider>

/**
 * Gets the Bar Time Frame in seconds. This is the number of seconds that each data-point represents on the `SCICategoryDateAxis` and is required for proper rendering.
 */
@property (nonatomic, readonly) double barTimeFrame;

/**
 * Transforms an index of a data point to the corresponding `NSDate` data value.
 * @param index The index
 * @return The data value
 */
- (NSDate *)transformIndexToData:(NSInteger)index NS_SWIFT_NAME(transformIndexToData(_:));

/**
 * Transforms a `NSDate` value to the nearest data point index.
 * @param dataValue The `NSDate` value
 * @return The index of the data point
 */
- (NSInteger)transformDataToIndex:(NSDate *)dataValue NS_SWIFT_NAME(transformDataToIndex(_:));

/**
 * Transforms a `NSDate` value to the corresponding data point index using the specified search mode.
 * @param dataValue The `NSDate` value
 * @param mode The search mode
 * @return The index of data point
 */
- (NSInteger)transformDataToIndex:(NSDate *)dataValue withSearchMode:(SCISearchMode)mode NS_SWIFT_NAME(transformDataToIndex(_:searchMode:));

@end
