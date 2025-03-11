// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceEntry.h"

@interface LynxInitContainerEntry : LynxPerformanceEntry
@property(nonatomic, strong) NSNumber* openTime;
@property(nonatomic, strong) NSNumber* containerInitStart;
@property(nonatomic, strong) NSNumber* containerInitEnd;
@property(nonatomic, strong) NSNumber* prepareTemplateStart;
@property(nonatomic, strong) NSNumber* prepareTemplateEnd;
@property(nonatomic, strong) NSDictionary* extraTiming;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
