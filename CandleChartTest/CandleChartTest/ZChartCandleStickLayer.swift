////
////  ZChartCandleStickLayer.swift
////  CandleChartTest
////
////  Created by 박진수 on 04/02/2020.
////  Copyright © 2020 박진수. All rights reserved.
////
//
//import UIKit
////import SwiftCharts
//
//class ZChartCandleStickLayer<T: ChartPointCandleStick>: ChartCandleStickLayer<T> {
//    var screenItems: [CandleStickScreenItem] = []
//    
//    fileprivate let itemWidth: CGFloat
//    fileprivate let strokeWidth: CGFloat
//    fileprivate let increasingColor: UIColor
//    fileprivate let decreasingColor: UIColor
//    
//    override init(xAxis: ChartAxis, yAxis: ChartAxis, chartPoints: [T], itemWidth: CGFloat = 10, strokeWidth: CGFloat = 1, increasingColor: UIColor = UIColor.black, decreasingColor: UIColor = UIColor.white) {
//        self.itemWidth = itemWidth
//        self.strokeWidth = strokeWidth
//        self.increasingColor = increasingColor
//        self.decreasingColor = decreasingColor
//        
//        super.init(xAxis: xAxis, yAxis: yAxis, chartPoints: chartPoints, itemWidth: itemWidth, strokeWidth: strokeWidth, increasingColor: increasingColor, decreasingColor: decreasingColor)
//    }
//    
//    override func chartContentViewDrawing(context: CGContext, chart: Chart) {
//        for screenItem in screenItems {
//            context.setLineWidth(strokeWidth)
//            context.setStrokeColor(UIColor.blue.cgColor)
//            context.move(to: CGPoint(x: screenItem.x, y: screenItem.lineTop))
//            context.addLine(to: CGPoint(x: screenItem.x, y: screenItem.lineBottom))
//            context.strokePath()
//            
//            context.setFillColor(red: 1.0, green: 1.0, blue: 1.0, alpha: 0.0)
//            context.setFillColor(screenItem.fillColor.cgColor)
//            context.fill(screenItem.rect)
////            context.stroke(screenItem.rect)
//        }
//    }
//    
//    override func chartInitialized(chart: Chart) {
//        super.chartInitialized(chart: chart)
//        
//        self.screenItems = generateScreenItems()
//    }
//    
//    func generateScreenItems() -> [CandleStickScreenItem] {
//        return chartPointsModels.map {model in
//            
//            let chartPoint = model.chartPoint
//            
//            let x = model.screenLoc.x
//            
//            let highScreenY = modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.high)).y
//            let lowScreenY = modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.low)).y
//            let openScreenY = modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.open)).y
//            let closeScreenY = modelLocToScreenLoc(x: Double(x), y: Double(chartPoint.close)).y
//            
//            let (rectTop, rectBottom, fillColor) = closeScreenY < openScreenY ? (closeScreenY, openScreenY, self.increasingColor) : (openScreenY, closeScreenY, self.decreasingColor)
//            return CandleStickScreenItem(x: x, lineTop: highScreenY, lineBottom: lowScreenY, rectTop: rectTop, rectBottom: rectBottom, width: itemWidth, fillColor: fillColor)
//        }
//    }
//}
//
//struct CandleStickScreenItem {
//    let x: CGFloat
//    let lineTop: CGFloat
//    let lineBottom: CGFloat
//    let fillColor: UIColor
//    let rect: CGRect
//    
//    init(x: CGFloat, lineTop: CGFloat, lineBottom: CGFloat, rectTop: CGFloat, rectBottom: CGFloat, width: CGFloat, fillColor: UIColor) {
//        self.x = x
//        self.lineTop = lineTop
//        self.lineBottom = lineBottom
//        self.rect = CGRect(x: x - (width / 2), y: rectTop, width: width, height: rectBottom - rectTop)
//        self.fillColor = fillColor
//    }
//    
//}
//
