// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceMetric.h"

@implementation LynxPerformanceMetric

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super init];
    if (self) {
        self.name = dictionary[@"name"] ?: @"";
        self.duration = dictionary[@"duration"] ?: @(-1);
        self.startTimestampName = dictionary[@"startTimestampName"] ?: @"";
        self.startTimestamp = dictionary[@"startTimestamp"] ?: @(-1);
        self.endTimestampName = dictionary[@"endTimestampName"] ?: @"";
        self.endTimestamp = dictionary[@"endTimestamp"] ?: @(-1);
    }
    return self;
}

@end
