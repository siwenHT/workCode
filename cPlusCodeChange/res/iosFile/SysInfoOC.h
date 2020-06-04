//
//  SysInfoOC.h
//  sysInfo
//
//  Created by alexzen on 14-10-29.
//  Copyright (c) 2014年 kuniu. All rights reserved.
//

#ifndef sysInfo_SysInfoOC_h
#define sysInfo_SysInfoOC_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface SysInfoOC : NSObject {
    int _scriptHandler;
}

- (int) getScriptHandler;
+(void)playMovie:(NSDictionary *)dict;

+ (SysInfoOC*) getInstance;
+ (void) destroyInstance;

+ (void) registerScriptHandler:(NSDictionary *)dict;
+ (void) unregisterScriptHandler;

+ (int)  addTwoNumbers:(NSDictionary *)dict;

+ (void) callbackScriptHandler;

+ (float) getBatteryLevel:(NSDictionary *)dict;

+(int) getNetState:(NSDictionary *)dict;


- (id) init;

@end

#endif
