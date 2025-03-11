// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>

@interface LynxPerformanceMetric : NSObject
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSNumber* duration;
@property(nonatomic, strong) NSString* startTimestampName;
@property(nonatomic, strong) NSNumber* startTimestamp;
@property(nonatomic, strong) NSString* endTimestampName;
@property(nonatomic, strong) NSNumber* endTimestamp;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
