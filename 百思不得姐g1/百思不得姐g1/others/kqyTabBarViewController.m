//
//  kqyTabBarViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyTabBarViewController.h"
#import "kqyNavViewController.h"
#import "kqy1essentialViewController.h"
#import "kqy2newViewController.h"
#import "kqy3noticeTableViewController.h"
#import "kqy4meViewController.h"

@interface kqyTabBarViewController ()

@end

@implementation kqyTabBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupChildVc];
}
- (void) setupChildVc {
//    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[kqy1essentialViewController alloc] init] andTitle:@"1ess" andImage:@"" andSelectedImg:@""];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy1essentialViewController alloc] init ]] andTitle:@"111" andImage:@"" andSelectedImg:@""];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy2newViewController alloc] init]] andTitle:@"22" andImage:@"" andSelectedImg:@""];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[UIViewController alloc] init]] andTitle:@"" andImage:@"" andSelectedImg:@""];
    
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy3noticeTableViewController alloc] init] ] andTitle:@"3" andImage:@"" andSelectedImg:@""];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy4meViewController alloc] init]] andTitle:@"4" andImage:@"" andSelectedImg:@""];
    
}
- (void) publishButtonClick {
    kqyLog(@"publish>..click");
}
- (void)setOneChildVC:(UIViewController *) vc andTitle:(NSString *)title andImage:(NSString *)image andSelectedImg:(NSString *)selectedImg {
    vc.view.backgroundColor = kqyRandomColor;
    vc.tabBarItem.title = title;
    vc.tabBarItem.image = [UIImage imageNamed:image];
    vc.tabBarItem.selectedImage = [UIImage imageNamed:selectedImg];
    [self addChildViewController:vc];
    
}
- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:YES];
    
    UIButton *publishButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [publishButton setImage:[UIImage imageNamed:@"tabBar_publish_icon"] forState:UIControlStateNormal];
    [publishButton setImage:[UIImage imageNamed:@"tabBar_publish_click_icon"] forState:UIControlStateSelected];
    //这样加按钮，并不是在正中间。 ??????
    publishButton.center = CGPointMake(self.tabBar.frame.size.width * 0.5, self.tabBar.frame.size.height * 0.5);
    publishButton.frame = CGRectMake(0,0,self.tabBar.frame.size.width * 0.2, self.tabBar.frame.size.height);
    [publishButton addTarget:self action:@selector(publishButtonClick) forControlEvents:UIControlEventTouchUpInside];
//    [publishButton sizeToFit];
    [self.tabBar addSubview:publishButton ];
}

@end
