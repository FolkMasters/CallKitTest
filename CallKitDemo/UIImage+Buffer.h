//
//  UIImage+Buffer.h
//  CallKitDemo
//
//  Created by Zafer.Lee on 2021/1/19.
//  Copyright © 2021 zafer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Buffer)
+ (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)sampleBuffer;
+ (UIImage*)uiImageFromPixelBuffer:(CVPixelBufferRef)p;
@end

NS_ASSUME_NONNULL_END
