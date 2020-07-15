//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIBrushColorPalette.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIMeshColorPalette.h"

@class SCIBrushStyle;

/**
 * Defines a color palette converted from `SCIBrushStyle` which can be used with `SCISurfaceMeshRenderableSeries3D` and `SCIFreeSurfaceRenderableSeries3D` e.g. to give a height-map at runtime.
 */
@interface SCIBrushColorPalette : SCIMeshColorPalette

/**
 * Creates a new instance of `SCIBrushColorPalette` class.
 * @param brushStyle The `SCIBrushStyle` to use.
 */
- (nonnull instancetype)initWithBrushStyle:(nonnull SCIBrushStyle *)brushStyle;

@end
