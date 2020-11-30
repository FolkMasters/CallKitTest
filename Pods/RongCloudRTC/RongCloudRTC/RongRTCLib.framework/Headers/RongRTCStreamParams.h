//
//  RongRTCStreamParams.h
//  RongRTCLib
//
//  Created by RongCloud on 2020/04/15.
//  Copyright © 2020 RongCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RongRTCDefine.h"


NS_ASSUME_NONNULL_BEGIN

/*!
 创建 RongRTCAVOutputStream 时所使用的流参数类
 */
@interface RongRTCStreamParams : NSObject

/*!
 视频分辨率参数
 */
@property (nonatomic, assign) RongRTCVideoSizePreset videoSizePreset;

/*!
 视频发送帧率. 默认是 15 FPS
 */
@property (nonatomic, assign) RongRTCVideoFPS videoFrameRate;

/*!
 视频编解码
 */
@property (nonatomic, assign) RongRTCCodecType codecType;

/*!
 音频编解码方式
 */
@property (nonatomic, assign) RongRTCAudioCodecType audioCodecType;

/*!
 最大码率
 */
@property (nonatomic, assign) NSUInteger maxBitrate;

/*!
 最小码率
 */
@property (nonatomic, assign) NSUInteger minBitrate;

/*!
 分辨率
 
 @discussion
 分辨率
 
 @remarks 视频配置
 @return 分辨率
 */
- (CGSize)resolution;

/*!
 帧率
 
 @discussion
 帧率
 
 @remarks 视频配置
 @return 帧率
 */
- (NSInteger)fpsValue;

@end

NS_ASSUME_NONNULL_END
