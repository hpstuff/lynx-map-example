//
//  AppleMap.h
//  Hello-Lynx-OC
//
//  Created by Rumen Russanov on 12.03.25.
//

#import <MapKit/MapKit.h>
#import <UIKit/UIKit.h>
#import <Lynx/LynxUI.h>

NS_ASSUME_NONNULL_BEGIN

@interface MapView : MKMapView
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                  zoomLevel:(double)zoomLevel
                   animated:(BOOL)animated;

- (double)zoomLevel;
@end

@interface LynxMapUIView : LynxUI <MapView *> <MKMapViewDelegate>

@property(nonatomic, retain) NSNumber* latitude;
@property(nonatomic, retain) NSNumber* longitude;
@property(nonatomic, retain) NSNumber* zoom;

@end

NS_ASSUME_NONNULL_END
