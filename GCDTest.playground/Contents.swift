import UIKit

var str = "Hello, playground"

/// sync 실험
//let serialSyncDispatchQueue = DispatchQueue(label: "Serial Queue")
//
//serialSyncDispatchQueue.sync {
//    print("1")
//}
//print("2")
//
//DispatchQueue.global().sync {
//    print("3")
//}
//
//DispatchQueue.global(qos: .background).sync {
//    print("4")
//}
//
//serialSyncDispatchQueue.sync {
//    print("5")
//}
/// 결과 : 12345


/// Serial, Concurrent
//DispatchQueue(label: "serial 1").async {
//    print("1")
//}
//DispatchQueue.global().async {
//    print("concurrent 1")
//}
//
//print("2")
//
//DispatchQueue.global().async {
//    print("concurrent 1")
//}
//
//DispatchQueue(label: "serail 2").async {
//    print("3")
//}
//DispatchQueue(label: "serial 3").sync {
//    print("4")
//}
//print("5")

/// 결과 : 21435는 일정 concurrent는 그 때 그 때 다름


/// 같은 DispatchQueue에서 sync, async해보기
//let serialDispatchQueue = DispatchQueue(label: "Serial Queue")

//serialDispatchQueue.sync {
//    print("1")
//}
//
//serialDispatchQueue.async {
//    print("2")
//}
//
//serialDispatchQueue.async {
//    print("3")
//}
//
//serialDispatchQueue.async {
//    print("4")
//}
//
//serialDispatchQueue.sync {
//    print("5")
//}
//serialDispatchQueue.async {
//    print("6")
//}

/// 결과 : 123456 순서대로 된다


//let serialDispatchQueue = DispatchQueue(label: "Serial Queue")
//let concurrentDispatchQueue = DispatchQueue.global()
//
//
//serialDispatchQueue.async {
//    print("1")
//}
//
//concurrentDispatchQueue.async {
//    print("2")
//}

let concurrentDispatchQueue = DispatchQueue.global()

concurrentDispatchQueue.async {
    print("2")
}

concurrentDispatchQueue.async {
    print("3")
}

concurrentDispatchQueue.async {
    print("4")
}

concurrentDispatchQueue.async {
    print("5")
}


