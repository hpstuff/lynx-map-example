// Copyright 2024 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.
#import <Foundation/Foundation.h>
#import "LynxPerformanceEntryConverter.h"
#import "LynxPipelineEntry.h"
#import "LynxLoadBundleEntry.h"
#import "LynxInitContainerEntry.h"
#import "LynxInitLynxviewEntry.h"
#import "LynxInitBackgroundRuntimeEntry.h"
#import "LynxMetricFcpEntry.h"
#import "LynxMetricTtiEntry.h"
#import "LynxMetricActualFmpEntry.h"

@implementation LynxPerformanceEntryConverter
+ (LynxPerformanceEntry *)makePerformanceEntry:(NSDictionary *)dict {
    NSString *name = dict[@"name"];
    NSString *type = dict[@"entry_type"];
    LynxPerformanceEntry *entry;
    if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"updateTriggeredByBts"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"updateTriggeredByNts"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"updateTriggeredByNative"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"reactHydrate"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"setNativeProps"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"updateGlobalProps"]) {
        entry = [[LynxPipelineEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"loadBundle"]) {
        entry = [[LynxLoadBundleEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"reloadBundleFromNative"]) {
        entry = [[LynxLoadBundleEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"pipeline"] && [name isEqualToString:@"reloadBundleFromBackgroundRuntime"]) {
        entry = [[LynxLoadBundleEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"init"] && [name isEqualToString:@"container"]) {
        entry = [[LynxInitContainerEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"init"] && [name isEqualToString:@"lynxview"]) {
        entry = [[LynxInitLynxviewEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"init"] && [name isEqualToString:@"backgroundRuntime"]) {
        entry = [[LynxInitBackgroundRuntimeEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"metric"] && [name isEqualToString:@"fcp"]) {
        entry = [[LynxMetricFcpEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"metric"] && [name isEqualToString:@"tti"]) {
        entry = [[LynxMetricTtiEntry alloc] initWithDictionary:dict];
    }
    else if ([type isEqualToString:@"metric"] && [name isEqualToString:@"actualFmp"]) {
        entry = [[LynxMetricActualFmpEntry alloc] initWithDictionary:dict];
    }
    else {
        entry = [[LynxPerformanceEntry alloc] initWithDictionary:dict];
    }
    return entry;
}
@end
