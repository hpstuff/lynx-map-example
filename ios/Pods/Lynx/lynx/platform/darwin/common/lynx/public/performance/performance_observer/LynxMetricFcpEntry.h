// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceEntry.h"
#import "LynxPerformanceMetric.h"

@interface LynxMetricFcpEntry : LynxPerformanceEntry
@property(nonatomic, strong) LynxPerformanceMetric* fcp;
@property(nonatomic, strong) LynxPerformanceMetric* lynxFcp;
@property(nonatomic, strong) LynxPerformanceMetric* totalFcp;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
