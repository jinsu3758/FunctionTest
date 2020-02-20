//
//  ChartAxisModel.swift
//  SwiftCharts
//
//  Created by ischuetz on 22/04/15.
//  Copyright (c) 2015 ivanschuetz. All rights reserved.
//

import UIKit

public enum ChartAxisPadding {
    case label /// Add padding corresponding to half of leading / trailing label sizes
    case none
    case fixed(CGFloat) /// Set a fixed padding value
    case maxLabelFixed(CGFloat) /// Use max of padding value corresponding to .Label and a fixed value
    case labelPlus(CGFloat) /// Use .Label padding + a fixed value
}

public func ==(a: ChartAxisPadding, b: ChartAxisPadding) -> Bool {
    switch (a, b) {
    case (.label, .label): return true
    case (.fixed(let a), .fixed(let b)) where a == b: return true
    case (.maxLabelFixed(let a), .maxLabelFixed(let b)) where a == b: return true
    case (.labelPlus(let a), .labelPlus(let b)) where a == b: return true
    case (.none, .none): return true
    default: return false
    }
}

/// This class models the contents of a chart axis
open class ChartAxisModel {
    
    let firstModelValue: Double
    let lastModelValue: Double
    
    let axisValuesGenerator: ChartAxisValuesGenerator
    let labelsGenerator: ChartAxisLabelsGenerator
    
    /// The color used to draw the axis lines
    let lineColor: UIColor  // axis 컬러

    /// The axis title lables
    let axisTitleLabels: [ChartAxisLabel]

    let labelsConflictSolver: ChartAxisLabelsConflictSolver?
    
    let leadingPadding: ChartAxisPadding
    let trailingPadding: ChartAxisPadding

    let labelSpaceReservationMode: AxisLabelsSpaceReservationMode
    let clipContents: Bool
    
    public convenience init<T>(value: [T], labelSettings: ChartLabelSettings = ChartLabelSettings(font: UIFont.systemFont(ofSize: 0)), lineColor: UIColor = .black, axisTitle: String? = nil, dateFormat: String = "MM dd") {
        var xValue: [ChartAxisValue] = []
        switch T.self {
        case is Double.Type:
            xValue = value.map { ChartAxisValueDouble($0 as! Double, labelSettings: labelSettings)}
        case is Date.Type:
            let dateFormatter = DateFormatter()
            dateFormatter.dateFormat = dateFormat
            xValue = value.map { ChartAxisValueDate(date: $0 as! Date, formatter: dateFormatter, labelSettings: labelSettings) }
        case is Int.Type:
            xValue = value.map { ChartAxisValueInt($0 as! Int, labelSettings: labelSettings)}
        default:
            break
        }
        if let axisTitle = axisTitle {
            self.init(axisValues: xValue, lineColor: lineColor, axisTitleLabel: ChartAxisLabel(text: axisTitle, settings: labelSettings))
        }
        else {
            self.init(axisValues: xValue, lineColor: lineColor)
        }
    }
    
    public convenience init(axisLineColor: UIColor = UIColor.black, labelSettings: ChartLabelSettings = ChartLabelSettings(font: UIFont.systemFont(ofSize: 0)), firstModelValue: Double, lastModelValue: Double, axisTitle: String? = nil, axisValuesGenerator: ChartAxisValuesGenerator, labelsGenerator: ChartAxisLabelsGenerator) {
        if let axisTitle = axisTitle {
            self.init(lineColor: axisLineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisTitleLabels: [ChartAxisLabel(text: axisTitle, settings: labelSettings)], axisValuesGenerator: axisValuesGenerator, labelsGenerator: labelsGenerator)
        }
        else {
            self.init(lineColor: axisLineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisValuesGenerator: axisValuesGenerator, labelsGenerator: labelsGenerator)
        }
        
    }
    
    public convenience init(axisValues: [ChartAxisValue], lineColor: UIColor = UIColor.black, axisTitleLabel: ChartAxisLabel, labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
        self.init(axisValues: axisValues, lineColor: lineColor, axisTitleLabels: [axisTitleLabel], labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
    }

    /// Convenience initializer to pass a fixed axis value array. The array is mapped to axis values and label generators. 
    public convenience init(axisValues: [ChartAxisValue], lineColor: UIColor = UIColor.black, axisTitleLabels: [ChartAxisLabel] = [], labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
        precondition(!axisValues.isEmpty, "Axis cannot be empty")
        
        var scalars: [Double] = []
        var dict = [Double: [ChartAxisLabel]]()
        for axisValue in axisValues {
            scalars.append(axisValue.scalar)
            dict[axisValue.scalar] = axisValue.labels
        }
        let (firstModelValue, lastModelValue) = (axisValues.first!.scalar, axisValues.last!.scalar)
        
        let fixedArrayGenerator = ChartAxisValuesGeneratorFixed(values: scalars)
        let fixedLabelGenerator = ChartAxisLabelsGeneratorFixed(dict: dict)
        
        self.init(lineColor: lineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisTitleLabels: axisTitleLabels, axisValuesGenerator: fixedArrayGenerator, labelsGenerator: fixedLabelGenerator, labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
    }
    
    public convenience init(lineColor: UIColor = UIColor.black, firstModelValue: Double, lastModelValue: Double, axisTitleLabel: ChartAxisLabel, axisValuesGenerator: ChartAxisValuesGenerator, labelsGenerator: ChartAxisLabelsGenerator, labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
        self.init(lineColor: lineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisTitleLabels: [axisTitleLabel], axisValuesGenerator: axisValuesGenerator, labelsGenerator: labelsGenerator, labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
    }

    public init(lineColor: UIColor = UIColor.black, firstModelValue: Double, lastModelValue: Double, axisTitleLabels: [ChartAxisLabel] = [], axisValuesGenerator: ChartAxisValuesGenerator, labelsGenerator: ChartAxisLabelsGenerator, labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
        
        self.lineColor = lineColor
        self.firstModelValue = firstModelValue
        self.lastModelValue = lastModelValue
        self.axisTitleLabels = axisTitleLabels
        self.axisValuesGenerator = axisValuesGenerator
        self.labelsGenerator = labelsGenerator
        self.labelsConflictSolver = labelsConflictSolver
        self.leadingPadding = leadingPadding
        self.trailingPadding = trailingPadding
        self.labelSpaceReservationMode = labelSpaceReservationMode
        self.clipContents = clipContents
    }
}

extension ChartAxisModel: CustomDebugStringConvertible {
    public var debugDescription: String {
        return [
            "firstModelValue": firstModelValue,
            "lastModelValue": lastModelValue,
            "axisTitleLabels": axisTitleLabels,
            
        ]
            .debugDescription
    }
}
