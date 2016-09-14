//
//  kqyTabBarView.h
//  网易彩票g1
//
//  Created by kqy on 9/5/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import <UIKit/UIKit.h>
@class kqyTabBarView;
@protocol kqyTabBarViewDelegate <NSObject>
@optional
- (void)tabBar:(kqyTabBarView *)tabBar didClickBtn:(NSInteger)buttonIndex;
@end
                
@interface kqyTabBarView : UIView
@property (nonatomic, weak) id<kqyTabBarViewDelegate> delegate;
@property (nonatomic, strong) NSArray  *barItems;

//
@end       
