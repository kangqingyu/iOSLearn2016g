//
//  kqyTabBarView.m
//  网易彩票g1
//
//  Created by kqy on 9/5/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyTabBarView.h"
#import "kqyTabBarButton.h"
@interface kqyTabBarView ()
@property (nonatomic, weak) UIButton *selectedBtn;
@end
@implementation kqyTabBarView
- (void)setBarItems:(NSArray *)barItems {
    _barItems = barItems;
    int i = 100;
    for (UITabBarItem *item in barItems) {
        kqyTabBarButton *button = [kqyTabBarButton buttonWithType:UIButtonTypeCustom];
        button.tag = i;
        [button setImage:item.image forState:UIControlStateNormal];
        [button setImage:item.selectedImage forState:UIControlStateSelected];
        [button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchDown];
        ++ i;
     if (i == 100) {
        [self buttonClick:button ];
        }
        [self addSubview:button];
    }
}

- (void)buttonClick:(UIButton *)button {
    self.selectedBtn.selected = NO;
    button.selected = YES;
    _selectedBtn = button;
//
    //
    //
    if ([_delegate respondsToSelector:@selector((tabBar:didClickBtn:))]) {
        [_delegate tabBar:self didClickBtn:button.tag];
    }
}

- (void)layoutSubviews {
    [super layoutSubviews];
    int count = (int)self.barItems.count;
//    CGFloat buttonW = self.frame.size.width / count;
//    CGFloat buttonH = self.frame.size.height;
    CGFloat buttonW = self.bounds.size.width / count;
    CGFloat buttonH = self.bounds.size.height;
    CGFloat buttonX = 0;
    CGFloat buttonY = 0;
    for (int i = 0; i < count; ++i) {
        UIButton *button = self.subviews[i];
        buttonX = buttonW * i;
        button.frame = CGRectMake(buttonX, buttonY, buttonW, buttonH);
    }
}
@end
