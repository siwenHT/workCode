#import "GameSoftCaller.h"
#import "GameServer.h"
#import "JSON.h"

#import "XGPush.h"
#import "ShatterSubmesh_Cyclerefraction.h"

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
#import <UserNotifications/UserNotifications.h>
#endif

static NSString * GameID = @"1125";
static NSString * packetid = @"1001125001";
static BOOL isSDKTest = NO;
static NSString * iapProductId = @"polka.candle.money";

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
    NSLog(@"%s, result %@, error %@", __FUNCTION__, isSuccess?@"OK":@"NO", error);
}

- (void)xgPushDidFinishStop:(BOOL)isSuccess error:(NSError *)error {
    NSLog(@"%s, result %@, error %@", __FUNCTION__, isSuccess?@"OK":@"NO", error);
}

- (void)xgPushDidRegisteredDeviceToken:(NSString *)deviceToken error:(NSError *)error {
    NSLog(@"%s, result %@, error %@", __FUNCTION__, error?@"NO":@"OK", error);
}

// iOS 10 新增 API
// iOS 10 会走新 API, iOS 10 以前会走到老 API
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
// App 用户点击通知
// App 用户选择通知中的行为
// App 用户在通知中心清除消息
// 无论本地推送还是远程推送都会走这个回调
- (void)xgPushUserNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    NSLog(@"[XGDemo] click notification");
    if ([response.actionIdentifier isEqualToString:@"xgaction001"]) {
        NSLog(@"click from Action1");
    } else if ([response.actionIdentifier isEqualToString:@"xgaction002"]) {
        NSLog(@"click from Action2");
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
    NSLog(@"%s, result %@, error %@", __FUNCTION__, error?@"NO":@"OK", error);
}

/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic {
    if (callback==nil) {
        callback = [[SDKCallback alloc]init];
    }
    [[XGPush defaultManager] setEnableDebug:YES];
    [[XGPush defaultManager] startXGWithAppID:2200331971 appKey:@"I88SI4M7L2RU" delegate:self];
    // 清除角标
    if ([XGPush defaultManager].xgApplicationBadgeNumber > 0) {
        [[XGPush defaultManager] setXgApplicationBadgeNumber:0];
    }
    [[XGPush defaultManager] reportXGNotificationInfo:dic[@"launchOptions"]];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(registerDeviceFailed) name:@"registerDeviceFailed" object:nil];
    [[ShatterSubmesh_Cyclerefraction shareShatterSubmesh_Cyclerefraction] ShatterSubmesh_Cyclerefraction_IAPRestore:^(NSString *buDanJieGuo, NSString *buDanDingDanID, int buDanDingDanJinE) {
        
        NSLog(@"\n补单交易支付结果=%@\n拇指订单号=%@\n支付金额=%d", buDanJieGuo, buDanDingDanID, buDanDingDanJinE);
    }];
    NSLog(@"初始化调用");
}

-(void)showSplash: (void(^)(NSDictionary*))completion{
    [[GameSoftCaller shared] showSplashImg:@"showImg.png" completion:^(NSDictionary*){
        [[GameSoftCaller shared] showSplashImg:(NSString *)@"splash.jpg" completion:completion];
        
    } ];
}

