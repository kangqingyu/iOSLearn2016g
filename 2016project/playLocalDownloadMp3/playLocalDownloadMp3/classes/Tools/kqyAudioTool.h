//
//  kqyAudioTool.h
//  playLocalDownloadMp3
//
//  Created by kqy on 09/02/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
@interface kqyAudioTool : NSObject
+ (AVAudioPlayer *) playMusicWithFileName:(NSString *)fileName;
+ (void) pauseMusicWithFileName:(NSString *)fileName;
+ (void)stopMudicWithFileName:(NSString *)fileName;
+(void) playSoundWithSoundName:(NSString *)soundName;
@end
