//
//  kqyMicroBLogVC.m
//  211-2 autolayoutMicroBlog-2 myself-1
//
//  Created by kqy on 8/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyMicroBLogVC.h"
#import "microBlogModel.h"
#import "kqyMicroBlogCell.h"
#define randomColor  [UIColor colorWithRed:(arc4random_uniform(255)/255.0) green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1];
@interface kqyMicroBLogVC () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) NSArray *dataArray;
@end

@implementation kqyMicroBLogVC
- (NSArray *)dataArray {
    if (!_dataArray) {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"weibo" ofType:@"plist"];
        NSArray *tempArray = [NSArray arrayWithContentsOfFile:path];
        NSMutableArray *mutArray = [NSMutableArray array];
        for (NSDictionary *dict in tempArray) {
            microBlogModel *microModel = [microBlogModel microBlogWithDict:dict];
            [mutArray addObject:microModel];
        }
        _dataArray = mutArray;
    }
    return _dataArray;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    UITableView *tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    [self.view addSubview:tableView];
    tableView.backgroundColor  = [UIColor yellowColor];
    tableView.delegate = self;
    tableView.dataSource = self;
    
    tableView.estimatedRowHeight = 99;
    tableView.rowHeight = UITableViewAutomaticDimension;
    
}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataArray.count;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"cell for row");
    static NSString *identifier = @"microBlogCell";
    kqyMicroBlogCell *cell = [[kqyMicroBlogCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    if (!cell) {
        cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    }
    cell.backgroundColor = randomColor;
    microBlogModel *blogModel = self.dataArray[indexPath.row];
    cell.blogModel  = blogModel;
    return cell;
}


@end
