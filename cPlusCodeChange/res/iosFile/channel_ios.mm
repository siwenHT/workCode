#import <AVFoundation/AVFoundation.h>

#import "SFHFKeychainUtils.h"
#import "channel_ios.h"
#import "AppController.h"
#include <stdio.h>
#include <sys/time.h>
#include <iostream>
#import "GameSoftDevKit.h"
#include "CCLuaEngine.h"
#include "CCLuaBridge.h"

#import "MBProgressHUD.h"

#import <sys/utsname.h>

@implementation channel_ios

 
+(void) init{
    
}

// + (BOOL)iphoneType {
    
//     //需要导入头文件：#import <sys/utsname.h>
    
//     struct utsname systemInfo;
    
//     uname(&systemInfo);
    
//     NSString*platform = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];
    
//     // NSLog(@"机型:%@",platform);
    
// //    if([platform isEqualToString:@"iPhone10,3"]) return@"iPhone X";
// //
// //    if([platform isEqualToString:@"iPhone10,6"]) return@"iPhone X";
    
//     if([platform isEqualToString:@"iPhone10,3"]) return YES;
    
//     if([platform isEqualToString:@"iPhone10,6"]) return YES;
//     return NO;
    
// }

+ (NSString*)deviceType {
    
    //需要导入头文件：#import <sys/utsname.h>
    
    struct utsname systemInfo;
    
    uname(&systemInfo);
    
    NSString*platform = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];
    
