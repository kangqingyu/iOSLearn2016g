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

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
