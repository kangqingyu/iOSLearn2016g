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
@property (nonatomic, strong) UIButton *publishBtn;

@end

@implementation kqyTabBarViewController
- (UIButton *)publishBtn {
    NSLog(@"lazy did load");
    if (_publishBtn == nil) {
    _publishBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        _publishBtn.backgroundColor = kqyRandomColor;
    [_publishBtn setImage:[UIImage imageNamed:@"tabBar_publish_icon"] forState:UIControlStateNormal];
    [_publishBtn setImage:[UIImage imageNamed:@"tabBar_publish_click_icon"] forState:UIControlStateSelected];
        _publishBtn.frame = CGRectMake(0,0,self.tabBar.frame.size.width * 0.2, self.tabBar.frame.size.height);
        _publishBtn.center = CGPointMake(self.tabBar.frame.size.width * 0.5, self.tabBar.frame.size.height * 0.5);
    [_publishBtn addTarget:self action:@selector(publishButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _publishBtn;
}

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
    kqy1essentialViewController *test1essVC = [[kqy1essentialViewController alloc] init];
    [self presentViewController:test1essVC animated:YES completion:nil];
}
- (void)setOneChildVC:(UIViewController *) vc andTitle:(NSString *)title andImage:(NSString *)image andSelectedImg:(NSString *)selectedImg {
    vc.view.backgroundColor = kqyRandomColor;
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
    
    [self.tabBar addSubview:self.publishBtn];
}

@end
