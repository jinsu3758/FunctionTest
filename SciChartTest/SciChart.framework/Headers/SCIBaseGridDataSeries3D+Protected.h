//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIBaseGridDataSeries3D+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIBaseGridDataSeries3D.h"
#import "SCIDataSeriesCore+Protected.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIBaseGridDataSeries3D`.
 */
@interface SCIBaseGridDataSeries3D ()

@property (nonatomic) SCIGridData<id<ISCIComparable>> *yValues;
@property (nonatomic) NSInteger xSize;
@property (nonatomic) NSInteger zSize;
@property (nonatomic) NSInteger count;

/**
 * Creates a new `BaseGridDataSeries3D` instance.
 * @param xType The type of `X-Data`.
 * @param yType The type of `Y-Data`.
 * @param zType The type of `Z-Data`.
 * @param xSize The size of the X.
 * @param zSize The size of the Z.
 */
- (instancetype)initWithXType:(SCIDataType)xType yType:(SCIDataType)yType zType:(SCIDataType)zType xSize:(NSInteger)xSize zSize:(NSInteger)zSize;

@end
