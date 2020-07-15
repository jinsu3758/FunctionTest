//
//  AppDelegate.swift
//  SciChartTest
//
//  Created by 박진수 on 2020/06/08.
//  Copyright © 2020 박진수. All rights reserved.
//

import UIKit
import SciChart

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        SCIChartSurface.setRuntimeLicenseKey("QHEKM+GVBK6+APW3vKpjbwNa8W2c3WfiPReLRblvdWfkqDQIqevqxCVeS1DvzoYEtF3/uAFysmo2nJkh8pX707WZQ5GPPj9j96fdMMJb+ydXIA1S3ZhJcMc/" + "r436YxVlRg5VCVFgmDX29tWdxEmk3iAk8SnJfHuC4cspgEiVCNe+G69/Pjf+wayn+Nvad7lQH6YjB2Ql25I/wK6vVLbaS865nGoeL3NEKygI4QLgSQv7NRSW7hwgpawSlB1FJvQF8PNZWXVKV6E655DjnMwx88" + "emnHFZtj9PZREFxlNb0jTykoIS9X99pl/JrT5E36o2Xp3WUI+tw6b8aiLJNKmdkr7c/yfgGq9dH3ba+emwBOH/98icAp+VnoJZ67Q0Hpu1lpc6yQtknDUW6MynRhIRdtL/EHCMBsDkq+9MATN15z+ziI9Ioub+Ca7NfnZTyxfZWOgUyFDFERsOq08rOZGocXZsif" + "g44+kgy259yPVo8imB+yXpZxAL6XExZqR4ePlZ+/TgJ6leVBARWGGy/JkvbGz2SGbBOaQKv1JaNAB8d34tKtUBjiM4UcafdqCWmsUy/7BN")
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

