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
    [self setupUIBarButtonItem];
    [self setupScrollView];
    [self setupTitlesView];
}

- (void) setupUIBarButtonItem {
    // Do any additional setup after loading the view.
    self.navigationItem.titleView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"MainTitle"]];
    self.navigationItem.leftBarButtonItem = [UIBarButtonItem setItemImage:@"MainTagSubIcon" andHighlightImage:@"MainTagSubIconClick" andTarget:self andAction:@selector(backClick)];
}

- (void) setupTitlesView {
    UIView *titleView = [[UIView alloc] init];
    titleView.backgroundColor = [UIColor colorWithWhite:1 alpha:0.2];
//    titleView.backgroundColor = [UIColor whiteColor];
    titleView.frame = CGRectMake(0, 64, self.view.kqy_width, 35);
    [self.view addSubview:titleView];
    
    NSInteger titleBtnNumber = 5;
    CGFloat titleWidth = self.view.kqy_width / titleBtnNumber;
    CGFloat titleHeight = 35;
    NSArray *titleArray =@[@"all", @"videos", @"voices", @"com", @"5"];
    for (int i = 0; i < titleBtnNumber; ++i) {
        UIButton *titleBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [titleBtn addTarget:self action:@selector(titleClick:) forControlEvents:UIControlEventTouchUpInside];
        [titleBtn setTitle:titleArray[i] forState:UIControlStateNormal];
        [titleBtn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
        titleBtn.frame = CGRectMake(i * titleWidth, 0, titleWidth, titleHeight);
        [titleView addSubview:titleBtn];
    }

    
}
- (void) titleClick:(UIButton *) titBtn {
    NSLog(@"tit btn click");
}

- (void) setupScrollView {
    UIScrollView *mainScrollView = [[UIScrollView alloc] init];
    mainScrollView.backgroundColor  = kqyRandomColor;
    mainScrollView.frame = [UIScreen mainScreen].bounds;
    [self.view addSubview:mainScrollView];
    
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
