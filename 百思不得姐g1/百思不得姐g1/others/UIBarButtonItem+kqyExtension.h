//
//  UIBarButtonItem+kqyExtension.h
//  百思不得姐g1
//
//  Created by kqy on 7/26/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (kqyExtension)

+ (instancetype ) setItemImage:(NSString *)image andHighlightImage:(NSString *) highLightImage andTarget:(id)target andAction:(SEL)action ;
@end
