//
//  main.swift
//  ReferenceTest
//
//  Created by 박진수 on 2020/07/02.
//  Copyright © 2020 박진수. All rights reserved.
//

import Foundation

// 강한 순환 참조 예시
// 메모리에서 closureTest 객체가 deallocated되지 않는다.
// 클로저 안에 정의된 컨텍스트 안에서 모든 상수 및 변수가 캡쳐될 수 있기 때문



// MARK: 테스트 1
var closureTest: ClosureTest? = ClosureTest(id: 1)
print(closureTest!.closure())
//closureTest = nil

// MARK: 테스트 2
let incrementByTen = closureTest!.makeIncrementer(forIncrement: 10)
print(incrementByTen())
print(incrementByTen())
print(incrementByTen())

closureTest = nil
print(incrementByTen())


// MARK: 테스트 3
func sing() -> () -> Void {
  let daftPunk = Singer()

  let singing = {
    daftPunk.playSong()
    return
  }

  return singing
}

var singFunction: (() -> Void)? = sing()
singFunction!()
singFunction = nil




