//
//  meSquareModel.h
//  百思不得姐g1
//
//  Created by kqy on 8/10/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface meSquareModel : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *icon;
- (instancetype) initWithDict :(NSDictionary *)dict;
+ (instancetype) meSquareWithDict:(NSDictionary *)dict;

@end
