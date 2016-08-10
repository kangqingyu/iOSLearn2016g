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
//        self.imageView.contentMode = UIViewContentModeScaleToFill;
        self.textLabel.textColor = [UIColor darkGrayColor];
        self.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        self.backgroundView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"mainCellBackground"]];
    }
    return self;
}
- (void)layoutSubviews {
    [super layoutSubviews];
    if (!self.imageView.image) {
        self.imageView.kqy_y = 15;
        self.imageView.kqy_height = self.contentView.kqy_height - 30;
        self.imageView.kqy_width = self.imageView.kqy_height;
        self.textLabel.kqy_x = self.imageView.kqy_right + 35;
    } else {
   // label
    }
}

@end
