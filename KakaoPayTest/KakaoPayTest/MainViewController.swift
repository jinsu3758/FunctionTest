//
//  ViewController.swift
//  KakaoPayTest
//
//  Created by 박진수 on 05/11/2019.
//  Copyright © 2019 박진수. All rights reserved.
//

import UIKit

class MainViewController: UIViewController {

    let dataController = DataController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func onPay(_ sender: Any) {
        dataController.requestPay { [unowned self] payinfo in
            if let webVC = self.storyboard?.instantiateViewController(withIdentifier: "webVC") as? WebViewController {
                webVC.payInfo = payinfo
                self.present(webVC, animated: true, completion: nil)
            }
        }
    }
    
}

