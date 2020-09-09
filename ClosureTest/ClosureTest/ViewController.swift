//
//  ViewController.swift
//  ClosureTest
//
//  Created by 박진수 on 2020/08/07.
//  Copyright © 2020 jinsu. All rights reserved.
//

import UIKit
import Combine

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        Just(5).sink { value in
            print(value)
        }
    }


}

