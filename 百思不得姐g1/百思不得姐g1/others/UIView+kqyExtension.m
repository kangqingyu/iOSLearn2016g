//
//  UIView+kqyExtension.m
//  百思不得姐g1
//
//  Created by kqy on 7/23/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "UIView+kqyExtension.h"

@implementation UIView (kqyExtension)
- (CGFloat )kqy_width {
    return self.frame.size.width;
}
- (CGFloat )kqy_height {
    return self.frame.size.height;
}
- (void)setKqy_width:(CGFloat )kqy_width {
//    self.kqy_width = kqy_width;
    CGRect frame = self.frame;
    frame.size.width = kqy_width;
    self.frame = frame;
}

- (void)setKqy_height:(CGFloat )kqy_height {
//    self.kqy_height = kqy_height;
    CGRect tempFrame = self.frame;
    tempFrame.size.height = kqy_height;
    self.frame = tempFrame;
}

- (CGFloat)kqy_x {
    return self.frame.origin.x;
}
- (CGFloat)kqy_y {
    return self.frame.origin.y;
}
- (void)setKqy_x:(CGFloat)kqy_x {
    CGRect tempFrame = self.frame;
    tempFrame.origin.x = kqy_x;
    self.frame = tempFrame;
}
- (void)setKqy_y:(CGFloat)kqy_y {
    CGRect tempFrame = self.frame;
    tempFrame.origin.y = kqy_y;
    self.frame = tempFrame;
}
- (CGFloat)kqy_centerX {
    return self.center.x;
}
- (CGFloat)kqy_centerY {
    return self.center.y;
}
- (void)setKqy_centerX:(CGFloat)kqy_centerX {
    CGPoint tempCenter = self.center;
    tempCenter.x = kqy_centerX;
    self.center = tempCenter;
}
- (void)setKqy_centerY:(CGFloat)kqy_centerY {
    CGPoint tempCenter = self.center;
    tempCenter.y = kqy_centerY;
    self.center = tempCenter;
}
- (CGFloat)kqy_right {
    return CGRectGetMaxX(self.frame);
}
- (CGFloat)kqy_bottom {
    return CGRectGetMaxY(self.frame);
}
- (void)setKqy_right:(CGFloat)kqy_right {
    //ymc设右边，其实要设x。
    self.kqy_x = kqy_right - self.kqy_width;
}
- (void)setKqy_bottom:(CGFloat)kqy_bottom {
    self.kqy_y = kqy_bottom - self.kqy_height;
}


@end
