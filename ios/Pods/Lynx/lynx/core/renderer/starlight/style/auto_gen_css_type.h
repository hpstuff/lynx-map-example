// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

// AUTO INSERT, DON'T CHANGE IT!

#ifndef CORE_RENDERER_STARLIGHT_STYLE_AUTO_GEN_CSS_TYPE_H_
#define CORE_RENDERER_STARLIGHT_STYLE_AUTO_GEN_CSS_TYPE_H_

#include <limits.h>
#include <stdint.h>

namespace lynx {
namespace starlight {

enum class PositionType : unsigned {
  kAbsolute = 0,  // version:1.0
  kRelative = 1,  // version:1.0
  kFixed = 2,     // version:1.0
  kSticky = 3,    // version:1.4
};
enum class BoxSizingType : unsigned {
  kBorderBox = 0,   // version:1.0
  kContentBox = 1,  // version:1.0
  kAuto = 2,        // version:2.0
};
enum class DisplayType : unsigned {
  kNone = 0,      // version:1.0
  kFlex = 1,      // version:1.0
  kGrid = 2,      // version:1.0
  kLinear = 3,    // version:1.0
  kRelative = 4,  // version:2.0
  kBlock = 5,     // version:2.0
  kAuto = 6,      // version:2.0
};
enum class WhiteSpaceType : unsigned {
  kNormal = 0,  // version:1.0
  kNowrap = 1,  // version:1.0
};
enum class TextAlignType : unsigned {
  kLeft = 0,     // version:1.0
  kCenter = 1,   // version:1.0
  kRight = 2,    // version:1.0
  kStart = 3,    // version:2.0
  kEnd = 4,      // version:2.0
  kJustify = 5,  // version:2.10
};
enum class TextOverflowType : unsigned {
  kClip = 0,      // version:1.0
  kEllipsis = 1,  // version:1.0
};
enum class FontWeightType : unsigned {
  kNormal = 0,  // version:1.0
  kBold = 1,    // version:1.0
  k100 = 2,     // version:1.0
  k200 = 3,     // version:1.0
  k300 = 4,     // version:1.0
  k400 = 5,     // version:1.0
  k500 = 6,     // version:1.0
  k600 = 7,     // version:1.0
  k700 = 8,     // version:1.0
  k800 = 9,     // version:1.0
  k900 = 10,    // version:1.0
};
enum class FlexDirectionType : unsigned {
  kColumn = 0,         // version:1.0
  kRow = 1,            // version:1.0
  kRowReverse = 2,     // version:1.0
  kColumnReverse = 3,  // version:1.0
};
enum class FlexWrapType : unsigned {
  kWrap = 0,         // version:1.0
  kNowrap = 1,       // version:1.0
  kWrapReverse = 2,  // version:1.0
};
enum class AlignContentType : unsigned {
  kFlexStart = 0,     // version:1.0
  kFlexEnd = 1,       // version:1.0
  kCenter = 2,        // version:1.0
  kStretch = 3,       // version:1.0
  kSpaceBetween = 4,  // version:1.0
  kSpaceAround = 5,   // version:1.0
};
enum class JustifyContentType : unsigned {
  kFlexStart = 0,     // version:1.0
  kCenter = 1,        // version:1.0
  kFlexEnd = 2,       // version:1.0
  kSpaceBetween = 3,  // version:1.0
  kSpaceAround = 4,   // version:1.0
  kSpaceEvenly = 5,   // version:1.0
  kStretch = 6,       // version:2.1
};
enum class FontStyleType : unsigned {
  kNormal = 0,   // version:1.0
  kItalic = 1,   // version:1.0
  kOblique = 2,  // version:1.0
};
enum class LinearOrientationType : unsigned {
  kHorizontal = 0,         // version:1.0
  kVertical = 1,           // version:1.0
  kHorizontalReverse = 2,  // version:1.0
  kVerticalReverse = 3,    // version:1.0
  kRow = 4,                // version:2.2
  kColumn = 5,             // version:2.2
  kRowReverse = 6,         // version:2.2
  kColumnReverse = 7,      // version:2.2
};
enum class LinearGravityType : unsigned {
  kNone = 0,              // version:1.0
  kTop = 1,               // version:1.0
  kBottom = 2,            // version:1.0
  kLeft = 3,              // version:1.0
  kRight = 4,             // version:1.0
  kCenterVertical = 5,    // version:1.0
  kCenterHorizontal = 6,  // version:1.0
  kSpaceBetween = 7,      // version:1.0
  kStart = 8,             // version:1.6
  kEnd = 9,               // version:1.6
  kCenter = 10,           // version:1.6
};
enum class LinearLayoutGravityType : unsigned {
  kNone = 0,              // version:1.0
  kTop = 1,               // version:1.0
  kBottom = 2,            // version:1.0
  kLeft = 3,              // version:1.0
  kRight = 4,             // version:1.0
  kCenterVertical = 5,    // version:1.0
  kCenterHorizontal = 6,  // version:1.0
  kFillVertical = 7,      // version:1.0
  kFillHorizontal = 8,    // version:1.0
  kCenter = 9,            // version:1.6
  kStretch = 10,          // version:1.6
  kStart = 11,            // version:1.6
  kEnd = 12,              // version:1.6
};
enum class VisibilityType : unsigned {
  kHidden = 0,    // version:1.0
  kVisible = 1,   // version:1.0
  kNone = 2,      // version:1.0
  kCollapse = 3,  // version:1.0
};
enum class WordBreakType : unsigned {
  kNormal = 0,    // version:1.0
  kBreakAll = 1,  // version:1.0
  kKeepAll = 2,   // version:1.0
};
enum class DirectionType : unsigned {
  kNormal = 0,   // version:1.0
  kLynxRtl = 1,  // version:1.0
  kRtl = 2,      // version:1.0
  kLtr = 3,      // version:2.0
};
enum class RelativeCenterType : unsigned {
  kNone = 0,        // version:1.0
  kVertical = 1,    // version:1.0
  kHorizontal = 2,  // version:1.0
  kBoth = 3,        // version:1.0
};
enum class LinearCrossGravityType : unsigned {
  kNone = 0,     // version:1.0
  kStart = 1,    // version:1.0
  kEnd = 2,      // version:1.0
  kCenter = 3,   // version:1.0
  kStretch = 4,  // version:1.6
};
enum class ImageRenderingType : unsigned {
  kAuto = 0,        // version:2.14
  kCrispEdges = 1,  // version:2.14
  kPixelated = 2,   // version:2.14
};
enum class HyphensType : unsigned {
  kNone = 0,    // version:2.14
  kManual = 1,  // version:2.14
  kAuto = 2,    // version:2.14
};
enum class XAppRegionType : unsigned {
  kNone = 0,    // version:2.17
  kDrag = 1,    // version:2.17
  kNoDrag = 2,  // version:2.17
};
enum class XAnimationColorInterpolationType : unsigned {
  kAuto = 0,       // version:2.18
  kSRGB = 1,       // version:2.18
  kLinearRGB = 2,  // version:2.18
};

}  // namespace starlight
}  // namespace lynx

#endif  // CORE_RENDERER_STARLIGHT_STYLE_AUTO_GEN_CSS_TYPE_H_

// AUTO INSERT END, DON'T CHANGE IT!
