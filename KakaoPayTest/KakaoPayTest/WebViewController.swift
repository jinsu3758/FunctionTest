//
//  WebViewController.swift
//  KakaoPayTest
//
//  Created by 박진수 on 12/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit
import WebKit

class WebViewController: UIViewController {
    @IBOutlet weak var webView: WKWebView!
    
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
}
