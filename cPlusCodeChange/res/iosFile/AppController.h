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


#import "GameSoftDevKit.h"

#define kScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define kScreenHeight ([UIScreen mainScreen].bounds.size.height)
#define  isIphoneX_XS     (((kScreenWidth == 375.f && kScreenHeight == 812.f) || (kScreenHeight == 375.f && kScreenWidth == 812.f)) ? YES : NO)
#define  isIphoneXR_XSMax    (((kScreenWidth == 414.f && kScreenHeight == 896.f)||(kScreenHeight == 414.f && kScreenWidth == 896.f)) ? YES : NO)
#define   isFullScreen    (isIphoneX_XS || isIphoneXR_XSMax)
// Status bar height.
#define  StatusBarHeight     (isFullScreen ? 44.f : 20.f)
// Navigation bar height.
#define  NavigationBarHeight  44.f
// Tabbar height.
#define  TabbarHeight         (isFullScreen ? (49.f+34.f) : 49.f)
// Tabbar safe bottom margin.
#define  TabbarSafeBottomMargin         (isFullScreen ? 34.f : 0.f)
// Status bar & navigation bar height.
#define  StatusBarAndNavigationBarHeight  (isFullScreen ? 88.f : 64.f)

@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate>
{

    //UIWindow *window;

    RootViewController *viewController;
}
@property(nonatomic,strong)UIWindow* window;
+(RootViewController*) getUIView;
+(AppController*) getInstance;
 
@end

