//
//  ZChartAxisModel.swift
//  CandleChartTest
//
//  Created by 박진수 on 17/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

struct ZChartAxisModel<T, M> {
    fileprivate let chartSettings: ChartSettings
    fileprivate let labelSettings: ChartLabelSettings
    fileprivate let chartFrame: CGRect
    fileprivate var xValue: [ChartAxisValue] = []
    fileprivate var yValue: [ChartAxisValue] = []
    fileprivate let lineColor: UIColor
    var xAxisTitle: String?
    var yAxisTitle: String?
    
    init(chartFrame: CGRect, chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, labelSettings: ChartLabelSettings = ChartLabelSettings(font: UIFont.systemFont(ofSize: 12)), xAxisValue: [T], yAxisValue: [M], lineColor: UIColor = .black, dateFormat: String = "MM dd") {
        self.chartFrame = chartFrame
        self.chartSettings = chartSettings
        self.labelSettings = labelSettings
        self.lineColor = lineColor
        switch T.self {
        case is Double.Type:
            xValue = xAxisValue.map { ChartAxisValueDouble($0 as! Double, labelSettings: labelSettings)}
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = dateFormat
            xValue = xAxisValue.map { ChartAxisValueDate(date: $0 as! Date, formatter: dateFormatter, labelSettings: labelSettings) }
        default:
            break
        }
        switch M.self {
        case is Double.Type:
            yValue = yAxisValue.map { ChartAxisValueDouble($0 as! Double, labelSettings: labelSettings)}
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = dateFormat
            yValue = yAxisValue.map { ChartAxisValueDate(date: $0 as! Date, formatter: dateFormatter, labelSettings: labelSettings) }
        default:
            break
        }
        
        
    }
    
    
    func getAxisSpace(axisDirection: AxisDirection = .leftBottom) -> (ChartAxisLayer, ChartAxisLayer, CGRect) {
        let xModel = xAxisTitle != nil ? ChartAxisModel(axisValues: xValue, lineColor: lineColor, axisTitleLabel: ChartAxisLabel(text: xAxisTitle!, settings: labelSettings)) : ChartAxisModel(axisValues: xValue, lineColor: lineColor)
        let yModel = yAxisTitle != nil ? ChartAxisModel(axisValues: yValue, lineColor: lineColor, axisTitleLabel: ChartAxisLabel(text: yAxisTitle!, settings: labelSettings)) : ChartAxisModel(axisValues: yValue, lineColor: lineColor)
        
        switch axisDirection {
        case .leftTop:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .leftBottom:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightTop:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        case .rightBottom:
            let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
            return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        }
    }
}
