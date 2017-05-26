//
//  kqyMusicTool.h
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "kqyMusicModel.h"
@interface kqyMusicTool : NSObject
+(NSArray *)musics;// 音乐列表
+ (kqyMusicModel *) playingMusic;// 当前正在播放的音乐。
+ (void) setupPlayingMusic:(kqyMusicModel *) playingMusic;// 设置播放的音乐。

@end
