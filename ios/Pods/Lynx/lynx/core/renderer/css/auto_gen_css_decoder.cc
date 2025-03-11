// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#include "core/renderer/css/auto_gen_css_decoder.h"

#include <sstream>
#include <utility>

#include "base/include/debug/lynx_assert.h"
#include "core/renderer/css/css_color.h"
#include "core/runtime/vm/lepus/array.h"
#include "core/runtime/vm/lepus/table.h"
#include "core/style/timing_function_data.h"
#include "core/style/transform_raw_data.h"

namespace lynx {
namespace tasm {

using namespace lynx::starlight;  // NOLINT
using namespace lynx::tasm;       // NOLINT
// AUTO INSERT, DON'T CHANGE IT!

std::string AutoGenCSSDecoder::ToPositionType(PositionType type) {
  switch (type) {
    case PositionType::kAbsolute:
      return "absolute";
    case PositionType::kRelative:
      return "relative";
    case PositionType::kFixed:
      return "fixed";
    case PositionType::kSticky:
      return "sticky";
  }
}

std::string AutoGenCSSDecoder::ToBoxSizingType(BoxSizingType type) {
  switch (type) {
    case BoxSizingType::kBorderBox:
      return "border-box";
    case BoxSizingType::kContentBox:
      return "content-box";
    case BoxSizingType::kAuto:
      return "auto";
  }
}

std::string AutoGenCSSDecoder::ToDisplayType(DisplayType type) {
  switch (type) {
    case DisplayType::kNone:
      return "none";
    case DisplayType::kFlex:
      return "flex";
    case DisplayType::kGrid:
      return "grid";
    case DisplayType::kLinear:
      return "linear";
    case DisplayType::kRelative:
      return "relative";
    case DisplayType::kBlock:
      return "block";
    case DisplayType::kAuto:
      return "auto";
  }
}

std::string AutoGenCSSDecoder::ToWhiteSpaceType(WhiteSpaceType type) {
  switch (type) {
    case WhiteSpaceType::kNormal:
      return "normal";
    case WhiteSpaceType::kNowrap:
      return "nowrap";
  }
}

std::string AutoGenCSSDecoder::ToTextAlignType(TextAlignType type) {
  switch (type) {
    case TextAlignType::kLeft:
      return "left";
    case TextAlignType::kCenter:
      return "center";
    case TextAlignType::kRight:
      return "right";
    case TextAlignType::kStart:
      return "start";
    case TextAlignType::kEnd:
      return "end";
    case TextAlignType::kJustify:
      return "justify";
  }
}

std::string AutoGenCSSDecoder::ToTextOverflowType(TextOverflowType type) {
  switch (type) {
    case TextOverflowType::kClip:
      return "clip";
    case TextOverflowType::kEllipsis:
      return "ellipsis";
  }
}

std::string AutoGenCSSDecoder::ToFontWeightType(FontWeightType type) {
  switch (type) {
    case FontWeightType::kNormal:
      return "normal";
    case FontWeightType::kBold:
      return "bold";
    case FontWeightType::k100:
      return "100";
    case FontWeightType::k200:
      return "200";
    case FontWeightType::k300:
      return "300";
    case FontWeightType::k400:
      return "400";
    case FontWeightType::k500:
      return "500";
    case FontWeightType::k600:
      return "600";
    case FontWeightType::k700:
      return "700";
    case FontWeightType::k800:
      return "800";
    case FontWeightType::k900:
      return "900";
  }
}

std::string AutoGenCSSDecoder::ToFlexDirectionType(FlexDirectionType type) {
  switch (type) {
    case FlexDirectionType::kColumn:
      return "column";
    case FlexDirectionType::kRow:
      return "row";
    case FlexDirectionType::kRowReverse:
      return "row-reverse";
    case FlexDirectionType::kColumnReverse:
      return "column-reverse";
  }
}

std::string AutoGenCSSDecoder::ToFlexWrapType(FlexWrapType type) {
  switch (type) {
    case FlexWrapType::kWrap:
      return "wrap";
    case FlexWrapType::kNowrap:
      return "nowrap";
    case FlexWrapType::kWrapReverse:
      return "wrap-reverse";
  }
}

std::string AutoGenCSSDecoder::ToAlignContentType(AlignContentType type) {
  switch (type) {
    case AlignContentType::kFlexStart:
      return "flex-start";
    case AlignContentType::kFlexEnd:
      return "flex-end";
    case AlignContentType::kCenter:
      return "center";
    case AlignContentType::kStretch:
      return "stretch";
    case AlignContentType::kSpaceBetween:
      return "space-between";
    case AlignContentType::kSpaceAround:
      return "space-around";
  }
}

std::string AutoGenCSSDecoder::ToJustifyContentType(JustifyContentType type) {
  switch (type) {
    case JustifyContentType::kFlexStart:
      return "flex-start";
    case JustifyContentType::kCenter:
      return "center";
    case JustifyContentType::kFlexEnd:
      return "flex-end";
    case JustifyContentType::kSpaceBetween:
      return "space-between";
    case JustifyContentType::kSpaceAround:
      return "space-around";
    case JustifyContentType::kSpaceEvenly:
      return "space-evenly";
    case JustifyContentType::kStretch:
      return "stretch";
  }
}

std::string AutoGenCSSDecoder::ToFontStyleType(FontStyleType type) {
  switch (type) {
    case FontStyleType::kNormal:
      return "normal";
    case FontStyleType::kItalic:
      return "italic";
    case FontStyleType::kOblique:
      return "oblique";
  }
}

std::string AutoGenCSSDecoder::ToLinearOrientationType(
    LinearOrientationType type) {
  switch (type) {
    case LinearOrientationType::kHorizontal:
      return "horizontal";
    case LinearOrientationType::kVertical:
      return "vertical";
    case LinearOrientationType::kHorizontalReverse:
      return "horizontal-reverse";
    case LinearOrientationType::kVerticalReverse:
      return "vertical-reverse";
    case LinearOrientationType::kRow:
      return "row";
    case LinearOrientationType::kColumn:
      return "column";
    case LinearOrientationType::kRowReverse:
      return "row-reverse";
    case LinearOrientationType::kColumnReverse:
      return "column-reverse";
  }
}

std::string AutoGenCSSDecoder::ToLinearGravityType(LinearGravityType type) {
  switch (type) {
    case LinearGravityType::kNone:
      return "none";
    case LinearGravityType::kTop:
      return "top";
    case LinearGravityType::kBottom:
      return "bottom";
    case LinearGravityType::kLeft:
      return "left";
    case LinearGravityType::kRight:
      return "right";
    case LinearGravityType::kCenterVertical:
      return "center-vertical";
    case LinearGravityType::kCenterHorizontal:
      return "center-horizontal";
    case LinearGravityType::kSpaceBetween:
      return "space-between";
    case LinearGravityType::kStart:
      return "start";
    case LinearGravityType::kEnd:
      return "end";
    case LinearGravityType::kCenter:
      return "center";
  }
}

std::string AutoGenCSSDecoder::ToLinearLayoutGravityType(
    LinearLayoutGravityType type) {
  switch (type) {
    case LinearLayoutGravityType::kNone:
      return "none";
    case LinearLayoutGravityType::kTop:
      return "top";
    case LinearLayoutGravityType::kBottom:
      return "bottom";
    case LinearLayoutGravityType::kLeft:
      return "left";
    case LinearLayoutGravityType::kRight:
      return "right";
    case LinearLayoutGravityType::kCenterVertical:
      return "center-vertical";
    case LinearLayoutGravityType::kCenterHorizontal:
      return "center-horizontal";
    case LinearLayoutGravityType::kFillVertical:
      return "fill-vertical";
    case LinearLayoutGravityType::kFillHorizontal:
      return "fill-horizontal";
    case LinearLayoutGravityType::kCenter:
      return "center";
    case LinearLayoutGravityType::kStretch:
      return "stretch";
    case LinearLayoutGravityType::kStart:
      return "start";
    case LinearLayoutGravityType::kEnd:
      return "end";
  }
}

std::string AutoGenCSSDecoder::ToVisibilityType(VisibilityType type) {
  switch (type) {
    case VisibilityType::kHidden:
      return "hidden";
    case VisibilityType::kVisible:
      return "visible";
    case VisibilityType::kNone:
      return "none";
    case VisibilityType::kCollapse:
      return "collapse";
  }
}

std::string AutoGenCSSDecoder::ToWordBreakType(WordBreakType type) {
  switch (type) {
    case WordBreakType::kNormal:
      return "normal";
    case WordBreakType::kBreakAll:
      return "break-all";
    case WordBreakType::kKeepAll:
      return "keep-all";
  }
}

std::string AutoGenCSSDecoder::ToDirectionType(DirectionType type) {
  switch (type) {
    case DirectionType::kNormal:
      return "normal";
    case DirectionType::kLynxRtl:
      return "lynx-rtl";
    case DirectionType::kRtl:
      return "rtl";
    case DirectionType::kLtr:
      return "ltr";
  }
}

std::string AutoGenCSSDecoder::ToRelativeCenterType(RelativeCenterType type) {
  switch (type) {
    case RelativeCenterType::kNone:
      return "none";
    case RelativeCenterType::kVertical:
      return "vertical";
    case RelativeCenterType::kHorizontal:
      return "horizontal";
    case RelativeCenterType::kBoth:
      return "both";
  }
}

std::string AutoGenCSSDecoder::ToLinearCrossGravityType(
    LinearCrossGravityType type) {
  switch (type) {
    case LinearCrossGravityType::kNone:
      return "none";
    case LinearCrossGravityType::kStart:
      return "start";
    case LinearCrossGravityType::kEnd:
      return "end";
    case LinearCrossGravityType::kCenter:
      return "center";
    case LinearCrossGravityType::kStretch:
      return "stretch";
  }
}

std::string AutoGenCSSDecoder::ToImageRenderingType(ImageRenderingType type) {
  switch (type) {
    case ImageRenderingType::kAuto:
      return "auto";
    case ImageRenderingType::kCrispEdges:
      return "crisp-edges";
    case ImageRenderingType::kPixelated:
      return "pixelated";
  }
}

std::string AutoGenCSSDecoder::ToHyphensType(HyphensType type) {
  switch (type) {
    case HyphensType::kNone:
      return "none";
    case HyphensType::kManual:
      return "manual";
    case HyphensType::kAuto:
      return "auto";
  }
}

std::string AutoGenCSSDecoder::ToXAppRegionType(XAppRegionType type) {
  switch (type) {
    case XAppRegionType::kNone:
      return "none";
    case XAppRegionType::kDrag:
      return "drag";
    case XAppRegionType::kNoDrag:
      return "no-drag";
  }
}

std::string AutoGenCSSDecoder::ToXAnimationColorInterpolationType(
    XAnimationColorInterpolationType type) {
  switch (type) {
    case XAnimationColorInterpolationType::kAuto:
      return "auto";
    case XAnimationColorInterpolationType::kSRGB:
      return "sRGB";
    case XAnimationColorInterpolationType::kLinearRGB:
      return "linearRGB";
  }
}

// AUTO INSERT END, DON'T CHANGE IT!

}  // namespace tasm
}  // namespace lynx
