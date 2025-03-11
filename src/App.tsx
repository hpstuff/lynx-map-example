import { useCallback, useEffect, useRef, useState } from '@lynx-js/react'
import type { EventHandler, StandardProps } from '@lynx-js/types';

import './App.css'

interface LynxBaseEvent<T> {
  detail: T
}

interface MapCameraPositionChange {
  latitude: number;
  longitude: number;
  zoom: number;
}

interface MapMarkerTap {
  id: string;
}

export interface MapProps extends StandardProps {
  latitude?: number | undefined;
  longitude?: number | undefined;
  zoom?: number | undefined;
  bindmarkertap: EventHandler<LynxBaseEvent<MapMarkerTap>>;
  bindcamerapositionchange?: EventHandler<LynxBaseEvent<MapCameraPositionChange>>;
}

declare global {
  namespace JSX {
    interface IntrinsicElements {
      'google-map': MapProps;
      'apple-map': MapProps;
    }
  }
}

export function App() {
  const [latitude, setLatitude] = useState(-33.86);
  const [longitude, setLongitude] = useState(151.20);
  const [zoom, setZoom] = useState(12.0);
  const timeoutId = useRef<NodeJS.Timeout | null>(null);
  const [open, setOpen] = useState(false);

  useEffect(() => {
    'background only'
    lynx
      .createSelectorQuery()
      .select("#map")
      .invoke({
        "method": "addMarker",
        "params": {
          id: "sofia-marker",
          latitude: 42.69751,
          longitude: 23.32415,
        },
      })
      .exec();
  }, []);

  const onTap = useCallback(() => {
    'background only'
    setLatitude(42.69751);
    setLongitude(23.32415);
    setZoom(12.0);
  }, [])

  const onMarkerTap = useCallback((e: LynxBaseEvent<MapMarkerTap>) => {
    'background only'
    console.log("marker.id:", e.detail.id);
    setOpen(true);
  }, []);

  const onCameraPositionChange = useCallback((e: LynxBaseEvent<MapCameraPositionChange>) => {
    'background only'
    clearTimeout(timeoutId.current!);
    timeoutId.current = setTimeout(() => {
      console.log("camera position change:", JSON.stringify(e.detail));
      setLatitude(e.detail.latitude);
      setLongitude(e.detail.longitude);
      setZoom(e.detail.zoom);
    }, 300);
  }, []);

  const onClose = useCallback(() => {
    'background only'
    setOpen(false);
  }, []);

  return (
    <view className={'container'}>
      <apple-map id='map' className='map' latitude={latitude} longitude={longitude} zoom={zoom} bindmarkertap={onMarkerTap} bindcamerapositionchange={onCameraPositionChange} />
      <view className={'overlay'}>
        <text>{`lat: ${latitude}, lon: ${longitude}`}</text>
      </view>
      <view className={'button'} bindtap={onTap}>
        <text>+</text>
      </view>
      <view className={`modal ${open && 'open'}`}>
        <view className='close-button' bindtap={onClose}>
          <text>✖</text>
        </view>
      </view>
    </view>
  )
}
