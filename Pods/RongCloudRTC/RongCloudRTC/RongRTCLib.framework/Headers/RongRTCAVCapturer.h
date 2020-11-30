//
//  RongRTCAVCapturer.h
//  RongRTCLib
//
//  Created by RongCloud on 2019/1/8.
//  Copyright © 2019年 RongCloud. All rights reserved.
//

#import "RongRTCAVOutputStream.h"
#import <CoreMedia/CoreMedia.h>
#import <UIKit/UIKit.h>
#import "RongRTCLocalVideoView.h"
#import "RongRTCVideoCaptureParam.h"
#import "RongRTCDefine.h"
#import "RongRTCAudioMixer.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 音视频采集管理实例, 注意: 该类已废弃, 音频操作请使用 RongRTCAudioCapturer 替换, 视频操作请使用 RongRTCVideoCapturer 替换
 */
@interface RongRTCAVCapturer : RongRTCAVOutputStream

/*!
 初始化
 
 @discussion
 初始化
 
 @warning
 不可用
 
 @remarks 资源管理
 @return 失败
 */
- (instancetype)init NS_UNAVAILABLE;

/*!
 初始化
 
 @discussion
 初始化
 
 @warning
 不可用
 
 @remarks 资源管理
 @return 失败
 */
- (instancetype)new NS_UNAVAILABLE;

/*!
 初始化
 
 @param pars 采集参数
 @param tag 标识
 @discussion
 初始化
 
 @warning
 不可用
 
 @remarks 资源管理
 @return 失败
 */
- (instancetype)initWithParameters:(nullable RongRTCStreamParams *)pars
                               tag:(NSString *)tag NS_UNAVAILABLE;

/*!
 获取单例对象
 
 @discussion
 获取单例对象
 
 @remarks 资源管理
 @return 采集器单例对象
 */
+ (instancetype)sharedInstance DEPRECATED_MSG_ATTRIBUTE("已废弃, 音频操作请使用 RongRTCAudioCapturer 替换, 视频操作请使用 RongRTCVideoCapturer 替换");

@end

NS_ASSUME_NONNULL_END
