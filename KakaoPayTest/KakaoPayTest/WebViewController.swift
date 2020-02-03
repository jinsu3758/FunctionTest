//
//  WebViewController.swift
//  KakaoPayTest
//
//  Created by 박진수 on 12/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit
import WebKit

protocol KaKaoPayDelegate {
    func successPay()
}

enum RedirectURL {
    case success
    case cancel
    case fail
    
    init(url: String) {
        if url.contains("Success") {
            self = .success
        }
        else if url.contains("Cancel") {
            self = .cancel
        }
        else {
            self = .fail
        }
    
    }
    
}

class WebViewController: UIViewController {
    @IBOutlet weak var webView: WKWebView!
    @IBOutlet weak var indicator: UIActivityIndicatorView!
    
    var payInfo: PayInfo?
    var payDelegate: KaKaoPayDelegate?
    private let dataController = DataController()
    
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
        print("리다이렉트!!")
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        guard let urlString = navigationAction.request.url?.absoluteString, let urlComponents = URLComponents(string: urlString), urlString.contains("localhost") else {
            decisionHandler(.allow)
            return
        }
        let result = RedirectURL(url: urlString)
        switch result {
        case .success:
            guard let token = urlComponents.queryItems?.first?.value else { break }
            indicator.startAnimating()
            dataController.requestPayApprove(payId: payInfo?.payId ?? "", token: token, completion: { [unowned self] data in
                if data == nil {
                    let alert = UIAlertController(title: "실패", message: nil, preferredStyle: .alert)
                    self.present(alert, animated: true, completion: nil)
                }
                print("성공!")
                self.indicator.stopAnimating()
                self.payDelegate?.successPay()
                self.dismiss(animated: true, completion: nil)

            })
        case .cancel:
            print("취소!")
        case .fail:
            print("실패!")
        }
        decisionHandler(.allow)
    }
}
