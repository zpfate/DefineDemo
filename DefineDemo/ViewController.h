//
//  ViewController.h
//  DefineDemo
//
//  Created by Twisted Fate on 2019/7/31.
//  Copyright © 2019 Twisted Fate. All rights reserved.
//

#import <UIKit/UIKit.h>

FOUNDATION_EXPORT NSString *const kFoundationExportString;

extern NSString *const kExternString;

#define kDefineString @"Hello World"

typedef NSString *ViewControllerKey NS_STRING_ENUM;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeyTitle;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeySubtitle;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeySummary;

#define BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); };

#ifdef DEBUG
#define LogInfo( s, ... ) NSLog( @"[LogInfo]<%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define LogInfo( s, ... )
#endif

@interface ViewController : UIViewController


@end

