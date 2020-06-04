#import "GameSoftCaller.h"
#import "GameServer.h"
#import "JSON.h"
#import "AppController.h"
#import "XGPush.h"
#import "DDFBSDK.h"

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
#import <UserNotifications/UserNotifications.h>
#endif

static NSString * GameID = @"1185";
static NSString * iapProductId = @"an.ywl.";

static int callLogin = 0;
static NSString* serverId = nil;
static NSString* serverName = nil;
static NSString* partyName = nil;
static NSString* userId = nil;
static NSString* roleName = nil;
static NSString* roleLv = nil;
static NSString* vipLevel = nil;

typedef  void(^sdkCallback)(NSDictionary*);
sdkCallback sdklogin = nil;
sdkCallback sdkloginout = nil;
@interface GameSoftCaller ()<XGPushDelegate>

@end

@interface SDKCallback : NSObject
@end

@implementation SDKCallback

#pragma mark -
#pragma mark - Notifications

@end

static SDKCallback *callback = nil;

@implementation GameSoftCaller
#pragma mark - XGPushDelegate
- (void)xgPushDidFinishStart:(BOOL)isSuccess error:(NSError *)error {
    NSLog(PathFormat("%s, result %@, error %@"), __FUNCTION__, isSuccess?PathFormat("OK"):PathFormat("NO"), error);
}

- (void)xgPushDidFinishStop:(BOOL)isSuccess error:(NSError *)error {
    NSLog(PathFormat("%s, result %@, error %@"), __FUNCTION__, isSuccess?PathFormat("OK"):PathFormat("NO"), error);
}

- (void)xgPushDidRegisteredDeviceToken:(NSString *)deviceToken error:(NSError *)error {
    NSLog(PathFormat("%s, result %@, error %@"), __FUNCTION__, error?PathFormat("NO"):PathFormat("OK"), error);
}

// iOS 10 新增 API
// iOS 10 会走新 API, iOS 10 以前会走到老 API
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
// App 用户点击通知
// App 用户选择通知中的行为
// App 用户在通知中心清除消息
// 无论本地推送还是远程推送都会走这个回调
- (void)xgPushUserNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    // NSLog(@"[XGDemo] click notification");
    if ([response.actionIdentifier isEqualToString:PathFormat("xgaction001")]) {
        NSLog(PathFormat("click from Action1"));
    } else if ([response.actionIdentifier isEqualToString:PathFormat("xgaction002")]) {
        NSLog(PathFormat("click from Action2"));
    }
    
    [[XGPush defaultManager] reportXGNotificationResponse:response];
    
    completionHandler();
}

// App 在前台弹通知需要调用这个接口
//- (void)xgPushUserNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
//    [[XGPush defaultManager] reportXGNotificationInfo:notification.request.content.userInfo];
//    completionHandler(UNNotificationPresentationOptionBadge | UNNotificationPresentationOptionSound | UNNotificationPresentationOptionAlert);
//}
#endif
/**
 统一收到通知消息的回调
 @param notification 消息对象
 @param completionHandler 完成回调
 @note SDK 3.2.0+
 */
- (void)xgPushDidReceiveRemoteNotification:(id)notification withCompletionHandler:(void (^)(NSUInteger))completionHandler {
    if ([notification isKindOfClass:[NSDictionary class]]) {
        [[XGPush defaultManager] reportXGNotificationInfo:(NSDictionary *)notification];
        completionHandler(UIBackgroundFetchResultNewData);
    } else if ([notification isKindOfClass:[UNNotification class]]) {
        [[XGPush defaultManager] reportXGNotificationInfo:((UNNotification *)notification).request.content.userInfo];
        completionHandler(UNNotificationPresentationOptionBadge | UNNotificationPresentationOptionSound | UNNotificationPresentationOptionAlert);
    }
}

- (void)xgPushDidSetBadge:(BOOL)isSuccess error:(NSError *)error {
    NSLog(PathFormat("%s, result %@, error %@"), __FUNCTION__, error?PathFormat("NO"):PathFormat("OK"), error);
}

/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic {
    if (callback==nil) {
        callback = [[SDKCallback alloc]init];
    }
    [[XGPush defaultManager] setEnableDebug:NO];
    [[XGPush defaultManager] startXGWithAppID:2200346193 appKey:@"IAH29ZS2Y81R" delegate:self];
    // 清除角标
    if ([XGPush defaultManager].xgApplicationBadgeNumber > 0) {
        [[XGPush defaultManager] setXgApplicationBadgeNumber:0];
    }
    [[XGPush defaultManager] reportXGNotificationInfo:dic[PathFormat("launchOptions")]];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(registerDeviceFailed) name:PathFormat("registerDeviceFailed") object:nil];
    [[DDFBSDK shareDDFBSDK]DDFBSDK_IAPRestore:^(NSString *IAPPaymentResult, NSString *IAPOrderID, int IAPOrderAmount) {
        
    }];
}

-(void)showSplash: (void(^)(NSDictionary*))completion{
    [[GameSoftCaller shared] showSplashImg:PathFormat("showImg.png") completion:^(NSDictionary*){ 
        [[GameSoftCaller shared] showSplashImg:(NSString *)PathFormat("splash.jpg") completion:completion]; 
        
    } ];
}

