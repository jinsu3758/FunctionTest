//
//  ZSocketManager.swift
//  SocketIOTest
//
//  Created by 박진수 on 17/03/2020.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit
import SocketIO

class ZSocketManager: NSObject {
    static let instance = ZSocketManager()
    
    fileprivate var manager = SocketManager(socketURL: URL(string: "wss://host/ws/v1/graph/candle")!, config: [.log(true), .compress])
    fileprivate var socket: SocketIOClient!
    
    override init() {
        super.init()
        socket = self.manager.defaultSocket
        // socket = self.manager.socket(forNamespace: "/test")  // test라는 룸을 만들어 룸단위로 구분 가능 default는 기본 위치 "/"
        
        socket.on(clientEvent: .connect) {data, ack in
            print("socket connected")
        }
        
    }
    
    func establishConnect() {
        socket.connect()
    }
    
    func disConnect() {
        socket.disconnect()
    }
    
    func sendMessage() {
        
    }
}