- (void)registerDeviceFailed {
    NSLog(@"registerDeviceFailed.....");
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
    NSLog(@"开始登陆");
    callLogin = [dic[@"callback"] intValue];
    //***********************************************************登录***********************************************************/
    [[ShatterSubmesh_Cyclerefraction shareShatterSubmesh_Cyclerefraction] ShatterSubmesh_Cyclerefraction_LoginWithGameID:GameID andTouTiaoAppID:@"162088" andLandscapeMode:TRUE andLoginResult:^(NSString *loginUserID, NSString *loginUserName, NSString *loginSign, NSString *loginTimestamp) {
        
        if (callLogin > 0)
        {
            NSMutableDictionary * dic = [[NSMutableDictionary alloc] init];
            dic[@"openid"] = loginUserID;
            dic[@"state"] = @"1";
            dic[@"callLogin"] = [NSString stringWithFormat:@"%d", callLogin];
        
            [[XGPushTokenManager defaultTokenManager] bindWithIdentifier:loginUserID type:XGPushTokenBindTypeAccount];
            if (sdklogin)
            {
                sdklogin(dic);
            }
            NSLog(@"\n用户ID=%@\n用户名=%@\n签名=%@\n时间戳=%@", loginUserID, loginUserName, loginSign, loginTimestamp);
        }
        
        callLogin = 0;
    }];
    
    NSLog(@"结束登陆");
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
    
    userId     = [dic[@"roleId"] copy] ;
    roleName   = [dic[@"roleName"]copy] ;
    roleLv     = [dic[@"lv"]copy] ;
    vipLevel   = [dic[@"vipLevel"]copy] ;
    serverId   = [dic[@"serverId"]copy] ;
    serverName = [dic[@"serverName"]copy] ;
    //[[GameServer shared]updateRoleInfo:dic];
    partyName = [dic[@"factionName"] copy];
    //***********************************************************进入游戏***********************************************************//
    [[ShatterSubmesh_Cyclerefraction shareShatterSubmesh_Cyclerefraction] ShatterSubmesh_Cyclerefraction_RoleInfoSynchronizeWithRoleId:userId andRoleName:roleName andRoleLevel:roleLv andRoleVipLevel:vipLevel andServerId:serverId andServerName:serverName andAESKEY:@"VpMz6IeA2olb2DvV" andAESAPIKEY:@"VpMz6IeA2olb2DvV" roleSynchronizeResult:^(NSString *roleSynchronizeResult, NSString *roleSynchronizeMessage) {
        MLog(@"同步结果=%@,信息=%@", roleSynchronizeResult, roleSynchronizeMessage);
    }];

    NSLog(@"上报角色完成");
 

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
 
    if (ret[@"orderID"]==nil) {
        MLog(@"orderID 不存在!!");
        return;
    }
    
    if (ret[@"serverID"]==nil) {
        MLog(@"serverID 不存在!!");
        return;
    }
    
    if (ret[@"roleLev"]==nil) {
        MLog(@"roleLev 不存在!!");
        return;
    }
    
    if (ret[@"roleId"]==nil) {
        MLog(@"roleId 不存在!!");
        return;
    }
    
    if (ret[@"money"]==nil) {
        MLog(@"money 不存在!!");
        return;
    }

    NSString *productId = [NSString stringWithFormat:@"%@%d", iapProductId, [ret[@"money"] intValue]];
    NSString* orderID = [NSString stringWithFormat:@"%@", ret[@"orderID"]];
    NSString* roleId = [NSString stringWithFormat:@"%@", ret[@"roleId"]];
    int serverID =  [ret[@"serverID"] intValue];
    int roleLev = [ret[@"roleLev"] intValue];
    NSLog(@"获取订单ID %@",orderID);

    
    //money = 0.1f;
    //***********************************************************支付***********************************************************//
    [[ShatterSubmesh_Cyclerefraction shareShatterSubmesh_Cyclerefraction] ShatterSubmesh_Cyclerefraction_IAPWithProductID:productId andCPOrderID:orderID andCPServerID:serverID andCPRoleID:roleId andCPRoleLevel:roleLev andCPTokenURL:nil andAppleIAPResult:^(NSString *IAPPaymentResult, NSString *IAPOrderID, int IAPOrderAmount) {
            MLog(@"\n交易支付结果=%@\n订单号=%@\n金额=%d", IAPPaymentResult, IAPOrderID, IAPOrderAmount);
    }];
    //***********************************************************支付***********************************************************//
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"registerDeviceFailed" object:nil];}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{
    [[XGPush defaultManager] reportXGNotificationInfo:userInfo];
}
@end
