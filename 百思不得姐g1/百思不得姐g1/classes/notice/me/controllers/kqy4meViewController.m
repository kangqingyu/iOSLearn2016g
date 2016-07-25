//
//  kqy4meViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy4meViewController.h"

@interface kqy4meViewController ()

@end

@implementation kqy4meViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    self.navigationItem.title = @"me";
    
    // right 1
    UIButton *setttingBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [setttingBtn setImage:[UIImage imageNamed:@"mine-setting-icon"] forState:UIControlStateNormal];
    [setttingBtn setImage:[UIImage imageNamed:@"mine-setting-icon-click"] forState:UIControlStateHighlighted];
    [setttingBtn sizeToFit];
    [setttingBtn addTarget:self action:@selector(settingClick) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *settingItem = [[UIBarButtonItem alloc] initWithCustomView:setttingBtn];
    // right 2
    UIButton *moonBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [moonBtn setImage:[UIImage imageNamed:@"mine-moon-icon"] forState:UIControlStateNormal];
    [moonBtn setImage:[UIImage imageNamed:@"mine-moon-icon-click"] forState:UIControlStateHighlighted];
    UIBarButtonItem *moonItem = [[UIBarButtonItem alloc] initWithCustomView:moonBtn];
    [moonBtn addTarget:self action:@selector(moonClick) forControlEvents:UIControlEventTouchUpInside];
    
    self.navigationItem.rightBarButtonItems = @[settingItem, moonItem];
    
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
