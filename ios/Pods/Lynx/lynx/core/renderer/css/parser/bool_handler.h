// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_BOOL_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_BOOL_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace BoolHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDImplicitAnimation] = &Handle;
  array[kPropertyIDRelativeLayoutOnce] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

bool Process(const lepus::Value& input, CSSValue& css_value,
             const CSSParserConfigs& configs, CSSPropertyID key);

}  // namespace BoolHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_BOOL_HANDLER_H_
