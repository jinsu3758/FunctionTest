//
//  ZCandleChart.swift
//  CandleChartTest
//
//  Created by 박진수 on 24/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

class ZCandleChart: UIView {
    fileprivate var candleStickChart: Chart?
    fileprivate var barChart: Chart?
    fileprivate let candleChartFrame: CGRect
    fileprivate let barChartFrame: CGRect
    
    var chartSettings: ChartSettings
    var axisDirection: AxisDirection
    var dateComponent: Calendar.Component
    var barWidth: CGFloat
    var strokeWidth: CGFloat
    var upColor: UIColor
    var downColor: UIColor
    var axisLineColor: UIColor
    
    init(candleChartFrame: CGRect, barChartFrame: CGRect, chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, axisDirection: AxisDirection = .rightBottom, dateComponent: Calendar.Component, barWidth: CGFloat = 5, strokeWidth: CGFloat = 0.5, upColor: UIColor = .red,  downColor: UIColor = .blue, axisLineColor: UIColor = .clear) {
        self.chartSettings = chartSettings
        self.candleChartFrame = candleChartFrame
        self.barChartFrame = barChartFrame
        self.axisDirection = axisDirection
        self.dateComponent = dateComponent
        self.barWidth = barWidth
        self.strokeWidth = strokeWidth
        self.upColor = upColor
        self.downColor = downColor
        self.axisLineColor = axisLineColor
        super.init(frame: candleChartFrame)
        
    }
    
    fileprivate func getAxisSpace(xModel: ChartAxisModel, yModel: ChartAxisModel, frame: CGRect) -> (ChartAxisLayer, ChartAxisLayer, CGRect) {
        switch axisDirection {
        case .leftTop:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .leftBottom:
            let coordsSpace = ChartCoordsSpaceLeftBottomSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightTop:
            let coordsSpace = ChartCoordsSpaceRightTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightBottom:
            let coordsSpace = ChartCoordsSpaceRightBottomSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        }
    }
    
    func setChart(candleStickChartPoints: [ChartPointCandleStick], barChartValues: [Double]) {
        var barChartModel: [ChartBarModel] = []
        var maxCandleHighValue: Double = 0
        var maxBarValue: Double = 0
        let zipChartPoints = zip(candleStickChartPoints, barChartValues)
        for (candle, barValue) in zipChartPoints {
            if candle.high > maxCandleHighValue { maxCandleHighValue = candle.high }
            if barValue > maxBarValue { maxBarValue = barValue }
            barChartModel.append(ChartBarModel(constant: ChartAxisValueDate(date: candle.date, formatter: candle.formatter), axisValue1: ChartAxisValueDouble(0), axisValue2: ChartAxisValueDouble(barValue), bgColor: candle.open < candle.close ? upColor.withAlphaComponent(0.5) : downColor.withAlphaComponent(0.5)))
            //            barChartPoints.append(ChartPoint(x: ChartAxisValueDate(date: candle.date, formatter: candle.formatter), y: ChartAxisValueDouble(barValue)))
        }
        
        
        let xGenerator = ChartAxisValuesGeneratorDate(unit: dateComponent, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yValues = stride(from: 20, through: maxCandleHighValue, by: 5).map {ChartAxisValueDouble(Double($0))}
        let yGenerator = ChartAxisGeneratorMultiplier(2)
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: ChartLabelSettings())
        let yLabelGenerator = ChartAxisLabelsGeneratorNumber()
        
        let firstDate = candleStickChartPoints[0].date
        let lastDate = candleStickChartPoints[candleStickChartPoints.count - 1].date
        
        let xModel = ChartAxisModel(lineColor: axisLineColor, firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        let yModel = ChartAxisModel(axisValues: yValues, lineColor: axisLineColor)
        let barYmodel = ChartAxisModel(lineColor: axisLineColor, firstModelValue: 0, lastModelValue: maxBarValue, axisValuesGenerator: xGenerator, labelsGenerator: yLabelGenerator)
        
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace(xModel: xModel, yModel: yModel, frame: candleChartFrame)
        let viewGenerator = {[unowned self] (chartPointModel: ChartPointLayerModel<ChartPointCandleStick>, layer: ChartPointsViewsLayer<ChartPointCandleStick, ChartCandleStickView>, chart: Chart) -> ChartCandleStickView? in
            let (chartPoint, screenLoc) = (chartPointModel.chartPoint, chartPointModel.screenLoc)
            
            let x = screenLoc.x
            
            let highScreenY = screenLoc.y
            let lowScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.low)).y
            let openScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.open)).y
            let closeScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.close)).y
            
            let (rectTop, rectBottom, fillColor) = closeScreenY < openScreenY ? (closeScreenY, openScreenY, self.upColor) : (openScreenY, closeScreenY, self.downColor)
            let v = ChartCandleStickView(lineX: screenLoc.x, width: self.barWidth, top: highScreenY, bottom: lowScreenY, innerRectTop: rectTop, innerRectBottom: rectBottom, fillColor: fillColor, strokeWidth: self.strokeWidth)
            v.isUserInteractionEnabled = false
            return v
        }
        
        let (barXAxisLayer, barYAxisLayer, barInnerFrame) = getAxisSpace(xModel: xModel, yModel: barYmodel, frame: barChartFrame)
        let barViewSettings = ChartBarViewSettings(animDuration: 0.5)
        let candleStickLayer = ChartPointsCandleStickViewsLayer<ChartPointCandleStick, ChartCandleStickView>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, innerFrame: innerFrame, chartPoints: candleStickChartPoints, viewGenerator: viewGenerator)
        let barLayer = ChartBarsLayer(xAxis: barXAxisLayer.axis, yAxis: barYAxisLayer.axis, bars: barChartModel, barWidth: barWidth, settings: barViewSettings)
        
        let chart = Chart(frame: candleChartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, candleStickLayer])
        let barChart = Chart(frame: barChartFrame, innerFrame: barInnerFrame, settings: chartSettings, layers: [barXAxisLayer, barXAxisLayer, barLayer])
        self.candleStickChart = chart
        self.barChart = barChart
        self.addSubview(barChart.view)
        self.addSubview(chart.view)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
