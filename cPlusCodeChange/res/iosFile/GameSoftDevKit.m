//
//  GameSoftDevKit.m
//  SYMiddleware
//
//  Created by sg on 2017/6/21.
//  Copyright © 2017年 sy. All rights reserved.
//

#import "GameSoftDevKit.h"
#import "GameSoftCaller.h"
#import "GameServer.h"
#import "MBProgressHUD.h"
 

@implementation GameSoftDevKit
/**
 单例
 
 @return instancetype
 */
+(instancetype)shared{
    static GameSoftDevKit*sharedMyManager = nil;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        
        sharedMyManager = [[self alloc] init];
        
    });
    
    return sharedMyManager;
}



/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic{
    
    [[GameServer shared]initServer];
    
    [[GameSoftCaller shared]initWithParams:dic];
    
}


-(void)showSplash: (void(^)(NSDictionary*))completion{
    [[GameSoftCaller shared]showSplash:completion];
}

/**
 登陆
 */
-(void)loginWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion Andloginoutcallback: (void(^)(NSDictionary*))loginoutcallback{
    [[GameSoftCaller shared]loginWithParams:dic completion:completion Andloginoutcallback:loginoutcallback];
}

-(NSString*)getPid{
   return  [[GameSoftCaller shared]getPid];
}
-(NSString*)getGid{
   return [[GameSoftCaller shared]getGid];
}

/**
 实名制
 */
-(void)showRealNameBindingWithParams:(NSDictionary*)dic{
    [[GameSoftCaller shared]showRealNameBindingWithParems:dic];
}

/**
 进入游戏
 */
-(void)onEnterGame:(NSDictionary*)dic{
    [[GameSoftCaller shared] onEnterGameWithParems:dic];
}

/**
 打开客服
 */
-(void)callCustomer{
    [[GameSoftCaller shared]callCustomer];
}

/**
打开facebook
 */
-(void)callFacebookShare{
    [[GameSoftCaller shared]callFacebookShare];
}

/**
 角色升级
 */
-(void)onLevelup:(NSDictionary*)dic{
    [[GameSoftCaller shared ]onLevelup:dic];
}

/**
 资源下载完成
 */
-(void)finishDownloadRes:(NSDictionary*)dic{
    [[GameSoftCaller shared]finishDownloadRes:dic];
}

/**
 新手教程结束
 */
-(void)finishTutorial:(NSDictionary*)dic{
    [[GameSoftCaller shared]finishDownloadRes:dic];
}


/**
 注销
 */
-(void)loginoutWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion{
    [[GameSoftCaller shared]loginoutWithParams:dic completion:completion];
}

-(NSString*)getIAPProductID{
    
    if ( [[GameSoftCaller shared]getIAPProductID].length > 0){
        return [[GameSoftCaller shared]getIAPProductID];
    }else{
        return [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
    }
}

/**
 支付
 */
-(void)qqqWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion{
    
//    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
//    
//    hud.mode = MBProgressHUDModeText;
//    hud.label.font = [UIFont systemFontOfSize:13];
//    hud.label.text = @"申请订单中...";
 
    [[GameSoftCaller shared]qqqWithParams:dic completion:completion];
//    [[GameServer shared]sendAppstore:dic completion:^(NSDictionary *ret) {
//
//        [MBProgressHUD hideHUDForView:[UIApplication sharedApplication].keyWindow animated:YES];
//
//        [[GameSoftCaller shared]qqqWithParams:ret];
//    }];
}


/**
 设置推送
 */
-(void)setPush:(NSData*)data{
    [[GameSoftCaller shared] setPush:data];
}

-(void)sendToken{
    [[GameSoftCaller shared]sendToken];
}

-(void)sendToken:(NSString*)platform{
    [[GameServer shared]setPlatform:platform];
    [[GameSoftCaller shared]sendToken ];
}

/**
 打开推送
 */
-(void)openPush{
    
    [[GameSoftCaller shared] openPush];
   
}

/**
 关闭xg推送
 */
-(void)closePush{
    [[GameSoftCaller shared]closePush];
}

/**
 推送相关
 
 @param application application
 @param userInfo userInfo
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{
    [[GameSoftCaller shared]application:application didReceiveRemoteNotification:userInfo];
}

/**
 收到静默推送的回调
 
 @param application  UIApplication 实例
 @param userInfo 推送时指定的参数
 @param completionHandler 完成回调
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler{
    [[GameSoftCaller shared]application:application didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
}

 

/**
 应用跳转相关
 
 @param url 地址
 */
 
-(void)application:(UIApplication *)application handleOpenURL:(NSURL *)url{
    [[GameSoftCaller shared] application:application handleOpenURL:url];
}

/**
 应用跳转相关
 
 @param url 地址
 */
 
-(void)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
    [[GameSoftCaller shared]application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}
/**
 将要返回应用
 
 @param application 应用
 */
-(void) applicationWillEnterForeground:(UIApplication *)application{
    [[GameSoftCaller shared]applicationWillEnterForeground:application];
}



/**
 已经进入后台
 
 @param application 应用
 */
-(void) applicationDidEnterBackground:(UIApplication *)application{
    [[GameSoftCaller shared]applicationDidEnterBackground:application];
}


/**
 WillResignActive
 
 @param application application
 */
- (void)applicationWillResignActive:(UIApplication *)application{
    [[GameSoftCaller shared]applicationWillResignActive:application];
}

/**
 DidBecomeActive
 
 @param application application
 */
- (void)applicationDidBecomeActive:(UIApplication *)application{
    [[GameSoftCaller shared]applicationDidBecomeActive:application];
}

/**
 applicationWillTerminate
 
 @param application application
 */
- (void)applicationWillTerminate:(UIApplication *)application{
    [[GameSoftCaller shared]applicationWillTerminate:application];
}


- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window{
    return  [[GameSoftCaller shared] application:application supportedInterfaceOrientationsForWindow:window];
}

- (void)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    [[GameSoftCaller shared]application:app openURL:url options:options];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken{
    [[GameSoftCaller shared]application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    [[GameSoftCaller shared]application:application didFailToRegisterForRemoteNotificationsWithError:error];
}

- (void)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray * restorableObjects))restorationHandler{
    [[GameSoftCaller shared]application:application continueUserActivity:userActivity restorationHandler:restorationHandler];
}

/**
 通用方法
 
 @return 返回值
 */
- (NSString*)callAction:(NSDictionary*)action{
    return [[GameSoftCaller shared] callAction:action];
}

@end
