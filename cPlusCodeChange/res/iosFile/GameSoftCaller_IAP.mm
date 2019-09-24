#import "GameSoftCaller.h"
#import "GameServer.h"
#import "JSON.h"
#import <GameKit/GameKit.h>
#import <GameplayKit/GameplayKit.h>
#import <NotificationCenter/NotificationCenter.h>
#import <StoreKit/StoreKit.h>
#import "MBProgressHUD.h"
#import "../../Common/IAPManager/IAPManager.h"
#import "../../Category/NSString+EX.h"

#include "CCLuaEngine.h"
#include "CCLuaBridge.h"

static NSString * iapProductId = @"hkd.reds.dea";

static int callLogin = 0;

typedef  void(^sdkCallback)(NSDictionary*);
static sdkCallback sdklogin = nil;
static sdkCallback sdkloginout = nil;

static NSString* serverId = nil;
static NSString* serverName = nil;
static NSString* partyName = nil;
static NSString* userId = nil;
static NSString* gRoleId = nil;
static NSString* serverUrl = nil;
static NSString* roleName = nil;
static NSString* roleLv = nil;
static NSString* vipLevel = nil;

BOOL _hasInit;
BOOL _hasLoginOnce;
NSString* _lastPlayerId;
static int qqqOkCB = 0;
static sdkCallback qqqOkCallBack = nil;
NSString* gameOrderID = nil;

@interface SDKCallback : NSObject
@end

@implementation SDKCallback

#pragma mark -
#pragma mark - Notifications

@end

static SDKCallback *callback = nil;

@implementation GameSoftCaller

- (void)successedWithReceipt:(SKPaymentTransaction *)transaction{
    if (serverUrl && ![serverUrl isEqualToString:@""]){
        NSString* bundleId = [NSBundle mainBundle].bundleIdentifier;
        NSURL *receiptURL = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receiptData = [NSData dataWithContentsOfURL:receiptURL];
        NSString *receiptString=[receiptData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
        //除去receiptdata中的特殊字符
//        NSString *receipt1=[receiptString stringByReplacingOccurrencesOfString:@"\n" withString:@""];
//        NSString *receipt2=[receipt1 stringByReplacingOccurrencesOfString:@"\r" withString:@""];
//        NSString *receipt3=[receipt2 stringByReplacingOccurrencesOfString:@"+" withString:@"%2B"];
       
        NSString* orderId = [transaction.payment.applicationUsername copy];
        
        NSMutableDictionary * dic = [[NSMutableDictionary alloc] init];
        dic[@"receipt"] = receiptString;
        dic[@"orderId"] = orderId;
        dic[@"bundleId"] = bundleId;
        dic[@"transactionId"] = transaction.transactionIdentifier;
        dic[@"roleId"] = gRoleId;
        dic[@"price"] = [transaction.payment.productIdentifier stringByReplacingOccurrencesOfString:iapProductId withString:@""];
        [self checkAppstore:dic];
    }
}

-(void) checkAppstore:(NSDictionary*)dic {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        if (serverUrl == nil || [serverUrl isEqualToString:@""]) {
            NSLog(@"还是没有服务器地址，不能验证订单！");
            return;
        }
        
        NSString* url1 = [NSString stringWithFormat: @"https://sandbox.itunes.apple.com/verifyReceipt"];
        NSString* body = [NSString stringWithFormat: @"{\"receipt-data\" : \"%@\"}", dic[@"receipt"]];

        NSData *bodyData = [body dataUsingEncoding:NSUTF8StringEncoding];
        
        //创建请求到苹果官方进行购买验证
        NSURL *url=[NSURL URLWithString:url1];
        NSMutableURLRequest *requestM=[NSMutableURLRequest requestWithURL:url];
        requestM.HTTPBody=bodyData;
        requestM.HTTPMethod=@"POST";
        NSLog(@"验证订单 %@", dic[@"orderId"]);
        
        //创建连接并发送同步请求
        NSError *error=nil;
        NSData *responseData=[NSURLConnection sendSynchronousRequest:requestM returningResponse:nil error:&error];
        if (error) {
            MLog(@"AppStore 验证过程中发生错误，错误信息：%@",error.localizedDescription);
            return;
        }
        NSDictionary *ret=[NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingAllowFragments error:nil];
        MLog(@"ret = %@",ret);
        
        if([ret[@"status"] intValue] == 0){
            MLog(@"AppStore 验证成功！");
            
            [self gotoServer:dic];
        }else{
            MLog(@"AppStore 验证失败，未通过验证！");
            [[IAPManager sharedManager] checkOldTransaction:nil oId:dic[@"orderId"]];
        }
    });
}

