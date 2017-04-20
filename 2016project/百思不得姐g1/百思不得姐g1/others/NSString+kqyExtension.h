//
//  NSString+kqyExtension.h
//  百思不得姐g1
//
//  Created by kqy on 8/16/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (kqyExtension)
+ (unsigned long long)fileSizeForFilePath:(NSString *)filePath;
- (unsigned long long)fileSize;
@end
