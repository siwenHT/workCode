//
//  MoviePlayer.m
//  happy
//
//  Created by 曾 哲 on 14-2-13.
//
//

#import "MoviePlayerHelper.h"
#import "SysInfoOC.h"
#include "CCLuaBridge.h"


static MPMoviePlayerController *mppc;
//static UIButton *btn;

@interface SkipTouchLayer : UIView @end

@implementation SkipTouchLayer

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    
    if (mppc) {
        [mppc stop];
    }
    
}

@end


static SkipTouchLayer *skpl;

@implementation MoviePlayerHelper



+(void)playMovieWithFile:(NSString *)path{
    NSArray *sz= [path componentsSeparatedByString:@"."];
    NSString *filePath=[[NSBundle mainBundle] pathForResource:[sz objectAtIndex:0] ofType:[sz objectAtIndex:1]];
    if (filePath==nil){
        NSLog(@"影片不存在");
        int scriptHandler =[[SysInfoOC getInstance] getScriptHandler];
        cocos2d::LuaBridge::pushLuaFunctionById(scriptHandler);
        cocos2d::LuaBridge::getStack()->executeFunction(0);
        cocos2d::LuaBridge::getStack()->clean();
        return;
    }
    mppc=[[MPMoviePlayerController alloc] initWithContentURL:[NSURL fileURLWithPath:filePath]];
    [mppc setControlStyle:MPMovieControlStyleNone];
    
    [mppc setScalingMode:MPMovieScalingModeAspectFill];
    
    
    CGSize size = [[UIScreen mainScreen] bounds].size;
    //scale_screen=1 为普屏幕，scale_screen=2 为视网膜屏幕
    size=CGSizeMake(MAX(size.width,size.height), MIN(size.width, size.height));//io7 横屏兼容
    CGFloat scale_screen = [UIScreen mainScreen].scale;
    
    int width;
    int height;
    if (scale_screen==1) {
        width=(int)size.width*scale_screen; //全宽
        height=(int)size.height*scale_screen; //全高
    }else{
        width=(int)size.width*scale_screen/2; //半宽
        height=(int)size.height*scale_screen/2; //半高
    }
    
    [mppc.view setFrame:CGRectMake(0, 0, width, height)];
    
    
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    [window.rootViewController.view addSubview:mppc.view];
    skpl=[[SkipTouchLayer alloc] initWithFrame:CGRectMake(0, 0, width, height)] ;
    [window.rootViewController.view addSubview:skpl];
    
//    btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
 //   btn.frame = CGRectMake(width*0.87, height*0.90, 60, 30);
//    [btn setTitle:@"点击跳过" forState:UIControlStateNormal];
//    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
//    [btn addTarget:self action:@selector(tiaoGuoAction:) forControlEvents:UIControlEventTouchUpInside];
//    [window.rootViewController.view  addSubview:btn];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(myMovieFinishedCallback:)
                                                 name:MPMoviePlayerPlaybackDidFinishNotification
                                               object:mppc];
    
    [mppc play];
}


+(void)tiaoGuoAction:(id) sender{

    NSLog(@"跳过视频播放");
   
//    [btn removeFromSuperview];
    
    [mppc stop];
    
    

}


+(void)myMovieFinishedCallback:(NSNotification*)notify

{
//    [btn removeFromSuperview];
    //视频播放对象
    MPMoviePlayerController* theMovie = [notify object];
    
    //销毁播放通知
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:MPMoviePlayerPlaybackDidFinishNotification
                                                  object:theMovie];
    [theMovie.view removeFromSuperview];
    // 释放视频对象
    [theMovie release];
    
    [skpl removeFromSuperview];
    [skpl release];
    
    int scriptHandler =[[SysInfoOC getInstance] getScriptHandler];
    cocos2d::LuaBridge::pushLuaFunctionById(scriptHandler);
    cocos2d::LuaBridge::getStack()->executeFunction(0);
    cocos2d::LuaBridge::getStack()->clean();
}



@end
