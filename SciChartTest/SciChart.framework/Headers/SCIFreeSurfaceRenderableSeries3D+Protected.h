//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIFreeSurfaceRenderableSeries3D+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIFreeSurfaceRenderableSeries3D.h"
#import "SCISmartPropertyInt.h"
#import "SCISmartPropertyFloat.h"
#import "SCISmartProperty.h"
#import "SCISmartPropertyBool.h"
#import "SCIContourMeshRenderableSeries3DBase+Protected.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIFreeSurfaceRenderableSeries3D`.
 */
@interface SCIFreeSurfaceRenderableSeries3D ()

@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *paletteMinMaxModeProperty;
@property (nonnull, nonatomic, readonly) SCISmartProperty *paletteMinimumProperty;
@property (nonnull, nonatomic, readonly) SCISmartProperty *paletteMaximumProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *paletteRadialFactorProperty;
@property (nonnull, nonatomic, readonly) SCISmartProperty *paletteAxialFactorProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *paletteAzimuthalFactorProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *palettePolarFactorProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyBool *drawBackSideProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *contourAxisProperty;

@end
