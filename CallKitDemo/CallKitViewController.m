//
//  ViewController.m
//  CallKitDemo
//
//  Created by zafer on 2020/11/27.
//  Copyright © 2020 zafer. All rights reserved.
//

#import "CallKitViewController.h"
#import <RongIMLib/RongIMLib.h>
#import <RongCallKit/RongCallKit.h>
#import <RongIMKit/RongIMKit.h>
#import <RongRTCLib/RongRTCLib.h>
@interface CallKitViewController ()<RCIMUserInfoDataSource>
@property (strong, nonatomic) IBOutlet UITextField *idInputView;
@property (strong, nonatomic) IBOutlet UIButton *connectBtn;
@property (strong, nonatomic) IBOutlet UILabel *statusLabel;
@property (strong, nonatomic) IBOutlet UITextField *callInfoId;

@property (nonatomic,strong) NSDictionary *dataMap;
@end

@implementation CallKitViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
//    [RCIM sharedRCIM].userInfoDataSource = self;
//    [RCIM sharedRCIM].enablePersistentUserInfoCache = YES;
//    [self connectAction:nil];
    
//    [RCRTCEngine sharedInstance].curActiveRoom.delegate = self;
    
}


- (IBAction)connectAction:(id)sender {
    NSString *key = self.idInputView.text ?: @"10001";
    NSString *token = self.dataMap[key];
    
    [[RCIMClient sharedRCIMClient] connectWithToken:token dbOpened:^(RCDBErrorCode code) {
            
        } success:^(NSString *userId) {
            [self updateUI:[NSString stringWithFormat:@"success userId = %@",userId]];
        } error:^(RCConnectErrorCode errorCode) {
            [self updateUI:[NSString stringWithFormat:@"status code= %ld",(long)errorCode]];
        }];
}

- (IBAction)audioConnect:(id)sender {
    NSString *callId = self.callInfoId.text;
    [[RCCall sharedRCCall] startSingleCall:callId mediaType:RCCallMediaAudio];
}

- (IBAction)videoConnect:(id)sender {
    NSString *callId = self.callInfoId.text;
    [[RCCall sharedRCCall] startSingleCall:callId mediaType:RCCallMediaVideo];
}

- (IBAction)logoutAction:(id)sender {
    [[RCIMClient sharedRCIMClient]logout];
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.idInputView endEditing:YES];
    [self.callInfoId endEditing:YES];
}

#pragma mark- RCIMUserInfoDataSource
- (void)getUserInfoWithUserId:(NSString *)userId completion:(void (^)(RCUserInfo *userInfo))completion {
    
}

#pragma mark- private
- (void)updateUI:(NSString *)msg {
    dispatch_async(dispatch_get_main_queue(), ^{
        self.statusLabel.text = msg;
    });
}

#pragma mark- getter
-(NSDictionary *)dataMap {
    return @{@"10001":@"LasbGC4jLW94lD2PA0rEWYa9SsbEb6gR/erDkZ3DP70=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10002":@"jwJLixyuK+t4lD2PA0rEWYa9SsbEb6gR9BcMHaaZlRg=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10003":@"uRqolSe7r5Z4lD2PA0rEWQh6x/4SvlP5F+s3r1yLM0Q=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10004":@"j+GFrzpL7Ix4lD2PA0rEWQh6x/4SvlP5UIw41SuAYn0=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10005":@"PqMZS9e7TWh4lD2PA0rEWe4P+Nl3ImJciOC27Gj5fMQ=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com"
    };
}

@end
