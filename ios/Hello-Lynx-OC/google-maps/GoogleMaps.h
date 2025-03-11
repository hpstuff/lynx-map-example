//
//  GoogleMaps.h
//  Hello-Lynx-OC
//
//  Created by Rumen Russanov on 9.03.25.
//
@import GoogleMaps;

#import <Lynx/LynxUI.h>

NS_ASSUME_NONNULL_BEGIN

@interface GoogleMapsView : GMSMapView

@end

@interface LynxGoogleMapView : LynxUI <GoogleMapsView *> <GMSMapViewDelegate>

@property(nonatomic, assign) NSNumber* latitude;
@property(nonatomic, assign) NSNumber* longitude;
@property(nonatomic, assign) NSNumber* zoom;

@end

NS_ASSUME_NONNULL_END
