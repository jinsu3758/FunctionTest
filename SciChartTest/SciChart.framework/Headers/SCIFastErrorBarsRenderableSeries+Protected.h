//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIFastErrorBarsRenderableSeries+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIXyRenderableSeriesBase+Protected.h"
#import "SCIErrorBarsRenderPassData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The extensions in this header are to be used only by subclasses of `SCIFastErrorBarsRenderableSeries`.
 */
@interface SCIFastErrorBarsRenderableSeries ()

@property (strong, nonatomic) SCISmartProperty *strokeHighStyleProperty;
@property (strong, nonatomic) SCISmartProperty *strokeLowStyleProperty;

@property (strong, nonatomic) SCISmartPropertyInt *errorDirectionProperty;
@property (strong, nonatomic) SCISmartPropertyInt *errorModeProperty;
@property (strong, nonatomic) SCISmartPropertyInt *errorTypeProperty;

@property (strong, nonatomic) SCISmartPropertyDouble *dataPointWidthProperty;

@end

/**
 * The extensions in this header are to be used only by subclasses of `SCIFastErrorBarsRenderableSeries`.
 */
@interface SCIFastErrorBarsRenderableSeries (Protected)

/**
 * Creates a new instance of `SCIFastErrorBarsRenderableSeries` class.
 * @param renderPassData The render pass data instance.
 * @param hitProvider The hit provider instance.
 * @param nearestPointProvider The nearest point provider instance.
 */
- (instancetype)initWithRenderPassData:(SCIErrorBarsRenderPassData *)renderPassData hitProvider:(id<ISCIHitProvider>)hitProvider nearestPointProvider:(id<ISCINearestPointProvider>)nearestPointProvider;

@end

NS_ASSUME_NONNULL_END
