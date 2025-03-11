// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef DARWIN_COMMON_LYNX_BASE_AUTO_GEN_LYNXCSSTYPE_H_
#define DARWIN_COMMON_LYNX_BASE_AUTO_GEN_LYNXCSSTYPE_H_

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, LynxWhiteSpaceType) {
  LynxWhiteSpaceNormal = 0,  // version:1.0
  LynxWhiteSpaceNowrap = 1,  // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxTextOverflowType) {
  LynxTextOverflowClip = 0,      // version:1.0
  LynxTextOverflowEllipsis = 1,  // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxFontWeightType) {
  LynxFontWeightNormal = 0,  // version:1.0
  LynxFontWeightBold = 1,    // version:1.0
  LynxFontWeight100 = 2,     // version:1.0
  LynxFontWeight200 = 3,     // version:1.0
  LynxFontWeight300 = 4,     // version:1.0
  LynxFontWeight400 = 5,     // version:1.0
  LynxFontWeight500 = 6,     // version:1.0
  LynxFontWeight600 = 7,     // version:1.0
  LynxFontWeight700 = 8,     // version:1.0
  LynxFontWeight800 = 9,     // version:1.0
  LynxFontWeight900 = 10,    // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxFontStyleType) {
  LynxFontStyleNormal = 0,   // version:1.0
  LynxFontStyleItalic = 1,   // version:1.0
  LynxFontStyleOblique = 2,  // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxVisibilityType) {
  LynxVisibilityHidden = 0,    // version:1.0
  LynxVisibilityVisible = 1,   // version:1.0
  LynxVisibilityNone = 2,      // version:1.0
  LynxVisibilityCollapse = 3,  // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxWordBreakType) {
  LynxWordBreakNormal = 0,    // version:1.0
  LynxWordBreakBreakAll = 1,  // version:1.0
  LynxWordBreakKeepAll = 2,   // version:1.0
};

typedef NS_ENUM(NSUInteger, LynxImageRenderingType) {
  LynxImageRenderingAuto = 0,        // version:2.14
  LynxImageRenderingCrispEdges = 1,  // version:2.14
  LynxImageRenderingPixelated = 2,   // version:2.14
};

typedef NS_ENUM(NSUInteger, LynxHyphensType) {
  LynxHyphensNone = 0,    // version:2.14
  LynxHyphensManual = 1,  // version:2.14
  LynxHyphensAuto = 2,    // version:2.14
};

typedef NS_ENUM(NSUInteger, LynxXAppRegionType) {
  LynxXAppRegionNone = 0,    // version:2.17
  LynxXAppRegionDrag = 1,    // version:2.17
  LynxXAppRegionNoDrag = 2,  // version:2.17
};

typedef NS_ENUM(NSUInteger, LynxXAnimationColorInterpolationType) {
  LynxXAnimationColorInterpolationAuto = 0,       // version:2.18
  LynxXAnimationColorInterpolationSRGB = 1,       // version:2.18
  LynxXAnimationColorInterpolationLinearRGB = 2,  // version:2.18
};

NS_ASSUME_NONNULL_END

#endif  // DARWIN_COMMON_LYNX_BASE_AUTO_GEN_LYNXCSSTYPE_H_
