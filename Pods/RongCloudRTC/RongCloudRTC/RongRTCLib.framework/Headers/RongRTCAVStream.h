//
//  RongRTCAVStream.h
//  RongRTCLib
//
//  Created by 孙承秀 on 2020/5/18.
//  Copyright © 2020 RongCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RongRTCAVStream : NSObject
/*!
 流ID，或者媒体ID
 */
@property (nonatomic, copy, readonly) NSString *streamId;

/*!
 发布人
 */
@property (nonatomic, copy, readonly) NSString *userId;

/*!
 唯一流扩展标识符
 */
@property (nonatomic, copy, readonly) NSString *tag;

@end

NS_ASSUME_NONNULL_END
