//
//  kqyFootView.m
//  百思不得姐g1
//
//  Created by kqy on 8/10/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyFootView.h"
#import "AFNetworking.h"
@implementation kqyFootView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        NSMutableDictionary *params = [NSMutableDictionary dictionary];
        params[@"a"] = @"square";
        params[@"c"] = @"topic";   
        [[AFHTTPSessionManager manager] GET:@"http://api.budejie.com/api/api_open.php" parameters:params  progress:^(NSProgress * _Nonnull downloadProgress) {
            
        } success :^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            
            
        }];
        
        
    }
    return self;
}
@end
