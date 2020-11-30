//
//  RongRTCAudioMixerEngine.h
//  IMRTCService
//
//  Created by RongCloud on 2019/5/7.
//  Copyright © 2019 RongCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>
#import "RongRTCGlobals.h"

typedef NS_ENUM(NSUInteger, RTCMixEngineStatus) {
    /**
     normal
     */
    RTCMixEngineStatusNormal,
    /**
     准备中
     */
    RTCMixEngineStatusPrepare,
    /**
     播放中（或混音中）
     */
    RTCMixEngineStatusPlaying,
    /**
     暂停中
     */
    RTCMixEngineStatusPause,
    
    /**
    停止
    */
    RTCMixEngineStatusStop
};

/// 无限期循环
RONGRTCLIB_EXTERN const UInt32 RongRTCLoopsIndefinitely;

/// 混音模式
typedef NS_ENUM(NSInteger, RongRTCMixerMode) {
    RongRTCMixerModeNone, /// 对端只能听见麦克风采集的声音
    RongRTCMixerModeMixing, /// 对端能够听到麦克风采集的声音和音频文件的声音
    RongRTCMixerModeReplace /// 对端只能听到音频文件的声音
};


NS_ASSUME_NONNULL_BEGIN


/// AudioMixer 的播放代理
@protocol RongRTCAudioMixerAudioPlayDelegate <NSObject>


/// 当前播放进度
/// @param progress 播放进度 range [0,1]
- (void)didReportPlayingProgress:(float)progress;

/// 播放结束，如果循环播放多次，多次循环后调用
- (void)didPlayToEnd;
@end

/**
 混音引擎
 */
@interface RongRTCAudioMixer : NSObject

/**
 获取混音引擎单例

 @return 混音引擎单例
 */
+(RongRTCAudioMixer *)sharedEngine;


/// AudioMixer 的代理
@property(nonatomic, weak) id<RongRTCAudioMixerAudioPlayDelegate> delegate;

/// 音频文件混音时的输入音量
/// audioFileInputVolume  取值范围 [0,100]
/// 默认值 100
@property (nonatomic, assign) NSUInteger mixingVolume;

/// 音频文件本地播放音量
/// audioFilePlayVolume  取值范围 [0,100]
/// 默认值 100
@property (nonatomic, assign) NSUInteger playingVolume;
/**
 当前混音状态
 */
@property (nonatomic, assign, readonly) RTCMixEngineStatus status;


/// 方法 writeAudioBufferList:frames:sampleTime:playback:  写入 AudioBufferList 的格式
@property (nonatomic, readonly, class) AudioStreamBasicDescription writeAsbd;

/// 获取指定音频文件的时长
/// @param url  音频文件的 File URL, 仅支持本地文件
+ (Float64)durationOfAudioFile:(NSURL*)url;


/// 设置播放进度
/// @param progress 设置播放进度 取值范围 [0,1]
- (void)setPlayProgress:(float)progress;


/// 混音功能（目前只支持混合本地音频数据），开始新混音之前需要先调用 stop，结束混音, 重复调用会忽略操作
/// @param fileURL 文件 URL  仅支持本地文件
/// @param isPlay   是否播放
/// @param mode 混音行为模式
/// @param count 循环混音或者播放次数
- (BOOL)startMixingWithURL:(NSURL*)fileURL
                  playback:(BOOL)isPlay
                 mixerMode:(RongRTCMixerMode)mode
                 loopCount:(NSUInteger)count;


/// 写入 自定义的 AudioBufferList
/// @param abl 音频数据
/// @param frames 音频帧个数
/// @param sampleTime 音频帧时间戳
/// @param isPlay 是否在本地播放
- (void)writeAudioBufferList:(const AudioBufferList*)abl
                      frames:(UInt32)frames
                  sampleTime:(SInt64)sampleTime
                    playback:(BOOL)isPlay;

/// 暂停
/// @return 暂停是否成功
- (BOOL)pause;

/// 恢复
/// @return 暂停是否成功
- (BOOL)resume;

/// 结束混音
- (BOOL)stop;

@end

NS_ASSUME_NONNULL_END
