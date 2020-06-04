//
//  GameSoftCaller.h
//  direnjie
//
//  Created by sg on 2017/6/22.
//
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import "GameCaller.h"
//#import "../../Common/IAPManager/IAPManager.h"

@interface GameSoftCaller : GameCaller //<IAPManagerDelegate>

-(void)qqqWithParams:(NSDictionary*)ret completion: (void(^)(NSDictionary*))completion;
-(void)loginoutWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion;
-(void)onEnterGameWithParems:(NSDictionary*)dic;
-(void)loginWithParams:(NSDictionary*)dic completion: (void(^)(NSDictionary*))completion Andloginoutcallback: (void(^)(NSDictionary*))loginoutcallback;
-(void)initWithParams:(NSDictionary*)dic;

-(void)showSplash: (void(^)(NSDictionary*))completion;
@end
