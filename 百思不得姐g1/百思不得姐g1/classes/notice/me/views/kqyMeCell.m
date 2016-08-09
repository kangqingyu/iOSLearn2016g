//
//  kqyMeCell.m
//  百思不得姐g1
//
//  Created by kqy on 8/9/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyMeCell.h"

@implementation kqyMeCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.imageView.contentMode = UIViewContentModeScaleToFill;
    }
    return self;
}
- (void)layoutSubviews {
    [super layoutSubviews];
}

@end
