// Copyright 2025 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef CORE_RENDERER_CSS_PARSER_NUMBER_HANDLER_H_
#define CORE_RENDERER_CSS_PARSER_NUMBER_HANDLER_H_

#include "core/renderer/css/parser/handler_defines.h"

namespace lynx {
namespace tasm {
namespace NumberHandler {

HANDLER_DECLARE();

HANDLER_REGISTER_IMPL_INL() {
  // AUTO INSERT, DON'T CHANGE IT!
  array[kPropertyIDOpacity] = &Handle;
  array[kPropertyIDFlexGrow] = &Handle;
  array[kPropertyIDFlexShrink] = &Handle;
  array[kPropertyIDOrder] = &Handle;
  array[kPropertyIDLinearWeightSum] = &Handle;
  array[kPropertyIDLinearWeight] = &Handle;
  array[kPropertyIDRelativeId] = &Handle;
  array[kPropertyIDRelativeTopOf] = &Handle;
  array[kPropertyIDRelativeRightOf] = &Handle;
  array[kPropertyIDRelativeBottomOf] = &Handle;
  array[kPropertyIDRelativeLeftOf] = &Handle;
  array[kPropertyIDZIndex] = &Handle;
  array[kPropertyIDRelativeInlineStartOf] = &Handle;
  array[kPropertyIDRelativeInlineEndOf] = &Handle;
  array[kPropertyIDGridColumnSpan] = &Handle;
  array[kPropertyIDGridRowSpan] = &Handle;

  // AUTO INSERT END, DON'T CHANGE IT!
}

}  // namespace NumberHandler
}  // namespace tasm
}  // namespace lynx

#endif  // CORE_RENDERER_CSS_PARSER_NUMBER_HANDLER_H_
