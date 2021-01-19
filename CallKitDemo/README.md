
快捷回复

起手问题
您是基于RongCallKit.framework、RongCallLib.framework、RongRTCLib.framework哪一个进行开发的？使用的版本号是多少？



//视频流
- (void)didPublishStreams:(NSArray <RCRTCInputStream *> *)streams


//基于RTCLib获取本地视频流
[RCRTCEngine sharedInstance].defaultVideoStream.videoSendBufferCallback = ^CMSampleBufferRef _Nullable(BOOL valid, CMSampleBufferRef  _Nullable sampleBuffer) {
    return sampleBuffer;
};
//基于CallLib获取本地视频流
RCCallSessionDelegate的这个接口获取本视频buffer
- (CMSampleBufferRef)processVideoFrame:(CMSampleBufferRef)sampleBuffer

//获取网络状态
您好，您需要调用[RCRTCEngine sharedInstance].statusReportDelegate = self;
实现RCRTCStatusReportDelegate的
  - (void)didReportStatusForm:(RCRTCStatusForm*)form {
           form.networkType
          form.........
}


