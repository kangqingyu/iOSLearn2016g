//
//  kqyMusicTool.m
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import "kqyMusicTool.h"
#import "kqyMusicModel.h"
#import "MJExtension.h"
@implementation kqyMusicTool
static NSArray *  _musics;
static kqyMusicModel *_playingMusic;
+ (void)initialize {
    if (_musics == nil) {
        _musics = [kqyMusicModel mj_objectArrayWithFilename:@"Musics.plist"];
    }
    if (!_playingMusic) {
        _playingMusic = _musics[1];
    }
}
+ (NSArray *)musics {
    return _musics;
}
+ (kqyMusicModel *)playingMusic {
    return _playingMusic;
}
+ (void)setupPlayingMusic:(kqyMusicModel *)playingMusic {
    _playingMusic = playingMusic;
}  
@end
