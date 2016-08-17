//
//  settingVc.m
//  百思不得姐g1
//
//  Created by kqy on 7/26/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "settingVc.h"
#import "SDImageCache.h"
#import "meClearCacheCell.h"
#import "meSettingOtherCell.h"
#import "meOtherCell.h"
@implementation settingVc

static NSString *const meClearCacheCellId = @"meClearCacheCell";
static NSString *const meSettingOtherCellId = @"meOtherCell";
static NSString *const meOtherCellIden = @"otherCell";
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    [self getCacheSize];
//    unsigned long long fileSize = [NSString fileSizeForFilePath:@"/Users/kqy/Desktop/mindNumber"];
//    NSLog(@"file desktop: %zd", fileSize);
//    kqyLog(@"%zd",@"/Users/kqy/Desktop/mindNumber".fileSize);
    
    [self.tableView registerClass:[meClearCacheCell class] forCellReuseIdentifier:meClearCacheCellId];
    [self.tableView registerClass:[meSettingOtherCell class] forCellReuseIdentifier:meSettingOtherCellId];
    [self.tableView registerNib:[UINib nibWithNibName:NSStringFromClass([meOtherCell class]) bundle:nil] forCellReuseIdentifier:meOtherCellIden];

    
}
- (instancetype)init {
    return [self initWithStyle:UITableViewStyleGrouped];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 2;
}
- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 15;
//    if (section == 0) {
//        return 9    ;
//    } else {
//        return 5;
//    }
}
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0) {
        if (indexPath.row == 0  ) {
        return [tableView dequeueReusableCellWithIdentifier:meClearCacheCellId];
        } else {
            meSettingOtherCell *otherCell = [tableView dequeueReusableCellWithIdentifier:meSettingOtherCellId];
            if (indexPath.row == 1) {
                otherCell.textLabel.text = @"222";
            } else if (indexPath.row == 2) {
                otherCell.textLabel.text = @"333";
            } else if (indexPath.row == 3) {
                otherCell.textLabel.text = @"4444444";
            } else {
                otherCell.textLabel.text = @"oooo";
            }
            return otherCell;
        }
        int x = 5;
    } else  {
        return [tableView dequeueReusableCellWithIdentifier:meOtherCellIden];
    }
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    kqyLogFunc;
    if (indexPath == 0) {
        NSLog(@"click 0 0");
    }
}

- (void)getCacheSize {
    unsigned long long size = 0;
    NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
    NSString *dirpath = [cachesPath stringByAppendingPathComponent:@"MP3"];
    
    NSFileManager *filMgr = [NSFileManager defaultManager];
    
    NSDirectoryEnumerator *enumerator = [filMgr enumeratorAtPath:dirpath];
    for (NSString *subpath in enumerator) {
        NSString *fullSubpath = [dirpath stringByAppendingPathComponent:subpath];
        size += [filMgr attributesOfItemAtPath:fullSubpath error:nil].fileSize;
    }
}
- (void)getCacheSize2 {

    NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
    NSString *dirPath = [cachesPath stringByAppendingPathComponent:@"MP3"];
    NSLog(@"dirPath:%@",dirPath);
    //file manager
    NSFileManager *fileMng =  [NSFileManager defaultManager];
    // attribute属性
    NSDictionary *attrs = [fileMng attributesOfItemAtPath:dirPath error:nil];
    kqyLog(@"%@", attrs);
    //得到一层文件夹的大小，得到所有的
    kqyLog(@"content: %@", [fileMng contentsOfDirectoryAtPath:dirPath error:nil]);
    kqyLog(@"subpaths:%@", [fileMng subpathsAtPath:dirPath]);
    NSUInteger size = 0;
    NSArray *subpaths = [fileMng subpathsAtPath:dirPath];
    for (NSString *subpath in subpaths) {
        NSString *fullSubPath = [dirPath stringByAppendingPathComponent:subpath];
        //文件的FileSize属性
        NSDictionary *attrs = [fileMng attributesOfItemAtPath:fullSubPath error:nil];
        size += [attrs[NSFileSize] unsignedIntegerValue];
    }
    kqyLog(@"file size : %zd", size / 1000.0);
    // story
    
    // 
}
@end
