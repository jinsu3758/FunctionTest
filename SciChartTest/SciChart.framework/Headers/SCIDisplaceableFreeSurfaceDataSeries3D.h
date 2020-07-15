//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIDisplaceableFreeSurfaceDataSeries3D.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIFreeSurfaceDataSeries3D.h"
#import "ISCIDisplaceableFreeSurfaceDataSeries3DValues.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 2D grid based free shaped 3D surface with displacement.
 */
@interface SCIDisplaceableFreeSurfaceDataSeries3D : SCIFreeSurfaceDataSeries3D<ISCIDisplaceableFreeSurfaceDataSeries3DValues>

/**
 * Sets the displacement at specified position.
 * @param uIndex The uIndex of point to update.
 * @param vIndex The vIndex of point to update.
 * @param displacement The new yValue.
 */
- (void)setDisplacement:(id<ISCIComparable>)displacement uIndex:(NSInteger)uIndex vIndex:(NSInteger)vIndex NS_REFINED_FOR_SWIFT;

/**
 * Pushes a row into the data series, which discards one old row in a First In First Out fashion. use this method to scroll the SCIGridData in the Z-direction.
 * @param array The row with new values.
 */
- (void)pushArrayRow:(NSArray *)array NS_REFINED_FOR_SWIFT;

/**
 * Pushes a row into the data series, which discards one old row in a First In First Out fashion. use this method to scroll the SCIGridData in the Z-direction.
 * @param values The row with new values.
 */
- (void)pushValuesRow:(id<ISCIValues>)values NS_SWIFT_NAME(push(_:));

/**
 * Sets the row at the specified Z index.
 * @param index The z-index to use.
 * @param row The row with new values.
 */
- (void)setArrayRow:(NSArray<id<ISCIComparable>> *)row at:(NSInteger)index NS_REFINED_FOR_SWIFT;

/**
 * Sets the row at the specified Z index.
 * @param index The z-index to use.
 * @param row The row with new values.
 */
- (void)setValuesRow:(id<ISCIValues>)row at:(NSInteger)index NS_SWIFT_NAME(set(_:at:));

/**
 * Copies array to this instance.
 * @param array The array to copy from.
 */
- (void)copyFromArray:(NSArray<id<ISCIComparable>> *)array NS_REFINED_FOR_SWIFT;

/**
 * Copies values to this instance.
 * @param values Values to copy from.
 */
- (void)copyFromValues:(id<ISCIValues>)values;

@end

NS_ASSUME_NONNULL_END
