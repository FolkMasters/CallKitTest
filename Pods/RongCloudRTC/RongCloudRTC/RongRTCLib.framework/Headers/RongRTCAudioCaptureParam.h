//
//  RongRTCAudioCaptureParam.h
//  RongRTCLib
//
//  Created by RongCloud on 2020/04/15.
//  Copyright © 2020 RongCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RongRTCDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface RongRTCAudioCaptureParam : NSObject

/*!
 获取默认音视频采集参数
 
 @discussion
 获取默认音视频采集参数
 
 @remarks 资源管理
 @return 视频采集器参数
 */
+ (RongRTCAudioCaptureParam *)defaultParameters;

/*!
 音频编解码方式, 默认: OPUS
 */
@property (nonatomic, assign) RongRTCAudioCodecType audioCodecType;

/*!
 音频使用模式，默认: 普通通话模式，RongRTC 支持音乐场景下的使用
 */
@property (nonatomic, assign) RongRTCAudioScenario audioScenario;

/*!
 当 RTC 音频为音乐模式时，可以设置音乐演奏模式，默认常规演奏模式
 */
@property (nonatomic, assign) RongRTCAudioScenarioMusicPlayMode musicPlayMode;

@end

NS_ASSUME_NONNULL_END
