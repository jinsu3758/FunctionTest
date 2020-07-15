//
//  ViewController.swift
//  SciChartTest
//
//  Created by 박진수 on 2020/06/08.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit
import SciChart

class ViewController: UIViewController {
    var surface: SCIChartSurface!

    override func viewDidLoad() {
        super.viewDidLoad()
        let formatter = DateFormatter()
        formatter.dateFormat = "dd.MM.yyyy"
        
        let date = {(str: String) -> Date in
            return formatter.date(from: str)!
        }
        
        surface = SCIChartSurface(frame: self.view.bounds)
        let xAxis = SCIDateAxis()
        let yAxis = SCINumericAxis()
        xAxis.drawMajorGridLines = false
        xAxis.drawMinorGridLines = false
        xAxis.axisBandsStyle = SCISolidBrushStyle()
        xAxis.majorTickLineStyle = SCISolidPenStyle()
        xAxis.minorTickLineStyle = SCISolidPenStyle()
        xAxis.tickLabelStyle = SCIFontStyle(fontSize: 10, andTextColor: .blue)
        
        
        yAxis.drawMajorGridLines = false
        yAxis.drawMinorGridLines = false
        yAxis.axisBandsStyle = SCISolidBrushStyle()
        yAxis.majorTickLineStyle = SCISolidPenStyle()
        yAxis.visibleRange = SCIDoubleRange(min: 0, max: 60)
        yAxis.tickLabelStyle = SCIFontStyle(fontSize: 0, andTextColor: .clear)
        
//        xAxes.majorGridLineStyle = SCISolidPenStyle(colorCode: 0x0000000, thickness: 0)
//        yAxes.majorGridLineStyle = SCISolidPenStyle(colorCode: 0x0000000, thickness: 0)
        surface.xAxes.add(items: xAxis)
        surface.yAxes.add(items: yAxis)
        
        let dataSeries = SCIOhlcDataSeries(xType: .date, yType: .double)
        let dateData = SCIDateValues()
        dateData.add(date("01.10.2015"))
        dateData.add(date("02.10.2015"))
        dateData.add(date("03.10.2015"))
        dateData.add(date("04.10.2015"))
        dateData.add(date("05.10.2015"))
        
        let openData = SCIDoubleValues(values: [10,20,15,20,15,10])
        let highData = SCIDoubleValues(values: [30, 40, 40, 50, 50])
        let lowData = SCIDoubleValues(values: [5, 5, 3, 2, 1])
        let closeData = SCIDoubleValues(values: [15, 25, 30, 40, 22])
        dataSeries.append(x: dateData, open: openData, high: highData, low: lowData, close: closeData)
        
        
        let candleStickSeries = SCIFastCandlestickRenderableSeries()
        
        candleStickSeries.dataSeries = dataSeries
        candleStickSeries.strokeUpStyle = SCISolidPenStyle(colorCode: 0xFF00AA00, thickness: 1.0)
        candleStickSeries.fillUpBrushStyle = SCISolidBrushStyle(colorCode: 0x9000AA00)
        candleStickSeries.strokeDownStyle = SCISolidPenStyle(colorCode: 0xFFFF0000, thickness: 1.0)
        candleStickSeries.fillDownBrushStyle = SCISolidBrushStyle(colorCode: 0x90FF0000)
        
//        surface.renderableSeriesAreaFillStyle = SCISolidBrushStyle(colorCode: 0x000000)
//        surface.backgroundColor = .blue
        surface.renderableSeriesAreaBorderStyle = SCISolidPenStyle(colorCode: 0x000000, thickness: 0)
        surface.renderableSeries.add(candleStickSeries)
        self.view.addSubview(surface)
    }


}

