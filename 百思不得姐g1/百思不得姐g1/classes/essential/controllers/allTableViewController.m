//
//  allTableViewController.m
//  百思不得姐g1
//
//  Created by kqy on 7/29/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "allTableViewController.h"

@interface allTableViewController ()

@end

@implementation allTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete implementation, return the number of rows
    return 35;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifier = @"cell"   ;
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellEditingStyleDelete reuseIdentifier:identifier];
        cell.backgroundColor = kqyRandomColor;
        
    }
    cell.textLabel.text = [NSString stringWithFormat:@"%@ %zd",[self class], indexPath.row];
    
    // Configure the cell...
    
    return cell;
}


@end
