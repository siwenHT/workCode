#import <Foundation/Foundation.h>

@interface channel_ios : NSObject

+(NSString*) call:(NSDictionary*)dic;
 
+(NSString*) getCurrentTime;

+(BOOL) canRecord;

@end
