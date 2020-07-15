//
//  StrongReference.swift
//  ReferenceTest
//
//  Created by 박진수 on 2020/07/02.
//  Copyright © 2020 박진수. All rights reserved.
//

import Foundation

class ClosureTest {
    var id: Int
    
    lazy var closure: () -> Int  = {
        self.id += 1
        return self.id
    }
    
    init(id: Int) {
        self.id = id
    }
    
    deinit {
        print("ClosureTest is deallocated")
    }
    
    func makeIncrementer(forIncrement amount: Int) -> () -> Int {
        var runningTotal = 0
        func incrementer() -> Int {
            runningTotal += amount
            return runningTotal
        }
        return incrementer
    }
    
}
