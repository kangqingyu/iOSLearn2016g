//
//  UIView+kqyExtension.m
//  百思不得姐g1
//
//  Created by kqy on 7/23/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "UIView+kqyExtension.h"

@implementation UIView (kqyExtension)
- (CGFloat *)kqy_width {
    return self.frame.size.width;
}
- (CGFloat *)kqy_height {
    return self.frame.size.height;
}

- (void)setKqy_width:(CGFloat *)kqy_width {
    self.kqy_width = kqy_width;
}

- (void)setKqy_height:(CGFloat *)kqy_height {
    self.kqy_height = kqy_height;
}

@end
