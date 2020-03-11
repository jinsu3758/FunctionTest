//
//  ChartPointsTrackerLayer.swift
//  SwiftCharts
//
//  Created by ischuetz on 29/04/15.
//  Copyright (c) 2015 ivanschuetz. All rights reserved.
//

import UIKit

protocol TrackerLayerDelegate {
    func longPressedBegan(_ location: CGPoint)
    func longPressedMoved(_ location: CGPoint)
    func longPressedEnded(_ location: CGPoint)
}

open class ChartPointsTrackerLayer<T: ChartPoint>: ChartPointsLayer<T>{
    fileprivate var view: TrackerView?

    fileprivate let lineColor: UIColor
    fileprivate let lineWidth: CGFloat
    
    
    var delegate: TrackerLayerDelegate?
    
    fileprivate lazy private(set) var currentPositionLineOverlay: UIView = {
        let currentPositionLineOverlay = UIView()
        currentPositionLineOverlay.backgroundColor = self.lineColor
        return currentPositionLineOverlay
    }()
    
    
    public init(xAxis: ChartAxis, yAxis: ChartAxis, chartPoints: [T], lineColor: UIColor = UIColor.black, lineWidth: CGFloat = 1) {
        self.lineColor = lineColor
        self.lineWidth = lineWidth
        super.init(xAxis: xAxis, yAxis: yAxis, chartPoints: chartPoints)
        self.currentPositionLineOverlay.isHidden = true
    }
    
    open override func display(chart: Chart) {
        let view = TrackerView(frame: chart.bounds, updateFunc: {[weak self] (location, state) in
            switch state {
            case .began:
                self?.currentPositionLineOverlay.isHidden = false
                self?.delegate?.longPressedMoved(location)
            case .changed:
                self?.delegate?.longPressedMoved(location)
            case .ended:
                self?.currentPositionLineOverlay.isHidden = true
                self?.delegate?.longPressedEnded(location)
            default:
                break
            }
        })
        view.isUserInteractionEnabled = true
        chart.addSubview(view)
        self.view = view
        
        view.addSubview(currentPositionLineOverlay)
        
        currentPositionLineOverlay.frame = CGRect(x: chart.containerFrame.origin.x + 200 - lineWidth / 2, y: modelLocToScreenLoc(y: yAxis.last), width: lineWidth, height: modelLocToScreenLoc(y: yAxis.first))
    }
    
    func moveToView(_ toX: CGFloat) {
        self.currentPositionLineOverlay.center.x = toX
    }
    
    
    func getChartPointForScreenLocX(_ x: CGFloat, dateComponent: ChartDateComponent) -> ChartPoint {
        var interval: Double = 0
        var chartPoint = ChartPoint()
        switch dateComponent {
        case .day:
            interval = 60
        case .week:
            interval = 604800
        case .month:
            interval = 2592000
        case .threeMonth:
            interval = 7776000
        case .year:
            interval = 31536000
        case .fiveYear:
            interval = 157680000
        default:
            break
        }
        self.chartPoints.forEach { point in
            
            let chartPointsX = point.x.scalar
            let screenX = Double(x)
            if (chartPointsX - interval)...(chartPointsX + 60) ~= screenX {
                chartPoint = point
                return
            }
        }
        return chartPoint
    }
    
    override open func chartPointsForScreenLocX(_ x: CGFloat) -> [T] {
        return super.chartPointsForScreenLocX(x)
    }
}


private class TrackerView: UIView {
    
    let updateFunc: ((CGPoint, UIGestureRecognizer.State) -> ())?
    var gesture: UILongPressGestureRecognizer = UILongPressGestureRecognizer()
    
    init(frame: CGRect, updateFunc: @escaping (CGPoint, UIGestureRecognizer.State) -> ()) {
        self.updateFunc = updateFunc
        super.init(frame: frame)
        gesture = UILongPressGestureRecognizer(target: self, action: #selector(longPressend(_:)))
        self.addGestureRecognizer(gesture)
    }
    
    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @objc func longPressend(_ sender: UILongPressGestureRecognizer) {
        let location = sender.location(in: self)
        self.updateFunc?(location, sender.state)
    }
}
