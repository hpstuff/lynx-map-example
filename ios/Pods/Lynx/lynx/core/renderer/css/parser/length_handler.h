// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_LENGTH_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_LENGTH_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace LengthHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDTop] = &Handle;
  array[kPropertyIDLeft] = &Handle;
  array[kPropertyIDRight] = &Handle;
  array[kPropertyIDBottom] = &Handle;
  array[kPropertyIDHeight] = &Handle;
  array[kPropertyIDWidth] = &Handle;
  array[kPropertyIDMaxWidth] = &Handle;
  array[kPropertyIDMinWidth] = &Handle;
  array[kPropertyIDMaxHeight] = &Handle;
  array[kPropertyIDMinHeight] = &Handle;
  array[kPropertyIDPaddingLeft] = &Handle;
  array[kPropertyIDPaddingRight] = &Handle;
  array[kPropertyIDPaddingTop] = &Handle;
  array[kPropertyIDPaddingBottom] = &Handle;
  array[kPropertyIDMarginLeft] = &Handle;
  array[kPropertyIDMarginRight] = &Handle;
  array[kPropertyIDMarginTop] = &Handle;
  array[kPropertyIDMarginBottom] = &Handle;
  array[kPropertyIDFontSize] = &Handle;
  array[kPropertyIDFlexBasis] = &Handle;
  array[kPropertyIDMarginInlineStart] = &Handle;
  array[kPropertyIDMarginInlineEnd] = &Handle;
  array[kPropertyIDPaddingInlineStart] = &Handle;
  array[kPropertyIDPaddingInlineEnd] = &Handle;
  array[kPropertyIDInsetInlineStart] = &Handle;
  array[kPropertyIDInsetInlineEnd] = &Handle;
  array[kPropertyIDGridColumnGap] = &Handle;
  array[kPropertyIDGridRowGap] = &Handle;
  array[kPropertyIDPerspective] = &Handle;
  array[kPropertyIDTextIndent] = &Handle;
  array[kPropertyIDColumnGap] = &Handle;
  array[kPropertyIDRowGap] = &Handle;
  array[kPropertyIDXHandleSize] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

bool Handle(CSSPropertyID key, const lepus::Value &input, StyleMap &output,
            const CSSParserConfigs &configs);
// help parse length css
bool Process(const lepus::Value &input, CSSValue &css_value,
             const CSSParserConfigs &configs);

}  // namespace LengthHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_LENGTH_HANDLER_H_
