//
//  kqy1essentialViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/21/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqy1essentialViewController.h"
#import "titleButton.h"
#import "allTableViewController.h"
#import "voiceTableViewController.h"    
#import "videoTableViewController.h"
#import "pictureTableViewController.h"  
#import "wordTableViewController.h"
@interface kqy1essentialViewController ()  <UIScrollViewDelegate>
@property (nonatomic, weak) UIButton *selectedButton;
@property (nonatomic, weak) UIView *indicatorView;
@property (nonatomic, weak) UIScrollView *mainScrollView;
@property (nonatomic, weak) UIView *titleView;


@end

@implementation kqy1essentialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = kqyRandomColor;
    [self setupUIBarButtonItem];
    [self setupChildView];
    [self setupScrollView];
    [self setupTitlesView];
}

- (void) setupUIBarButtonItem {
    // Do any additional setup after loading the view.
    self.navigationItem.titleView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"MainTitle"]];
    self.navigationItem.leftBarButtonItem = [UIBarButtonItem setItemImage:@"MainTagSubIcon" andHighlightImage:@"MainTagSubIconClick" andTarget:self andAction:@selector(backClick)];
    
    self.automaticallyAdjustsScrollViewInsets = NO;
}

- (void) setupTitlesView {
    UIView *titleView = [[UIView alloc] init];
    titleView.backgroundColor = [UIColor colorWithWhite:1 alpha:0.2];
//    titleView.backgroundColor = [UIColor whiteColor];
    titleView.frame = CGRectMake(0, 64, self.view.kqy_width, 35);
    [self.view addSubview:titleView];
    _titleView = titleView;
    
    NSInteger titleBtnNumber = 5;
    CGFloat titleWidth = self.view.kqy_width / titleBtnNumber;
    CGFloat titleHeight = 35;
    NSArray *titleArray =@[@"all", @"videos", @"voices", @"com", @"5"];
    for (int i = 0; i < titleBtnNumber; ++i) {
        titleButton *titleBtn = [titleButton buttonWithType:UIButtonTypeCustom];
        [titleBtn addTarget:self action:@selector(titleClick:) forControlEvents:UIControlEventTouchUpInside];
        titleBtn.tag = i;
        [titleBtn setTitle:titleArray[i] forState:UIControlStateNormal];
        titleBtn.frame = CGRectMake(i * titleWidth, 0, titleWidth, titleHeight);
        [titleView addSubview:titleBtn];
        
    }
    UIView *indicatorView = [[UIView alloc] init];
    indicatorView.backgroundColor = [UIColor redColor];
    indicatorView.kqy_y = titleView.kqy_height - 2;
    indicatorView.kqy_height = 1;
    _indicatorView = indicatorView;
    
    [titleView addSubview:_indicatorView];
    
    titleButton *firstTitleView = titleView.subviews.firstObject;
    [firstTitleView.titleLabel sizeToFit];
    _indicatorView.kqy_centerX = firstTitleView.kqy_centerX;
    _indicatorView.kqy_width = firstTitleView.titleLabel.kqy_width ;
    
    firstTitleView.selected = YES;
    self.selectedButton = firstTitleView;
}
- (void) titleClick:(UIButton *) titBtn {
    _selectedButton.selected = NO;
    titBtn.selected = YES;
    _selectedButton = titBtn;
    //1
    CGFloat titleW = [titBtn.currentTitle sizeWithAttributes:@{NSFontAttributeName:titBtn.titleLabel.font}].width;
    // 2
//    _indicatorView.kqy_width = titBtn.titleLabel.kqy_width;
    
    [UIView animateWithDuration:1 animations:^{
        _indicatorView.kqy_width = titleW + 6;
//        _indicatorView.kqy_centerX = titBtn.titleLabel.kqy_centerX; 用这个不行，原来这个不错的。。。。
        _indicatorView.kqy_centerX = titBtn.kqy_centerX;
    }];
    
    CGPoint scrollOffsetPoint = _mainScrollView.contentOffset;
    NSInteger pageNumber = titBtn.tag;
    scrollOffsetPoint.x = pageNumber * self.view.kqy_width;
    [_mainScrollView setContentOffset:scrollOffsetPoint animated:YES];
}
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView {
    [self addChildVcAfterScrollView];
}
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    CGFloat contentOffset = _mainScrollView.contentOffset.x;
    NSInteger index  = contentOffset / self.view.kqy_width;
    titleButton *titBtn = _titleView.subviews[index];
    [self titleClick:titBtn];
    
    [self addChildVcAfterScrollView];
    
}

- (void) addChildVcAfterScrollView {
    NSInteger index = self.mainScrollView.contentOffset.x / self.view.kqy_width;
    UIViewController *childVc = self.childViewControllers[index];
//    UITableView *childVc =  self.childViewControllers[index];
//    childVc.contentInset = UIEdgeInsetsMake(64 + 35, 0, 29, 0);
    childVc.view.kqy_y = 0;
    childVc.view.kqy_x = index * self.view.kqy_width;
    childVc.view.kqy_width = self.view.kqy_width;
    childVc.view.kqy_height = self.view.kqy_height;
//    childVc.kqy_y = 0;
//    childVc.kqy_x = index *self.view.kqy_width;
//    childVc.kqy_width = self.view.kqy_width;
//    childVc.kqy_height = self.view.kqy_height;
    
    [_mainScrollView addSubview:childVc.view];
}


- (void) setupScrollView {
    UIScrollView *mainScrollView = [[UIScrollView alloc] init];
    mainScrollView.backgroundColor  = kqyRandomColor;
    mainScrollView.frame = [UIScreen mainScreen].bounds;
    [self.view addSubview:mainScrollView];
    mainScrollView.pagingEnabled = YES;
    mainScrollView.delegate = self;
    NSInteger vcCount = self.childViewControllers.count;
    
//    mainScrollView.contentInset = UIEdgeInsetsMake(64 + 20, 0, 49, 0); //不是他，而是tableview 的contentInset.
    
    NSLog(@"vc count: %zd",vcCount);
    mainScrollView.contentSize = CGSizeMake(vcCount * mainScrollView.kqy_width, 0);
//    for (int i = 0; i < vcCount; ++i) {
//        UITableView *childVc = (UITableView *)self.childViewControllers[i].view;
//        childVc.frame = CGRectMake(i * childVc.kqy_width, 0, childVc.kqy_width, childVc.kqy_height);
//        
//        childVc.contentInset = UIEdgeInsetsMake(64 + 35, 0, 29, 0);
//        childVc.scrollIndicatorInsets = childVc.contentInset;
//        [mainScrollView addSubview:childVc];
//        
//    }
    
    _mainScrollView = mainScrollView;
}

- (void) setupChildView {
    allTableViewController *all = [[allTableViewController alloc] init];
    [self addChildViewController:all];
    
    voiceTableViewController *voiceVc = [[voiceTableViewController alloc] init];
    [self addChildViewController:voiceVc];
    
    videoTableViewController *videoVc = [[videoTableViewController alloc] init];
    [self addChildViewController:videoVc];
    
    pictureTableViewController *picVc = [[pictureTableViewController alloc] init];
    [self addChildViewController:picVc];
    
    wordTableViewController *wordVc = [[wordTableViewController alloc] init];
    [self addChildViewController: wordVc];
    
}
- (void) backClick {
    kqyLogFunc;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
