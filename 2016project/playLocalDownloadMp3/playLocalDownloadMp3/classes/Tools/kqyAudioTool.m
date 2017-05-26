//
//  kqyAudioTool.m
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import "kqyAudioTool.h"

@implementation kqyAudioTool
static NSMutableDictionary *_soundIDs;
static NSMutableDictionary *_players;
+ (void)initialize {
    _soundIDs = [NSMutableDictionary dictionary];
    _players = [NSMutableDictionary dictionary];
}
+ (AVAudioPlayer *) playMusicWithFileName:(NSString *)fileName {
    AVAudioPlayer *player = nil;
    player = _players[fileName];
    if (!player) {
        NSURL *fileUrl = [[NSBundle mainBundle] URLForResource:fileName withExtension:nil];
        if (!fileUrl) {
            return nil;
        }
        player = [[AVAudioPlayer alloc] initWithContentsOfURL:fileUrl error:nil];
        [_players setObject:player forKey:fileName];
        [player prepareToPlay];
    }
    [player play];
    return  player;
    
}
@end
