//
//  recommendFriendViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "recommendFriendViewController.h"
#import "kqyLoginRegisterViewController.h"
@interface recommendFriendViewController ()

@end

@implementation recommendFriendViewController
- (IBAction)loginClick {
    kqyLoginRegisterViewController *loginRegesierVc = [[kqyLoginRegisterViewController alloc] init];
    [self presentViewController:loginRegesierVc animated:YES completion:nil];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
