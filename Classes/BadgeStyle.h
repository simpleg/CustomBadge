/*
 
 ------------------------------------------------------------------------------------
 BadgeStyle.h
 ------------------------------------------------------------------------------------
 CustomBadge Version 3 comes with better separation between style and rendering.
 This class provides all informtion (Colors, Options, Font, ...) for the drawing
 The drawing itself happens in the "CustomBadge.m" class
 ------------------------------------------------------------------------------------
 
 The MIT License (MIT)
 
 Copyright (c) 2014 Sascha Paulus
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 */


#import <TargetConditionals.h>

#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#import <UIKit/UIKit.h>
#else
#import <APPKit/AppKit.h>
#endif

typedef enum : NSUInteger {
    BadgeStyleFontTypeHelveticaNeueMedium,
    BadgeStyleFontTypeHelveticaNeueLight,
} BadgeStyleFontType;

@interface BadgeStyle : NSObject {
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
    UIColor *badgeTextColor;
    UIColor *badgeInsetColor;
    UIColor *badgeFrameColor;
#else
    NSColor *badgeTextColor;
    NSColor *badgeInsetColor;
    NSColor *badgeFrameColor;
#endif
    BOOL badgeFrame;
    BOOL badgeShining;
    BadgeStyleFontType badgeFontType;

}
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
@property(nonatomic, strong) UIColor *badgeTextColor;
@property(nonatomic, strong) UIColor *badgeInsetColor;
@property(nonatomic, strong) UIColor *badgeFrameColor;
#else
@property(nonatomic, strong) NSColor *badgeTextColor;
@property(nonatomic, strong) NSColor *badgeInsetColor;
@property(nonatomic, strong) NSColor *badgeFrameColor;
#endif
@property(nonatomic) BadgeStyleFontType badgeFontType;
@property(nonatomic) BOOL badgeFrame;
@property(nonatomic) BOOL badgeShining;
@property(nonatomic) BOOL badgeShadow;


+ (BadgeStyle*) defaultStyle;
+ (BadgeStyle*) oldStyle;
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
+ (BadgeStyle*) freeStyleWithTextColor:(UIColor*)textColor withInsetColor:(UIColor*)insetColor withFrameColor:(UIColor*)frameColor withFrame:(BOOL)frame withShadow:(BOOL)shadow withShining:(BOOL)shining withFontType:(BadgeStyleFontType)fontType;
#else
+ (BadgeStyle*) freeStyleWithTextColor:(NSColor*)textColor withInsetColor:(NSColor*)insetColor withFrameColor:(NSColor*)frameColor withFrame:(BOOL)frame withShadow:(BOOL)shadow withShining:(BOOL)shining withFontType:(BadgeStyleFontType)fontType;
#endif


@end

