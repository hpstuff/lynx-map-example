// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxLoadBundleEntry.h"

@implementation LynxLoadBundleEntry

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    self = [super initWithDictionary:dictionary];
    if (self) {
        self.loadBundleStart = dictionary[@"loadBundleStart"] ?: @(-1);
        self.loadBundleEnd = dictionary[@"loadBundleEnd"] ?: @(-1);
        self.parseStart = dictionary[@"parseStart"] ?: @(-1);
        self.parseEnd = dictionary[@"parseEnd"] ?: @(-1);
        self.loadBackgroundStart = dictionary[@"loadBackgroundStart"] ?: @(-1);
        self.loadBackgroundEnd = dictionary[@"loadBackgroundEnd"] ?: @(-1);
    }
    return self;
}

@end
