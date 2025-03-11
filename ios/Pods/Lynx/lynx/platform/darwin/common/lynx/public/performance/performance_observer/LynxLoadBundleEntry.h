// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPipelineEntry.h"

@interface LynxLoadBundleEntry : LynxPipelineEntry
@property(nonatomic, strong) NSNumber* loadBundleStart;
@property(nonatomic, strong) NSNumber* loadBundleEnd;
@property(nonatomic, strong) NSNumber* parseStart;
@property(nonatomic, strong) NSNumber* parseEnd;
@property(nonatomic, strong) NSNumber* loadBackgroundStart;
@property(nonatomic, strong) NSNumber* loadBackgroundEnd;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
