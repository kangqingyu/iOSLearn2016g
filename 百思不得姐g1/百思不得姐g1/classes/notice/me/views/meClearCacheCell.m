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
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            
//            unsigned long long size = @"/Users/kqy/Desktop/kedouxueche".fileSize;
            [NSThread sleepForTimeInterval:2];

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
                
                self.textLabel.text = cacheNumber;
                self.accessoryView = nil;
                self.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
                [self addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(cellClick)]];
                self.userInteractionEnabled = YES;
                //        [self reloadInputViews];
                //        [self layoutIfNeeded];
                
            });
        });
        
    }
    return self;
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
@end
