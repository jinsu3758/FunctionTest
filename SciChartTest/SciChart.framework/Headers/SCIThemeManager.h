//******************************************************************************
// SCICHART® Copyright SciChart Ltd. 2011-2019. All rights reserved.
//
// Web: http://www.scichart.com
// Support: support@scichart.com
// Sales:   sales@scichart.com
//
// SCIThemeManager.h is part of SCICHART®, High Performance Scientific Charts
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

#import <Foundation/Foundation.h>

@protocol ISCIThemeable;
@protocol ISCIThemeProvider;

/// Defines the `Key` for the `BlackSteel` theme in SciChart.
static NSString * _Nonnull const SCIChart_BlackSteelStyleKey = @"SciChart_BlackSteel";

/// Defines the `Key` for the `SciChartv4Dark` theme in SciChart.
static NSString * _Nonnull const SCIChart_SciChartv4DarkStyleKey = @"SciChart_SciChartv4Dark";

/// Defines the `Key` for the `Bright_Spark` theme in SciChart.
static NSString * _Nonnull const SCIChart_Bright_SparkStyleKey = @"SciChart_Bright_Spark";

/// Defines the `Key` for the `Chrome` theme in SciChart.
static NSString * _Nonnull const SCIChart_ChromeStyleKey = @"SciChart_Chrome";

/// Defines the `Key` for the `Electric` theme in SciChart.
static NSString * _Nonnull const SCIChart_ElectricStyleKey = @"SciChart_Electric";

/// Defines the `Key` for the `ExpressionLight` theme in SciChart.
static NSString * _Nonnull const SCIChart_ExpressionLightStyleKey = @"SciChart_ExpressionLight";

/// Defines the `Key` for the `Oscilloscope` theme in SciChart.
static NSString * _Nonnull const SCIChart_OscilloscopeStyleKey = @"SciChart_Oscilloscope";

/// Defines the `Key` for the `ExpressionDark` theme in SciChart.
static NSString * _Nonnull const SCIChart_ExpressionDarkStyleKey = @"SciChart_ExpressionDark";

/// Defines the `Key` for the default theme in SciChart. Which is `SCIChart_SciChartv4DarkStyleKey`.
static NSString * _Nonnull const SCIChart_DefaultThemeKey = @"SciChart_SciChartv4Dark";

/**
 * Provides API for automatic theme management.
 */
@interface SCIThemeManager : NSObject

/**
 * Gets `ISCIThemeProvider` instance by `themeKey`
 * @param themeKey The id of theme to get.
 * @return `ISCIThemeProvider` instance.
 */
+ (nullable id<ISCIThemeProvider>)themeProviderWith:(nonnull NSString*)themeKey;

/**
 * Removes cached `ISCIThemeProvider` instance by its `themeKey`.
 * @param themeKey The `themeKey` of theme to remove.
 */
+ (void)removeThemeByThemeKey:(nonnull NSString*)themeKey;

/**
 * Creates and adds theme from specified style.
 * @param themeKey The theme style to create `ISCIThemeProvider` from.
 */
+ (void)addThemeByThemeKey:(nonnull NSString*)themeKey;

/**
 * Apply theme to specified `ISCIThemeable` instance.
 * @param themeable The target to apply theme to.
 * @param themeKey The theme id.
 */
+ (void)applyThemeToThemeable:(nonnull id<ISCIThemeable>)themeable withThemeKey:(nonnull NSString*)themeKey;

/**
 * Apply default theme to specified `ISCIThemeable` instance.
 * @param themeable The target to apply theme to.
 */
+ (void)applyDefaultThemeToThemeable:(nonnull id<ISCIThemeable>)themeable;

@end
