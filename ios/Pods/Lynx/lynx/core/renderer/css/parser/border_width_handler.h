// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_BORDER_WIDTH_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_BORDER_WIDTH_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"
#include "core/renderer/css/parser/length_handler.h"

namespace lynx {
namespace tasm {
namespace BorderWidthHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDBorderLeftWidth] = &Handle;
  array[kPropertyIDBorderRightWidth] = &Handle;
  array[kPropertyIDBorderTopWidth] = &Handle;
  array[kPropertyIDBorderBottomWidth] = &Handle;
  array[kPropertyIDOutlineWidth] = &Handle;
  array[kPropertyIDBorderInlineStartWidth] = &Handle;
  array[kPropertyIDBorderInlineEndWidth] = &Handle;
  array[kPropertyIDTextStrokeWidth] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

}  // namespace BorderWidthHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_BORDER_WIDTH_HANDLER_H_
