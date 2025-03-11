// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>

@interface LynxPerformanceEntry : NSObject
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong) NSString* entryType;
@property(nonatomic, strong) NSDictionary* rawDictionary;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
- (NSDictionary*)toDictionary;
@end
