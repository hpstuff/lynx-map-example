// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxInitContainerEntry.h"

@implementation LynxInitContainerEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.openTime = dictionary[@"openTime"] ?: @(-1);
        self.containerInitStart = dictionary[@"containerInitStart"] ?: @(-1);
        self.containerInitEnd = dictionary[@"containerInitEnd"] ?: @(-1);
        self.prepareTemplateStart = dictionary[@"prepareTemplateStart"] ?: @(-1);
        self.prepareTemplateEnd = dictionary[@"prepareTemplateEnd"] ?: @(-1);
        self.extraTiming = dictionary[@"extraTiming"] ?: @{};
    }
    return self;
}

@end
