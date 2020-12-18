//
//  UIViewController+Navigation.m
//  CallLibTest
//
//  Created by Zafer.Lee on 2020/12/14.
//

#import "UIViewController+Navigation.h"
#import <objc/runtime.h>

static char *rightBarButtonItemKey = "setRightBarButtonItem";
static char *leftBarButtonItemKey = "setLeftBarButtonItem";

@interface UIViewController ()
@property (nonatomic, copy)ClickHandle leftClickHandle;
@property (nonatomic, copy)ClickHandle rightClickHandle;
@end


@implementation UIViewController (Navigation)

- (void)showToast:(NSString *)text{
}
#pragma mark-
#pragma mark-user list
- (void)showUserList:(NSDictionary *)data type:(ListType)type complete:(CompleteHandle)complete {
    NSString *messageString = type == ListTypeLogin ? @"选择登陆用户" : @"选择呼叫用户";
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"" message:messageString preferredStyle:UIAlertControllerStyleActionSheet];
    
    for (NSString *uid in data.allKeys) {
        UIAlertAction *action = [UIAlertAction actionWithTitle:uid style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSString *token = data[action.title];
            if (complete) {
                complete(action.title, token);
            }
        }];
        [alertController addAction:action];
    }
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        [alertController dismissViewControllerAnimated:YES completion:nil];
    }];
    [alertController addAction:cancelAction];
    
    [self presentViewController:alertController animated:YES completion:nil];
}
#pragma mark-
#pragma mark-left
- (void)addLeftItemWithName:(NSString *)itemName handle:(ClickHandle)handle {
    UIButton *leftBtn = [[UIButton alloc] initWithFrame:CGRectMake(2, 2, 40, 40)];
    [leftBtn addTarget:self action:@selector(leftClickEvent:) forControlEvents:UIControlEventTouchUpInside];

    [leftBtn setTitle:itemName forState:UIControlStateNormal];

    [leftBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

    UIBarButtonItem *leftItem = [[UIBarButtonItem alloc] initWithCustomView:leftBtn];

    [self.navigationItem setLeftBarButtonItem:leftItem];
    self.leftClickHandle = handle;
}

- (void)leftClickEvent:(UIButton *)sender {
    if (self.leftClickHandle) {
        self.leftClickHandle();
    }
}

-(ClickHandle)leftClickHandle {
    return objc_getAssociatedObject(self, &leftBarButtonItemKey);
}

- (void)setLeftClickHandle:(ClickHandle)leftClickHandle {
    objc_setAssociatedObject(self, &leftBarButtonItemKey, leftClickHandle, OBJC_ASSOCIATION_COPY);
}

#pragma mark-
#pragma mark-right
- (void)addRightItemWithName:(NSString *)itemName handle:(ClickHandle)handle {
    UIButton *rightBtn = [[UIButton alloc] initWithFrame:CGRectMake(2, 2, 40, 40)];
    [rightBtn addTarget:self action:@selector(clickEvent:) forControlEvents:UIControlEventTouchUpInside];

    [rightBtn setTitle:itemName forState:UIControlStateNormal];

    [rightBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

    UIBarButtonItem *rightItem = [[UIBarButtonItem alloc] initWithCustomView:rightBtn];

    [self.navigationItem setRightBarButtonItem:rightItem];
    self.rightClickHandle = handle;
}

- (void)clickEvent:(UIButton *)sender {
    if (self.rightClickHandle) {
        self.rightClickHandle();
    }
}

- (ClickHandle)rightClickHandle {
    return objc_getAssociatedObject(self, &rightBarButtonItemKey);
}

-(void)setRightClickHandle:(ClickHandle)rightClickHandle {
    objc_setAssociatedObject(self, &rightBarButtonItemKey, rightClickHandle, OBJC_ASSOCIATION_COPY);
}
@end
