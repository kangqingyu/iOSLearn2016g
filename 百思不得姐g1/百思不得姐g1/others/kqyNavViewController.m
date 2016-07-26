//
//  kqyNavViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyNavViewController.h"

@interface kqyNavViewController ()

@end

@implementation kqyNavViewController

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {
    if (self.childViewControllers.count > 0) {
        UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [backBtn setImage:[UIImage imageNamed:@"navigationButtonReturn"] forState:UIControlStateNormal];
        [backBtn setImage:[UIImage imageNamed:@"navigationButtonReturnClick"] forState:UIControlStateHighlighted];
        [backBtn setTitle:@"back" forState:UIControlStateNormal];
        [backBtn addTarget:self action:@selector(backClick) forControlEvents:UIControlEventTouchUpInside];
        [backBtn sizeToFit];
        backBtn.contentEdgeInsets = UIEdgeInsetsMake(0, -18, 0, 0);
        [backBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [backBtn setTitleColor:[UIColor redColor] forState:UIControlStateHighlighted];
        
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:backBtn];
    }
    [super pushViewController:viewController animated:animated];
    
}
- (void) backClick {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
