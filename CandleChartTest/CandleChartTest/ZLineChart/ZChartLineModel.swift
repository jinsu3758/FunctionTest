//
//  ZChartLineModel.swift
//  CandleChartTest
//
//  Created by 박진수 on 18/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

struct ZLineChartModel<T, M> {
    var chartPoints: [ChartPoint] = []
    let lineColor: UIColor
    let lineWidth: CGFloat
    /// 선이 꺽이는 부분의 스타일
    let lineJoin: LineJoin
    /// 선 끝 부분의 스타일
    let lineCap: LineCap
    let animDuration: Float
    let animDelay: Float
    
    init(chartPoints: [(T, M)], lineColor: UIColor = .black, lineWidth: CGFloat = 1, lineJoin: LineJoin = .round, lineCap: LineCap = .round,
         animDuration: Float = 0, animDelay: Float = 0, xDateFormat: String? = nil, yDateFormat: String? = nil) {
        var xValue: [ChartAxisValue] = []
        var yValue: [ChartAxisValue] = []
        
        switch T.self {
        case is Double.Type:
            xValue = chartPoints.map { ChartAxisValueDouble($0.0 as! Double) }
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = xDateFormat!
            xValue = chartPoints.map { ChartAxisValueDate(date: $0.0 as! Date, formatter: dateFormatter) }
        default:
            break
        }
        
        switch M.self {
        case is Double.Type:
            yValue = chartPoints.map { ChartAxisValueDouble($0.0 as! Double) }
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = xDateFormat!
            xValue = chartPoints.map { ChartAxisValueDate(date: $0.0 as! Date, formatter: dateFormatter) }
        default:
            break
        }
        
        self.lineColor = lineColor
        self.lineWidth = lineWidth
        self.lineJoin = lineJoin
        self.lineCap = lineCap
        self.animDuration = animDuration
        self.animDelay = animDelay
    }
    
}
