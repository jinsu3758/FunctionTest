//
//  ZChartLineModel.swift
//  CandleChartTest
//
//  Created by 박진수 on 18/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

enum ChartDateComponent {
    case day
    case week
    case month
    case threeMonth
    case year
    case fiveYear
    case total
}

struct ZLineChartModel<T, M> {
    let chartPoints: [ChartPoint]
    let lineColor: UIColor
    let lineWidth: CGFloat
    /// 선이 꺽이는 부분의 스타일
    let lineJoin: LineJoin
    /// 선 끝 부분의 스타일
    let lineCap: LineCap
    let animDuration: Float
    let animDelay: Float
    let chartDateComponent: ChartDateComponent
    
    init(chartPoints: [(T, M)], chartDateComponent: ChartDateComponent, lineColor: UIColor = .black, lineWidth: CGFloat = 1, lineJoin: LineJoin = .round, lineCap: LineCap = .round,
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
        case is Int.Type:
            xValue = chartPoints.map { ChartAxisValueInt($0.0 as! Int)}
        default:
            break
        }
        
        switch M.self {
        case is Double.Type:
            yValue = chartPoints.map { ChartAxisValueDouble($0.1 as! Double) }
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = xDateFormat!
            xValue = chartPoints.map { ChartAxisValueDate(date: $0.1 as! Date, formatter: dateFormatter) }
        case is Int.Type:
            yValue = chartPoints.map { ChartAxisValueInt($0.1 as! Int)}
        default:
            break
        }
        
        self.chartPoints = zip(xValue, yValue).map { ChartPoint(x: $0, y: $1) }
        self.lineColor = lineColor
        self.lineWidth = lineWidth
        self.lineJoin = lineJoin
        self.lineCap = lineCap
        self.animDuration = animDuration
        self.animDelay = animDelay
        self.chartDateComponent = chartDateComponent
    }
    
    func getChartLineModel() -> ChartLineModel<ChartPoint> {
        return ChartLineModel(chartPoints: chartPoints, lineColor: lineColor, lineWidth: lineWidth, lineJoin: lineJoin, lineCap: lineCap, animDuration: animDuration, animDelay: animDelay, dashPattern: nil)
    }
    
}
