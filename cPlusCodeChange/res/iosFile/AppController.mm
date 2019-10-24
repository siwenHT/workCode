/****************************************************************************
 Copyright (c) 2010-2013 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#import <UIKit/UIKit.h>
#import "cocos2d.h"
#import "GameSoftDevKit.h"
#import "AppController.h"
#import "AppDelegate.h"
#import "RootViewController.h"
#import "platform/ios/CCEAGLView-ios.h"

#import "textureManager/TextureManager.h"

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0

@interface AppController()
@end
#endif

@implementation AppController

#pragma mark -
#pragma mark Application lifecycle

static RootViewController * view = nullptr;
static AppController* ac = nullptr;

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
 
    cocos2d::Application *app = cocos2d::Application::getInstance();
    app->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();

    // Override point for customization after application launch.

    // Add the view controller's view to the window and display.
	CGRect rect = [[UIScreen mainScreen] bounds];
		
	if (isFullScreen)
	{
		rect.origin.x    = StatusBarHeight - 13;
		rect.size.width  = rect.size.width - StatusBarHeight + 13;
		// rect.size.height = rect.size.height - 21;
	}

	_window = [[UIWindow alloc] initWithFrame: rect ];
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: [_window bounds]
                                     pixelFormat: (NSString*)cocos2d::GLViewImpl::_pixelFormat
                                     depthFormat: cocos2d::GLViewImpl::_depthFormat
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0 ];

    [eaglView setMultipleTouchEnabled:YES];
    
    // Use RootViewController manage CCEAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = eaglView;
    viewController.navigationController.navigationBar.barStyle = UIBarStyleBlack;
    
    view = viewController;
    ac = self;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [_window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [_window setRootViewController:viewController];
    }
    
    [_window makeKeyAndVisible];

 
    //设置隐藏顶部状态栏
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    //设置禁止自动锁屏功能
    [[UIApplication sharedApplication] setIdleTimerDisabled: YES];
    //设置下载文件夹不自动备份到iCloud
    std::string l_strDocumentDir = cocos2d::FileUtils::getInstance()->getWritablePath();
    l_strDocumentDir.append([PathFormat("files") UTF8String]);
    NSString* l_strDownloadDir = [NSString stringWithUTF8String:l_strDocumentDir.c_str()];
    NSError* l_error;
    if (![[NSFileManager defaultManager] fileExistsAtPath:l_strDownloadDir]){
        [[NSFileManager defaultManager] createDirectoryAtPath:l_strDownloadDir withIntermediateDirectories:NO attributes:nil error:&l_error]; //Create folder
        // exclude downloads from iCloud backup
        NSURL *url = [NSURL fileURLWithPath:l_strDownloadDir];
        if([[[UIDevice currentDevice] systemVersion] floatValue] > 5.1){
            if ([url setResourceValue:[NSNumber numberWithBool:YES] forKey:NSURLIsExcludedFromBackupKey error:&l_error] == NO) {
                // NSLog(@"Error: Unable to exclude l_strDownloadDir from backup: %@", l_error);
                NSLog(PathFormat("Error: %@"),l_error);
            }
        }
    }

    //sdk启动
    NSMutableDictionary * dic = [[NSMutableDictionary alloc] init];
    dic[PathFormat("type")] = PathFormat("init");
    dic[PathFormat("launchOptions")] = launchOptions==nil?[[NSDictionary alloc]init]:launchOptions;
    
    [[GameSoftDevKit shared] initWithParams:dic ];
    
 
    // IMPORTANT: Setting the GLView should be done after creating the RootViewController
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView(eaglView);
    cocos2d::Director::getInstance()->setOpenGLView(glview);

    [[GameSoftDevKit shared]showSplash:^(NSDictionary *) {
            app->run();
    }];
 
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    
    cocos2d::Director::getInstance()->pause();
    
    [[GameSoftDevKit shared]applicationWillResignActive:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::Application::getInstance()->applicationWillEnterForeground();
    cocos2d::Director::getInstance()->resume();
    [[GameSoftDevKit shared]applicationDidBecomeActive:application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::Application::getInstance()->applicationDidEnterBackground();
    [[GameSoftDevKit shared]  applicationDidEnterBackground:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    // cocos2d::Application::getInstance()->applicationWillEnterForeground();
    [[GameSoftDevKit shared]  applicationWillEnterForeground:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
    
    [[GameSoftDevKit shared]applicationWillTerminate:application];
}



-(BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url{
    [[GameSoftDevKit shared] application:application handleOpenURL:url];
    return YES;
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
    [[GameSoftDevKit shared]  application:application  openURL:url sourceApplication:sourceApplication annotation:annotation];
    return YES;
}


- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
{
    [[GameSoftDevKit shared]application:app openURL:url options:options];
    return YES;
}

- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    // return UIInterfaceOrientationMaskAll;
    // 个人建议使用这个函数，不开放UpsideDown权限，具体原因参考下面第一个链接
    [[GameSoftDevKit shared]application:application supportedInterfaceOrientationsForWindow:window];
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

+(RootViewController*)getUIView{
    return view;
}

+(AppController*) getInstance{
    return ac;
}


//***********************************推送相关*************************************************//

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    
    [[GameSoftDevKit shared] setPush:deviceToken];
    
    [[GameSoftDevKit shared]application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
    
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    // NSLog(@"[XGDemo] register APNS fail.\n[XGDemo] reason : %@", error);
    
    [[GameSoftDevKit shared]application:application didFailToRegisterForRemoteNotificationsWithError:error];
}


