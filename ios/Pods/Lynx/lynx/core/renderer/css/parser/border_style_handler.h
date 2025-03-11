// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_BORDER_STYLE_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_BORDER_STYLE_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace BorderStyleHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDBorderLeftStyle] = &Handle;
  array[kPropertyIDBorderRightStyle] = &Handle;
  array[kPropertyIDBorderTopStyle] = &Handle;
  array[kPropertyIDBorderBottomStyle] = &Handle;
  array[kPropertyIDOutlineStyle] = &Handle;
  array[kPropertyIDBorderInlineStartStyle] = &Handle;
  array[kPropertyIDBorderInlineEndStyle] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

}  // namespace BorderStyleHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_BORDER_STYLE_HANDLER_H_