- (void)registerDeviceFailed {
    NSLog(PathFormat("registerDeviceFailed....."));
}

-(void)showSplashImg:(NSString*)imgstr completion:(void(^)(NSDictionary*))completion{
    
    UIImage *image = [UIImage imageNamed:imgstr];
    
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
    sdklogin = completion;
    sdkloginout = loginoutcallback;
    // NSLog(@"开始登陆");
    callLogin = [dic[PathFormat("callback")] intValue];
    //***********************************************************登录***********************************************************/
    [[DDFBSDK shareDDFBSDK] DDFBSDK_LoginWithGameID:GameID andTouTiaoAppID:@"168590" andLandscapeMode:TRUE andLoginResult:^(NSString *loginUserID, NSString *loginUserName, NSString *loginSign, NSString *loginTimestamp) {
         NSMutableDictionary * dic = [[NSMutableDictionary alloc] init];
         dic[PathFormat("openid")] = loginUserID;
         dic[PathFormat("state")] = @"1";
         dic[PathFormat("callLogin")] = [NSString stringWithFormat:@"%d", callLogin];
        
         [[XGPushTokenManager defaultTokenManager] bindWithIdentifier:loginUserID type:XGPushTokenBindTypeAccount];
         if (sdklogin)
         {
             sdklogin(dic);
         }
     
         callLogin = 0;
    }];
    
    // NSLog(@"结束登陆");
}

-(NSString*)getPid{
    return iapProductId;
}
-(NSString*)getGid{
    return GameID;
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
    if(userId)
        userId = nil;
    if(roleName)
        roleName = nil;
    
    userId     = [dic[PathFormat("roleId")] copy] ; 
    roleName   = [dic[PathFormat("roleName")]copy] ; 
    roleLv     = [dic[PathFormat("lv")]copy] ;
    vipLevel   = [dic[PathFormat("vipLevel")]copy] ; 
    serverId   = [dic[PathFormat("serverId")]copy] ; 
    serverName = [dic[PathFormat("serverName")]copy] ; 
    //[[GameServer shared]updateRoleInfo:dic];
    partyName = [dic[PathFormat("factionName")] copy]; 
    //***********************************************************进入游戏***********************************************************//
    [[DDFBSDK shareDDFBSDK]DDFBSDK_RoleInfoSynchronizeWithRoleId:userId andRoleName:roleName andRoleLevel:roleLv andRoleVipLevel:vipLevel andServerId:serverId andServerName:serverName andAESKEY:@"MAI7ryVqNHlO90ri" andAESAPIKEY:@"MAI7ryVqNHlO90ri" roleSynchronizeResult:^(NSString *roleSynchronizeResult, NSString *roleSynchronizeMessage) {
        
    }];

    // NSLog(@"上报角色完成");
 

      //***********************************************************进入游戏***********************************************************//
}

/**
 注销
 */
-(void)loginoutWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion {
    
    //***********************************************************注销***********************************************************//
    if (sdkloginout) {
        sdkloginout(@{});
    }

    //***********************************************************注销**********************************************************//
}

-(NSString*)getIAPProductID{
    return iapProductId;
}

/**
 支付
 */
-(void)qqqWithParams:(NSDictionary*)ret  completion: (void(^)(NSDictionary*))completion{
 
    if (ret[PathFormat("orderID")]==nil) {
        // MLog(@"orderID error!!");
        return;
    }
    
    if (ret[PathFormat("serverID")]==nil) {
        // MLog(@"serverID error!!");
        return;
    }
    
    if (ret[PathFormat("roleLev")]==nil) {
        // MLog(@"roleLev error!");
        return;
    }
    
    if (ret[PathFormat("roleId")]==nil) {
        // MLog(@"roleId error!!");
        return;
    }
    
    if (ret[PathFormat("money")]==nil) {
        // MLog(@"money error!!");
        return;
    }

    NSString *productId = [NSString stringWithFormat:PathFormat("%@%d"), iapProductId, [ret[PathFormat("money")] intValue]];
    NSString* orderID = [NSString stringWithFormat:PathFormat("%@"), ret[PathFormat("orderID")]];
    NSString* roleId = [NSString stringWithFormat:PathFormat("%@"), ret[PathFormat("roleId")]];
    int serverID =  [ret[PathFormat("serverID")] intValue];
    int roleLev = [ret[PathFormat("roleLev")] intValue];
    // NSLog(@"获取订单ID %@",orderID);

    
    //***********************************************************支付***********************************************************//
    [[DDFBSDK shareDDFBSDK] DDFBSDK_IAPWithProductID:productId andCPOrderID:orderID andCPServerID:serverID andCPRoleID:roleId andCPRoleLevel:roleLev andCPTokenURL:nil andAppleIAPResult:^(NSString *IAPPaymentResult, NSString *IAPOrderID, int IAPOrderAmount) {
    }];
    //***********************************************************支付***********************************************************//
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    [[NSNotificationCenter defaultCenter] postNotificationName:PathFormat("registerDeviceFailed") object:nil];}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{
    [[XGPush defaultManager] reportXGNotificationInfo:userInfo];
}
@end
