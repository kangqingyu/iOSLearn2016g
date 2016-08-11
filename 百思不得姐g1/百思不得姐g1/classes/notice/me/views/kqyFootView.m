//
//  kqyFootView.m
//  百思不得姐g1
//
//  Created by kqy on 8/10/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyFootView.h"
#import "AFNetworking.h"
#import "MJExtension.h"
#import "meSquareModel.h"
@implementation kqyFootView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        NSMutableDictionary *params = [NSMutableDictionary dictionary];
        params[@"a"] = @"square";
        params[@"c"] = @"topic";
        
        AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
//        manager.securityPolicy.validatesDomainName = NO;// 这个可以忽略HTTP7的安全。
        
        [manager GET:@"http://api.budejie.com/api/api_open.php" parameters:params success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            
        NSArray *squares = [meSquareModel mj_objectArrayWithKeyValuesArray:responseObject[@"square_list"]];
            [self createSquares:squares];
//            kqyLog(@"success: %@   %@",[responseObject class], responseObject);
//            [responseObject writeToFile:@"/Users/kqy/Desktop/baisi081001.plist" atomically:YES ];
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            kqyLog(@"fail: %@", error);
        }];
        
//        [manager GET:@"http://api.budejie.com/api/api_open.php" parameters:params  progress:^(NSProgress * _Nonnull downloadProgress) {
//            
//        } success :^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
//            
//        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
//            
//            
//        }];
        
        
    }
    return self;
}
- (void)createSquares:(NSArray *)squares {
    NSInteger totalNumber = squares.count;
    NSInteger columns = 4 ;
    CGFloat margin = 15;
    CGFloat btnWidth = self.frame.size.width / columns;
    for (int i = 0; i < totalNumber; ++i) {
        int colIdx = i % columns;
        int rowIdx = i / columns;
        meSquareModel *squarMod = squares[i];
        
        UIButton *button = [[UIButton alloc] init];
        CGFloat btnX = colIdx * btnWidth;
        CGFloat btnY = rowIdx * btnWidth;
        button.frame = CGRectMake(btnX, btnY, btnWidth, btnWidth);
        button.backgroundColor = kqyRandomColor;
        [self addSubview:button];
    }

}
@end
