//
//  GoogleMaps.m
//  Hello-Lynx-OC
//
//  Created by Rumen Russanov on 9.03.25.
//

#import "GoogleMaps.h"
#import <Lynx/LynxComponentRegistry.h>
#import <Lynx/LynxPropsProcessor.h>
#import <Lynx/LynxUIMethodProcessor.h>

@implementation LynxGoogleMapView {
  GoogleMapsView *_mapView;
  NSMutableDictionary* _markers;
}

LYNX_LAZY_REGISTER_UI("google-map");

- (GoogleMapsView *)createView {
  GMSCameraPosition *camera = [GMSCameraPosition cameraWithLatitude:-33.86 longitude:151.20 zoom:12];
  _mapView = [GoogleMapsView mapWithFrame:CGRectZero camera:camera];
  
  _mapView.delegate = self;
  return _mapView;
}


LYNX_PROP_SETTER("latitude", setLatitude, NSNumber *) {
  self.latitude = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxGoogleMapView *)ui) updateCenter];
  }];
}
LYNX_PROP_SETTER("longitude", setLongitude, NSNumber *) {
  self.longitude = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxGoogleMapView *)ui) updateCenter];
  }];
}
LYNX_PROP_SETTER("zoom", setZoom, NSNumber *) {
  self.zoom = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxGoogleMapView *)ui) updateCenter];
  }];
}

LYNX_UI_METHOD(addMarker) {
  NSString *markerId = params[@"id"];
  NSNumber *latitude = params[@"latitude"];
  NSNumber *longitude = params[@"longitude"];
  
  CLLocationCoordinate2D mapCenter = CLLocationCoordinate2DMake(latitude.doubleValue, longitude.doubleValue);
  
  if (_markers == NULL) {
    _markers = [NSMutableDictionary new];
  }
  
  GMSMarker *existingMarker = [_markers objectForKey:markerId];
  
  if (existingMarker != NULL) {
    existingMarker.position = mapCenter;
  }else {
    GMSMarker *marker = [GMSMarker markerWithPosition:mapCenter];
    
    marker.map = _mapView;
    
    [_markers setObject:marker
                 forKey:markerId];
  }
  
  callback(kUIMethodSuccess, nil);
}

- (void)emitEvent:(NSString *)name detail:(NSDictionary *)detail {
  LynxCustomEvent *eventInfo = [[LynxDetailEvent alloc] initWithName:name
                                                          targetSign:[self sign]
                                                              detail:detail];
  [self.context.eventEmitter dispatchCustomEvent:eventInfo];
}

- (BOOL)mapView:(GMSMapView *)mapView didTapMarker:(GMSMarker *)marker {
  NSArray *keys = [_markers allKeysForObject:marker];
  [self emitEvent:@"markertap" detail: @{ @"id": [keys objectAtIndex:0] }];
  return YES;
}

- (void)mapView:(GMSMapView *)mapView didChangeCameraPosition:(GMSCameraPosition *)position {
  [self emitEvent:@"camerapositionchange" detail: @{
    @"latitude": [[NSNumber alloc] initWithDouble: position.target.latitude],
    @"longitude": [[NSNumber alloc] initWithDouble: position.target.longitude],
    @"zoom": [[NSNumber alloc] initWithDouble: position.zoom],
  }];
}

- (void)updateCenter {
  if (self.latitude != NULL && self.longitude != NULL) {
    float zoom = self.zoom.floatValue;
    if (self.zoom == NULL) {
      zoom = 14;
    }
    GMSCameraPosition *camera = [GMSCameraPosition cameraWithLatitude:self.latitude.doubleValue
                                                            longitude:self.longitude.doubleValue
                                                                 zoom:zoom];
    
    [self.view animateWithCameraUpdate:[GMSCameraUpdate setCamera:camera]];
  }
}


@end

@implementation GoogleMapsView

@end
