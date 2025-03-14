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
          latitude: 42.658793,
          longitude: 23.3156789,
        },
      })
      .exec();
  }, []);

  const onTap = useCallback(() => {
    'background only'
    setLatitude(42.658793);
    setLongitude(23.3156789);
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
    <view className={'bg-white h-screen w-screen'}>
      <apple-map id='map' className={'fixed w-screen h-screen bg-purple'} latitude={latitude} longitude={longitude} zoom={zoom} bindmarkertap={onMarkerTap} bindcamerapositionchange={onCameraPositionChange} />
      <view className={'fixed safe-b bottom-0 w-screen flex justify-center'}>
        <view className={'bg-white py-2 px-3 rounded-full mb-6 shadow-sm'}>
          <text className={'text-black'}>{`lat: ${latitude.toFixed(3)}, lon: ${longitude.toFixed(3)}`}</text>
        </view>
      </view>
      <view className={'fixed w-[50px] h-[50px] bottom-[40px] right-[20px] rounded-full bg-white flex items-center justify-center active:bg-gray-200'} bindtap={onTap}>
        <text className={'icon'}></text>
      </view>
      <view className={`w-screen h-[300px] bg-white rounded-t-xl bottom-0 left-0 fixed translate-y-[100%] modal ${open && 'open' }`}>
        <view className={'absolute top-2 right-2 p-2 active:opacity-60 z-50'} bindtap={onClose}>
          <text className='icon'>󰅙</text>
        </view>
        <view className={'p-4 pt-8'}>
          <text className={'text-xl font-bold'}>{"LATE Café & Roastery"}</text>
          <view className={'text-gray-500'}>
            <text className={'text-sm'}>{"Hladilnika, Blvd. \"Cherni vrah\" 100, 1407 Sofia"}</text>
          </view>
          <view className={'flex items-start gap-2 py-8'}>
            <view className={'flex w-auto bg-black rounded-full text-white items-center px-2 py-1'}>
              <text className="icon text-md mr-1 text-white"></text>
              <text className="text-md text-white">26 min</text>
            </view>
            <view className={'flex w-auto bg-black text-white rounded-full items-center px-2 py-1'}>
              <text className="icon text-md mr-1 text-white">󰂣</text>
              <text className="text-md text-white">14 min</text>
            </view>
            <view className={'flex w-auto bg-black text-white rounded-full items-center px-2 py-1'}>
              <text className="icon text-md mr-1 text-white"></text>
              <text className="text-md text-white">6 min</text>
            </view>
          </view>
        </view>
      </view>
    </view>
  )
}
