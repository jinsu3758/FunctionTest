//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIRangeCalculatorHelperBase+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "ISCIRange.h"
#import "ISCIMath.h"
#import "ISCIAxisCore.h"

/*
 * The extensions in this header are to be used only by subclasses of `SCIRangeCalculatorHelperBase`.
 */
@interface SCIRangeCalculatorHelperBase<TAxis: id<ISCIAxisCore>> ()

@property (strong, nonatomic) id<ISCIRange> maximumRange;
@property (strong, nonatomic) id<ISCIRange> dataRange;
@property (strong, nonatomic) id<ISCIMath> math;
@property (weak, nonatomic) TAxis axis;

/**
 * Creates a new instance of `SCIRangeCalculatorHelperBase` class.
 * @param maximumRange The `ISCIRange` instance for storing maximum range.
 * @param dataRange The `ISCIRange` instance for storing data range.
 * @param math The `ISCIMath` instance used for calculations.
 */
- (instancetype)initWithAxisType:(Protocol *)type maximumRange:(id<ISCIRange>)maximumRange dataRange:(id<ISCIRange>)dataRange math:(id<ISCIMath>)math NS_DESIGNATED_INITIALIZER;

- (void)updateDataRange:(id<ISCIRange>)dataRange;

/**
 * Updates maximum range for attached axis.
 * @param maximumRange The range to update.
 * @param forceCacheUpdate Flag indicating whether the cached results should be updated.
 */
- (void)updateMaximumRange:(id<ISCIRange>)maximumRange forceCacheUpdate:(BOOL)forceCacheUpdate;

- (void)coerceZeroRange:(id<ISCIRange>)range;

- (void)growRange:(id<ISCIRange>)range by:(id<ISCIRange>)growBy;

- (void)coerceUndefinedRange:(id<ISCIRange>)range;

@end
