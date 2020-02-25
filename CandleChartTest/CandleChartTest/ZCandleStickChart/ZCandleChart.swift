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
    
    init(frame: CGRect, chartPoints: [ChartPointCandleStick], chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, axisDirection: AxisDirection = .leftBottom, dateComponent: Calendar.Component) {
        self.chartPoints = chartPoints
        self.chartSettings = chartSettings
        self.chartFrame = frame
        self.axisDirection = axisDirection
        self.dateComponent = dateComponent
        let xGenerator = ChartAxisValuesGeneratorDate(unit: dateComponent, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yGenerator = ChartAxisGeneratorMultiplier(5)
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: ChartLabelSettings())
        let yLabelGenerator = ChartAxisLabelsGeneratorNumber()
        
        let firstDate = chartPoints[0].date
        let lastDate = chartPoints[chartPoints.count - 1].date
        xModel = ChartAxisModel(firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        yModel = ChartAxisModel(firstModelValue: 0, lastModelValue: chartPoints[chartPoints.count - 1].high, axisValuesGenerator: yGenerator, labelsGenerator: yLabelGenerator)
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
    
    fileprivate func setAxisModel() {
        let xGenerator = ChartAxisValuesGeneratorDate(unit: dateComponent, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yGenerator = ChartAxisGeneratorMultiplier(10)
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: ChartLabelSettings())
        
        let firstDate = chartPoints[0].date
        let lastDate = chartPoints[chartPoints.count - 1].date
        var min: Double = 0
        var maxHighValue: Double {
            for item in chartPoints {
                if item.high > min { min = item.high }
            }
            return min
        }
        xModel = ChartAxisModel(firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        yModel = ChartAxisModel(firstModelValue: 0, lastModelValue: maxHighValue, axisValuesGenerator: yGenerator, labelsGenerator: labelGenerator)
        
    }
    
    func setChart() {
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace()
        let chartCandleStickLayer = ChartCandleStickLayer<ChartPointCandleStick>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, chartPoints: chartPoints)
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, chartCandleStickLayer])
        self.chart = chart
        self.addSubview(chart.view)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
