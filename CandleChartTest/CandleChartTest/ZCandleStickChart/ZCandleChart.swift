//
//  ZCandleChart.swift
//  CandleChartTest
//
//  Created by 박진수 on 24/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

class ZCandleChart: UIView {
    fileprivate var chart: Chart?
    var xModel: ChartAxisModel
    var yModel: ChartAxisModel
    var chartPoints: [ChartPointCandleStick]
    var chartSettings: ChartSettings
    var chartFrame: CGRect
    var axisDirection: AxisDirection
    var dateComponent: Calendar.Component
    
    init(frame: CGRect, chartPoints: [ChartPointCandleStick], chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, axisDirection: AxisDirection = .rightBottom, dateComponent: Calendar.Component, axisLineColor: UIColor = .clear) {
        self.chartPoints = chartPoints
        self.chartSettings = chartSettings
        self.chartFrame = frame
        self.axisDirection = axisDirection
        self.dateComponent = dateComponent
        var min: Double = 0
        var maxHighValue: Double {
            for item in chartPoints {
                if item.high > min { min = item.high }
            }
            return min
        }
        
        let xGenerator = ChartAxisValuesGeneratorDate(unit: dateComponent, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yValues = stride(from: 20, through: maxHighValue, by: 5).map {ChartAxisValueDouble(Double($0))}
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: ChartLabelSettings())
        
        let firstDate = chartPoints[0].date
        let lastDate = chartPoints[chartPoints.count - 1].date
        
        print("\(maxHighValue)!!!")
        xModel = ChartAxisModel(lineColor: axisLineColor, firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        yModel = ChartAxisModel(axisValues: yValues, lineColor: axisLineColor)
        
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
        let candleStickLayer = ChartPointsCandleStickViewsLayer<ChartPointCandleStick, ChartCandleStickView>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, innerFrame: innerFrame, chartPoints: chartPoints, viewGenerator: viewGenerator)
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, candleStickLayer])
        self.chart = chart
        self.addSubview(chart.view)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
