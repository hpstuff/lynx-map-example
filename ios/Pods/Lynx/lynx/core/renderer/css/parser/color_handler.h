// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_COLOR_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_COLOR_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace ColorHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDBackgroundColor] = &Handle;
  array[kPropertyIDBorderLeftColor] = &Handle;
  array[kPropertyIDBorderRightColor] = &Handle;
  array[kPropertyIDBorderTopColor] = &Handle;
  array[kPropertyIDBorderBottomColor] = &Handle;
  array[kPropertyIDColor] = &Handle;
  array[kPropertyIDOutlineColor] = &Handle;
  array[kPropertyIDTextDecorationColor] = &Handle;
  array[kPropertyIDBorderInlineStartColor] = &Handle;
  array[kPropertyIDBorderInlineEndColor] = &Handle;
  array[kPropertyIDTextStrokeColor] = &Handle;
  array[kPropertyIDXHandleColor] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

bool Process(const lepus::Value &input, CSSValue &css_value,
             const CSSParserConfigs &configs, bool is_text_color = false);

}  // namespace ColorHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_COLOR_HANDLER_H_
