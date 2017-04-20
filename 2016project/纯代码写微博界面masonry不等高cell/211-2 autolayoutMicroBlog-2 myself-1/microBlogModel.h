//
//  microBlogModel.h
//  211-2 autolayoutMicroBlog-2 myself-1
//
//  Created by kqy on 8/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface microBlogModel : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *picture;
@property (nonatomic, assign, getter=isVip) NSInteger vip;
- (instancetype) initWithDict:(NSDictionary *)dict;
+ (instancetype) microBlogWithDict:(NSDictionary *)dict;
@end
