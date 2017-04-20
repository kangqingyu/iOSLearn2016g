//
//  kqy4meViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy4meViewController.h"
#import "settingVc.h"
#import "kqyMeCell.h"
#import "kqyFootView.h"

@interface kqy4meViewController ()

@end

//
@implementation kqy4meViewController
- (void) testBtnClick {
    NSLog(@"test click");
}
- (instancetype)init {
    return [self initWithStyle:UITableViewStyleGrouped];
}
- (void)viewDidLoad {
    [super viewDidLoad];

    [self setupNav];
    [self setupTableView];
}
- (void)setupNav {
    self.tableView.contentInset = UIEdgeInsetsMake(-10 * 2 , 0, 0, 0);
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithImage:[UIImage imageNamed:@"mine-setting-icon"] style:UIBarButtonItemStyleDone target:self action:@selector(settingClick)];

}
- (void)setupTableView {
    self.view.backgroundColor = kqyRandomColor;
    self.navigationItem.title = @"me我的控制作器制作制";
    self.navigationItem.hidesBackButton = YES;
    self.tableView.tableFooterView = [[kqyFootView alloc] init];
    
}
- (void)setupFootView {
    UIView *footView = [[UIView alloc] init];
    footView.backgroundColor = [UIColor greenColor];
//    footView.kqy_height = 200;
    CGRect tempFootViewFrame = footView.frame;
    tempFootViewFrame.size.height = 200;
    footView.frame = tempFootViewFrame;
    self.tableView.tableFooterView = footView;
}
- (void) settingClick {
    settingVc *settingVC = [[settingVc alloc] init];
    settingVC.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:settingVC animated:YES];
}
- (void) moonClick {
    NSLog(@"moon click");
}

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView {
    return 2;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *identifier = @"identIdCell";
    kqyMeCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (!cell) {
        cell = [[kqyMeCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
        
    }
    if (indexPath.section == 0) {
        cell.imageView.image = [UIImage imageNamed:@"setup-head-default"];
        cell.textLabel.text = @"login/registrer";
    } else if (indexPath.section == 1) {
        cell.textLabel.text = @"download outline";
    }
    
    return cell;
}
@end
