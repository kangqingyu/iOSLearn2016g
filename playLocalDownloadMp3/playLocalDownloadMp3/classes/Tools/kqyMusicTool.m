//
//  kqyMusicTool.m
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import "kqyMusicTool.h"
@implementation kqyMusicTool
static NSArray *  _musics;
static kqyMusicModel *_playingMusic;

+ (NSArray *)musics {
    return _musics;
}
+ (kqyMusicModel *)playingMusic {
    return _playingMusic;
}
@end
