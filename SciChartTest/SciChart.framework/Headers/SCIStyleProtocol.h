//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIStyleProtocol.h is part of SCICHART®, High Performance Scientific Charts
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

/**
 * Block which defines action without parameters.
 */
typedef void (^SCIActionBlock) (void);

/**
 * Protocol for classes that define all chart elements visual style
 * @note For every style check in documentation (or by name) for which elements it can be used, else you will get exception.
 */
@protocol SCIStyleProtocol <NSObject>

/**
 * Block which is called on every style property change.
 * @note It is used for invalidating parent annotation and provoking redraw of annotations and modifiers on style change.
 * @warning It is not advised to replace this block manually
 * @see `SCIActionBlock`
 */
@property (nonatomic, copy) SCIActionBlock styleChanged;

@end
