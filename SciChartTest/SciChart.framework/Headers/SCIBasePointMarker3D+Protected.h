//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIBasePointMarker3D+Protected.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIMarkerType.h"
#import "SCISmartPropertyInt.h"
#import "SCISmartPropertyFloat.h"
#import "SCIBasePointMarker3D.h"

/**
 * The extensions in this header are to be used only by subclasses of `SCIBasePointMarker3D`.
 */
@interface SCIBasePointMarker3D ()

@property (nonatomic, readonly) SCIFloatPropertyChangeListener floatInvalidateElementListener;
@property (nonatomic, readonly) SCIIntPropertyChangeListener intInvalidateElementListener;

@property (strong, nonatomic) SCISmartPropertyInt *fillColorProperty;
@property (strong, nonatomic) SCISmartPropertyFloat *sizeProperty;

- (instancetype)initWithMarkerType:(SCIMarkerType)type;

@end
