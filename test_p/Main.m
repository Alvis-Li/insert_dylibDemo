//
//  Main.m
//  test_p
//
//  Created by simple on 2017/5/24.
//  Copyright © 2017年 simple. All rights reserved.
//

#import "Main.h"
#import "ViewController.h"

@implementation NSObject (MacWeChatTimeLinePlugin)

-(void)test:(id)arg1{
    NSLog(@"aaa");
}

@end


static void __attribute__((constructor)) initialize(void) {
    NSLog(@"++++++++ MacWeChatTimeLinePlugin loaded ++++++++");
    CBHookInstanceMethod(ViewController, @selector(click:), @selector(test:));
}
