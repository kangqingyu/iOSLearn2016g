//
//  NSString+kqyExtension.m
//  百思不得姐g1
//
//  Created by kqy on 8/16/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "NSString+kqyExtension.h"

@implementation NSString (kqyExtension)
+ (unsigned long long)fileSizeForFilePath:(NSString *)filePath {
    unsigned long long size = 0;
    NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
    NSString *dirpath = [cachesPath stringByAppendingPathComponent:filePath];
    
    NSFileManager *filMgr = [NSFileManager defaultManager];
    
    NSDirectoryEnumerator *enumerator = [filMgr enumeratorAtPath:dirpath];
    for (NSString *subpath in enumerator) {
        NSString *fullSubpath = [dirpath stringByAppendingPathComponent:subpath];
        size += [filMgr attributesOfItemAtPath:fullSubpath error:nil].fileSize;
    }
    return size/1000.0;
}
- (unsigned long long)fileSize {
    unsigned long long size = 0;
    
    NSFileManager *filMgr = [NSFileManager defaultManager];
    BOOL isDirectory = NO;
    BOOL exists = [filMgr fileExistsAtPath:self isDirectory:&isDirectory];
    if (!exists) {
        return 0;
    }
//    if ([attrs.fileType isEqualToString:NSFileTypeDirectory]) {
    if (isDirectory) {
        NSDirectoryEnumerator *enumerator = [filMgr enumeratorAtPath:self];
        for (NSString *subpath in enumerator) {
            NSString *fullSubpath = [self  stringByAppendingPathComponent:subpath];
            size += [filMgr attributesOfItemAtPath:fullSubpath error:nil].fileSize;
        }
    } else {
        NSDictionary *attrs = [filMgr attributesOfItemAtPath:self error:nil];
        size = attrs.fileSize;
    }
    
    return size/1000.0;
}


- (unsigned long long)fileSize1 {
    unsigned long long size = 0;
    
    NSFileManager *filMgr = [NSFileManager defaultManager];
    NSDictionary *attrs = [filMgr attributesOfItemAtPath:self error:nil];
    if ([attrs.fileType isEqualToString:NSFileTypeDirectory]) {
    NSDirectoryEnumerator *enumerator = [filMgr enumeratorAtPath:self];
    for (NSString *subpath in enumerator) {
        NSString *fullSubpath = [self  stringByAppendingPathComponent:subpath];
        size += [filMgr attributesOfItemAtPath:fullSubpath error:nil].fileSize;
    }     
    } else {
        size = attrs.fileSize;
    }
   
    return size/1000.0;
}
@end
