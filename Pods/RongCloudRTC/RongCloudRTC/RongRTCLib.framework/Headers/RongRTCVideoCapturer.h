//
//  RongRTCVideoCapturer.h
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

NS_ASSUME_NONNULL_BEGIN

/*!
 音视频采集管理实例
 */
@interface RongRTCVideoCapturer : RongRTCAVOutputStream

/**
 设置通话过程中的视频分辨率
 */
@property (nonatomic, readonly) RongRTCVideoSizePreset videoSizePreset;

/*!
 设置通话过程中视频帧率
 */
@property (nonatomic, readonly) RongRTCVideoFPS videoFrameRate;

/*!
 当前摄像头的位置
 */
@property (nonatomic, readonly) RongRTCDeviceCamera cameraPosition;

/*!
 设置摄像头采集方向,默认以 AVCaptureVideoOrientationPortrait 角度进行采集
 */
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;

/*!
 引擎底部开始视频编码并发送之前会往上层抛一个回调,用户可以修改和调整 CMSampleBufferRef 数据,然后返回一个 CMSampleBufferRef 数据,如果返回空或者没有实现该回调,则会使用默认视频数据传输
 
 注：如果用户传正常数据,则内部会自行 CFRelease CMSampleBufferRef 对象,上层不需要再考虑释放问题
 */
@property (nonatomic, copy, nullable) RongRTCVideoCMSampleBufferCallback videoSendBufferCallback;

/*!
 本地摄像头采集的视频在即将预览前会往上层抛一个视频帧回调,用户可以处理视频帧数据之后然后回传给 RTC,RTC 使用用户处理的视频帧进行预览
 
 注：如果用户传正常数据,则内部会自行 CFRelease CMSampleBufferRef 对象,上层不需要再考虑释放问题
 */
@property (nonatomic, copy, nullable) RongRTCVideoCMSampleBufferCallback videoDisplayBufferCallback;

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
- (instancetype)initWithParameters:(nullable RongRTCStreamParams *)pars tag:(NSString *)tag NS_UNAVAILABLE;

/*!
 获取单例对象
 
 @discussion
 获取单例对象
 
 @remarks 资源管理
 @return 采集器单例对象
 */
+ (instancetype)sharedInstance;

/*!
 通话前设置视频采集参数
 
 @param params 参数
 @discussion
 通话前设置视频采集参数, 通话过程中设置无效
 
 @remarks 资源管理
*/
- (void)setVideoCaptureParam:(RongRTCVideoCaptureParam *)params;

/*!
 设置视频媒体数据的渲染界面
 
 @param render 渲染界面
 @discussion
 设置视频媒体数据的渲染界面
 
 @remarks 视频配置
 */
- (void)setVideoRender:(nullable RongRTCLocalVideoView *)render;

/*!
 切换前后摄像头
 
 @discussion
 切换前后摄像头
 
 @remarks 视频配置
 */
- (void)switchCamera;

/*!
 采集运行中关闭或打开摄像头
 
 @param disable YES 关闭  NO 打开
 @discussion
 采集运行中关闭或打开摄像头
 
 @remarks 视频配置
 */
- (void)setCameraDisable:(BOOL)disable;

/*!
 开启音视频采集
 
 @discussion
 开启音视频采集
 
 @remarks 资源管理
 */
- (void)startCapture;

/*!
 关闭音视频采集
 
 @discussion
 关闭音视频采集
 
 @remarks 资源管理
 */
- (void)stopCapture;

@end

NS_ASSUME_NONNULL_END
