// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxInitBackgroundRuntimeEntry.h"

@implementation LynxInitBackgroundRuntimeEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.loadCoreStart = dictionary[@"loadCoreStart"] ?: @(-1);
        self.loadCoreEnd = dictionary[@"loadCoreEnd"] ?: @(-1);
    }
    return self;
}

@end
