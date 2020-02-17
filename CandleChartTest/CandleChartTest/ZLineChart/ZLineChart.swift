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

class ZLineChart: UIView {
    fileprivate var chart: Chart?
    fileprivate let chartSettings: ChartSettings
    fileprivate let innerFrame: CGRect
    fileprivate let xAxisLayer: ChartAxisLayer
    fileprivate let yAxisLayer: ChartAxisLayer
    
    init(frame: CGRect, chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, xAxisValueDouble: [Double], yAxisValueDouble: [Double], axisDirection: AxisDirection = .leftBottom, labelSettings: ChartLabelSettings = ChartLabelSettings(font: UIFont.systemFont(ofSize: 12)), axisLineColor: UIColor = .black) {
        self.chartSettings = chartSettings
        let xValue = xAxisValueDouble.map { ChartAxisValueDouble($0, labelSettings: labelSettings)}
        let yValue = yAxisValueDouble.map { ChartAxisValueDouble($0, labelSettings: labelSettings)}
        
        let xModel = ChartAxisModel(axisValues: xValue, lineColor: axisLineColor, axisTitleLabel: ChartAxisLabel(text: "Axis title", settings: labelSettings))
        let yModel = ChartAxisModel(axisValues: yValue, lineColor: axisLineColor, axisTitleLabel: ChartAxisLabel(text: "Axis title", settings: labelSettings.defaultVertical()))
        var getAxisSpace: (ChartAxisLayer, ChartAxisLayer, CGRect) {
            switch axisDirection {
            case .leftTop:
                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
            case .leftBottom:
                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
            case .rightTop:
                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
            case .rightBottom:
                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
            }
        }
        
        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace
        self.innerFrame = innerFrame
        self.xAxisLayer = xAxisLayer
        self.yAxisLayer = yAxisLayer
        
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    


}
