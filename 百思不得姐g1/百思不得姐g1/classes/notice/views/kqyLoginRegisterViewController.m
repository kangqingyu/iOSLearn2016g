//
//  kqyLoginRegisterViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyLoginRegisterViewController.h"

@interface kqyLoginRegisterViewController ()

@end

@implementation kqyLoginRegisterViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    // Do any additional setup after loading the view from its nib.
}
- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self  dismissViewControllerAnimated:YES completion:nil];
    
}

@end
