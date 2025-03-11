// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxMetricTtiEntry.h"

@implementation LynxMetricTtiEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.tti = dictionary[@"tti"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"tti"]] : nil;
        self.lynxTti = dictionary[@"lynxTti"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"lynxTti"]] : nil;
        self.totalTti = dictionary[@"totalTti"] ? [[LynxPerformanceMetric alloc] initWithDictionary:dictionary[@"totalTti"]] : nil;
    }
    return self;
}

@end
