//
//  ViewController.swift
//  CandleChartTest
//
//  Created by 박진수 on 28/01/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit
//import SwiftCharts

class ViewController: UIViewController {
    
    fileprivate var chart: Chart?

    override func viewDidLoad() {
        super.viewDidLoad()
        
//        let labelSettings = ChartLabelSettings(font: UIFont(name: "Helvetica", size: 0) ?? UIFont.systemFont(ofSize: 0))
        
        let readFormatter = DateFormatter()
        readFormatter.dateFormat = "dd.MM.yyyy"
        
        let displayFormatter = DateFormatter()
        displayFormatter.dateFormat = "MMM dd"
        
        let date = {(str: String) -> Date in
            return readFormatter.date(from: str)!
        }
        
        
        let chartPoints = [
            ChartPointCandleStick(date: date("01.10.2015"), formatter: displayFormatter, high: 40, low: 37, open: 39.5, close: 39),
            ChartPointCandleStick(date: date("02.10.2015"), formatter: displayFormatter, high: 39.8, low: 38, open: 39.5, close: 38.4),
            ChartPointCandleStick(date: date("03.10.2015"), formatter: displayFormatter, high: 43, low: 39, open: 41.5, close: 42.5),
            ChartPointCandleStick(date: date("04.10.2015"), formatter: displayFormatter, high: 48, low: 42, open: 44.6, close: 44.5),
            ChartPointCandleStick(date: date("05.10.2015"), formatter: displayFormatter, high: 45, low: 41.6, open: 43, close: 44),
            ChartPointCandleStick(date: date("06.10.2015"), formatter: displayFormatter, high: 46, low: 42.6, open: 44, close: 46),
            ChartPointCandleStick(date: date("07.10.2015"), formatter: displayFormatter, high: 47.5, low: 41, open: 42, close: 45.5),
            ChartPointCandleStick(date: date("08.10.2015"), formatter: displayFormatter, high: 50, low: 46, open: 46, close: 49),
            ChartPointCandleStick(date: date("09.10.2015"), formatter: displayFormatter, high: 45, low: 41, open: 44, close: 43.5),
            ChartPointCandleStick(date: date("11.10.2015"), formatter: displayFormatter, high: 47, low: 35, open: 45, close: 39),
            ChartPointCandleStick(date: date("12.10.2015"), formatter: displayFormatter, high: 45, low: 33, open: 44, close: 40),
            ChartPointCandleStick(date: date("13.10.2015"), formatter: displayFormatter, high: 43, low: 36, open: 41, close: 38),
            ChartPointCandleStick(date: date("14.10.2015"), formatter: displayFormatter, high: 42, low: 31, open: 38, close: 39),
            ChartPointCandleStick(date: date("15.10.2015"), formatter: displayFormatter, high: 39, low: 34, open: 37, close: 36),
            ChartPointCandleStick(date: date("16.10.2015"), formatter: displayFormatter, high: 35, low: 32, open: 34, close: 33.5),
            ChartPointCandleStick(date: date("17.10.2015"), formatter: displayFormatter, high: 32, low: 29, open: 31.5, close: 31),
            ChartPointCandleStick(date: date("18.10.2015"), formatter: displayFormatter, high: 31, low: 29.5, open: 29.5, close: 30),
            ChartPointCandleStick(date: date("19.10.2015"), formatter: displayFormatter, high: 29, low: 25, open: 25.5, close: 25),
            ChartPointCandleStick(date: date("20.10.2015"), formatter: displayFormatter, high: 28, low: 24, open: 26.7, close: 27.5),
            ChartPointCandleStick(date: date("21.10.2015"), formatter: displayFormatter, high: 28.5, low: 25.3, open: 26, close: 27),
            ChartPointCandleStick(date: date("22.10.2015"), formatter: displayFormatter, high: 30, low: 28, open: 28, close: 30),
            ChartPointCandleStick(date: date("23.10.2015"), formatter: displayFormatter, high: 30, low: 28, open: 28, close: 30),
            ChartPointCandleStick(date: date("24.10.2015"), formatter: displayFormatter, high: 30, low: 28, open: 28, close: 30),
            ChartPointCandleStick(date: date("25.10.2015"), formatter: displayFormatter, high: 31, low: 29, open: 31, close: 31),
            ChartPointCandleStick(date: date("26.10.2015"), formatter: displayFormatter, high: 31.5, low: 29.2, open: 29.6, close: 29.6),
            ChartPointCandleStick(date: date("27.10.2015"), formatter: displayFormatter, high: 30, low: 27, open: 29, close: 28.5),
            ChartPointCandleStick(date: date("28.10.2015"), formatter: displayFormatter, high: 32, low: 30, open: 31, close: 30.6),
            ChartPointCandleStick(date: date("29.10.2015"), formatter: displayFormatter, high: 35, low: 31, open: 31, close: 33),
            ChartPointCandleStick(date: date("30.10.2015"), formatter: displayFormatter, high: 35, low: 31, open: 31, close: 33),
            ChartPointCandleStick(date: date("31.10.2015"), formatter: displayFormatter, high: 35, low: 31, open: 31, close: 33),
        ]
        
        let barValues: [Double] = [15,20,54,24,23,43,23,43,23,43,23,43,55, 66, 77, 88, 99]
        let candleChart = ZCandleChart(candleChartFrame: CGRect(x: 0, y: 70, width: self.view.bounds.width, height: self.view.bounds.height - 90), barChartFrame: CGRect(x: 0, y: self.view.bounds.height - 180, width: self.view.bounds.width, height: 100))
        
        self.view.addSubview(candleChart)
        candleChart.setChart(candleStickChartPoints: chartPoints, barChartValues: barValues)
        
//        let yValues = stride(from: 20, through: 55, by: 5).map {ChartAxisValueDouble(Double($0), labelSettings: labelSettings)}
//
//        let xGeneratorDate = ChartAxisValuesGeneratorDate(unit: .day, preferredDividers:2, minSpace: 1, maxTextSize: 12)
//        let xLabelGeneratorDate = ChartAxisLabelsGeneratorDate(labelSettings: labelSettings, formatter: displayFormatter)
//        let firstDate = date("01.10.2015")
//        let lastDate = date("31.10.2015")
//        let xModel = ChartAxisModel(firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGeneratorDate, labelsGenerator: xLabelGeneratorDate)
//
//        let yModel = ChartAxisModel(axisValues: yValues, axisTitleLabel: ChartAxisLabel(text: "Axis title", settings: labelSettings.defaultVertical()))
//        let chartFrame = ExamplesDefaults.chartFrame(view.bounds)
//
//        let chartSettings = ExamplesDefaults.chartSettings // for now zoom & pan disabled, layer needs correct scaling mode.
//
//        let coordsSpace = ChartCoordsSpaceRightBottomSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
//        let (xAxisLayer, yAxisLayer, innerFrame) = (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//
//        let chartPointsLineLayer = ChartCandleStickLayer<ChartPointCandleStick>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, chartPoints: chartPoints)
//
//        let chart = Chart(
//            frame: chartFrame,
//            innerFrame: innerFrame,
//            settings: chartSettings,
//            layers: [
//                xAxisLayer,
//                yAxisLayer,
//                chartPointsLineLayer
//            ]
//        )
//        view.addSubview(chart.view)
//        self.chart = chart
        
//        func filler(_ date: Date) -> ChartAxisValueDate {
//            let filler = ChartAxisValueDate(date: date, formatter: displayFormatter)
//            filler.hidden = true
//            return filler
//        }
//
//        // 20에서 55까지 5의 보폭으로
//        let yValues = stride(from: 20, through: 55, by: 5).map { ChartAxisValueDouble(Double($0), labelSettings: labelSettings) }   // y축 label value 생성, generator가 아니 value array로 생성
//        let xGeneratorDate = ChartAxisValuesGeneratorDate(unit: .month, preferredDividers: 5, minSpace: 1, maxTextSize: 12)   // 2칸으로 나누는 듯
//        let xLabelGeneratorDate = ChartAxisLabelsGeneratorDate(labelSettings: labelSettings, formatter: displayFormatter)
//        let firstDate = date("01.01.2015")
//        let lastDate = date("29.12.2015")
//        print("\(firstDate.timeIntervalSince1970)!!")
//        // firstDate부터 lastDate까지 xGenerator과 xLabelGenerator로 x축 모델을 만듬
//        let xModel = ChartAxisModel(firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970,  axisValuesGenerator: xGeneratorDate, labelsGenerator: xLabelGeneratorDate)
//        // y축 label들을 구성할 value array로 y축 모델 구성
//        let yModel = ChartAxisModel(axisValues: yValues)
//
//        let chartFrame = ExamplesDefaults.chartFrame(view.bounds)
////        let chartFrame = chartView.bounds
//        let chartSettings = ExamplesDefaults.chartSettingsWithPanZoom
//
//        let coordsSpace = ChartCoordsSpaceRightBottomSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)   // axis layer 생성
//        let (xAxisLayer, yAxisLayer, innerFrame) = (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
//
//
//        let chartPointsLineLayer = ChartCandleStickLayer<ChartPointCandleStick>(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, chartPoints: chartPoints, itemWidth: 5, strokeWidth: 1, increasingColor: .red, decreasingColor: .blue, isHiddenRectStroke: true)
////        let guidelineSettings = ChartGuideLinesLayerSettings(linesColor: .red, linesWidth: ExamplesDefaults.guidelinesWidth)
////        let guidelineLayer = ChartGuideLinesLayer(xAxisLayer: xAxisLayer, yAxisLayer: yAxisLayer, settings: guidelineSettings)
////
////        let dividersSettings = ChartDividersLayerSettings(linesColor: .green, linesWidth: ExamplesDefaults.guidelinesWidth, start: 4, end: 0)
////        let dividersLayer = ChartDividersLayer(xAxisLayer: xAxisLayer, yAxisLayer: yAxisLayer, settings: dividersSettings)
//
//        let candleChart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, chartPointsLineLayer])
//
//        view.addSubview(candleChart.view)
//        self.chart = candleChart
        
    }
    
    
    


}

