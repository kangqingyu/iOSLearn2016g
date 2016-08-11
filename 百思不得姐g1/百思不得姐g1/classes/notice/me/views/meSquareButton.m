//
//  meSquareButton.m
//  百思不得姐g1
//
//  Created by kqy on 8/11/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "meSquareButton.h"

@implementation meSquareButton

- (void)layoutSubviews {
    [super layoutSubviews];
    self.imageView.kqy_y = self.kqy_height * 0.2;
    self.imageView.kqy_width = self.kqy_width * 0.5;
    self.imageView.kqy_height = self.imageView.kqy_width;
    self.imageView.kqy_centerX = self.kqy_width * 0.5;
    
//    self.titleLabel.kqy_centerX = self.kqy_centerX;
    self.titleLabel.kqy_x = 0;
    self.titleLabel.kqy_y = self.kqy_height * 0.75;
    self.titleLabel.kqy_width = self.kqy_width;
    self.titleLabel.kqy_height = self.kqy_height - self.imageView.kqy_bottom;
    
}
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        
    [self setBackgroundImage:[UIImage imageNamed:@"mainCellBackground"] forState:UIControlStateNormal];
    [self setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    self.titleLabel.textAlignment = NSTextAlignmentCenter;
        
    }
    return self;
}

//- (void)layoutSubviews {
//    [super layoutSubviews];
//    self.imageView.kqy_y = 0;
//    self.imageView.kqy_centerX = self.kqy_width * 0.5;
//    
//    self.titleLabel.kqy_y = self.imageView.kqy_bottom;
//    //    self.titleLabel.kqy_centerX = self.kqy_width * 0.5;
//    self.titleLabel.kqy_x = 0;
//    self.titleLabel.kqy_width = self.kqy_width;
//    
//}

@end
