//
//  AppDelegate+Log.m
//  CallKitDemo
//
//  Created by Zafer.Lee on 2020/12/30.
//  Copyright © 2020 zafer. All rights reserved.
//

#import "AppDelegate+Log.h"
#import <RongIMKit/RongIMKit.h>

@implementation AppDelegate (Log)

- (void)redirectNSlogToDocumentFolder {
    [[RCIMClient sharedRCIMClient] setLogLevel:RC_Log_Level_Verbose];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentDirectory = [paths objectAtIndex:0];
    

    NSDate *currentDate = [NSDate date];
    NSDateFormatter *dateformatter = [[NSDateFormatter alloc] init];
    [dateformatter setDateFormat:@"MMddHHmmss"];
    NSString *formattedDate = [dateformatter stringFromDate:currentDate];

    NSString *fileName = [NSString stringWithFormat:@"rc%@.log", formattedDate];
    NSString *logFilePath = [documentDirectory stringByAppendingPathComponent:fileName];
    NSLog(@"%@",logFilePath);
    freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stdout);
    freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stderr);
}
@end

/*
 您好，请在AppDelegate.m中添加redirectNSlogToDocumentFolder方法, 并在
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 中添加下面日志级别设置 和 此方法的调用.
 [[RCIMClient sharedRCIMClient] setLogLevel:RC_Log_Level_Verbose];
 [self redirectNSlogToDocumentFolder];

 编译运行, 复现后把沙盒中的/Documents/rc******.log 日志 发一下吧
 ****************************************************************************************
 - (void)redirectNSlogToDocumentFolder {
     NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
     NSString *documentDirectory = [paths objectAtIndex:0];

     NSDate *currentDate = [NSDate date];
     NSDateFormatter *dateformatter = [[NSDateFormatter alloc] init];
     [dateformatter setDateFormat:@"MMddHHmmss"];
     NSString *formattedDate = [dateformatter stringFromDate:currentDate];

     NSString *fileName = [NSString stringWithFormat:@"rc%@.log", formattedDate];
     NSString *logFilePath = [documentDirectory stringByAppendingPathComponent:fileName];

     freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stdout);
     freopen([logFilePath cStringUsingEncoding:NSASCIIStringEncoding], "a+", stderr);
 }
 */