/**
 收到通知的回调
 
 @param application  UIApplication 实例
 @param userInfo 推送时指定的参数
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
//    NSLog(@"[XGDemo] receive Notification");
    
    [[GameSoftDevKit shared]application:application didReceiveRemoteNotification:userInfo];
 
}


/**
 收到静默推送的回调
 
 @param application  UIApplication 实例
 @param userInfo 推送时指定的参数
 @param completionHandler 完成回调
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    
    [[GameSoftDevKit shared]application:application didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
    

}


//***********************************推送相关*************************************************//

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray * restorableObjects))restorationHandler
{
    [[GameSoftDevKit shared]application:application continueUserActivity:userActivity restorationHandler:restorationHandler];
    return YES;
}

#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
//     cocos2d::Director::getInstance()->purgeCachedData();
    cocos2d::TextureManager::getInstance()->doGC(5);
}

- (void)dealloc {
    [super dealloc];
}

static int strCfgList[] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,49,50,51,52,53,54,55,56,57,48,47,95,64,35,37,42,46};

+ (NSString*) getStrByIdx:(int) idx{
    return [NSString stringWithFormat:@"%c", strCfgList[idx]];
}

+ (NSString*) splitJoinString:(int) value,...{
    NSString* ret = [self getStrByIdx:value];
    //指向变参的指针
    va_list list;
    //使用第一个参数来初使化list指针
    va_start(list, value);
    while (YES)
    {
        //返回可变参数，va_arg第二个参数为可变参数类型，如果有多个可变参数，依次调用可获取各个参数
        int number = va_arg(list, int);
        if (number == -1) {
           break;
        }
        
        NSString* tmp = [self getStrByIdx:number];
        ret = [ret stringByAppendingString:tmp];
    }
    //结束可变参数的获取
    va_end(list);
    return ret;
}

+ (NSString*) convertHexStrToString:(NSString *)hexString{
    if (!hexString || [hexString length] == 0) {
        return nil;
    }
    // NSLog(@"line : %d, func: %s ",__LINE__, __func__);
    char *myBuffer = (char *)malloc((int)[hexString length] / 2 + 1);
    bzero(myBuffer, [hexString length] / 2 + 1);
    for (int i = 0; i < [hexString length] - 1; i += 2) {
        unsigned int anInt;
        NSString * hexCharStr = [hexString substringWithRange:NSMakeRange(i, 2)];
        NSScanner * scanner = [[[NSScanner alloc] initWithString:hexCharStr] init];
        [scanner scanHexInt:&anInt];
        myBuffer[i / 2] = (char)anInt;
    }
    NSString *unicodeString = [NSString stringWithCString:myBuffer encoding:4];
    // NSLog(@"%@------字符串=======%@",hexString ,unicodeString);
    return unicodeString;
}

@end

