// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxMetricActualFmpEntry.h"

@implementation LynxMetricActualFmpEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.actualFmp = dictionary[@"actualFmp"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"actualFmp"]] : nil;
        self.lynxActualFmp = dictionary[@"lynxActualFmp"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"lynxActualFmp"]] : nil;
        self.totalActualFmp = dictionary[@"totalActualFmp"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"totalActualFmp"]] : nil;
    }
    return self;
}

@end
