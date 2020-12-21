//
//  ViewController.m
//  CallKitDemo
//
//  Created by zafer on 2020/11/27.
//  Copyright © 2020 zafer. All rights reserved.
//

#import "ViewController.h"
#import <RongIMLib/RongIMLib.h>
#import <RongCallKit/RongCallKit.h>
#import <RongIMKit/RongIMKit.h>
@interface ViewController ()<RCIMUserInfoDataSource>
@property (strong, nonatomic) IBOutlet UITextField *idInputView;
@property (strong, nonatomic) IBOutlet UIButton *connectBtn;
@property (strong, nonatomic) IBOutlet UILabel *statusLabel;
@property (strong, nonatomic) IBOutlet UITextField *callInfoId;
@property (strong, nonatomic) IBOutlet UISwitch *typeSwitch;
@property (strong, nonatomic) IBOutlet UILabel *typeLabel;

@property (nonatomic,strong) NSDictionary *dataMap;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    [RCIM sharedRCIM].userInfoDataSource = self;
    [RCIM sharedRCIM].enablePersistentUserInfoCache = YES;
    [self connectAction:nil];
    
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
//
- (IBAction)groupCallAction:(id)sender {
    RCCallMediaType type = self.typeSwitch.on ? RCCallMediaAudio : RCCallMediaVideo;
    [[RCCall sharedRCCall] startMultiCallViewController:ConversationType_GROUP targetId:@"101" mediaType:type userIdList:@[@"10001",@"10005"]];
}
//
- (IBAction)groupOptionalAction:(id)sender {
    
    RCCallMediaType type = self.typeSwitch.on ? RCCallMediaAudio : RCCallMediaVideo;
    [[RCCall sharedRCCall] startMultiCall:type targetId:@"101" mediaType:RCCallMediaAudio];
}
//
- (IBAction)typeSwitchAction:(UISwitch*)sender {
    self.typeLabel.text = sender.on ? @"语音" : @"视频";
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

/*
- (NSString *)getDeviceToken:(NSString *)uid {
    // 1.创建一个网络路径
    NSURL *url = [NSURL URLWithString:@"https://developer.rongcloud.cn/apitrial/apiProcess"];
    // 2.创建一个网络请求，分别设置请求方法、请求参数
    NSMutableURLRequest *request =[NSMutableURLRequest requestWithURL:url];
    request.HTTPMethod = @"POST";
    NSString *args = [NSString stringWithFormat:@"userId=%@&name=&portraitUri=&id=DqgQ-DZFyjMvDhJgTxbImg&apiId=0slhRzAYp1TUAZx1RFgaWA&format=1&environment=1",uid];
    request.HTTPBody = [args dataUsingEncoding:NSUTF8StringEncoding];
    // 3.获得会话对象
    NSURLSession *session = [NSURLSession sharedSession];
    // 4.根据会话对象，创建一个Task任务
    NSURLSessionDataTask *sessionDataTask = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
    NSLog(@"从服务器获取到数据");
        
        NSHTTPURLResponse *HTTPURLResponse = (id)response.classForCoder;
        NSDictionary *allHeaderFields = HTTPURLResponse.allHeaderFields;
        

    
    //对从服务器获取到的数据data进行相应的处理.
    
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:data options:(NSJSONReadingMutableLeaves) error:nil];
        
        NSLog(@"%@",dict);
    }];
    //5.最后一步，执行任务，(resume也是继续执行)。
    [sessionDataTask resume];
    
    return nil;
}*/

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
