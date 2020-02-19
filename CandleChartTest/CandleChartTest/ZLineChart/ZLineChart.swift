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
    
    init(chartAxisModel: ZChartAxisModel<T, M>, lineModels: [ZLineChartModel<T, M>] ) {
        super.init(frame: chartAxisModel.chartFrame)
        let (xAxisLayer, yAxisLayer, innerFrame) = chartAxisModel.getAxisSpace()
        let chartLineModels = lineModels.map { $0.getChartLineModel() }
        let chartPointsLineLayer = ChartPointsLineLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, lineModels: chartLineModels)
        let chart = Chart(frame: chartAxisModel.chartFrame, innerFrame: innerFrame, settings: chartAxisModel.chartSettings, layers:
            [xAxisLayer, yAxisLayer, chartPointsLineLayer])
        self.addSubview(chart.view)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    


}
