//
//  kqy3noticeTableViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy3noticeTableViewController.h"
#import "recommendFriendViewController.h"
@interface kqy3noticeTableViewController ()

@end

@implementation kqy3noticeTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    
    self.navigationItem.title = @"attention";
    
    UIButton *friendBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [friendBtn setImage:[UIImage imageNamed:@"friendsRecommentIcon"] forState:UIControlStateNormal];
    [friendBtn setImage:[UIImage imageNamed:@"friendsTrend_login_click"] forState:UIControlStateHighlighted];
    [friendBtn sizeToFit];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:friendBtn];
    [friendBtn addTarget:self action:@selector(friendClick) forControlEvents:UIControlEventTouchUpInside];
    
}
- (void) friendClick {
 
    recommendFriendViewController *recommentFriVc = [[recommendFriendViewController alloc] init];
    [self.navigationController pushViewController:recommentFriVc animated:YES];
}



@end
