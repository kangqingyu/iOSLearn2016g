//
//  kqyMicroBlogCell.m
//  211-2 autolayoutMicroBlog-2 myself-1
//
//  Created by kqy on 8/27/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyMicroBlogCell.h"
#import "microBlogModel.h"
#import "Masonry.h"
@interface kqyMicroBlogCell()
@property (nonatomic, weak) UIImageView *iconImg;
@property (nonatomic, weak) UILabel *nameLbl;
@property (nonatomic, weak) UIImageView *vip;
@property (nonatomic, weak) UILabel *contentlbl;
@property (nonatomic, weak) UIImageView *picImg;

@end
@implementation kqyMicroBlogCell

- (void)setBlogModel:(microBlogModel *)blogModel {
    _blogModel = blogModel;
    _iconImg.image = [UIImage imageNamed:blogModel.icon];
    _nameLbl.text = blogModel.name;
    _contentlbl.text = blogModel.text;
//    self.contentView.
    [_contentlbl mas_makeConstraints:^(MASConstraintMaker *make) {
    make.bottom.equalTo(self.contentView.mas_bottom).offset(-10);
    }];
    if (_picImg) {
       
        [_picImg mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(50);
//            make.bottom.equalTo(self.contentView.mas_bottom).offset(-10);
//            make.top.equalTo(_contentlbl.mas_bottom).offset(10);
        }];
            _picImg.image = [UIImage imageNamed:blogModel.picture];
    
    } else {
        [_picImg mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(0);
            make.bottom.equalTo(self.contentView.mas_bottom).offset(0);
//            make.bottom.equalTo(0);
        }];
    }
    
}
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
    
    UIImageView *iconImg = [[UIImageView alloc] init];
    [self.contentView addSubview:iconImg];
    _iconImg = iconImg;
    
    UILabel *nameLbl = [[UILabel alloc] init];
    _nameLbl = nameLbl;
    [self.contentView addSubview:nameLbl];
    
    UIImageView *vipImg = [[UIImageView alloc] init];
    _vip = vipImg;
    [self.contentView addSubview:vipImg];
    _vip.image = [UIImage imageNamed:@"vip"];
    
    UILabel *contentLbl = [[UILabel alloc] init];
        contentLbl.numberOfLines = 0;
    _contentlbl = contentLbl ;
    [self.contentView addSubview:contentLbl];
    
    UIImageView *picImg = [[UIImageView alloc] init];
    _picImg = picImg ;
    [self.contentView addSubview:picImg];     
        
    [iconImg mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.contentView.mas_top).with.offset(1);
        make.top.equalTo(self.contentView.mas_top).with.offset(1);
        make.width.mas_equalTo(40);
        make.height.mas_equalTo(40);
        //        make.width.equalTo(self.contentView.mas_width).multipliedBy(0.2);
//        make.height.equalTo(self.contentView.mas_height).multipliedBy(0.8);
       
//        make.bottom.equalTo(self.contentView.mas_bottom).offset(10);
    }];
    [nameLbl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(iconImg.mas_right).offset(10);
        make.top.equalTo(iconImg.mas_top).offset(0);
        make.width.mas_equalTo(100);
        make.height.mas_equalTo(30);
    }];
    [contentLbl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.contentView.mas_leading).offset(10);
        make.trailing.equalTo(self.contentView.mas_trailing).offset(-10);
        make.top.equalTo(iconImg.mas_bottom).offset(10);
        
    }];
    
    [picImg mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(contentLbl.mas_bottom).offset(10);
        make.leading.equalTo(self.contentView.mas_leading).offset(10);
        make.width.mas_equalTo(50);
        make.height.mas_equalTo(50);
        
        make.bottom.equalTo(self.contentView.mas_bottom).offset(-10);
    }];
    
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
//    _iconImg.frame = CGRectMake(1, 1, 200, 30);
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    // Configure the view for the selected state
}

@end
