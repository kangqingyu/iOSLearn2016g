//
//  kqyLoginRegisterViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyLoginRegisterViewController.h"

@interface kqyLoginRegisterViewController ()
- (IBAction)closeBtn;
- (IBAction)registerBtn:(UIButton *)sender;
@property (weak, nonatomic) IBOutlet UIButton *loginBtn;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *leftMargin;

@end


@implementation kqyLoginRegisterViewController
- (IBAction)loginOrRegist:(UIButton *)sender {

    [self.view endEditing:YES];
    
    if (self.leftMargin.constant ) {
        self.leftMargin.constant = 0;
//        [sender setTitle:@"注册" forState:UIControlStateNormal];
    } else {
        self.leftMargin.constant = - self.view.frame.size.width;
//        [sender setTitle:@"haveed" forState:UIControlStateNormal];
    }
    [UIView animateWithDuration:1 animations:^{
        [self.view layoutIfNeeded];
    }];
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
//    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    // Do any additional setup after loading the view from its nib.
//    self.loginBtn.layer.cornerRadius = 5;
//    self.loginBtn.layer.masksToBounds = YES;
    [self.loginBtn setValue:@5 forKeyPath:@"layer.cornerRadius"];
    [self.loginBtn setValue:@YES forKeyPath:@"layer.masksToBounds"];
}
- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
    
}

- (IBAction)closeBtn {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)registerBtn:(id)sender {
}
@end
