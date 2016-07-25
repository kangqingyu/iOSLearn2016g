//
//  kqy1essentialViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy1essentialViewController.h"

@interface kqy1essentialViewController ()

@end

@implementation kqy1essentialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    // Do any additional setup after loading the view.
    self.navigationItem.titleView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"MainTitle"]];
    
//    UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
//    [backBtn addTarget:self action:@selector(backClick) forControlEvents:UIControlEventTouchUpInside];
//    [backBtn setImage:[UIImage imageNamed:@"MainTagSubIcon"] forState:UIControlStateNormal];
//    [backBtn setImage:[UIImage imageNamed:@"MainTagSubIconClick"] forState:UIControlStateHighlighted];
//    backBtn.kqy_size = [UIImage imageNamed:@"MainTagSubIcon"].size;
//    backBtn.kqy_size = [backBtn imageForState:UIControlStateNormal].size;
    
//    [backBtn sizeToFit];
//    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:backBtn];
//    UIBarButtonItem *leftMainItem = [
    self.navigationItem.leftBarButtonItem = [self setItemImage:@"MainTagSubIcon" andHighlightImage:@"MainTagSubIconClick" andAction:@selector(backClick)];
    
}
- (UIBarButtonItem *) setItemImage:(NSString *)image andHighlightImage:(NSString *) highLightImage andAction:(SEL)action {
    UIButton *itemBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [itemBtn setImage:[UIImage imageNamed:image] forState:UIControlStateNormal];
    [itemBtn setImage:[UIImage imageNamed:highLightImage] forState:UIControlStateHighlighted];
    itemBtn.kqy_size = [itemBtn imageForState:UIControlStateNormal].size;
    [itemBtn addTarget:self action:@selector(action) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *barItem = [[UIBarButtonItem alloc] initWithCustomView:itemBtn];
    return barItem;
}

- (void) backClick {
    kqyLogFunc;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self dismissViewControllerAnimated:YES completion:nil];
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
