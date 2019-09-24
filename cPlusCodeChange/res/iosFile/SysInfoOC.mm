//
//  SysInfoOC.m
//  sysInfo
//
//  Created by alexzen on 14-10-29.
//  Copyright (c) 2014年 kuniu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SysInfoOC.h"
#import "Reachability.h"

#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "CCLuaBridge.h"
#import "MoviePlayerHelper.h"


using namespace cocos2d;

@implementation SysInfoOC

static SysInfoOC* s_instance = nil;


+ (SysInfoOC*) getInstance
{
    if (!s_instance)
    {
        s_instance = [SysInfoOC alloc];
        [s_instance init];
    }
    
    return s_instance;
}

+ (void) destroyInstance
{
    [s_instance release];
}

- (void) setScriptHandler:(int)scriptHandler
{
    if (_scriptHandler)
    {
        LuaBridge::releaseLuaFunctionById(_scriptHandler);
        _scriptHandler = 0;
    }
    _scriptHandler = scriptHandler;
}

- (int) getScriptHandler
{
    return _scriptHandler;
}

+(void)playMovie:(NSDictionary *)dict{
    [SysInfoOC registerScriptHandler:dict];
    [MoviePlayerHelper playMovieWithFile:[dict objectForKey:@"fileName"]];
    
}


+(void) registerScriptHandler:(NSDictionary *)dict
{
    [[SysInfoOC getInstance] setScriptHandler:[[dict objectForKey:@"scriptHandler"] intValue]];
}


+ (void) unregisterScriptHandler
{
    [[SysInfoOC getInstance] setScriptHandler:0];
}

+ (int)  addTwoNumbers:(NSDictionary *)dict
{
    int num1 = [[dict objectForKey:@"num1"] intValue];
    int num2 = [[dict objectForKey:@"num2"] intValue];
    
    return num1 + num2;
}

+ (void) callbackScriptHandler
{
    int scriptHandler = [[SysInfoOC getInstance] getScriptHandler];
    if (scriptHandler)
    {
        LuaBridge::pushLuaFunctionById(scriptHandler);
        LuaStack *stack = LuaBridge::getStack();
        stack->pushString("success");
        stack->executeFunction(1);
    }
}


+(float)getBatteryLevel:(NSDictionary *)dict{

    [[UIDevice currentDevice] setBatteryMonitoringEnabled:YES];
    return [[UIDevice currentDevice] batteryLevel];

}

+(int)getNetState:(NSDictionary *)dict{

    Reachability *r = [Reachability reachabilityForInternetConnection];
    switch ([r currentReachabilityStatus]) {
        case NotReachable:
            // 没有网络连接
//            NSLog(@"无网络");
            return 0;
            break;
        case ReachableViaWWAN:
            // 使用3G网络
//            NSLog(@"3G");
            return 3;
            break;
        case ReachableViaWiFi:
            // 使用WiFi网络
//            NSLog(@"WFI");
            return 4;
            
            }
}

- (id)init
{
    _scriptHandler = 0;
    return self;
}

@end
