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

@implementation kqy4meViewController
- (void) testBtnClick {
    NSLog(@"test click");
}
- (instancetype)init {
    return [self initWithStyle:UITableViewStyleGrouped];
}
- (void)viewDidLoad {
    [super viewDidLoad];
//    self.tableView.sectionFooterHeight = 0;
//    self.tableView.sectionHeaderHeight = 10;
///    UIButton *testBtn = [UIButton buttonWithType:UIButtonTypeCustom];
//    testBtn.frame = CGRectMake(150, 300, 60, 40);
//    [self.view addSubview:testBtn];
//    [testBtn addTarget:self action:@selector(testBtnClick) forControlEvents:UIControlEventTouchUpInside];
//    // right 1
    [self setupNav];
    [self setupTableView];
//    [self setupFootView];// this is test
}
- (void)setupNav {
    self.tableView.contentInset = UIEdgeInsetsMake(-10 * 2 , 0, 50, 0);

}
- (void)setupTableView {
//    self.tableView.contentInset = UIEdgeInsetsMake(-30 , 0, -100, 0);
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
//- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
//    if (indexPath.section == 2) {
//        return 200;
//    } else {
//        return 49;
//    }
//}
//- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
//    if ( section == 0 ) { return 10; }
//    else {
//        return 30;
//    }
//}
//- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
//    UITableViewCell *selectedCell = [tableView cellForRowAtIndexPath:indexPath];
//    kqyLog(@"%@",NSStringFromCGRect(selectedCell.frame));
//}

//- (void) setupTestXib {
//    NSArray *nibContents = [[NSBundle mainBundle] loadNibNamed:@"test3buttonxib" owner:nil options:nil];
//    UIView *plainView = [nibContents lastObject];
////    CGSize padding = (CGSize) {0,69};
////    plainView.frame = (CGRect){padding.width, padding.height, plainView.frame.size};
//    plainView.frame = CGRectMake(0, 60, self.view.frame.size.width, self.view.frame.size.height);
//    [self.view addSubview:plainView];
//}