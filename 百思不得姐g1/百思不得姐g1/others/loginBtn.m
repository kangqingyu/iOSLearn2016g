//
//  loginBtn.m
//  百思不得姐g1
//
//  Created by kqy on 7/28/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "loginBtn.h"

@implementation loginBtn

- (void)awakeFromNib {
    self.backgroundColor = [UIColor grayColor];
    self.imageView.backgroundColor = [UIColor redColor];
    self.titleLabel.backgroundColor = [UIColor greenColor];
    self.titleLabel.textAlignment = NSTextAlignmentCenter;

}
- (void)layoutSubviews {
    [super layoutSubviews];
    self.imageView.kqy_y = 0;
    self.imageView.kqy_centerX = self.kqy_width * 0.5;
    
    self.titleLabel.kqy_y = self.imageView.kqy_bottom;
//    self.titleLabel.kqy_centerX = self.kqy_width * 0.5;
    self.titleLabel.kqy_x = 0;
    self.titleLabel.kqy_width = self.kqy_width;
    
}
@end