-(void)gotoServer:(NSDictionary*)dic {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        if (serverUrl == nil || [serverUrl isEqualToString:@""]) {
            NSLog(@"还是没有服务器地址，不能验证订单！");
            return;
        }
        NSDate *datenow = [NSDate date];//现在时间,你可以输出来看下是什么格式
        NSString *signKey = @"cff283af381d3ed2d7235789345701e";
        NSString *timeSp = [NSString stringWithFormat:@"%ld", (long)[datenow timeIntervalSince1970]];
        
        NSString* sign = [[NSString stringWithFormat:@"%@%@%@", dic[@"roleId"], timeSp, signKey] md5];
        NSString* url1 = [NSString stringWithFormat: @"http://%@/apple/recharge",serverUrl];
        NSString* body = [NSString stringWithFormat: @"combineId=%@&time=%@&sign=%@&orderId=%@&receipt=%@&bundleId=%@&transactionId=%@&price=%@", dic[@"roleId"], timeSp, sign, dic[@"orderId"], dic[@"receipt"], dic[@"bundleId"], dic[@"transactionId"], dic[@"price"]];

        NSData *bodyData = [body dataUsingEncoding:NSUTF8StringEncoding];
        
        //创建请求到苹果官方进行购买验证
        NSURL *url=[NSURL URLWithString:url1];
        NSMutableURLRequest *requestM=[NSMutableURLRequest requestWithURL:url];
        requestM.HTTPBody=bodyData;
        requestM.HTTPMethod=@"POST";
        NSLog(@"向服务器验证订单 %@", dic[@"orderId"]);
        
        //创建连接并发送同步请求
        NSError *error=nil;
        NSData *responseData=[NSURLConnection sendSynchronousRequest:requestM returningResponse:nil error:&error];
        if (error) {
            MLog(@"服务器验证过程中发生错误，错误信息：%@",error.localizedDescription);
            return;
        }
        NSDictionary *ret=[NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingAllowFragments error:nil];
        MLog(@"ret = %@",ret);
        if([ret[@"Result"] intValue]==1){
            MLog(@"服务器 验证成功！");

            [[IAPManager sharedManager] checkOldTransaction:nil oId:dic[@"orderId"]];
        }else{
            MLog(@"服务器，未通过验证！");
            [[IAPManager sharedManager] checkOldTransaction:nil oId:dic[@"orderId"]];
        }
    });
}


- (void)failedPurchaseWithError:(NSString *)errorDescripiton{
    NSLog(@"购买失败:%@", errorDescripiton);
}

//用户变更检测
-(void)registerFoeAuthenticationNotificatio{
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(authenticationChanged) name:GKPlayerAuthenticationDidChangeNotificationName object:nil];
}

-(void)authenticationChanged{
    NSLog(@"authenticationChanged called");
    if([GKLocalPlayer localPlayer].isAuthenticated){
        if (_lastPlayerId != nil){
            if (sdkloginout){
                NSMutableDictionary * dic2 = [[NSMutableDictionary alloc] init];
                dic2[@"flg"] = @"onLogout";
                
                sdkloginout(dic2);
            }
        }
        
        _lastPlayerId = [GKLocalPlayer localPlayer].playerID;
    }else{
        MLog("[authenticationChanged] no login");
    }
}

-(void)getProductInfo{
    
}


/**
 初始化sdk
 */
-(void)initWithParams:(NSDictionary*)dic {
    if (callback){
        if (sdkloginout){
            NSMutableDictionary * dic2 = [[NSMutableDictionary alloc] init];
            dic2[@"flg"] = @"showLoginTips";

            sdkloginout(dic2);
            return;
        }
    }
    
    if (callback==nil) 
    {
        callback = [[SDKCallback alloc]init];
    }
    
    [self registerFoeAuthenticationNotificatio];
    [self initPlayHandle];
    [IAPManager sharedManager].delegate = self;
    NSLog(@"初始化调用");
}

