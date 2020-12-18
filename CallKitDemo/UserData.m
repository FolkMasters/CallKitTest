//
//  UserData.m
//  CallLibTest
//
//  Created by Zafer.Lee on 2020/12/14.
//

#import "UserData.h"

@interface UserData ()
@property (nonatomic,strong) NSMutableArray *userIds;
@property (nonatomic,strong) NSMutableDictionary *dataDic;
@end

@implementation UserData

- (NSMutableDictionary *)dataDic {
    if (!_dataDic) {
        _dataDic = [NSMutableDictionary new];
        [_dataDic addEntriesFromDictionary:self.dataMap];
    }
    return _dataDic;
}

-(NSString *)loginUid {
    if (!_loginUid) {
        _loginUid = @"";
    }
    return _loginUid;
}

-(NSDictionary*)getLoginData {
    if (![self.loginUid isEqualToString:@""]) {
        return nil;
    }
    return [NSDictionary dictionaryWithDictionary:self.dataDic];
}

-(NSDictionary*)getConnectData {
    if ([self.loginUid isEqualToString:@""]) {
        return nil;
    }
    
    [self.dataDic removeObjectForKey:self.loginUid];    
    return [NSDictionary dictionaryWithDictionary:self.dataDic];
}

-(NSDictionary *)dataMap {
    return @{@"10001":@"LasbGC4jLW94lD2PA0rEWYa9SsbEb6gR/erDkZ3DP70=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10002":@"jwJLixyuK+t4lD2PA0rEWYa9SsbEb6gR9BcMHaaZlRg=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10003":@"uRqolSe7r5Z4lD2PA0rEWQh6x/4SvlP5F+s3r1yLM0Q=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10004":@"j+GFrzpL7Ix4lD2PA0rEWQh6x/4SvlP5UIw41SuAYn0=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com",
             @"10005":@"PqMZS9e7TWh4lD2PA0rEWe4P+Nl3ImJciOC27Gj5fMQ=@rf59.cn.rongnav.com;rf59.cn.rongcfg.com"
    };
}

@end
