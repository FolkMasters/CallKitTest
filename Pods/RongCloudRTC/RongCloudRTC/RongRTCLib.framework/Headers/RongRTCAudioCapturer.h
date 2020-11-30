//
//  RongRTCAudioCapturer.h
//  RongRTCLib
//
//  Created by RongCloud on 2020/4/16.
//  Copyright © 2020年 RongCloud. All rights reserved.
//

#import "RongRTCAVOutputStream.h"
#import "RongRTCAudioCaptureParam.h"
#import "RongRTCDefine.h"
#import "RongRTCAudioMixer.h"

extern BOOL bluetoothEnter;
extern double prevSampleRate;
NS_ASSUME_NONNULL_BEGIN

/*!
 音视频采集管理实例
 */
@interface RongRTCAudioCapturer : RongRTCAVOutputStream

/*!
 麦克风的音量, 范围: 0~100, 默认值: 100
 */
@property (nonatomic, assign) NSUInteger micVolume;

/*!
将要发送的音频 pcm 数据的回调
 */
@property (nonatomic, copy, nullable) RongRTCAudioBufferListCallback willSendAudioBufferCallback;

/*!
从远端接受将要播放的音频 pcm 数据的回调
 */
@property (nonatomic, copy, nullable) RongRTCAudioBufferListCallback willPlayAudioBufferCallback;
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
+ (instancetype)sharedInstance;

/*!
 通话前设置音频采集参数
 
 @param params 参数
 @discussion
 通话前设置音频采集参数, 通话过程中设置无效
 
 @remarks 资源管理
 */
- (void)setAudioCaptureParam:(RongRTCAudioCaptureParam *)params;

/*!
 关闭/打开麦克风
 
 @param disable YES 关闭,NO 打开
 @discussion
 关闭/打开麦克风
 
 @remarks 音频配置
 */
- (void)setMicrophoneDisable:(BOOL)disable;

/*!
 切换使用外放/听筒
 
 @param useSpeaker YES 使用扬声器  NO 不使用
 @discussion
 切换使用外放/听筒
 
 @remarks 音频配置
 @return 接入外设时, 如蓝牙音箱等 返回 NO
 */
- (BOOL)useSpeaker:(BOOL)useSpeaker;

/*!
 将所有远端用户静音
 
 @param mute 是否静音所有远端用户, YES 禁止  NO 允许
 @discussion
 将所有远端用户静音, 注: 该功能只是不播放接收到的音频数据
 
 @remarks 音频流处理
 */
- (void)muteAllRemoteAudio:(BOOL)mute;

/*!
 设置音乐演奏模式
 
 @param mode RongRTCAudioScenarioMusicPlayMode 音乐演奏模式, RongRTCAudioScenarioMusicNomalPlay 常规演奏模式,默认模式
 @discussion
 设置音乐演奏模式
 
 @remarks 音频流处理
 @return 设置是否成功
 */
- (BOOL)changeMusicPlayMode:(RongRTCAudioScenarioMusicPlayMode)mode;

@end

NS_ASSUME_NONNULL_END
