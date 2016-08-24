//
//  meClearCacheCell.m
//  百思不得姐g1
//
//  Created by kqy on 8/16/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "meClearCacheCell.h"
#import "SDImageCache.h"
#import "SVProgressHUD.h"
@implementation meClearCacheCell
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.textLabel.text = @"clear cache（calculating...)";
        self.userInteractionEnabled = NO;
        //    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        UIActivityIndicatorView *loadingView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
        [loadingView startAnimating];
        self.accessoryView = loadingView;
        __weak typeof(self) weakSelf = self;
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            
//            unsigned long long size = @"/Users/kqy/Desktop/kedouxueche".fileSize;
            [NSThread sleepForTimeInterval:5];

            kqyLog(@"1111");
            if (!weakSelf) {
                return ;
            }
            kqyLog(@"222");
            NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
            NSString *dirpath = [cachesPath stringByAppendingPathComponent:@"MP5"];
    
            unsigned long long size = dirpath.fileSize;
            
            size += [SDImageCache sharedImageCache].getSize;
            NSString *cacheStr = nil;
            if (size > pow(10, 9)) {
                cacheStr = [NSString stringWithFormat:@"清空缓存(%.2f)Gb",size/ 1000.0 / 1000 / 1000];
            } else if (size > 1000 * 1000) {
                
                cacheStr = [NSString stringWithFormat:@"清空缓存(%.2f)Mb",size/ 1000.0 / 1000];
                
            } else if (size > 1000) {
                
                cacheStr = [NSString stringWithFormat:@"清空缓存(%.2f)Kb",size/ 1000.0];
            } else {
            cacheStr = [NSString stringWithFormat:@"清空缓存%zdb",size];
            }
            NSString *cacheNumber = [NSString stringWithFormat:@"%@",cacheStr];
            dispatch_async(dispatch_get_main_queue(), ^{
                
                weakSelf.textLabel.text = cacheNumber;
                weakSelf.accessoryView = nil;
                weakSelf.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
                [weakSelf addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:weakSelf action:@selector(cellClick)]];
                weakSelf.userInteractionEnabled = YES;
                //        [self reloadInputViews];
                //        [self layoutIfNeeded];
                
            });
        });
        
    }
    return self;
}
- (void)dealloc {
    kqyLogFunc;
}
- (void)cellClick {
    [SVProgressHUD showWithStatus:@"deleting...."];
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeBlack];
    
//    [SDImageCache sharedImageCache].clearDisk;
//    [[SDImageCache sharedImageCache] clearDiskOnCompletion:^{
//    }];
    [[SDImageCache sharedImageCache] clearDiskOnCompletion:^{
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
        NSString *dirpath = [cachesPath stringByAppendingPathComponent:@"MP5"];
        
        NSFileManager *filMng = [NSFileManager defaultManager];
        [filMng removeItemAtPath:dirpath  error:nil];
        [filMng createDirectoryAtPath:dirpath withIntermediateDirectories:YES attributes:nil error:nil];
        [NSThread sleepForTimeInterval:2];
        dispatch_async(dispatch_get_main_queue(), ^{
            [SVProgressHUD dismiss];
            self.textLabel.text = @"clear (0b)";
            }) ;
        });
     
    }];
}
- (void)layoutSubviews {
    [super layoutSubviews];
    UIActivityIndicatorView *loadingView = (UIActivityIndicatorView *)self.accessoryView;
    [loadingView startAnimating];
    kqyLogFunc;
}

@end
