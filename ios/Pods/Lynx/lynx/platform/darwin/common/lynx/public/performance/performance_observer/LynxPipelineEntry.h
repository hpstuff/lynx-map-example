// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceEntry.h"

@interface LynxPipelineEntry : LynxPerformanceEntry
@property(nonatomic, strong) NSString* identifier;
@property(nonatomic, strong) NSNumber* pipelineStart;
@property(nonatomic, strong) NSNumber* pipelineEnd;
@property(nonatomic, strong) NSNumber* mtsRenderStart;
@property(nonatomic, strong) NSNumber* mtsRenderEnd;
@property(nonatomic, strong) NSNumber* resolveStart;
@property(nonatomic, strong) NSNumber* resolveEnd;
@property(nonatomic, strong) NSNumber* layoutStart;
@property(nonatomic, strong) NSNumber* layoutEnd;
@property(nonatomic, strong) NSNumber* paintingUiOperationExecuteStart;
@property(nonatomic, strong) NSNumber* paintingUiOperationExecuteEnd;
@property(nonatomic, strong) NSNumber* layoutUiOperationExecuteStart;
@property(nonatomic, strong) NSNumber* layoutUiOperationExecuteEnd;
@property(nonatomic, strong) NSNumber* paintEnd;
@property(nonatomic, strong) NSDictionary* frameworkPipelineTiming;
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;
@end
