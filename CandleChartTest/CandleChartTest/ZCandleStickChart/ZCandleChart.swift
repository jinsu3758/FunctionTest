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
    
    var xModel: ChartAxisModel
    var yModel: ChartAxisModel
    var barYmodel: ChartAxisModel
    var candleStickChartPoints: [ChartPointCandleStick]
    var barChartPoints: [ChartPoint] = []
    var chartSettings: ChartSettings
    var chartFrame: CGRect
    var axisDirection: AxisDirection
    var dateComponent: Calendar.Component
    
    init(frame: CGRect, candleStickChartPoints: [ChartPointCandleStick], barChartValues: [Double], chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, axisDirection: AxisDirection = .rightBottom, dateComponent: Calendar.Component, axisLineColor: UIColor = .clear) {
        
        self.candleStickChartPoints = candleStickChartPoints
        self.chartSettings = chartSettings
        self.chartFrame = frame
        self.axisDirection = axisDirection
        self.dateComponent = dateComponent
        
        var maxCandleHighValue: Double = 0
        var maxBarValue: Double = 0
        let zipChartPoints = zip(candleStickChartPoints, barChartValues)
        for (candle, barValue) in zipChartPoints {
            if candle.high > maxCandleHighValue { maxCandleHighValue = candle.high }
            if barValue > maxBarValue { maxBarValue = barValue }
            barChartPoints.append(ChartPoint(x: ChartAxisValueDate(date: candle.date, formatter: candle.formatter), y: ChartAxisValueDouble(barValue)))
        }
        
        
        let xGenerator = ChartAxisValuesGeneratorDate(unit: dateComponent, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yValues = stride(from: 20, through: maxCandleHighValue, by: 5).map {ChartAxisValueDouble(Double($0))}
        let yGenerator = ChartAxisGeneratorMultiplier(2)
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: ChartLabelSettings())
        let yLabelGenerator = ChartAxisLabelsGeneratorNumber()
        
        let firstDate = candleStickChartPoints[0].date
        let lastDate = candleStickChartPoints[candleStickChartPoints.count - 1].date
        
        xModel = ChartAxisModel(lineColor: axisLineColor, firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        yModel = ChartAxisModel(axisValues: yValues, lineColor: axisLineColor)
        barYmodel = ChartAxisModel(lineColor: axisLineColor, firstModelValue: 0, lastModelValue: maxBarValue, axisValuesGenerator: xGenerator, labelsGenerator: yLabelGenerator)
        
        super.init(frame: frame)
        
    }
    
    fileprivate func getAxisSpace() -> (ChartAxisLayer, ChartAxisLayer, CGRect) {
        switch axisDirection {
        case .leftTop:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .leftBottom:
            let coordsSpace = ChartCoordsSpaceLeftBottomSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightTop:
            let coordsSpace = ChartCoordsSpaceRightTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightBottom:
            let coordsSpace = ChartCoordsSpaceRightBottomSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        }
    }
    
    func setChart(width: CGFloat = 5, strokeWidth: CGFloat = 0.5, upColor: UIColor = .red,  downColor: UIColor = .blue) {
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace()
        let viewGenerator = {(chartPointModel: ChartPointLayerModel<ChartPointCandleStick>, layer: ChartPointsViewsLayer<ChartPointCandleStick, ChartCandleStickView>, chart: Chart) -> ChartCandleStickView? in
            let (chartPoint, screenLoc) = (chartPointModel.chartPoint, chartPointModel.screenLoc)
            
            let x = screenLoc.x
            
            let highScreenY = screenLoc.y
            let lowScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.low)).y
            let openScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.open)).y
            let closeScreenY = layer.modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.close)).y
            
            let (rectTop, rectBottom, fillColor) = closeScreenY < openScreenY ? (closeScreenY, openScreenY, upColor) : (openScreenY, closeScreenY, downColor)
            let v = ChartCandleStickView(lineX: screenLoc.x, width: width, top: highScreenY, bottom: lowScreenY, innerRectTop: rectTop, innerRectBottom: rectBottom, fillColor: fillColor, strokeWidth: strokeWidth)
            v.isUserInteractionEnabled = false
            return v
        }
        
        let barViewGenerator = {(chartPointModel: ChartPointLayerModel, layer: ChartPointsViewsLayer, chart: Chart) -> UIView? in
            let bottomLeft = layer.modelLocToScreenLoc(x: 0, y: 0)
            
            let barWidth: CGFloat = 30
            
            let settings = ChartBarViewSettings(animDuration: 0.5)
            
            let (p1, p2): (CGPoint, CGPoint) = {
                return (CGPoint(x: chartPointModel.screenLoc.x, y: bottomLeft.y), CGPoint(x: chartPointModel.screenLoc.x, y: chartPointModel.screenLoc.y))
            }()
            return ChartPointViewBar(p1: p1, p2: p2, width: barWidth, bgColor: UIColor.blue.withAlphaComponent(0.6), settings: settings)
        }
        
        let candleStickLayer = ChartPointsCandleStickViewsLayer<ChartPointCandleStick, ChartCandleStickView>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, innerFrame: innerFrame, chartPoints: candleStickChartPoints, viewGenerator: viewGenerator)
        
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, candleStickLayer])
        self.candleStickChart = chart
        self.addSubview(chart.view)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
