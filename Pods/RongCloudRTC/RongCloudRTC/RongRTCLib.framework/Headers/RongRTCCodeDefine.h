//
//  RongRTCError.h
//  RongRTCLib
//
//  Created by RongCloud on 2019/1/12.
//  Copyright © 2019 RongCloud. All rights reserved.
//

#ifndef RongRTCError_h
#define RongRTCError_h

/*!
 音视频错误码定义
 
 服务器返回错误以 4 开头，后两位是业务代码，最后两位是错误码 4XXXX，如 400XX 基础连接部分
 本地返回错误以 5 开头，后两位是业务代码，最后两位是错误码 5XXXX，如 500XX 初始化基础连接部分
 */
typedef NS_ENUM (NSInteger, RongRTCCode)
{
    /*!
     成功
     */
    RongRTCCodeSuccess = 0,
    /*!
     初始化失败, 信令服务（IM Server）未连接
     */
    RongRTCCodeSignalServerNotConnect = 50000,
    /*!
     参数错误
     */
    RongRTCCodeParameterError = 50001,
    /*!
     加入相同房间错误，表示用户在客户端重复加入相同的房间
     */
    RongRTCCodeJoinToSameRoom = 50002,
    /*!
     不在房间中
     */
    RongRTCCodeNotInRTCRoom = 50003,
    /*!
     请检查是否开通音视频服务
     */
    RongRTCCodeEngineError = 50004,
    /*!
     HTTP 请求超时
     */
    RongRTCCodeHttpTimeoutError = 50010,
    /*!
     HTTP 响应错误（含 500，404，405 等错误）
     */
    RongRTCCodeHttpResponseError = 50011,
    /*!
     HTTP 请求错误（含网络不可达，请求未能为能正常发出）
     */
    RongRTCCodeHttpRequestError = 50012,
    /*!
     发布重复资源
     */
    RongRTCCodePublishDuplicateResources = 50020,
    /*!
     初步会话协商错误，没有消息的音视频参数
     */
    RongRTCCodeSessionDegotiateOfferError = 50021,
    /*!
     会话协商错误，协商数据不匹配或者其他问题
     */
    RongRTCCodeSessionDegotiateSetRemoteError = 50022,
    /*!
     发布的流的个数已经到达上限
     */
    RongRTCCodePublishStreamsHasReachedMaxCount = 50023,
    /*!
     取消发布不存在的资源
     */
    RongRTCCodeUnpublishUnexistStream = 50024,
    /*!
     订阅不存在的音视频资源
     */
    RongRTCCodeSubscribeNotExistResources = 50030,
    /*!
     资源重复订阅
     */
    RongRTCCodeSubscribeDuplicateResources = 50031,
    /*!
     取消订阅不存在的音视频资源
     */
    RongRTCCodeUnsubscribeNotExistResouce = 50032,
    /*!
     SDK 内部业务逻辑错误码
     */
    RongRTCCodeSDKInternalError = 50071
};

#endif /* RongRTCError_h */