-(void)showSplash: (void(^)(NSDictionary*))completion{
    [[GameSoftCaller shared] showSplashImg:@"shanp.png" completion:^(NSDictionary*){
        [[GameSoftCaller shared] showSplashImg:(NSString *)@"splash.jpg" completion:completion];
    } ];
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

-(void)initPlayHandle{
    MLog(@"[initPlayHandle] called");
    GKLocalPlayer * localPlayer = [GKLocalPlayer localPlayer];
    [localPlayer setAuthenticateHandler:^(UIViewController * _Nullable viewController, NSError * _Nullable error){
        if (viewController) {
            UIViewController * rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
            [rootViewController presentViewController:viewController animated:YES completion:nil];
        } else {
            if ([GKLocalPlayer localPlayer].authenticated) {
                NSLog(@"\n initPlayHandle succ 回调了 playId=%@\n", [GKLocalPlayer localPlayer].playerID);
            } else {
                if (error){
                    MLog(@"\n登陆gameCenter错误，error=%ld,desc=%@", (long)error.code, error.description);
//                    if ((long)error.code == 2){
//                        UIViewController * rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
//                        [rootViewController presentViewController:viewController animated:YES completion:nil];
//                    }
                }else{
                    MLog(@"\n登陆Game Center登出了或者未知错误");
                }
            }
        }
    }];
}

-(void)getSignature
{
    // 如果还没有登录，特殊处理
    if (![GKLocalPlayer localPlayer].authenticated){
        NSMutableDictionary * dic2 = [[NSMutableDictionary alloc] init];
        dic2[@"flg"] = @"showLoginTips";
        //玩家还没有登录GameCenter，切到后台再切回来登陆，或者去Game Center登陆。
        sdkloginout(dic2);
        //[self initPlayHandle];
        MLog(@"还没有登陆，提示去登陆");
        return;
    }
    
    GKLocalPlayer *localPlayer = [GKLocalPlayer localPlayer];
    [localPlayer generateIdentityVerificationSignatureWithCompletionHandler:^(NSURL *publicKeyUrl, NSData *signature, NSData *salt, uint64_t timestamp, NSError *error)
     {
         if(error != nil)
         {
             MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
         
             hud.mode = MBProgressHUDModeText;
             hud.label.font = [UIFont systemFontOfSize:18];
             hud.label.text = @"获取登陆账号信息错误,请重启游戏！";
             MLog(@"\n获取登陆账号信息错误，error=%ld,desc=%@", (long)error.code, error.description);
           
             return;
         }
         
         NSString* url = [publicKeyUrl absoluteString];
         NSString* sig = [NSString stringWithFormat:@"%@", [signature base64EncodedStringWithOptions: 0]];
         NSString* slt = [NSString stringWithFormat:@"%@", [salt base64EncodedStringWithOptions: 0]];
         NSString* stamp = [NSString stringWithFormat:@"%llu", timestamp];
         NSString* playerId = [GKLocalPlayer localPlayer].playerID;
         NSString* bundleId = [NSBundle mainBundle].bundleIdentifier;
         
         NSString* data = [NSString stringWithFormat:@"%@|%@|%@|%@|%@|%@", playerId, sig, slt, stamp, url, bundleId];
         NSLog(@"%@", data);
         
         if (callLogin > 0)
         {
             NSMutableDictionary * dic = [[NSMutableDictionary alloc] init];
             dic[@"openid"] = [GKLocalPlayer localPlayer].playerID;
             dic[@"state"] = @"1";
             dic[@"callLogin"] = [NSString stringWithFormat:@"%d", callLogin];
             
             if (sdklogin)
             {
                 sdklogin(dic);
             }
             NSLog(@"\n gameCenter ID=%@\n", dic[@"openid"]);
         }
         
         callLogin = 0;
     }];
}

/**
 登陆
 */
-(void)loginWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion Andloginoutcallback: (void(^)(NSDictionary*))loginoutcallback{
    sdklogin = completion;
    sdkloginout = loginoutcallback;
    NSLog(@"开始登陆");
    callLogin = [dic[@"callback"] intValue];
    
    [self getSignature];
//
    //***********************************************************登录***********************************************************//

    NSLog(@"结束登陆");
}

-(NSString*)getPid{
    return @"partnerID";
}

-(NSString*)getGid{
    return @"11";
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
    userId = [dic[@"userId"] copy] ;
    if(roleName)
        roleName = nil;
    roleName = [dic[@"roleName"]copy] ;
    
    vipLevel =  [dic[@"vipLevel"]copy] ;
    roleLv = [dic[@"lv"]copy] ;
 
    serverId = [dic[@"serverId"]copy] ;
    serverName = [dic[@"serverName"]copy] ;
    [[GameServer shared]updateRoleInfo:dic];
    partyName = [dic[@"factionName"] copy];
    
    serverUrl = [dic[@"serverUrl"] copy];
    gRoleId = [dic[@"roleId"] copy];
    
    if (serverUrl && ![serverUrl isEqualToString:@""]){
        [[IAPManager sharedManager] checkOldTransaction:nil oId:nil];
    }
    
    //***********************************************************进入游戏***********************************************************//
/*
    //creatRoleInfo                 2
    //upgradeRoleInfo           4
    //submitRoleInfo
    NSString *sceneType = [dic[@"sceneType"] copy];
    NSLog(@"上报角色类型 message=%@", sceneType);
    NSLog(@"上报角色 message=%@", dic);
    NSDictionary* dic1 = [NSDictionary dictionaryWithObjectsAndKeys:userId, @"roleId", roleName, @"roleName", roleLv, @"roleLevel", @"无帮派", @"partyName",@"0",@"balance",@"0",@"vip",serverId,@"zoneId",serverName, @"zoneName",@"1212121",@"roleCTime",@"1212121",@"roleLevelMTime",nil];
//    NSLog(@"上报角色 message=%@", dic1);
    NSError* error1;
    NSData* jsonData1 = [NSJSONSerialization dataWithJSONObject:dic1 options:NSJSONWritingPrettyPrinted error:&error1];
    NSString* roleData1 = [[NSString alloc] initWithData:jsonData1 encoding: NSUTF8StringEncoding];
    if ( [dic[@"sceneType"] intValue] == 2 ) {
        //[YiJieOnlineHelper setData:@"createrole" :roleData1];
    }else if ( [dic[@"sceneType"] intValue] == 1 ) {
        //[YiJieOnlineHelper setRoleData:roleData1];
        //[YiJieOnlineHelper setData:@"enterServer" :roleData1];
        NSLog(@"上报角色信息");
    }else if ( [dic[@"sceneType"] intValue] == 4 ) {
        //[YiJieOnlineHelper setData:@"levelup" :roleData1];
        
    }else{
       
    }
    NSLog(@"上报角色完成");
   */

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
-(void)qqqWithParams:(NSDictionary*)ret completion:(void(^)(NSDictionary*))completion{
 
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
    
    gRoleId = [ret[@"roleId"] copy];
    serverUrl = [ret[@"serverUrl"] copy];
    int serverID =  [ret[@"serverID"] intValue];
    int roleLev = [ret[@"roleLev"] intValue];
    NSLog(@"获取订单ID %@",orderID);
    
    gameOrderID = orderID;
    qqqOkCB = [ret[@"payCallback"] intValue];
    NSLog(@"qqqOkCallBack  set value======================");
    [[IAPManager sharedManager] requestProducts:productId andExtend:orderID];

    //money = 0.1f;
    //***********************************************************支付***********************************************************//
//    [[srcs_palace_srcs tengcent_sharesrcs_palace_srcs] srcs_palace_srcs_zhiFuWithShangPinID:productId
//                                                                             andCPDingDanID:orderID
//                                                                             andCPQuFuID:serverID
//                                                                             andCPJueSeID:roleId
//                                                                             andCPJueSeDengJi:roleLev
//                                                                             andCPHuiDioaURL:nil
//     andZhiFuHuiDiao:^(NSString *zhiFuJieGuo,NSString *dingDanID, int dingDanJinE) {
//        
//        NSLog(@"\n当前交易支付结果=%@\n拇指订单号=%@\n支付金额=%d", zhiFuJieGuo, dingDanID, dingDanJinE);
//        
//    }];
    //***********************************************************支付***********************************************************//
}
@end
