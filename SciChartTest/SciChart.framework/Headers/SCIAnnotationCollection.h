//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIAnnotationCollection.h is part of SCICHART®, High Performance Scientific Charts
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

#import "SCIObservableCollection.h"
#import "ISCIAnnotation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains a collection of `ISCIAnnotation`.
 */
@interface SCIAnnotationCollection : SCIObservableCollection<id<ISCIAnnotation>>

/**
 * Initializes a new instance of `SCIAxisCollection` class.
 * @param collection The collections with items to add.
 */
- (instancetype)initWithCollection:(NSArray<id<ISCIAnnotation>> *)collection;

/**
 * Tries to select annotation from this collection.
 * @param annotation The annotation to select.
 * @return True if annotation has been selected.
 */
- (BOOL)trySelectAnnotation:(id<ISCIAnnotation>)annotation;
    
/**
 * Deselects all annotations in this collection.
 */
- (void)deselectAll;
    
@end

NS_ASSUME_NONNULL_END
