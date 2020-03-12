//
//  ZLineChartPoint.swift
//  CandleChartTest
//
//  Created by 박진수 on 11/03/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

class ZLineChartPoint: ChartPoint {
    let date: Date
    let close: Double
    
    init(date: Date, close: Double) {
        let x = ChartAxisValueDate(date: date, formatter: DateFormatter())
        self.date = date
        self.close = close
        super.init(x: x, y: ChartAxisValueDouble(close))
        
    }
    
    required public init(x: ChartAxisValue, y: ChartAxisValue) {
        fatalError("init(x:y:) has not been implemented")
    }
}
