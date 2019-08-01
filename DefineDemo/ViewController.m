//
//  ViewController.m
//  DefineDemo
//
//  Created by Twisted Fate on 2019/7/31.
//  Copyright © 2019 Twisted Fate. All rights reserved.
//

#import "ViewController.h"
#import "DefineDemo-Swift.h"

NSString *const kFoundationExportString = @"Hello World";
NSString *const kExternString = @"Hello World";

ViewControllerKey const ViewControllerKeyTitle = @"title";
ViewControllerKey const ViewControllerKeySubtitle = @"subtitle";
ViewControllerKey const ViewControllerKeySummary = @"summary"; 

NSString *const kConstantString = @"string"; // 指针常量
const NSString *kString = @"string2";  // 常量指针

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    kConstantString = @"1";
    kString = @"1";
    
    EnumManager *manager = [[EnumManager alloc] init];
    [manager show];
}


@end
