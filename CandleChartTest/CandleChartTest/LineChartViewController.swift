//
//  LineChartViewController.swift
//  CandleChartTest
//
//  Created by 박진수 on 10/02/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit

class LineChartViewController: UIViewController {
    fileprivate var chart: Chart?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let labelSettings = ChartLabelSettings(font: ExamplesDefaults.labelFont)
        let chartPoints: [ChartPoint] = [(1, 3), (2, 5), (3, 7.5), (4, 10), (5, 6), (6, 12)].map{ChartPoint(x: ChartAxisValueDouble($0.0, labelSettings: labelSettings), y: ChartAxisValueDouble($0.1))}
        let chartPoints2: [ChartPoint] = [(1, 5), (2, 2), (3, 8), (4, 4), (5, 2), (6, 9)].map{ChartPoint(x: ChartAxisValueDouble($0.0, labelSettings: labelSettings), y: ChartAxisValueDouble($0.1))}
        
        let xValues = chartPoints.map{$0.x}
        let yValues = ChartAxisValuesStaticGenerator.generateYAxisValuesWithChartPoints(chartPoints, minSegmentCount: 10, maxSegmentCount: 20, multiple: 2, axisValueGenerator: {ChartAxisValueDouble($0, labelSettings: labelSettings)}, addPaddingSegmentIfEdge: false)
        
        let lineModel = ChartLineModel(chartPoints: chartPoints, lineColor: UIColor.red, lineWidth: 2, animDuration: 0, animDelay: 0)
        let lineModel2 = ChartLineModel(chartPoints: chartPoints2, lineColor: UIColor.green, animDuration: 0, animDelay: 0)
        
        
        let xModel = ChartAxisModel(axisValues: xValues)
        let yModel = ChartAxisModel(axisValues: yValues)
        let chartFrame = ExamplesDefaults.chartFrame(view.bounds)
        let chartSettings = ExamplesDefaults.chartSettingsWithPanZoom
        
        let coordsSpace = ChartCoordsSpaceRightBottomSingleAxis(chartSettings: chartSettings, chartFrame: chartFrame, xModel: xModel, yModel: yModel)
        let (xAxisLayer, yAxisLayer, innerFrame) = (coordsSpace.xAxisLayer, coordsSpace.yAxisLayer, coordsSpace.chartInnerFrame)
        
        let chartPointsLineLayer = ChartPointsLineLayer(xAxis: xAxisLayer.axis, yAxis: yAxisLayer.axis, lineModels: [lineModel, lineModel2])
        
        let chart = Chart(frame: chartFrame, innerFrame: innerFrame, settings: chartSettings, layers: [xAxisLayer, yAxisLayer, chartPointsLineLayer])
        view.addSubview(chart.view)
        self.chart = chart
    }
    
    @IBAction func backVC(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
    }
    
}
