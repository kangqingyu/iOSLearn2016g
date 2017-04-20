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
+(NSArray *)musics;
+ (kqyMusicModel *) playingMusic;
+ (void) setupPlayingMusic:(kqyMusicModel *) playingMusic;

@end
