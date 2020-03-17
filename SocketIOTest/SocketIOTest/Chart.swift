//
//  Chart.swift
//  SocketIOTest
//
//  Created by 박진수 on 17/03/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import Foundation

enum GraphType: String {
    case day = "1d"
    case week = "1w"
    case month = "1m"
    case thirdMonth = "3m"
    case year = "1y"
    case fifthYear = "5y"
}

struct Chart: Decodable {
    let type: String
    let graphType: String
    let market: String
    let stockId: Int
}
