//
//  WebViewController.swift
//  KakaoPayTest
//
//  Created by 박진수 on 12/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit
import WebKit

enum RedirectURL: String {
    case success = "http://localhost:8080/kakaoPaySuccess"
    case cancel = "http://localhost:8080/kakaoPayCancel"
    case fail = "http://localhost:8080/kakaoPayFail"
    
}

class WebViewController: UIViewController {
    @IBOutlet weak var webView: WKWebView!
    @IBOutlet weak var indicator: UIActivityIndicatorView!
    
    var payInfo: PayInfo?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.addSubview(webView)
        webView.uiDelegate = self
        webView.navigationDelegate = self
        if let payInfo = payInfo, let url = URL(string: payInfo.webURL) {
            let request = URLRequest(url: url)
            webView.load(request)
            if let appUrl = URL(string: payInfo.iosScheme), UIApplication.shared.canOpenURL(appUrl) {
                UIApplication.shared.open(appUrl, options: [:], completionHandler: nil)
            }

        }
    }

}

extension WebViewController: WKUIDelegate, WKNavigationDelegate {
    func webView(_ webView: WKWebView, didReceiveServerRedirectForProvisionalNavigation navigation: WKNavigation!) {
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        if let url = navigationAction.request.url?.absoluteString, let result = RedirectURL(rawValue: url) {
            switch result {
            case .success:
                indicator.startAnimating()
            case .cancel:
                break
            case .fail:
                break
            }
        }
        decisionHandler(.allow)
    }
}
