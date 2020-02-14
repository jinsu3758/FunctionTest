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
    
    init(frame: CGRect, chartPointsDouble: [(Double, Double)], chartSettings: ChartSettings = ExamplesDefaults.chartSettingsWithPanZoom, xAxisValueDouble: [Double], yAxisValueDouble: [Double], axisDirection: AxisDirection = .leftBottom, labelSettings: ChartLabelSettings? = nil, axisLineColor: UIColor = .black) {
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

}
