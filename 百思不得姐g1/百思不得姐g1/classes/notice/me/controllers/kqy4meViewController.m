//
//  kqy4meViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy4meViewController.h"
#import "settingVc.h"

@interface kqy4meViewController ()

@end

@implementation kqy4meViewController
- (void) testBtnClick {
    NSLog(@"test click");
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    self.navigationItem.title = @"me我的控制作器制作制";
    self.navigationItem.hidesBackButton = YES;
    UIButton *testBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    testBtn.frame = CGRectMake(150, 300, 60, 40);
    [self.view addSubview:testBtn];
    [testBtn addTarget:self action:@selector(testBtnClick) forControlEvents:UIControlEventTouchUpInside];
    // right 1
    UIBarButtonItem *settingItem = [UIBarButtonItem setItemImage:@"mine-setting-icon" andHighlightImage:@"mine-setting-icon-click" andTarget:self andAction:@selector(settingClick)];
    
    // right 2
    UIBarButtonItem *moonItem = [UIBarButtonItem setItemImage:@"mine-moon-icon" andHighlightImage:@"mine-moon-icon-click" andTarget:self andAction:@selector(moonClick)];
    self.navigationItem.rightBarButtonItems = @[settingItem, moonItem];
//    [self setupTestXib];
    // Do any additional setup after loading the view.
}
//- (void) setupTestXib {
//    NSArray *nibContents = [[NSBundle mainBundle] loadNibNamed:@"test3buttonxib" owner:nil options:nil];
//    UIView *plainView = [nibContents lastObject];
////    CGSize padding = (CGSize) {0,69};
////    plainView.frame = (CGRect){padding.width, padding.height, plainView.frame.size};
//    plainView.frame = CGRectMake(0, 60, self.view.frame.size.width, self.view.frame.size.height);
//    [self.view addSubview:plainView];
//}
- (void) settingClick {
    settingVc *settingVC = [[settingVc alloc] init];
    settingVC.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:settingVC animated:YES];
}
- (void) moonClick {
    NSLog(@"moon click");
}

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 3;
}
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifier = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier: identifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
        
    }
    
    cell.textLabel.text = [NSString stringWithFormat:@"list: %zd", indexPath.row];
    return cell;
}

@end
