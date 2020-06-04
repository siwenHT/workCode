//
//  GameSoftDevKit.h
//  SYMiddleware
//
//  Created by sg on 2017/6/21.
//  Copyright © 2017年 sy. All rights reserved.
//

#import <UIKit/UIKit.h>
 
@interface GameSoftDevKit : NSObject


/**
 单例

 @return instancetype
 */
+(instancetype)shared;


/**
 闪屏图

 @param completion 回调
 */
-(void)showSplash: (void(^)(NSDictionary*))completion;


/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic;


/**
 登陆
 */
-(void)loginWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion Andloginoutcallback: (void(^)(NSDictionary*))loginoutcallback;

-(NSString*)getPid;
-(NSString*)getGid;
/**
 实名制
 */
-(void)showRealNameBindingWithParams:(NSDictionary*)dic;


/**
 进入游戏
 */
-(void)onEnterGame:(NSDictionary*)dic;

/**
 打开客服
 */
-(void)callCustomer;

/**
 打开facebook
 */
-(void)callFacebookShare;

/**
 角色升级
 */
-(void)onLevelup:(NSDictionary*)dic;

/**
 资源下载完成
 */
-(void)finishDownloadRes:(NSDictionary*)dic;

/**
 新手教程结束
 */
-(void)finishTutorial:(NSDictionary*)dic;


/**
 注销
 */
-(void)loginoutWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion;


-(NSString*)getIAPProductID;


/**
 支付
 */
-(void)qqqWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion;


/**
 设置推送
 */
-(void)setPush:(NSData*)data;


-(void)sendToken;

-(void)sendToken:(NSString*)platform;

/**
 打开推送
 */
-(void)openPush;


/**
 关闭xg推送
 */
-(void)closePush;


/**
        推送相关

 @param application application
 @param userInfo userInfo
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 收到静默推送的回调
 
 @param application  UIApplication 实例
 @param userInfo 推送时指定的参数
 @param completionHandler 完成回调
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

 
/**
 应用跳转相关

 @param url 地址
 */
//-(void) handleOpenURL:(NSURL *)url;
-(void)application:(UIApplication *)application handleOpenURL:(NSURL *)url;

/**
 应用跳转相关

 @param url 地址
 */
//-(void) openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
-(void)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
/**
 将要返回应用

 @param application 应用
 */
-(void) applicationWillEnterForeground:(UIApplication *)application;


/**
 已经进入后台

 @param application 应用
 */
-(void) applicationDidEnterBackground:(UIApplication *)application;



/**
 WillResignActive

 @param application application
 */
- (void)applicationWillResignActive:(UIApplication *)application;

/**
 DidBecomeActive
 
 @param application application
 */
- (void)applicationDidBecomeActive:(UIApplication *)application;


/**
 applicationWillTerminate

 @param application application
 */
- (void)applicationWillTerminate:(UIApplication *)application;


- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window;

- (void)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options;

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

- (void)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray * restorableObjects))restorationHandler;


/**
 通用方法

 @return 返回值
 */
- (NSString*)callAction:(NSDictionary*)action;
@end
