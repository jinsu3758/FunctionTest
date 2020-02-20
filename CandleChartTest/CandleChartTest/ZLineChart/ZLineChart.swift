//
//  ZLineChart.swift
//  CandleChartTest
//
//  Created by 박진수 on 14/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

enum AxisDirection {
    case leftTop
    case rightTop
    case leftBottom
    case rightBottom
}

class ZLineChart<T, M>: UIView {
    fileprivate var chart: Chart?
    var xModel: ChartAxisModel
    var yModel: ChartAxisModel
    var chartSettings: ChartSettings
    var chartFrame: CGRect
    var axisDirection: AxisDirection
    var lineModels: [ZLineChartModel<T, M>]
    
    init(frame: CGRect, chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, xModel: ChartAxisModel, yModel: ChartAxisModel, lineModels: [ZLineChartModel<T, M>], axisDirection: AxisDirection = .leftBottom) {
        self.chartFrame = frame
        self.chartSettings = chartSettings
        self.xModel = xModel
        self.yModel = yModel
        self.axisDirection = axisDirection
        self.lineModels = lineModels
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
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
    
    func setChart() {
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace()
        let chartLineModels = lineModels.map { $0.getChartLineModel() }
        let chartLineLayers = ChartPointsLineLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, lineModels: chartLineModels)
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, chartLineLayers])
        self.chart = chart
        self.addSubview(chart.view)
    }
    
    
    


}
