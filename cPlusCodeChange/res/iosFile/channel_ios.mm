#import <AVFoundation/AVFoundation.h>

#import "SFHFKeychainUtils.h"
#import "channel_ios.h"
#import "AppController.h"
#include <stdio.h>
#include <sys/time.h>
#include <iostream>

#include "CCLuaEngine.h"
#include "CCLuaBridge.h"

#import "MBProgressHUD.h"

#import <sys/utsname.h>

@implementation channel_ios

 
+(void) init{
    
}

+ (BOOL)iphoneType {
    
    //需要导入头文件：#import <sys/utsname.h>
    
    struct utsname systemInfo;
    
    uname(&systemInfo);
    
    NSString*platform = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];
    
    NSLog(@"机型:%@",platform);
    
//    if([platform isEqualToString:@"iPhone10,3"]) return@"iPhone X";
//
//    if([platform isEqualToString:@"iPhone10,6"]) return@"iPhone X";
    
    if([platform isEqualToString:@"iPhone10,3"]) return YES;
    
    if([platform isEqualToString:@"iPhone10,6"]) return YES;
    return NO;
    
}

+ (NSString*)deviceType {
    
    //需要导入头文件：#import <sys/utsname.h>
    
    struct utsname systemInfo;
    
    uname(&systemInfo);
    
    NSString*platform = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];
    
