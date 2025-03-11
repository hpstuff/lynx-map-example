// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPipelineEntry.h"

@implementation LynxPipelineEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.identifier = dictionary[@"identifier"] ?: @"";
        self.pipelineStart = dictionary[@"pipelineStart"] ?: @(-1);
        self.pipelineEnd = dictionary[@"pipelineEnd"] ?: @(-1);
        self.mtsRenderStart = dictionary[@"mtsRenderStart"] ?: @(-1);
        self.mtsRenderEnd = dictionary[@"mtsRenderEnd"] ?: @(-1);
        self.resolveStart = dictionary[@"resolveStart"] ?: @(-1);
        self.resolveEnd = dictionary[@"resolveEnd"] ?: @(-1);
        self.layoutStart = dictionary[@"layoutStart"] ?: @(-1);
        self.layoutEnd = dictionary[@"layoutEnd"] ?: @(-1);
        self.paintingUiOperationExecuteStart = dictionary[@"paintingUiOperationExecuteStart"] ?: @(-1);
        self.paintingUiOperationExecuteEnd = dictionary[@"paintingUiOperationExecuteEnd"] ?: @(-1);
        self.layoutUiOperationExecuteStart = dictionary[@"layoutUiOperationExecuteStart"] ?: @(-1);
        self.layoutUiOperationExecuteEnd = dictionary[@"layoutUiOperationExecuteEnd"] ?: @(-1);
        self.paintEnd = dictionary[@"paintEnd"] ?: @(-1);
        self.frameworkPipelineTiming = dictionary[@"frameworkPipelineTiming"];
    }
    return self;
}

@end
