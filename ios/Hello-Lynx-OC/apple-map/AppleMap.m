//
//  AppleMap.m
//  Hello-Lynx-OC
//
//  Created by Rumen Russanov on 12.03.25.
//
#import "AppleMap.h"
#import <Lynx/LynxComponentRegistry.h>
#import <Lynx/LynxPropsProcessor.h>
#import <Lynx/LynxUIMethodProcessor.h>

@implementation LynxMapUIView {
  MapView *_mapView;
  NSMutableDictionary* _markers;
}

LYNX_LAZY_REGISTER_UI("apple-map");

- (MapView *)createView {
  
  _mapView = [[MapView alloc] init];
  
  _mapView.delegate = self;
  return _mapView;
}

LYNX_PROP_SETTER("latitude", setLatitude, NSNumber *) {
  self.latitude = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxMapUIView *)ui) updateCenter];
  }];
}
LYNX_PROP_SETTER("longitude", setLongitude, NSNumber *) {
  self.longitude = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxMapUIView *)ui) updateCenter];
  }];
}
LYNX_PROP_SETTER("zoom", setZoom, NSNumber *) {
  self.zoom = value;
  
  [self.nodeReadyBlockArray addObject:^(LynxUI *ui) {
    [((LynxMapUIView *)ui) updateCenter];
  }];
}

- (void) updateCenter {
  if (self.latitude != NULL && self.longitude != NULL) {
    double zoom = self.zoom.doubleValue;
    if (self.zoom == NULL) {
      zoom = 14;
    }
    
    CLLocationCoordinate2D center = CLLocationCoordinate2DMake(self.latitude.doubleValue, self.longitude.doubleValue);
    
    [self.view setCenterCoordinate:center zoomLevel:zoom animated:NO];
  }
}

- (void)emitEvent:(NSString *)name detail:(NSDictionary *)detail {
  LynxCustomEvent *eventInfo = [[LynxDetailEvent alloc] initWithName:name
                                                          targetSign:[self sign]
                                                              detail:detail];
  [self.context.eventEmitter dispatchCustomEvent:eventInfo];
}

- (void)mapView:(MKMapView *)mapView didSelectAnnotation:(id<MKAnnotation>)annotation {
  NSArray *keys = [_markers allKeysForObject:annotation];
  [self emitEvent:@"markertap" detail: @{ @"id": [keys objectAtIndex:0] }];
}

- (void)mapViewDidChangeVisibleRegion:(MKMapView *)mapView {
  CLLocationCoordinate2D center = self.view.centerCoordinate;
  CGFloat zoom = [self.view zoomLevel];
  
  [self emitEvent:@"camerapositionchange" detail: @{
    @"latitude": [[NSNumber alloc] initWithDouble: center.latitude],
    @"longitude": [[NSNumber alloc] initWithDouble: center.longitude],
    @"zoom": [[NSNumber alloc] initWithDouble: zoom],
  }];
}

LYNX_UI_METHOD(addMarker) {
  NSString *markerId = params[@"id"];
  NSNumber *latitude = params[@"latitude"];
  NSNumber *longitude = params[@"longitude"];
  
  CLLocationCoordinate2D centerCoordinate = CLLocationCoordinate2DMake(latitude.doubleValue, longitude.doubleValue);
  
  if (_markers == NULL) {
    _markers = [NSMutableDictionary new];
  }
  
  MKPointAnnotation *existingAnnotation = [_markers objectForKey:markerId];
  
  if (existingAnnotation != NULL) {
    [existingAnnotation setCoordinate:centerCoordinate];
  }else {
    MKPointAnnotation *annotation = [[MKPointAnnotation alloc] init];
    [annotation setCoordinate:centerCoordinate];
    [self.view addAnnotation:annotation];
    
    [_markers setObject:annotation
                 forKey:markerId];
  }
  
  callback(kUIMethodSuccess, nil);
}

@end

@implementation MapView

- (double)zoomLevel {
  return log2(360.0 * ((self.frame.size.width/256.0) / self.region.span.longitudeDelta));
}

- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                  zoomLevel:(double)zoomLevel
                   animated:(BOOL)animated
{
  MKCoordinateSpan span = MKCoordinateSpanMake(0, 360.0/pow(2, zoomLevel)*self.frame.size.width/256.0);
  [self setRegion:MKCoordinateRegionMake(centerCoordinate, span) animated:animated];
}


@end
