// Copyright 2022 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (LynxFadingEdge)

/*
 * Update size and direction for the fading edge.
 * Feel free to invoke this function, it will update the fading edge if necessary
 */
- (void)updateFadingEdgeWithSize:(CGFloat)size horizontal:(BOOL)horizontal;

@end

NS_ASSUME_NONNULL_END
