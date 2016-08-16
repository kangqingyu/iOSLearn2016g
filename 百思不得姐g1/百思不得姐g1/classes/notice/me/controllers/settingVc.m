//
//  settingVc.m
//  百思不得姐g1
//
//  Created by kqy on 7/26/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "settingVc.h"
#import "SDImageCache.h"
@implementation settingVc
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    [self getCacheSize];
    unsigned long long fileSize = [NSString fileSizeForFilePath:@"/Users/kqy/Desktop/mindNumber"];
    NSLog(@"file desktop: %zd", fileSize);
    kqyLog(@"%zd",@"/Users/kqy/Desktop/mindNumber".fileSize);

}
- (instancetype)init {
    return [self initWithStyle:UITableViewStyleGrouped];
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *identifier = @"identIdCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
        
    }
    cell.textLabel.text = @"clear cache";
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath == 0) {
        NSLog(@"click 0 0");
      
    }
    NSInteger imgSize = [SDImageCache sharedImageCache].getSize;
    
    NSLog(@"imgSize: %zd", imgSize);
 
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
