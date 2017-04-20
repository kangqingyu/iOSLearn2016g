//
//  kqyTabBar.m
//  百思不得姐g1
//
//  Created by kqy on 7/22/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyTabBar.h"
#import "kqy1essentialViewController.h"

@interface kqyTabBar ()
@property (nonatomic, weak) UIButton *publishBtn;
@end
@implementation kqyTabBar

- (void)layoutSubviews {
    [super layoutSubviews];
    int i = 0;
    
    CGFloat tabbarWidth = self.frame.size.width * 0.2;
    CGFloat tabbarHeight = self.frame.size.height ;
    
    for (UIView *subView in self.subviews) {
        if (subView.class != NSClassFromString(@"UITabBarButton")) {
            continue;
        }
        if (![@"UITabBarButton" isEqualToString:NSStringFromClass(subView.class)]) {
            continue;
        }
        
        subView.frame  = CGRectMake(i * tabbarWidth, 0, tabbarWidth, tabbarHeight);
        if (i == 1) {
            ++ i;
        }
        ++i;
   }
    
        self.publishBtn.frame = CGRectMake(0,0,self.frame.size.width * 0.2, self.frame.size.height);
        _publishBtn.center = CGPointMake(self.frame.size.width * 0.5, self.frame.size.height * 0.5);
    
}

- (UIButton *)publishBtn {
    if (_publishBtn == nil) {
        UIButton *publishBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
//        publishBtn.backgroundColor = kqyRandomColor;
        UIImage *image = [UIImage imageNamed:@"tabBar_publish_icon"];
        UIImage *originImage = [image imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
        UIImage *selectedImage = [UIImage imageNamed:@"tabBar_publish_click_icon"];
        UIImage *originSelectedImage = [selectedImage imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
        [publishBtn setImage:originImage forState:UIControlStateNormal];
        [publishBtn setImage:originSelectedImage forState:UIControlStateSelected];
        [publishBtn addTarget:self action:@selector(publishButtonClick) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:publishBtn   ];
        _publishBtn = publishBtn;
    }
//    if (_publishBtn == nil) {
//        _publishBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
//        _publishBtn.backgroundColor = kqyRandomColor;
//        [_publishBtn setImage:[UIImage imageNamed:@"tabBar_publish_icon"] forState:UIControlStateNormal];
//        [_publishBtn setImage:[UIImage imageNamed:@"tabBar_publish_click_icon"] forState:UIControlStateSelected];
//        [_publishBtn addTarget:self action:@selector(publishButtonClick) forControlEvents:UIControlEventTouchUpInside];
//        [self addSubview:_publishBtn   ];
//    }
    return _publishBtn;
}
- (void) publishButtonClick {
    kqyLog(@"publish>..click");
    kqy1essentialViewController *test1essVC = [[kqy1essentialViewController alloc] init];
//    [self presentViewController:test1essVC animated:YES completion:nil];
}
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
//        self.backgroundImage = [UIImage imageNamed:@"tabbar-light"];
        
    }
    return self;
}

@end
