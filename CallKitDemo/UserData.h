//
//  UserData.h
//  CallLibTest
//
//  Created by Zafer.Lee on 2020/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UserData : NSObject
@property (nonatomic, copy)NSString *loginUid;
-(NSDictionary*)getLoginData;
-(NSDictionary*)getConnectData;
@end

NS_ASSUME_NONNULL_END
