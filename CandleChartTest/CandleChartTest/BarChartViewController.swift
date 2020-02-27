//
//  BarChartViewController.swift
//  CandleChartTest
//
//  Created by 박진수 on 27/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

class BarChartViewController: UIViewController {
    fileprivate var chart: Chart?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        var readFormatter = DateFormatter()
        readFormatter.dateFormat = "dd.MM.yyyy"
        let date = {(str: String) -> Date in
            return readFormatter.date(from: str)!
        }
        let chartFrame = CGRect(x: 0, y: 80, width: self.view.bounds.width, height: self.view.bounds.height - 160)
        
        let value = [(date("01.10.2015"), 3), (date("02.10.2015"), 5), (date("03.10.2015"), 7.5), (date("04.10.2015"), 10), (date("05.10.2015"), 6), (date("06.10.2015"), 12)]
        let chartPoints: [ChartPoint] = value.map { ChartPoint(x: ChartAxisValueDate(date: $0.0, formatter: readFormatter), y: ChartAxisValueDouble($0.1)) }
        let labelSettings = ChartLabelSettings(font: ExamplesDefaults.labelFont)
        
        
        let firstDate = date("01.10.2015")
        let lastDate = date("06.10.2015")
        let xGenerator = ChartAxisValuesGeneratorDate(unit: .day, preferredDividers: 2, minSpace: 1, maxTextSize: 12)
        let yGenerator = ChartAxisGeneratorMultiplier(2)
        let labelGenerator = ChartAxisLabelsGeneratorDate(labelSettings: labelSettings)
        
        let xModel = ChartAxisModel(firstModelValue: firstDate.timeIntervalSince1970, lastModelValue: lastDate.timeIntervalSince1970, axisValuesGenerator: xGenerator, labelsGenerator: labelGenerator)
        let yModel = ChartAxisModel(firstModelValue: 0, lastModelValue: 15, axisValuesGenerator: yGenerator, labelsGenerator: labelGenerator)
        
        let barViewGenerator = {(chartPointModel: ChartPointLayerModel, layer: ChartPointsViewsLayer, chart: Chart) -> UIView? in
            let bottomLeft = layer.modelLocToScreenLoc(x: 0, y: 0)
            
            let barWidth: CGFloat = 30
            
            let settings = ChartBarViewSettings(animDuration: 0.5)
            
            let (p1, p2): (CGPoint, CGPoint) = {
                return (CGPoint(x: chartPointModel.screenLoc.x, y: bottomLeft.y), CGPoint(x: chartPointModel.screenLoc.x, y: chartPointModel.screenLoc.y))
            }()
            return ChartPointViewBar(p1: p1, p2: p2, width: barWidth, bgColor: UIColor.blue.withAlphaComponent(0.6), settings: settings)
        }
        
        let coordsSpace = ChartCoordsSpaceLeftBottomSingleAxis(chartSettings: ChartSettings(), chartFrame: chartFrame, xModel: xModel, yModel: yModel)
        let (xAxisLayer, yAxisLayer, innerFrame) = (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        
        let chartPointsLayer = ChartPointsViewsLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, chartPoints: chartPoints, viewGenerator: barViewGenerator)
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: ChartSettings(), layers: [xAxisLayer, yAxisLayer, chartPointsLayer])
        self.view.addSubview(chart.view)
        self.chart = chart
    }
    @IBAction func backBtn(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
    }
    
}
