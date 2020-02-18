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

//class ZLineChart<T, M>: UIView {
//    fileprivate var chart: Chart?
//    fileprivate let innerFrame: CGRect
//    fileprivate let xAxisLayer: ChartAxisLayer
//    fileprivate let yAxisLayer: ChartAxisLayer
//    
//    init(chartAxis: ZChartAxisModel<T, M>, chartPoints: [(T, M)], ) {
//        
//        let xModel = ChartAxisModel(axisValues: xValue, lineColor: axisLineColor, axisTitleLabel: ChartAxisLabel(text: "Axis title", settings: labelSettings))
//        let yModel = ChartAxisModel(axisValues: yValue, lineColor: axisLineColor, axisTitleLabel: ChartAxisLabel(text: "Axis title", settings: labelSettings.defaultVertical()))
//        var getAxisSpace: (ChartAxisLayer, ChartAxisLayer, CGRect) {
//            switch axisDirection {
//            case .leftTop:
//                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
//                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//            case .leftBottom:
//                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
//                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//            case .rightTop:
//                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
//                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//            case .rightBottom:
//                let coordsSpace = ChartCoordsSpaceLeftTopSingleAxis(chartSettings: chartSettings, chartFrame: frame, xModel: xModel, yModel: yModel)
//                return (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//            }
//        }
//        
//        let (xAxisLayer, yAxisLayer, innerFrame) = getAxisSpace
//        self.innerFrame = innerFrame
//        self.xAxisLayer = xAxisLayer
//        self.yAxisLayer = yAxisLayer
//        
//        super.init(frame: frame)
//    }
//    
//    required init?(coder: NSCoder) {
//        fatalError("init(coder:) has not been implemented")
//    }
//    
//    
//
//
//}
