//
//  settingVc.m
//  百思不得姐g1
//
//  Created by kqy on 7/26/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "settingVc.h"

@implementation settingVc
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    // left backBtn
//    UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
//    [backBtn setTitle:@"back" forState:UIControlStateNormal];
//    [backBtn setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
//    [backBtn setTitleColor:[UIColor blackColor] forState:UIControlStateHighlighted];
//    [backBtn setImage:[UIImage imageNamed:@"navigationButtonReturn"] forState:UIControlStateNormal];
//    [backBtn setImage:[UIImage imageNamed:@"navigationButtonReturnClick"] forState:UIControlStateHighlighted];
//    [backBtn sizeToFit];
//    backBtn.contentEdgeInsets = UIEdgeInsetsMake(0, -25, 0, 0);
//    [backBtn addTarget:self action:@selector(testClick) forControlEvents:UIControlEventTouchUpInside];
//    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:backBtn];
//    
}

- (void) testClick {
    [self.navigationController popViewControllerAnimated:YES];
    
}

@end
