//
//  essenTopModel.h
//  百思不得姐g1
//
//  Created by kqy on 8/18/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface essenTopModel : NSObject
@property (nonatomic, copy) NSString *ID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *profile_image;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *created_at;
@property (nonatomic, assign) NSInteger ding;
@property (nonatomic, assign) NSInteger cai;
@property (nonatomic, assign) NSInteger repost;
@property (nonatomic, assign) NSInteger comment;


@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

@end
