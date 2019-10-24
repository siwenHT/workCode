//
//  GameCaller.m
//  direnjie
//
//  Created by sg on 2017/6/30.
//
//

#import "GameCaller.h"
#import "GameServer.h"
#import "AppController.h"
//#import "XGPush.h"
//#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
//#import <UserNotifications/UserNotifications.h>
//#endif

@implementation GameCaller

/**
 单例
 
 @return instancetype
 */
+(instancetype)shared{
    static GameCaller*sharedMyManager = nil;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        
        sharedMyManager = [[self alloc] init];
        
    });
    
    return sharedMyManager;
}


/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic {

}

-(void)showSplash: (void(^)(NSDictionary*))completion{
    
    UIImage *image = [UIImage imageNamed:PathFormat("splash.jpg")];
    
    if (image == nil) {
         completion(@{});
    }else{
       
        UIImageView *splashImageView = [[UIImageView alloc]initWithImage:image];
        
        splashImageView.alpha = 0;
        splashImageView.frame = [UIScreen mainScreen].bounds;
        [ [UIApplication sharedApplication].keyWindow addSubview:splashImageView];
        [UIView animateWithDuration:2 animations:^{
            splashImageView.alpha = 1.0;
        } completion:^(BOOL finished) {
            completion(@{});
            [UIView animateWithDuration:1 animations:^{
               splashImageView.alpha = 0;
            } completion:^(BOOL finished) {
                [splashImageView removeFromSuperview];
            }];
        }];

    }
    
}

/**
 登陆
 */
-(void)loginWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion Andloginoutcallback: (void(^)(NSDictionary*))loginoutcallback{
   
}


-(NSString*)getPid{
    return @"";
}
-(NSString*)getGid{
    return @"";
}
/**
 实名制
 */
-(void)showRealNameBindingWithParems:(NSDictionary*)dic{
  
}


/**
 进入游戏
 */
-(void)onEnterGameWithParems:(NSDictionary*)dic{
    
}

/**
 打开客服
 */
-(void)callCustomer{
}

/**
 打开facebook
 */
-(void)callFacebookShare{
}

/**
 角色升级
 */
-(void)onLevelup:(NSDictionary*)dic{
    
}

/**
 资源下载完成
 */
-(void)finishDownloadRes:(NSDictionary*)dic{
    
}

/**
 新手教程结束
 */
-(void)finishTutorial:(NSDictionary*)dic{
    
}


/**
 注销
 */
-(void)loginoutWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion {
    
}

-(NSString*)getIAPProductID{
    return @"";
}


/**
 支付
 */
-(void)qqqWithParams:(NSDictionary*)ret completion: (void(^)(NSDictionary*))completion{
    
}


/**
 设置推送
 */
-(void)setPush:(NSData*)data{
  
}

-(void)sendToken{
   
}

/**
 打开推送
 */
-(void)openPush{
    
   
    
}

-(void)sendxgPush{
    
    
}



/**
 关闭xg推送
 */
-(void)closePush{
//   [[XGPush defaultManager] stopXGNotification];
}

/**
 推送相关
 
 @param application application
 @param userInfo userInfo
 */
-(void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{

}


/**
 收到静默推送的回调
 
 @param application  UIApplication 实例
 @param userInfo 推送时指定的参数
 @param completionHandler 完成回调
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
   
}


/**
 应用跳转相关
 
 @param url 地址
 */
 
-(void)application:(UIApplication *)application handleOpenURL:(NSURL *)url{
    
}

/**
 应用跳转相关
 
 @param url 地址
 */
-(void)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
    
}

/**
 将要返回应用
 
 @param application 应用
 */
-(void) applicationWillEnterForeground:(UIApplication *)application{
   
}



/**
 已经进入后台
 
 @param application 应用
 */
-(void) applicationDidEnterBackground:(UIApplication *)application{
    
}

/**
 WillResignActive
 
 @param application application
 */
- (void)applicationWillResignActive:(UIApplication *)application{
    
}

/**
 DidBecomeActive
 
 @param application application
 */
- (void)applicationDidBecomeActive:(UIApplication *)application{
    
}

/**
 applicationWillTerminate
 
 @param application application
 */
- (void)applicationWillTerminate:(UIApplication *)application{
    
}


- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window{
    
     return UIInterfaceOrientationMaskAllButUpsideDown;
}

- (void)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken{
    
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{

}

- (void)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray * restorableObjects))restorationHandler{
    
}


/**
 通用方法
 
 @return 返回值
 */
- (NSString*)callAction:(NSDictionary*)action{
    return @"";
}
@end
