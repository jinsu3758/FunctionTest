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

enum ApiError: Error {
    case urlError
    case requestError
    case decoderError
    case clientError
    case serverError
}

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
    
    func request<T: Decodable>(for: T.Type = T.self, with queryItems: [URLQueryItem], method: HTTPMethod, header: [String : String]? = nil, completion: @escaping (Result<T, Error>) -> Void) {
        guard var urlComponents = URLComponents(string: baseURL + path) else {
            completion(.failure(ApiError.urlError))
            return
        }
        
        if method == .get || method == .delete {
            urlComponents.queryItems = queryItems
        }
        
        guard let url = urlComponents.url else {
            completion(.failure(ApiError.urlError))
            return
        }
        
        var request: URLRequest = URLRequest(url: url)
        if let header = header {
            for (key, value) in header {
                request.setValue(value, forHTTPHeaderField: key)
            }
        }
        
        request.httpMethod = method.rawValue
        request.timeoutInterval = timeout
        request.cachePolicy = .reloadIgnoringCacheData
        
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
            guard let data = data, error == nil else {
                completion(.failure(ApiError.requestError))
                return
            }
            
            let result = ApiResponse(response)
            switch result {
            case .success:
                do {
                    let item = try JSONDecoder().decode(T.self, from: data)
                    DispatchQueue.main.async {
                        completion(.success(item))
                    }
                    
                }
                catch {
                    DispatchQueue.main.async {
                        completion(.failure(ApiError.decoderError))
                    }
                }
                
            case .clientError:
                DispatchQueue.main.async {
                    completion(.failure(ApiError.clientError))
                }
            case .serverError:
                DispatchQueue.main.async {
                    completion(.failure(ApiError.serverError))
                }
            }
        }
        dataTask?.resume()
    }
}
