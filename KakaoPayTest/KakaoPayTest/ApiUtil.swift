//
//  ApiUtil.swift
//  KakaoPayTest
//
//  Created by 박진수 on 05/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit

enum HTTPMethod: String {
    case get = "GET"
    case post = "POST"
    case delete = "DELETE"
    case put = "PUT"
}

public typealias ApiResult = (_ data: Data?, _ error: Error?) -> Void

public enum ApiResponse {
    case success(statusCode: Int)
    case clientError(statusCode: Int)
    case serverError(statusCode: Int)
    
    init(_ urlResponse: URLResponse?) {
        let statusCode = (urlResponse as? HTTPURLResponse)?.statusCode ?? 500
        
        switch statusCode {
        case 200..<300:
            self = .success(statusCode: statusCode)
        case 400..<500:
            self = .clientError(statusCode: statusCode)
        default:
            self = .serverError(statusCode: statusCode)
        }
    }
}

class ApiUtil: NSObject {
    var baseURL: String = "https://kapi.kakao.com"
    var timeout: TimeInterval = 10.0
    var path: String = ""
    
    private var dataTask: URLSessionTask?
    private let urlSession = URLSession.shared
    
    func request(with queryItems: [URLQueryItem], method: HTTPMethod, header: [String : String]? = nil, completion: @escaping ApiResult) {
        guard var urlComponents = URLComponents(string: baseURL + path) else {
            completion(nil, nil)
            return
        }
        
        if method == .get || method == .delete {
            urlComponents.queryItems = queryItems
        }
        
        guard let url = urlComponents.url else {
            completion(nil, nil)
            return
        }
        
        var request: URLRequest = URLRequest(url: url)
        if let header = header {
            for (key, value) in header {
                request.setValue(value, forHTTPHeaderField: key)
            }
        }
        
        request.httpMethod = method.rawValue
//        request.timeoutInterval = timeout
//        request.cachePolicy = .reloadIgnoringCacheData
        
        if method == .post || method == .put {
            var query = URLComponents()
            query.queryItems = queryItems
            
            if var httpBody = query.url?.absoluteString {
                if httpBody.first == "?" {
                    httpBody.removeFirst()
                }
                request.httpBody = httpBody.data(using: String.Encoding.ascii, allowLossyConversion: true)
            }
        }
        
        dataTask = urlSession.dataTask(with: request) { data, response, error in
            guard error == nil else {
                completion(nil ,error)
                return
            }
            
            let result = ApiResponse(response)
            switch result {
            case .success:
                completion(data, nil)
            case .clientError, .serverError:
                completion(nil, error)
            }
        }
        dataTask?.resume()
    }
}