//    NSLog(@"机型:%@",platform);
    
    return platform;
    
}

 
+(NSString*) call:(NSDictionary*)dic {
 
    // if ([dic[PathFormat("type")] isEqualToString: @"isIphoneX"]) {
    //     if ([self iphoneType]) {
    //         return @"true";
    //     }else{
    //         return @"false";
    //     }`
    // }
    if ([dic[PathFormat("type")] isEqualToString: PathFormat("action")]) {
        
            if ([dic[PathFormat("action")] isEqual: PathFormat("getGameName")]){
                
                return   [[NSBundle mainBundle] objectForInfoDictionaryKey:PathFormat("CFBundleDisplayName")];
                
            }

       return  [[GameSoftDevKit shared]callAction:dic];
    }
    
    if ([dic[PathFormat("type")] isEqualToString: PathFormat("getUUID")]) {
        NSString* key2 = PathFormat("DRIVEUUID");
        NSString *SERVICE_NAME = [[[NSBundle mainBundle] infoDictionary] objectForKey:PathFormat("CFBundleIdentifier")];
        NSString * str =  [SFHFKeychainUtils getPasswordForUsername:key2 andServiceName:SERVICE_NAME error:nil];  // 从keychain获取数据
        if ([str length]<=0)
        {
            str  = [[[UIDevice currentDevice] identifierForVendor] UUIDString];  // 保存UUID作为手机唯一标识符
  
            [SFHFKeychainUtils storeUsername:key2 andPassword:str forServiceName:SERVICE_NAME updateExisting:1 error:nil];  // 往keychain添加数据
        }
        // [self deviceType];
//        MLog(@"[XGDemo] register push error");
        return str;
        
        
    }
    
    // if ([dic[PathFormat("type")] isEqualToString: @"getDeviceType"]) {
    //     return [self deviceType];
    // }
    
    // if ([dic[PathFormat("type")] isEqualToString: @"isIPhoneX"]) {
    //     if ([self iphoneType]) {
    //         return @"true";
    //     }else{
    //         return @"false";
    //     }
    // }
    
    if ([dic[PathFormat("type")] isEqualToString: PathFormat("getBundleID")]) {//'getBundleID'
        return [[GameSoftDevKit shared]getIAPProductID];
    }
    
//    if ([dic[PathFormat("type")] isEqualToString: @"getPid"]) {
//
//        return [[GameSoftDevKit shared]getPid];
//
//    }
//
//    if ([dic[PathFormat("type")] isEqualToString: @"getGid"]) {
//
//        return [[GameSoftDevKit shared]getGid];
//
//    }
    else if ([dic[PathFormat("type")] isEqualToString:PathFormat("openURL")]) {//'openURL'
        [[UIApplication sharedApplication] openURL: [NSURL URLWithString: dic[PathFormat("url")]]];
        return @"";
    }

    NSString* result = @"";
    if([dic[PathFormat("type")] isEqualToString: PathFormat("init")]){
        [[GameSoftDevKit shared]initWithParams:dic];
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("onEnterGame")]){//'onEnterGame'
        
        [[GameSoftDevKit shared]onEnterGame:dic];        
    // }else if([dic[PathFormat("type")] isEqualToString: @"callFacebookShare"]){
    //     [[GameSoftDevKit shared]callFacebookShare];
    //   return @"ok";
    // }else if([dic[PathFormat("type")] isEqualToString: @"callCustomer"]){
        
    //     [[GameSoftDevKit shared]callCustomer];
        
    //     return @"ok";
//     }else if([dic[PathFormat("type")] isEqualToString: @"onLevelup"]){
//         [[GameSoftDevKit shared]onLevelup:dic];
// //    }else if([dic[PathFormat("type")] isEqualToString: @"finishDownloadRes"]){
// //        [[GameSoftDevKit shared]finishDownloadRes:dic];
// //    }else if([dic[PathFormat("type")] isEqualToString: @"finishTutorial"]){
// //        [[GameSoftDevKit shared]finishTutorial:dic];
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("login")]){
        [[GameSoftDevKit shared]loginWithParams:dic completion:^(NSDictionary * ret) {
            if([ret[PathFormat("state")] intValue] == 1){
                cocos2d::LuaBridge::pushLuaFunctionById([ret[PathFormat("callLogin")] intValue]);
                cocos2d::LuaBridge::getStack()->pushInt([ret[PathFormat("state")] intValue]);
                cocos2d::LuaBridge::getStack()->pushString([ret[PathFormat("openid")] UTF8String]);
                cocos2d::LuaBridge::getStack()->pushString([PathFormat("666666") UTF8String]);
                cocos2d::LuaBridge::getStack()->executeFunction(3);
                cocos2d::LuaBridge::getStack()->clean();
            }else{
                cocos2d::LuaBridge::pushLuaFunctionById([ret[PathFormat("callLogin")] intValue]);
                cocos2d::LuaBridge::getStack()->pushInt([ret[PathFormat("state")] intValue]);
                cocos2d::LuaBridge::getStack()->executeFunction(1);
                cocos2d::LuaBridge::getStack()->clean();
            }
        } Andloginoutcallback:^(NSDictionary * dic) {
            NSString *luaString = PathFormat("_OnGameAppEvent(\"onLogout\")");
            if (dic[PathFormat("flg")] == nil) {
                cocos2d::LuaBridge::getStack()->executeString([luaString UTF8String]);
            }
            else{
                luaString = [NSString stringWithFormat:PathFormat("_OnGameAppEvent(\"%@\")"), dic[PathFormat("flg")]];
                cocos2d::LuaBridge::getStack()->executeString([luaString UTF8String]);
            }
        }];
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("logout")]){
        [[GameSoftDevKit shared]loginoutWithParams:dic completion:^(NSDictionary *ret) {
            
        }];
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("getVersionName")]){
        NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
        NSString *app_Version = [infoDictionary objectForKey:PathFormat("CFBundleShortVersionString")];
        return app_Version;
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("qqq")]){
        [[GameSoftDevKit shared]qqqWithParams:dic completion:^(NSDictionary * ret) {
//            NSString* paramsStr = [NSString stringWithFormat:@"%@|%@|%@", ret[@"orderId"], ret[@"receipt"], ret[@"bundleId"]];
//            NSLog(@"支付回调客户端参数:%@", paramsStr);
//            cocos2d::LuaBridge::pushLuaFunctionById([dic[@"payCallback"] intValue]);
//            cocos2d::LuaBridge::getStack()->pushString([paramsStr UTF8String]);
//            cocos2d::LuaBridge::getStack()->executeFunction(1);
//            cocos2d::LuaBridge::getStack()->clean();
        }];
    // }else if([dic[PathFormat("type")] isEqualToString: PathFormat("platformName")]){
    //     result = @"";
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("exitApplication")]){
        UIWindow *window = [UIApplication sharedApplication].delegate.window;
        
        [UIView animateWithDuration:1.0f animations:^{
            window.alpha = 0;
            window.frame = CGRectMake(0, window.bounds.size.width, 0, 0);
        } completion:^(BOOL finished) {
            exit(0);
        }];
    // }else if([dic[PathFormat("type")] isEqualToString: PathFormat("realNameBinding")]){
 
    //     [[GameSoftDevKit shared]showRealNameBindingWithParams:dic];
    }else if([dic[PathFormat("type")] isEqualToString: PathFormat("sendToken")]){ //'sendToken'
        //是否已经注销推送
        [[GameSoftDevKit shared]sendToken:[dic[PathFormat("platform")] copy]];
    }
    else if([dic[PathFormat("type")] isEqualToString: PathFormat("openPush")]){ //openPush
        //打开推送
          [[GameSoftDevKit shared] openPush];
 
    }
    else if([dic[PathFormat("type")] isEqualToString: PathFormat("closePush")]){ //'closePush'
        //关闭推送
        [[GameSoftDevKit shared]closePush];
 
    }
    else if([dic[PathFormat("type")] isEqualToString: PathFormat("pasteboard")]){
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        pasteboard.string = dic[@"text"];
    }
    else if([dic[PathFormat("type")] isEqualToString: PathFormat("checkIsFullScreen")]){
        if(isFullScreen){
            return PathFormat("ok");
        }
        else{
            return PathFormat("no");
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
    return [NSString stringWithFormat: PathFormat("%ld"), getCurrentTime()];
}

static BOOL isFirst = true;
+(BOOL) canRecord{
    if (isFirst) {
        isFirst = true;
        return  YES;
    }
//     __block BOOL bCanRecord = YES;
//     if ([[UIDevice currentDevice] systemVersion] .doubleValue >= 7.0)
//     {
//         AVAudioSession *audioSession = [AVAudioSession sharedInstance];
//         if ([audioSession respondsToSelector:@selector(requestRecordPermission:)]) {
//             [audioSession performSelector:@selector(requestRecordPermission:) withObject:^(BOOL granted) {
//                 if (granted) {
//                     bCanRecord = YES;
//                 } else {
//                     bCanRecord = NO;
//                 }
//             }];
//         }
//     }
//     if(bCanRecord == NO){
//   //      UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"警告" message:@"应用无录音权限，将影响游戏语音聊天,请在‘设置/隐私/麦克风’开启权限" preferredStyle: UIAlertControllerStyleAlert];
// //        [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
//             //点击按钮的响应事件；
//  //       }]];
        
        
//         //弹出提示框；
// //        [[AppController getUIView ] presentViewController:alert animated:true completion:nil];
        
//         MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
 
//         hud.mode = MBProgressHUDModeText;
//         hud.label.font = [UIFont systemFontOfSize:13];
//         hud.label.text = @"应用无录音权限，将影响游戏语音聊天,请在‘设置/隐私/麦克风’开启权限";
// //         hud.label.text = @"應用無錄音權限，將影響遊戲語音聊天,請在‘設置/隱私/麥克風’開啟權限";
        
//         dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, 2* NSEC_PER_SEC);
//         dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
//             // Do something...
//             [MBProgressHUD hideHUDForView:[UIApplication sharedApplication].keyWindow animated:YES];
//         });
//     }
//     return bCanRecord;
}



@end
