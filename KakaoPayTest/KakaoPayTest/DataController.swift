//
//  DataController.swift
//  KakaoPayTest
//
//  Created by 박진수 on 11/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit

class DataController: NSObject {
    private let api = ApiUtil()
    private let header: [String:String] = ["Content-Type": "application/x-www-form-urlencoded", "Authorization":"KakaoAK abc6c5b515b81585963b1c7809712d52"]
    
    func requestPay(completion: @escaping (PayInfo?) -> Void) {
        api.path = "/v1/payment/ready"
        
        let body: [URLQueryItem] = [URLQueryItem(name: "cid", value: "TC0ONETIME"), URLQueryItem(name: "partner_order_id", value: "partner_order_id"), URLQueryItem(name: "partner_user_id", value: "partner_user_id"), URLQueryItem(name: "item_name", value: "초코파이"), URLQueryItem(name: "quantity", value: "1"), URLQueryItem(name: "total_amount", value: "2200"), URLQueryItem(name: "vat_amount", value: "200"), URLQueryItem(name: "tax_free_amount", value: "0"), URLQueryItem(name: "approval_url", value: "http://localhost:8080/kakaoPaySuccess"), URLQueryItem(name: "cancel_url", value: "http://localhost:8080/kakaoPayCancel"), URLQueryItem(name: "fail_url", value: "http://localhost:8080/kakaoPayFail")]
        api.request(with: body, method: .post, header: header, completion: { data, error in
            guard let data = data, error == nil else {
                DispatchQueue.main.async {
                    completion(nil)
                }
                return
            }
            do {
                guard let json = try JSONSerialization.jsonObject(with: data, options: .mutableContainers) as? [String:Any] else {
                    DispatchQueue.main.async {
                        completion(nil)
                    }
                    return
                }
                var payInfo = PayInfo()
                payInfo.payId = json["tid"] as? String ?? ""
                payInfo.webURL = json["next_redirect_app_url"] as? String ?? ""
                payInfo.iosScheme = json["ios_app_scheme"] as? String ?? ""
                payInfo.requestTime = json["created_at"] as? String ?? ""
                DispatchQueue.main.async {
                completion(payInfo)
                }
            }
            catch {
                DispatchQueue.main.async {
                    completion(nil)
                }
            }
            
        })
        
    }
    
    func requestPayApprove(payId: String, token: String, completion: @escaping (String?, Error?) -> Void) {
        api.path = "v1/payment/approve"
        let body: [URLQueryItem] = [URLQueryItem(name: "cid", value: "TC0ONETIME"), URLQueryItem(name: "tid", value: payId), URLQueryItem(name: "partner_order_id", value: "partner_order_id"), URLQueryItem(name: "partner_user_id", value: "partner_user_id"), URLQueryItem(name: "pg_token", value: token)]
        
        api.request(with: body, method: .post, header: header, completion: { data, error in
            guard let data = data, error == nil else {
                DispatchQueue.main.async {
                    completion(nil, nil)
                }
                return
            }
            do {
                guard let json = try JSONSerialization.jsonObject(with: data, options: .mutableContainers) as? [String:Any] else {
                    DispatchQueue.main.async {
                        completion("ee", nil)
                    }
                    return
                }
            }
            catch {
                DispatchQueue.main.async {
                    completion(nil, error)
                }
            }
            
        })
        
    }
    
    
}
