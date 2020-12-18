//
//  UIViewController+Navigation.h
//  CallLibTest
//
//  Created by Zafer.Lee on 2020/12/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ClickHandle)(void);

typedef void(^CompleteHandle)(NSString *uid, NSString *uToken);

typedef NS_ENUM(NSUInteger, ListType) {
    ListTypeLogin = 1,
    ListTypeCall
};

@interface UIViewController (Navigation)
- (void)showToast:(NSString *)text;
- (void)addLeftItemWithName:(NSString *)itemName handle:(ClickHandle)handle;
- (void)addRightItemWithName:(NSString *)itemName handle:(ClickHandle)handle;

- (void)showUserList:(NSDictionary *)data type:(ListType)type complete:(CompleteHandle)complete;
@end

NS_ASSUME_NONNULL_END
