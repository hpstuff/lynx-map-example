// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceEntry.h"

@interface LynxInitBackgroundRuntimeEntry : LynxPerformanceEntry
@property(nonatomic, strong) NSNumber* loadCoreStart;
@property(nonatomic, strong) NSNumber* loadCoreEnd;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
