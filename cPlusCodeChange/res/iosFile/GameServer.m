//
//  GameServer.m
//  SYMiddleware
//
//  Created by sg on 2017/6/21.
//  Copyright © 2017年 sy. All rights reserved.
//

#import "GameServer.h"
#import "JSON.h"
#import "NSString+EX.h"
 

@interface GameServer()
@property(nonatomic,strong)NSString*openId;
@end

@implementation GameServer
/**
 单例
 
 @return instancetype
 */
+(instancetype)shared{
    static GameServer*sharedMyManager = nil;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        
        sharedMyManager = [[self alloc] init];
        
           });
    
    return sharedMyManager;
}

/**
 初始化sdk网络服务层
 */
-(void)initServer{
}
 

-(void) sendAppstore: (NSDictionary*)dic completion: (void(^)(NSDictionary*))completion{
}


-(void) checkAppstore: (NSDictionary*)dic completion: (void(^)(NSDictionary*))completion{
}


-(void) check2Appstore: (NSDictionary*)dic completion: (void(^)(NSDictionary*))completion{
}


/*
-(void) sendLogin: (NSDictionary*)c completion: (void(^)(NSDictionary*))completion {
}

-(void)updateRoleInfo:(NSDictionary*)dic{
}

-(void) setPlatform:(NSString*)platform{
}

-(void) setToken:(NSData*)token{
}

-(void) sendToken:(NSString*)deviceTokenStr{
    
}

-(NSString *)getOpenId{
    return _openId;
}
-(NSData*)getToken{
    return _p_device_token;
}

-(NSString*)getAdchannel{
    return _version_channel;
}
*/
@end
