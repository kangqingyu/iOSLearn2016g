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
#import "kqyTabBar.h"
@interface kqyTabBarViewController ()


@end

@implementation kqyTabBarViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupChildVc];
}
- (void) setupChildVc {
    
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy1essentialViewController alloc] init ]] andTitle:@"111" andImage:@"tabBar_essence_icon" andSelectedImg:@"tabBar_essence_click_icon"];
    
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy2newViewController alloc] init]] andTitle:@"22" andImage:@"tabBar_new_icon" andSelectedImg:@"tabBar_new_click_icon"];
//    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[UIViewController alloc] init]] andTitle:@"" andImage:@"" andSelectedImg:@""];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy3noticeTableViewController alloc] init] ] andTitle:@"3" andImage:@"tabBar_friendTrends_icon" andSelectedImg:@"tabBar_friendTrends_click_icon"];
    [self setOneChildVC:[[kqyNavViewController alloc] initWithRootViewController:[[kqy4meViewController alloc] init]] andTitle:@"4" andImage:@"tabBar_me_icon" andSelectedImg:@"tabBar_me_click_icon"];
    
//change tabbar
    [self setValue:[[kqyTabBar alloc] init] forKey:@"tabBar"];
}

- (void)setOneChildVC:(UIViewController *) vc andTitle:(NSString *)title andImage:(NSString *)image andSelectedImg:(NSString *)selectedImg {
    
    vc.tabBarItem.title = title;
    // if image
    if (image.length > 0) {
    vc.tabBarItem.image = [UIImage imageNamed:image];
    vc.tabBarItem.selectedImage = [UIImage imageNamed:selectedImg];
    }
    [self addChildViewController:vc];
    
}
- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}
//
@end