//    NSLog(@"机型:%@",platform);
    
    return platform;
    
}

 
+(NSString*) call:(NSDictionary*)dic {
 
    if ([dic[@"type"] isEqualToString: @"isIphoneX"]) {
        if ([self iphoneType]) {
            return @"true";
        }else{
            return @"false";
        }
    }
    
    if ([dic[@"type"] isEqualToString: @"action"]) {
        
            if ([dic[@"action"] isEqual: @"getGameName"]){
                
                return   [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"];
                
            }

       return  [[GameSoftDevKit shared]callAction:dic];
    }
    
    if ([dic[@"type"] isEqualToString: @"getUUID"]) {
      //  return [[[UIDevice currentDevice] identifierForVendor] UUIDString];
        
        NSString *SERVICE_NAME = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
        NSString * str =  [SFHFKeychainUtils getPasswordForUsername:@"SYUUID" andServiceName:SERVICE_NAME error:nil];  // 从keychain获取数据
        if ([str length]<=0)
        {
            str  = [[[UIDevice currentDevice] identifierForVendor] UUIDString];  // 保存UUID作为手机唯一标识符
  
            [SFHFKeychainUtils storeUsername:@"SYUUID" andPassword:str forServiceName:SERVICE_NAME updateExisting:1 error:nil];  // 往keychain添加数据
        }
        [self deviceType];
//        MLog(@"[XGDemo] register push error");
        return str;
        
        
    }
    
    if ([dic[@"type"] isEqualToString: @"getDeviceType"]) {
        return [self deviceType];
    }
    
    if ([dic[@"type"] isEqualToString: @"isIPhoneX"]) {
        if ([self iphoneType]) {
            return @"true";
        }else{
            return @"false";
        }
    }
    
    if ([dic[@"type"] isEqualToString: @"getBundleID"]) {
        return [[GameSoftDevKit shared]getIAPProductID];
    
    }
    
//    if ([dic[@"type"] isEqualToString: @"getPid"]) {
//
//        return [[GameSoftDevKit shared]getPid];
//
//    }
//
//    if ([dic[@"type"] isEqualToString: @"getGid"]) {
//
//        return [[GameSoftDevKit shared]getGid];
//
//    }
    else if ([dic[@"type"] isEqualToString: @"openURL"]) {
        [[UIApplication sharedApplication] openURL: [NSURL URLWithString: dic[@"url"]]];
        return @"";
    }

    NSString* result = @"";
    if([dic[@"type"] isEqualToString: @"init"]){
        [[GameSoftDevKit shared]initWithParams:dic];
    }else if([dic[@"type"] isEqualToString: @"onEnterGame"]){
        
        [[GameSoftDevKit shared]onEnterGame:dic];
        
    }else if([dic[@"type"] isEqualToString: @"callFacebookShare"]){
        [[GameSoftDevKit shared]callFacebookShare];
      return @"ok";
    }else if([dic[@"type"] isEqualToString: @"callCustomer"]){
        
        [[GameSoftDevKit shared]callCustomer];
        
        return @"ok";
    }else if([dic[@"type"] isEqualToString: @"onLevelup"]){
        [[GameSoftDevKit shared]onLevelup:dic];
//    }else if([dic[@"type"] isEqualToString: @"finishDownloadRes"]){
//        [[GameSoftDevKit shared]finishDownloadRes:dic];
//    }else if([dic[@"type"] isEqualToString: @"finishTutorial"]){
//        [[GameSoftDevKit shared]finishTutorial:dic];
    }else if([dic[@"type"] isEqualToString: @"login"]){
        [[GameSoftDevKit shared]loginWithParams:dic completion:^(NSDictionary * ret) {
            if([ret[@"state"] intValue] == 1){
                cocos2d::LuaBridge::pushLuaFunctionById([ret[@"callLogin"] intValue]);
                cocos2d::LuaBridge::getStack()->pushInt([ret[@"state"] intValue]);
                cocos2d::LuaBridge::getStack()->pushString([ret[@"openid"] UTF8String]);
                cocos2d::LuaBridge::getStack()->pushString("666666");
                cocos2d::LuaBridge::getStack()->executeFunction(3);
                cocos2d::LuaBridge::getStack()->clean();
            }else{
                cocos2d::LuaBridge::pushLuaFunctionById([ret[@"callLogin"] intValue]);
                cocos2d::LuaBridge::getStack()->pushInt([ret[@"state"] intValue]);
                cocos2d::LuaBridge::getStack()->executeFunction(1);
                cocos2d::LuaBridge::getStack()->clean();
            }

        } Andloginoutcallback:^(NSDictionary * dic) {
            NSString *luaString = @"_OnGameAppEvent(\"onLogout\")";
            if (dic[@"flg"] == nil) {
                cocos2d::LuaBridge::getStack()->executeString([luaString UTF8String]);
            }
            else{
                luaString = [NSString stringWithFormat:@"_OnGameAppEvent(\"%@\")", dic[@"flg"]];
                cocos2d::LuaBridge::getStack()->executeString([luaString UTF8String]);
            }
        }];
    }else if([dic[@"type"] isEqualToString: @"logout"]){
        [[GameSoftDevKit shared]loginoutWithParams:dic completion:^(NSDictionary *ret) {
            
        }];
    }else if([dic[@"type"] isEqualToString: @"getVersionName"]){
        NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
         NSString *app_Version = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
        return app_Version;
    }else if([dic[@"type"] isEqualToString: @"qqq"]){
        [[GameSoftDevKit shared]qqqWithParams:dic completion:^(NSDictionary * ret) {
//            NSString* paramsStr = [NSString stringWithFormat:@"%@|%@|%@", ret[@"orderId"], ret[@"receipt"], ret[@"bundleId"]];
//            NSLog(@"支付回调客户端参数:%@", paramsStr);
//            cocos2d::LuaBridge::pushLuaFunctionById([dic[@"payCallback"] intValue]);
//            cocos2d::LuaBridge::getStack()->pushString([paramsStr UTF8String]);
//            cocos2d::LuaBridge::getStack()->executeFunction(1);
//            cocos2d::LuaBridge::getStack()->clean();
        }];
    }else if([dic[@"type"] isEqualToString: @"platformName"]){
        result = @"";
    }else if([dic[@"type"] isEqualToString: @"exitApplication"]){
        UIWindow *window = [UIApplication sharedApplication].delegate.window;
        
        [UIView animateWithDuration:1.0f animations:^{
            window.alpha = 0;
            window.frame = CGRectMake(0, window.bounds.size.width, 0, 0);
        } completion:^(BOOL finished) {
            exit(0);
        }];
    }else if([dic[@"type"] isEqualToString: @"realNameBinding"]){
 
        [[GameSoftDevKit shared]showRealNameBindingWithParams:dic];
    }else if([dic[@"type"] isEqualToString: @"sendToken"]){
        //是否已经注销推送
        [[GameSoftDevKit shared]sendToken:[dic[@"platform"] copy]];
 
    }
    else if([dic[@"type"] isEqualToString: @"openPush"]){
        //打开推送
          [[GameSoftDevKit shared] openPush];
 
    }
    else if([dic[@"type"] isEqualToString: @"closePush"]){
        //关闭推送
        [[GameSoftDevKit shared]closePush];
 
    }
    else if([dic[@"type"] isEqualToString: @"hshn"]){
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        pasteboard.string = dic[@"text"];
    }
    else if([dic[@"type"] isEqualToString: @"checkIsFullScreen"]){
        if(isFullScreen){
            return @"ok";
        }
        else{
            return @"no";
        }
    }

    return result;
}


long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

+(NSString*) getCurrentTime {
    return [NSString stringWithFormat: @"%ld", getCurrentTime()];
}

static BOOL isFirst = true;
+(BOOL) canRecord{
    if (isFirst) {
        isFirst = false;
        return  YES;
    }
    __block BOOL bCanRecord = YES;
    if ([[UIDevice currentDevice] systemVersion] .doubleValue >= 7.0)
    {
        AVAudioSession *audioSession = [AVAudioSession sharedInstance];
        if ([audioSession respondsToSelector:@selector(requestRecordPermission:)]) {
            [audioSession performSelector:@selector(requestRecordPermission:) withObject:^(BOOL granted) {
                if (granted) {
                    bCanRecord = YES;
                } else {
                    bCanRecord = NO;
                }
            }];
        }
    }
    if(bCanRecord == NO){
  //      UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"警告" message:@"应用无录音权限，将影响游戏语音聊天,请在‘设置/隐私/麦克风’开启权限" preferredStyle: UIAlertControllerStyleAlert];
//        [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            //点击按钮的响应事件；
 //       }]];
        
        
        //弹出提示框；
//        [[AppController getUIView ] presentViewController:alert animated:true completion:nil];
        
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
 
        hud.mode = MBProgressHUDModeText;
        hud.label.font = [UIFont systemFontOfSize:13];
        hud.label.text = @"应用无录音权限，将影响游戏语音聊天,请在‘设置/隐私/麦克风’开启权限";
//         hud.label.text = @"應用無錄音權限，將影響遊戲語音聊天,請在‘設置/隱私/麥克風’開啟權限";
        
        dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, 2* NSEC_PER_SEC);
        dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
            // Do something...
            [MBProgressHUD hideHUDForView:[UIApplication sharedApplication].keyWindow animated:YES];
        });
    }
    return bCanRecord;
}



@end
