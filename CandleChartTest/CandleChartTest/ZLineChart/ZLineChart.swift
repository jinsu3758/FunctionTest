//
//  ZLineChart.swift
//  CandleChartTest
//
//  Created by 박진수 on 14/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit
import AudioToolbox

enum AxisDirection {
    case leftTop
    case rightTop
    case leftBottom
    case rightBottom
}

class ZLineChart<T, M>: UIView {
    fileprivate var chart: Chart?
    fileprivate var trackerLayer: ChartPointsTrackerLayer<ChartPoint>?
    fileprivate var chartLineLayers: ChartPointsLineLayer<ChartPoint>?

    var xModel: ChartAxisModel?
    var yModel: ChartAxisModel?
    var chartSettings: ChartSettings
    var chartFrame: CGRect
    var axisDirection: AxisDirection
    var lineModels: [ZLineChartModel<T, M>]
    var isTrackerView: Bool = false
    
    init(frame: CGRect, chartSetting: ChartSettings = ChartSettings(), xModel: ChartAxisModel, yModel: ChartAxisModel, lineModels: [ZLineChartModel<T, M>], axisDirection: AxisDirection = .leftBottom) {
        self.chartFrame = frame
        self.chartSettings = chartSetting
        self.axisDirection = axisDirection
        self.lineModels = lineModels
        self.xModel = xModel
        self.yModel = yModel
        super.init(frame: frame)
    }
    
    init(frame: CGRect, chartSetting: ChartSettings = ChartSettings(), lineModels: [ZLineChartModel<T, M>], axisDirection: AxisDirection = .leftBottom) {
        self.chartFrame = frame
        self.chartSettings = chartSetting
        self.axisDirection = axisDirection
        self.lineModels = lineModels
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    fileprivate func getAxisSpace(xModel: ChartAxisModel, yModel: ChartAxisModel) -> (ChartAxisLayer, ChartAxisLayer, CGRect) {
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
    
    func setChart() {
        let chartPoints = lineModels[0].chartPoints
        let xValue = chartPoints.map { $0.x }
        let yValue = chartPoints.map { $0.y }
        
        let xModel = ChartAxisModel(axisValues: xValue)
        let yModel = ChartAxisModel(axisValues: yValue)
        
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace(xModel: xModel, yModel: yModel)
        let chartLineModels = lineModels.map { $0.getChartLineModel() }
        chartLineLayers = ChartPointsLineLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, lineModels: chartLineModels)
        if isTrackerView {
            trackerLayer = ChartPointsTrackerLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, chartPoints: lineModels[0].chartPoints)
            trackerLayer?.delegate = self
        }
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, chartLineLayers!, trackerLayer!])
        self.chart = chart
        self.addSubview(chart.view)
    }
    
    

}

extension ZLineChart: TrackerLayerDelegate {
    func longPressedBegan(_ location: CGPoint) {
        if let chartPoint = trackerLayer?.chartPointsForScreenLocX(location.x).first {
            trackerLayer?.moveToView(chartLineLayers!.modelLocToScreenLoc(x: chartPoint.x.scalar))
        }
    }
    
    func longPressedMoved(_ location: CGPoint) {
        if let chartPoint = trackerLayer?.chartPointsForScreenLocX(location.x).first {
            trackerLayer?.moveToView(chartLineLayers!.modelLocToScreenLoc(x: chartPoint.x.scalar))
        }
    }
    
    func longPressedEnded(_ location: CGPoint) {
        if let chartPoint = chartLineLayers?.chartPointsForScreenDateX(location.x).first {
            trackerLayer?.moveToView(location.x)
        }
//        if let chartPoint = chartLineLayers?.chartPointsForScreenLocX(location.x).first {
//            trackerLayer?.moveToView(chartLineLayers!.modelLocToScreenLoc(x: chartPoint.x.scalar))
//        }
//        if let chartPoint = candleStickLayer?.chartPointsForScreenLocX(location.x).first {
//            trackerLayer?.moveToView(candleStickLayer?.getChartPointsCenterX(location.x) ?? 0)
//            self.delegate?.longPressedEnded(chartPoint)
//        }
    }
}

