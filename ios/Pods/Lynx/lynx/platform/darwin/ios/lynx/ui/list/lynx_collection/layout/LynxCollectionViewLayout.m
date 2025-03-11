// Copyright 2020 The Lynx Authors. All rights reserved.
// Licensed under the Apache License Version 2.0 that can be found in the
// LICENSE file in the root directory of this source tree.

#import "LynxCollectionViewLayout.h"
#import "LynxCollectionDataSource.h"
#import "LynxCollectionInvalidationContext.h"
#import "LynxCollectionScroll.h"
#import "LynxCollectionViewLayoutModel.h"
#import "LynxCollectionViewLayoutSectionModel.h"
#import "LynxUICollection.h"

#ifndef LYNX_COLLECTION_COMPARE_EPSILON
#define LYNX_COLLECTION_COMPARE_EPSILON 0.0001
#endif

@interface LynxCollectionViewLayout ()

@property(nonatomic) LynxCollectionViewLayoutSectionModel *sectionModel;
@property(nonatomic) BOOL enableSticky;

@end

@implementation LynxCollectionViewLayout

+ (Class)invalidationContextClass {
  return [LynxCollectionInvalidationContext class];
}

- (instancetype)init {
  self = [super init];
  if (self) {
    _sectionModel = [[LynxCollectionViewLayoutSectionModel alloc] initWithItemCount:0];
    _needsAdjustContentOffsetForSelfSizingCells = NO;
  }
  return self;
}

- (void)setEnableAlignHeight:(BOOL)enableAlignHeight {
  _enableAlignHeight = enableAlignHeight;
  _sectionModel.needAlignHeight = enableAlignHeight;
}

- (void)setFixSelfSizingOffsetFromStart:(BOOL)fromStart {
  _sectionModel.fixSelfSizingOffsetFromStart = fromStart;
}

- (void)setUseOldSticky:(BOOL)useOldSticky {
  _sectionModel.useOldSticky = useOldSticky;
}

- (void)setStickyWithBounces:(BOOL)stickyWithBounces {
  _sectionModel.stickyWithBounces = stickyWithBounces;
}

- (void)setHorizontalLayout:(BOOL)useHorizontalLayout {
  _sectionModel.horizontalLayout = useHorizontalLayout;
}

- (void)prepareLayout {
  [_sectionModel layoutIfNeededForUICollectionView:self.collectionView];
}

- (NSArray *)layoutAttributesForElementsInRect:(CGRect)rect {
  NSArray<__kindof UICollectionViewLayoutAttributes *> *attributes =
      [_sectionModel layoutAttributesForElementsInRect:rect];
  if (@available(iOS 13.1, *)) {
    return attributes;
  } else {
    // For iOS 12 and previous versions. The 'invalidationContext' and corresponding invalidation in
    // performBatchUpdate will trigger a prepareLayout -- contentSize --
    // layoutAttributesForElementsInRect call sequence before numberOfItemsInSection being updated.
    // IndexPaths for attributes in NSArray returned by this call sequence will then be checked
    // against the stale item counts, which is the number of items before 'performBatchUpdate'. This
    // check will trigger an assertion failure in 'UICollectionViewData.m'. Circumvent this check by
    // filtering attributes.
    NSIndexSet *validIndices =
        [attributes indexesOfObjectsPassingTest:^BOOL(
                        __kindof UICollectionViewLayoutAttributes *_Nonnull layout, NSUInteger idx,
                        BOOL *_Nonnull stop) {
          if (layout.indexPath.row < [self.collectionView
                                         numberOfItemsInSection:layout.indexPath.section]) {
            return YES;
          }
          return NO;
        }];
    return [attributes objectsAtIndexes:validIndices];
  }
}

