//
//  UIBarButtonItem+kqyExtension.m
//  百思不得姐g1
//
//  Created by kqy on 7/26/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "UIBarButtonItem+kqyExtension.h"

@implementation UIBarButtonItem (kqyExtension)

+ (UIBarButtonItem *) setItemImage:(NSString *)image andHighlightImage:(NSString *) highLightImage andTarget:(id)target andAction:(SEL)action {
    UIButton *itemBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [itemBtn setImage:[UIImage imageNamed:image] forState:UIControlStateNormal];
    [itemBtn setImage:[UIImage imageNamed:highLightImage] forState:UIControlStateHighlighted];
    itemBtn.kqy_size = [itemBtn imageForState:UIControlStateNormal].size;
    [itemBtn addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *barItem = [[self alloc] initWithCustomView:itemBtn];
    return barItem;
}
@end
