//
//  GameServer.h
//  SYMiddleware
//
//  Created by sg on 2017/6/21.
//  Copyright © 2017年 sy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GameServer : NSObject
/**
 单例
 
 @return instancetype
 */
+(instancetype)shared;


/**
 初始化sdk网络服务层
 */
-(void)initServer;

/**
 申请订单

 @param dic 回调
 */
-(void) sendAppstore: (NSDictionary*)dic completion: (void(^)(NSDictionary*))completion;

/**
 向服务器发送验证
 
 @param dic 参数
 */
-(void) checkAppstore: (NSDictionary*)dic completion: (void(^)(NSDictionary*))completion;


-(void)setToken:(NSData*)token;

-(void) setPlatform:(NSString*)platform;

-(void) sendToken:(NSString*)deviceTokenStr;
/*
-(void) sendLogin: (NSDictionary*)c completion: (void(^)(NSDictionary*))completion;
-(void)updateRoleInfo:(NSDictionary*)dic;
-(NSString *)getOpenId;
-(NSData*)getToken;
-(NSString*)getAdchannel;
*/
@end
