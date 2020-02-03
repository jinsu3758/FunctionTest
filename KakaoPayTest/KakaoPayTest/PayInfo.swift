//
//  PayInfo.swift
//  KakaoPayTest
//
//  Created by 박진수 on 12/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import Foundation

struct PayInfo: Codable {
    var payId: String = ""
    var webURL: String = ""
    var iosScheme: String = ""
    var requestTime: String = ""
    
    init() {}
    
    private enum CodingKeys: String, CodingKey {
        case payId = "tid"
        case webURL = "next_redirect_app_url"
        case iosScheme = "ios_app_scheme"
        case requestTime = "created_at"
    }
}
