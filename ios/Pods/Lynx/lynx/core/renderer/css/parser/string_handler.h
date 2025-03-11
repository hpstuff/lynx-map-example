// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_STRING_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_STRING_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace StringHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDFontFamily] = &Handle;
  array[kPropertyIDAdaptFontSize] = &Handle;
  array[kPropertyIDContent] = &Handle;
  array[kPropertyIDCaretColor] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

}  // namespace StringHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_STRING_HANDLER_H_
