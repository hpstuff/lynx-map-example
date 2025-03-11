// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_AUTO_GEN_CSS_DECODER_H_
#define CORE_RENDERER_CSS_AUTO_GEN_CSS_DECODER_H_

#include <string>

#include "core/renderer/css/css_property.h"
#include "core/renderer/css/css_value.h"
#include "core/renderer/starlight/style/css_type.h"

namespace lynx {
namespace tasm {

class AutoGenCSSDecoder {
 public:
  // AUTO INSERT, DON'T CHANGE IT!

  static std::string ToPositionType(lynx::starlight::PositionType type);

  static std::string ToBoxSizingType(lynx::starlight::BoxSizingType type);

  static std::string ToDisplayType(lynx::starlight::DisplayType type);

  static std::string ToWhiteSpaceType(lynx::starlight::WhiteSpaceType type);

  static std::string ToTextAlignType(lynx::starlight::TextAlignType type);

  static std::string ToTextOverflowType(lynx::starlight::TextOverflowType type);

  static std::string ToFontWeightType(lynx::starlight::FontWeightType type);

  static std::string ToFlexDirectionType(
      lynx::starlight::FlexDirectionType type);

  static std::string ToFlexWrapType(lynx::starlight::FlexWrapType type);

  static std::string ToAlignContentType(lynx::starlight::AlignContentType type);

  static std::string ToJustifyContentType(
      lynx::starlight::JustifyContentType type);

  static std::string ToFontStyleType(lynx::starlight::FontStyleType type);

  static std::string ToLinearOrientationType(
      lynx::starlight::LinearOrientationType type);

  static std::string ToLinearGravityType(
      lynx::starlight::LinearGravityType type);

  static std::string ToLinearLayoutGravityType(
      lynx::starlight::LinearLayoutGravityType type);

  static std::string ToVisibilityType(lynx::starlight::VisibilityType type);

  static std::string ToWordBreakType(lynx::starlight::WordBreakType type);

  static std::string ToDirectionType(lynx::starlight::DirectionType type);

  static std::string ToRelativeCenterType(
      lynx::starlight::RelativeCenterType type);

  static std::string ToLinearCrossGravityType(
      lynx::starlight::LinearCrossGravityType type);

  static std::string ToImageRenderingType(
      lynx::starlight::ImageRenderingType type);

  static std::string ToHyphensType(lynx::starlight::HyphensType type);

  static std::string ToXAppRegionType(lynx::starlight::XAppRegionType type);

  static std::string ToXAnimationColorInterpolationType(
      lynx::starlight::XAnimationColorInterpolationType type);

  // AUTO INSERT END, DON'T CHANGE IT!
};

}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_AUTO_GEN_CSS_DECODER_H_
