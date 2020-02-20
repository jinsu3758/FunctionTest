////
////  ZChartAxisModel.swift
////  CandleChartTest
////
////  Created by 박진수 on 19/02/2020.
////  Copyright © 2020 박진수. All rights reserved.
////
//
//import UIKit
//
//class ZChartAxisModel<T>: ChartAxisModel {
//    let labelSettings: ChartLabelSettings
//    
//    init(axisValue: [T], labelSetting: ChartLabelSettings = ChartLabelSettings(font: UIFont.systemFont(ofSize: 0)), lineColor: UIColor = .black, axisTitle: String? = nil, dateFormat: String = "MM dd") {
//        self.labelSettings = labelSetting
//        var xValue: [ChartAxisValue] = []
//        switch T.self {
//        case is Double.Type:
//            xValue = axisValue.map { ChartAxisValueDouble($0 as! Double, labelSettings: labelSetting)}
//        case is Date.Type:
//            let dateFormatter = DateFormatter()
//            dateFormatter.dateFormat = dateFormat
//            xValue = axisValue.map { ChartAxisValueDate(date: $0 as! Date, formatter: dateFormatter, labelSettings: labelSettings) }
//        case is Int.Type:
//            xValue = axisValue.map { ChartAxisValueInt($0 as! Int, labelSettings: labelSettings)}
//        default:
//            break
//        }
////        axisTitle != nil ? super.init(axisValues: xValue, lineColor: lineColor, axisTitleLabel: ChartAxisLabel(text: axisTitle!, settings: labelSetting)) : super.init(axisValues: xValue, lineColor: lineColor)
//        
//    }
//    
//    fileprivate convenience init(axisValues: [ChartAxisValue], lineColor: UIColor = UIColor.black, axisTitleLabel: ChartAxisLabel, labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
//        self.init(axisValues: axisValues, lineColor: lineColor, axisTitleLabels: [axisTitleLabel], labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
//    }
//    
//    public convenience init(axisValues: [ChartAxisValue], lineColor: UIColor = UIColor.black, axisTitleLabels: [ChartAxisLabel] = [], labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
//        precondition(!axisValues.isEmpty, "Axis cannot be empty")
//        
//        var scalars: [Double] = []
//        var dict = [Double: [ChartAxisLabel]]()
//        for axisValue in axisValues {
//            scalars.append(axisValue.scalar)
//            dict[axisValue.scalar] = axisValue.labels
//        }
//        let (firstModelValue, lastModelValue) = (axisValues.first!.scalar, axisValues.last!.scalar)
//        
//        let fixedArrayGenerator = ChartAxisValuesGeneratorFixed(values: scalars)
//        let fixedLabelGenerator = ChartAxisLabelsGeneratorFixed(dict: dict)
//        
//        super.init(lineColor: lineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisTitleLabels: axisTitleLabels, axisValuesGenerator: fixedArrayGenerator, labelsGenerator: fixedLabelGenerator, labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
//    }
//    
//    public convenience init(lineColor: UIColor = UIColor.black, firstModelValue: Double, lastModelValue: Double, axisTitleLabel: ChartAxisLabel, axisValuesGenerator: ChartAxisValuesGenerator, labelsGenerator: ChartAxisLabelsGenerator, labelsConflictSolver: ChartAxisLabelsConflictSolver? = nil, leadingPadding: ChartAxisPadding = .none, trailingPadding: ChartAxisPadding = .none, labelSpaceReservationMode: AxisLabelsSpaceReservationMode = .minPresentedSize, clipContents: Bool = false) {
//        super.init(lineColor: lineColor, firstModelValue: firstModelValue, lastModelValue: lastModelValue, axisTitleLabels: [axisTitleLabel], axisValuesGenerator: axisValuesGenerator, labelsGenerator: labelsGenerator, labelsConflictSolver: labelsConflictSolver, leadingPadding: leadingPadding, trailingPadding: trailingPadding, labelSpaceReservationMode: labelSpaceReservationMode, clipContents: clipContents)
//    }
//}
//
