//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIExecuteOn.h is part of SCICHART®, High Performance Scientific Charts
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
 * Defines constants for when a `SCIGestureModifierBase` operation occurs.
 */
typedef NS_ENUM(NSUInteger, SCIExecuteOn) {
    /**
     * Executes on Single Tap gesture.
     */
    SCIExecuteOn_SingleTap,
    
    /**
     * Executes on Double Tap gesture.
     */
    SCIExecuteOn_DoubleTap,
    
    /**
     * Executes on Long Press gesture.
     */
    SCIExecuteOn_LongPress,

    /**
     * Executes on Fling gesture.
     */
    SCIExecuteOn_Fling
};
