//
//  CCommonMacroDefinition.h
//  MobilePortal
//
//  Created by Uncle.Chen on 12/7/15.
//  Copyright © 2015 BONC. All rights reserved.
//

#ifndef CCommonMacroDefinition_h
#define CCommonMacroDefinition_h

#pragma mark - keychain
/// keychain
#define __KEYCHAINLOGINID [[[KeychainItemWrapper alloc]initWithIdentifier:@"LOGIN_USER" accessGroup:nil] objectForKey:(__bridge id)kSecAttrAccount]
#define __KEYCHAINPASSWORD [[[KeychainItemWrapper alloc]initWithIdentifier:@"LOGIN_USER" accessGroup:nil] objectForKey:(__bridge id)kSecValueData]
#define __KEYCHAINGESTUREPASSWORD [[[KeychainItemWrapper alloc]initWithIdentifier:@"GESTUREPASSWORD" accessGroup:nil] objectForKey:(__bridge id)kSecValueData]
#define __KEYCHAINUUID [[[KeychainItemWrapper alloc]initWithIdentifier:@"UUID" accessGroup:nil] objectForKey:(__bridge id)kSecValueData]

#pragma mark - Toast
/// on navigationController view
#define __TOAST(info, positionValue) [[[CAPPLICATION navController] view] makeToast:info duration:1.0f position:positionValue]
/// on self
#define __SELFTOAST(info, positionValue) [self makeToast:info duration:1.0f position:positionValue]

#pragma mark - size
/// NavBar高度
#define __NAVIGATIONBARHEIGHT 44

/// 获取屏幕 宽度、高度
#define __SCREENWIDTH ([UIScreen mainScreen].bounds.size.width)
#define __SCREENHEIGHT ([UIScreen mainScreen].bounds.size.height)

#pragma mark - system
/// 获取系统版本
#define __SYSTEMVERSION [[[UIDevice currentDevice] systemVersion] floatValue]

#pragma mark - memory
/// 释放一个对象
#define __RELEASE(P) if(P) {[P release], P = nil;}
/// weak self
#define __WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
/// strong self
#define __SS(strongSelf)  __strong __typeof(&*weakSelf)strongSelf = weakSelf;
/// weak target
#define __WT(weakTarget, target)  __weak __typeof(&*target)weakTarget = target;

#pragma mark - image
/// 读取本地图片
#define __LOADIMAGE(file, type) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]

/// 定义UIImage对象
#define __IMAGENAME(p) [UIImage imageNamed:p]

#praga mark - color
/// rgb颜色转换（16进制->10进制）
#define __UICOLORFROMRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/// 带有RGBA的颜色设置
#define __RGBCOLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

/// 清除背景色
#define __CLEARCOLOR [UIColor clearColor]

#pragma mark - font
/// 系统字体
#define __SYSTEMFONT(s) [UIFont systemFontOfSize:s]
/// 自定义字体
#define __FONT(font, s) [UIFont fontWithName:font size:s]

#pragma mark - GCD
/// 异步global_queue
#define __ASYNCGLOBALQUEUE(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
/// 异步main_queue
#define __ASYNCMAINQUEUE(block) dispatch_async(dispatch_get_main_queue(),block)

#pragma mark - string
/// 日期转换，date 转换成 string
#define __DATETOSTRING(form, value) ({\
NSDateFormatter *formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:form];\
[formatter stringFromDate:value];\
});
/// 日期转换，string 转换成 date
#define __STRINGTODATE(form, value) ({\
NSDateFormatter *formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:form];\
[formatter dateFromString:value];\
});
/// 日期转换，sting间转换，change form2 to form1
#define __STRINGTOSTRING(form1, form2, value) ({\
NSDateFormatter *formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:form1];\
[formatter stringFromDate:({\
NSDateFormatter *formatter = [[NSDateFormatter alloc] init];\
[formatter setDateFormat:form2];\
[formatter dateFromString:value];\
})];\
});

#endif /* CCommonMacroDefinition_h */
