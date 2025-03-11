// Copyright 2022 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LynxScrollViewTouchBehavior) {
  LynxScrollViewTouchBehaviorNone = 0,
  LynxScrollViewTouchBehaviorForbid,
  LynxScrollViewTouchBehaviorPause,
  LynxScrollViewTouchBehaviorStop,
};

typedef NSInteger (^UIScrollViewGetIndexFromView)(UIView *view);

typedef CGRect (^UIScrollViewGetViewRectAtIndex)(NSInteger index);

typedef void (^UIScrollViewWillSnapToCallback)(NSInteger position, CGPoint offset);

typedef BOOL (^UIScrollViewLynxCompletion)(BOOL scrollEnabledAtStart, BOOL completed);

typedef CGPoint (^UIScrollViewLynxProgressInterception)(double timeProgress, double distProgress,
                                                        CGPoint contentOffset);
typedef double (^UIScrollViewLynxTimingFunction)(double input);

@interface UIScrollView (Lynx)

@property(nonatomic, assign) BOOL scrollEnableFromLynx;

/**
 Tell ths backend-UIScrollView of `<list>` if it is adjusting its `contentOffset` internally.
 Notice, the backend-UIScrollView of `<list>` should override this method.
 @param value if the `<list>` is adjusting its `contentOffset` internally
 */
- (void)setLynxListAdjustingContentOffset:(BOOL)value;
/**
 Check if `<list>` is adjusting its `contentOffset` internally. Notice, the backend-UIScrollView of
 `<list>` should override this method.
 @return the status
 */
- (BOOL)isLynxListAdjustingContentOffset;

/**
 Scroll to center of the page, just like  what `pagingEnable` does.
 @param proposedContentOffset the proposed offset generated by UIScrollView
 @param velocity  velocity is in points/millisecond
 @param visibleItems visible items
 @param getIndexFromView get the paging index of a view in the `visibleItems`
 @param getViewRectAtIndex get the rect of a view
 @param vertical vertical scroll
 @param rtl is rtl
 @param factor align factor, within [0, 1]
 @param callback target position callback
 @return the proposed offset which will let a view placed at the center of the UIScrollView
 */
- (CGPoint)targetContentOffset:(CGPoint)proposedContentOffset
         withScrollingVelocity:(CGPoint)velocity
              withVisibleItems:(NSArray<UIView *> *)visibleItems
              getIndexFromView:(UIScrollViewGetIndexFromView)getIndexFromView
            getViewRectAtIndex:(UIScrollViewGetViewRectAtIndex)getViewRectAtIndex
                      vertical:(BOOL)vertical
                           rtl:(BOOL)rtl
                        factor:(CGFloat)factor
                        offset:(CGFloat)offset
                      callback:(UIScrollViewWillSnapToCallback)callback;

/**
 Check if a UIScrollView could consume a delta offset
 @param delta the offset
 @param vertical vertical scroll
 @return consume the delta offset or not
 */
- (BOOL)consumeDeltaOffset:(CGPoint)delta vertical:(BOOL)vertical;

/**
 Make sure the `contentOffset` will not exceed the scrollable distance
 @param contentOffset the offset to be updated
 @param vertical is vertical
 @return updated position
 */
- (CGPoint)updateContentOffset:(CGPoint)contentOffset vertical:(BOOL)vertical;

/**
 scroll a UIScrollView with custom duration
 @param contentOffset target content offset
 @param behavior LynxScrollViewTouchBehavior
 @param duration scroll duration
 @param interval frame interval, default value is zero
 @param interception custom your own progress if needed
 @param callback called while scroll finished
 */
- (void)setContentOffset:(CGPoint)contentOffset
                behavior:(LynxScrollViewTouchBehavior)behavior
                duration:(NSTimeInterval)duration
                interval:(NSTimeInterval)interval
                progress:(_Nullable UIScrollViewLynxProgressInterception)interception
                complete:(_Nullable UIScrollViewLynxCompletion)callback;

/**
 scroll a UIScrollView with custom duration, with easeOut function, used to apply fling effection
 @param contentOffset target content offset
 @param behavior LynxScrollViewTouchBehavior
 @param duration scroll duration
 @param interval frame interval, default value is zero
 @param callback called while scroll finished
 */
- (void)scrollToTargetContentOffset:(CGPoint)contentOffset
                           behavior:(LynxScrollViewTouchBehavior)behavior
                           duration:(NSTimeInterval)duration
                           interval:(NSTimeInterval)interval
                           complete:(_Nullable UIScrollViewLynxCompletion)callback;

/**
 scroll a UIScrollView with a fixed rate
 @param rate scroll distance in every frame
 @param behavior LynxScrollViewTouchBehavior
 @param interval frame interval, default value is zero
 @param autoStop stop auto scroll if reach the bounds
 @param isVertical is vertical
 @param callback complete callback
 */
- (void)autoScrollWithRate:(CGFloat)rate
                  behavior:(LynxScrollViewTouchBehavior)behavior
                  interval:(NSTimeInterval)interval
                  autoStop:(BOOL)autoStop
                  vertical:(BOOL)isVertical
                  complete:(_Nullable UIScrollViewLynxCompletion)callback;

- (void)stopScroll;

/**
 Determine if the autoScroll is now in edge.
 */
- (BOOL)autoScrollWillReachToTheBounds;
@end

NS_ASSUME_NONNULL_END