- (UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath {
  return [_sectionModel layoutAttributeForElementAtIndexPath:indexPath];
}

- (UICollectionViewLayoutAttributes *)layoutAttributesForStickItemAtIndexPath:
    (NSIndexPath *)indexPath {
  if ([self isStickyItem:indexPath]) {
    return [_sectionModel layoutAttributesFromCacheAtRow:indexPath.item];
  } else {
    return [_sectionModel layoutAttributeForElementAtIndexPath:indexPath];
  }
}

- (BOOL)isStickyItem:(NSIndexPath *)indexPath {
  return [_sectionModel isStickyItem:(NSInteger)(indexPath.item)];
}

- (CGSize)collectionViewContentSize {
  return [_sectionModel contentSize];
}

- (BOOL)shouldInvalidateLayoutForPreferredLayoutAttributes:
            (UICollectionViewLayoutAttributes *)preferredAttributes
                                    withOriginalAttributes:
                                        (UICollectionViewLayoutAttributes *)originalAttributes {
  // preferredAttributes is generated by LynxCollectionViewCell, which return ui.frame, align it if
  // needed
  if (self.sectionModel.horizontalLayout) {
    CGFloat uiWidth = _enableAlignHeight ? ceil(preferredAttributes.frame.size.width)
                                         : preferredAttributes.frame.size.width;
    BOOL widthChanged =
        fabs(originalAttributes.frame.size.width - uiWidth) < LYNX_COLLECTION_COMPARE_EPSILON;
    return !widthChanged;
  } else {
    CGFloat uiHeight = _enableAlignHeight ? ceil(preferredAttributes.frame.size.height)
                                          : preferredAttributes.frame.size.height;

    BOOL heightChanged =
        fabs(originalAttributes.frame.size.height - uiHeight) < LYNX_COLLECTION_COMPARE_EPSILON;
    return !heightChanged;
  }
}

- (__kindof UICollectionViewLayoutInvalidationContext *)
    invalidationContextForPreferredLayoutAttributes:
        (UICollectionViewLayoutAttributes *)preferredAttributes
                             withOriginalAttributes:
                                 (UICollectionViewLayoutAttributes *)originalAttributes {
  LYNX_LIST_DEBUG_LOG(
      @"index: %@, height: (%@ -> %@), scale: %@, delta: %@", @(preferredAttributes.indexPath.row),
      @(originalAttributes.frame.size.height), @(preferredAttributes.frame.size.height),
      @(originalAttributes.frame.size.height / preferredAttributes.frame.size.height),
      @(originalAttributes.frame.size.height - preferredAttributes.frame.size.height));
  return [[LynxCollectionInvalidationContext alloc]
      initWithSelfSizingCellAtIndexPath:preferredAttributes.indexPath
                                 bounds:preferredAttributes.bounds
                         collectionView:self.collectionView
                           isHorizontal:self.sectionModel.horizontalLayout];
}

- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds {
  return _enableSticky == YES ||
         !(CGSizeEqualToSize(newBounds.size, self.collectionView.frame.size));
}

- (void)invalidateLayoutWithContext:(UICollectionViewLayoutInvalidationContext *)uiContext {
  LynxCollectionInvalidationContext *context = (LynxCollectionInvalidationContext *)uiContext;
  if (context.didSetInitialScrollIndex) {
    _needsAdjustContentOffsetForSelfSizingCells = YES;
  }

  [_sectionModel updateWithInvalidationContext:context collectionView:self.collectionView];
  [_scroll updateWithInvalidationContext:context];

  [self calculateTargetIndexPathWithContext:context];

  if (_needUpdateValidLayoutAttributesAfterDiff) {
    [_scroll updateLastIndexPathWithValidLayoutAttributes:context];
  }
  if (_needsAdjustContentOffsetForSelfSizingCells) {
    [_sectionModel
        adjustCollectionViewContentOffsetForSelfSizingCellInvaldationIfNeeded:self.collectionView];
  }
  [super invalidateLayoutWithContext:context];
}

// make sure collection stick to current item after diff
- (void)calculateTargetIndexPathWithContext:(LynxCollectionInvalidationContext *)context {
  if (self.targetIndexPathAfterBatchUpdate) {
    NSInteger targetIndex = self.targetIndexPathAfterBatchUpdate.item;

    for (NSIndexPath *indexPath in context.removals) {
      if (indexPath.row <= self.targetIndexPathAfterBatchUpdate.item) {
        targetIndex--;
      }
    }
    for (NSIndexPath *indexPath in context.insertions) {
      if (indexPath.row <= targetIndex) {
        targetIndex++;
      }
    }

    self.targetIndexPathAfterBatchUpdate =
        [NSIndexPath indexPathForItem:targetIndex < 0 ? 0 : targetIndex inSection:0];
  }
}

- (UICollectionViewLayoutInvalidationContext *)invalidationContextForBoundsChange:
    (CGRect)newBounds {
  [_sectionModel setBounds:newBounds];
  LynxCollectionInvalidationContext *context =
      [[LynxCollectionInvalidationContext alloc] initWithBoundsChanging:newBounds];
  return context;
}

#pragma mark - Animation Related

- (void)prepareForCollectionViewUpdates:(NSArray<UICollectionViewUpdateItem *> *)updateItems {
  [_sectionModel prepareForCollectionViewUpdates:updateItems];
}

- (UICollectionViewLayoutAttributes *)initialLayoutAttributesForAppearingItemAtIndexPath:
    (NSIndexPath *)itemIndexPath {
  UICollectionViewLayoutAttributes *defaultAttributes =
      [super initialLayoutAttributesForAppearingItemAtIndexPath:itemIndexPath];
  UICollectionViewLayoutAttributes *initialLayoutAttributes = nil;

  initialLayoutAttributes =
      [_sectionModel initialLayoutAttributesForAppearingItemAtIndexPath:itemIndexPath
                                                defaultLayoutAttributes:defaultAttributes
                                                       inCollectionView:self.collectionView];
  LYNX_LIST_DEBUG_LOG(@"row: %@, %@", @(itemIndexPath.row),
                      NSStringFromCGRect(initialLayoutAttributes.frame));
  return initialLayoutAttributes;
}

- (UICollectionViewLayoutAttributes *)finalLayoutAttributesForDisappearingItemAtIndexPath:
    (NSIndexPath *)itemIndexPath {
  UICollectionViewLayoutAttributes *finalLayoutAttributes;
  finalLayoutAttributes =
      [_sectionModel finalLayoutAttributesForDisappearingItemAtIndexPath:itemIndexPath];
  LYNX_LIST_DEBUG_LOG(@"row: %@, %@", @(itemIndexPath.row),
                      NSStringFromCGRect(finalLayoutAttributes.frame));
  return finalLayoutAttributes;
}

- (void)finalizeCollectionViewUpdates {
  [_sectionModel finalizeCollectionViewUpdates];
}

- (void)prepareForCellLayoutUpdate {
  [_sectionModel prepareForCellLayoutUpdate];
}

#pragma mark - Sticky Header & Footer

- (void)setEnableSticky:(BOOL)enableSticky {
  _enableSticky = enableSticky;
  [_sectionModel setEnableSticky:enableSticky];
}

- (void)setStickyOffset:(CGFloat)stickOffset {
  [_sectionModel setStickyOffset:stickOffset];
}

- (void)setIndexAsZIndex:(BOOL)indexAsZIndex {
  _indexAsZIndex = indexAsZIndex;
  [_sectionModel setIndexAsZIndex:indexAsZIndex];
}
@end
