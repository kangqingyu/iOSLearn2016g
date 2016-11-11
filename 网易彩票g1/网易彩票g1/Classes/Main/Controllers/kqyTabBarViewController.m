//
//  kqyTabBarViewController.m
//  网易彩票g1
//
//  Created by kqy on 9/5/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyTabBarViewController.h"
#import "kqyHallViewController.h"
#import "kqyArenaViewController.h"
#import "kqyDiscoveryViewController.h"
#import "kqyHistoryViewController.h"
#import "kqyMyLotteryViewController.h"
#import "kqyNavViewController.h"
#import "kqyTabBarView.h"
@interface kqyTabBarViewController ()
@property (nonatomic, strong) NSMutableArray *items;

@end

@implementation kqyTabBarViewController
- (NSMutableArray *)items {
    if (!_items) {
        _items = [NSMutableArray array];
    }
    return _items;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupChildVC];
    [self setupTabBar];
}
- (void)setupTabBar {
    [self.tabBar removeFromSuperview];
    kqyTabBarView *tabBarView = [[kqyTabBarView alloc] initWithFrame:self.tabBar.frame];
    tabBarView.barItems = _items;
    [self.view addSubview:tabBarView];
}
- (void)setupChildVC {
    
    kqyArenaViewController *arenaVC = [[kqyArenaViewController alloc] init];
    [self addOneChildVC:arenaVC withTitle:@"arena" withImage:@"TabBar_Arena_new" withSelectedImage:@"TabBar_Arena_selected_new"];
    kqyHallViewController *hallVC = [[kqyHallViewController alloc] init];
    [self addOneChildVC:hallVC withTitle:@"hall" withImage:@"TabBar_LotteryHall_new" withSelectedImage:@"TabBar_LotteryHall_selected_new"];
    kqyDiscoveryViewController *discoveryVC = [[kqyDiscoveryViewController alloc] init];
    [self addOneChildVC:discoveryVC withTitle:@"discovery" withImage:@"TabBar_Discovery_new" withSelectedImage:@"TabBar_Discovery_selected_new"];
    kqyHistoryViewController *historyVC = [[kqyHistoryViewController alloc] init];
    [self addOneChildVC:historyVC withTitle:@"history" withImage:@"TabBar_History_new" withSelectedImage:@"TabBar_History_selected_new"];
    kqyMyLotteryViewController *myLottery = [[kqyMyLotteryViewController alloc] init];
    [self addOneChildVC:myLottery withTitle:@"myLottery" withImage:@"TabBar_MyLottery_new" withSelectedImage:@"TabBar_MyLottery_selected_new"];
}
- (void)addOneChildVC:(UIViewController *)childVC withTitle:(NSString *)title withImage:(NSString *)image withSelectedImage:(NSString *)selectedImage {
    kqyNavViewController *nav =[[kqyNavViewController alloc] initWithRootViewController:childVC];
    childVC.navigationItem.title = title;
    self.tabBarItem.title = title;
   //
    //
    //
    //
//    self.tabBarItem.image = [UIImage imageNamed:image];
//    self.tabBarItem.selectedImage = [UIImage imageNamed:selectedImage];
    nav.tabBarItem.image = [UIImage imageNamed:image];
    nav.tabBarItem.selectedImage = [UIImage imageNamed:selectedImage];
    [self.items addObject:nav.tabBarItem];
    [self addChildViewController:nav];
}
//
//
@end
