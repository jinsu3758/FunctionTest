//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIContourMeshRenderableSeries3DBase+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIBaseRenderableSeries3D+Protected.h"
#import "SCIContourMeshRenderableSeries3DBase.h"
#import "SCISmartPropertyInt.h"
#import "SCISmartPropertyFloat.h"
#import "SCISmartProperty.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIContourMeshRenderableSeries3DBase`.
 */
@interface SCIContourMeshRenderableSeries3DBase ()

@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *drawMeshAsProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *strokeProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *strokeThicknessProperty;

@property (nonnull, nonatomic, readonly) SCISmartProperty *meshColorPaletteProperty;
@property (nonnull, nonatomic, readonly) SCISmartProperty *meshColorPaletteSizeProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *meshPaletteModeProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *cellHardnessFactorProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *highlightProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *lightingFactorProperty;

@property (nonnull, nonatomic, readonly) SCISmartPropertyInt *contourStrokeProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *contourOffsetProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *contourIntervalProperty;
@property (nonnull, nonatomic, readonly) SCISmartPropertyFloat *contourStrokeThicknessProperty;

@end
