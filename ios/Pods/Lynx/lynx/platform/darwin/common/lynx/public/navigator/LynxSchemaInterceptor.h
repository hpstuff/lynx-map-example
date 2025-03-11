// Copyright 2020 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#ifndef DARWIN_COMMON_LYNX_NAVIGATOR_LYNXSCHEMAINTERCEPTOR_H_
#define DARWIN_COMMON_LYNX_NAVIGATOR_LYNXSCHEMAINTERCEPTOR_H_

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LynxSchemaInterceptor <NSObject>

- (bool)intercept:(nonnull NSString *)schema withParam:(nonnull NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END

#endif  // DARWIN_COMMON_LYNX_NAVIGATOR_LYNXSCHEMAINTERCEPTOR_H_
