//
//  allTableViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/29/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "allTableViewController.h"
#import "AFNetworking.h"
#import "essenTopModel.h"
#import "MJExtension.h"
#import "UIImageView+WebCache.h"
#import "MJRefresh.h"
//#import <AFNetworking.h>

@interface allTableViewController ()
@property (nonatomic, strong) NSArray<essenTopModel *> *topics;

@end

@implementation allTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.contentInset = UIEdgeInsetsMake(64 + 35, 0, 49, 0);
    self.tableView.scrollIndicatorInsets = self.tableView.contentInset;
    
//    [self loadNewTopics];
    [self setupRefresh];
}
- (void)setupRefresh {
//    UIRefreshControl *control = [[UIRefreshControl alloc] init];
//    [control addTarget:self action:@selector(loadNewTopics:) forControlEvents:UIControlEventValueChanged];
//    [control beginRefreshing];
//    [self loadNewTopics:control];
//    
//    [self.tableView addSubview:control];
    
//    self.tableView.mj_header = [MJRefreshNormalHeader headerWithRefreshingBlock:^{
//        kqyLogFunc
//    }];
    MJRefreshNormalHeader *mj_header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(loadNewTopics)];
    mj_header.automaticallyChangeAlpha = YES;
    mj_header.lastUpdatedTime.accessibilityElementsHidden = YES;
    mj_header.stateLabel.hidden = YES;
    mj_header.arrowView.hidden = YES;
    self.tableView.mj_header = mj_header;
}
//

//- (void)loadNewTopics:(UIRefreshControl *)control {
- (void)loadNewTopics{
    kqyLogFunc;
    NSMutableDictionary *params = [NSMutableDictionary dictionary];
    params[@"a"] = @"list";
    params[@"c"] = @"data";
    [[AFHTTPSessionManager manager] GET:@"http://api.budejie.com/api/api_open.php"
    parameters:params progress:^(NSProgress * _Nonnull downloadProgress) {
    
     } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
//         [responseObject writeToFile:@"/Users/kqy/Desktop/0818plist" atomically:YES];
         kqyLog(@"write ok 0818.plist");
         self.topics = [essenTopModel mj_objectArrayWithKeyValuesArray:responseObject[@"list"]];
         [self.tableView reloadData];
         [self.tableView.mj_header endRefreshing];
//         [control endRefreshing];
     } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
         kqyLog(@"error:%@", error);
         [self.tableView.mj_header endRefreshing];
//         [control endRefreshing];
     }];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete implementation, return the number of rows
    return self.topics.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifier = @"cell"   ;
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellEditingStyleDelete reuseIdentifier:identifier];
        cell.backgroundColor = kqyRandomColor;
        
    }
    essenTopModel *topModel = self.topics[indexPath.row];
    cell.textLabel.text = topModel.name;
    cell.detailTextLabel.text = topModel.text;
    [cell.imageView sd_setImageWithURL:[NSURL URLWithString:topModel.profile_image] placeholderImage:[UIImage imageNamed:@"common-gif"]];
    // Configure the cell...
    
    return cell;
}


@end
