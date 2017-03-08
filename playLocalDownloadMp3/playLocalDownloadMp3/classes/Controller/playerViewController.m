//
//  playerViewController.m
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import "playerViewController.h"
#import "Masonry.h"
@interface playerViewController ()

@end

@implementation playerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor yellowColor];
    [self setupUI];
}

- (void) setupUI {
    UILabel *songNameLbl = [[UILabel alloc] init];
    [self.view addSubview:songNameLbl];
    [songNameLbl mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(self.view.mas_top).offset(@50);
        make.top.mas_equalTo(self.view.mas_top).offset(50);
        make.centerX.mas_equalTo(self.view.mas_centerX);
        make.width.mas_equalTo(@90);
        make.height.mas_equalTo(@35);
    }];
    songNameLbl.text = @"text ";
}

@end
