//
//  AppDelegate.m
//  CallKitTest
//
//  Created by zafer on 2020/11/27.
//  Copyright © 2020 zafer. All rights reserved.
//

#import "AppDelegate.h"
#import <RongIMKit/RongIMKit.h>
#import <RongIMLib/RongIMLib.h>
#import <RongCallKit/RongCallKit.h>
#import <RongCallLib/RongCallLib.h>
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    // AppKey 设置
    [[RCIMClient sharedRCIMClient] initWithAppKey:@"82hegw5u81m9x"];
//    [[RCIMClient sharedRCIMClient] setLogLevel:RC_Log_Level_Verbose];
    // RongCallKit初始化
    [RCCall sharedRCCall];
    return YES;
}
@end
