//
//  microBlogModel.m
//  211-2 autolayoutMicroBlog-2 myself-1
//
//  Created by kqy on 8/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "microBlogModel.h"

@implementation microBlogModel
- (instancetype)initWithDict:(NSDictionary *)dict {
    if (self = [super init]) {
        self.name = dict[@"name"];
        self.icon = dict[@"icon"];
        self.text = dict[@"text"];
        self.picture = dict[@"picture"];
        self.vip = dict[@"vip"];
    }
    return self;
}
+ (instancetype) microBlogWithDict:(NSDictionary *)dict {
    return [[self alloc] initWithDict:dict];
}
@end
