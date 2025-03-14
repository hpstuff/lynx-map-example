import { Loader } from '@googlemaps/js-api-loader';

interface GoogleMarkerProps {
  id: string;
  latitude: number;
  longitude: number;
}

class GoogleMapElement extends HTMLElement {
  private loader: Loader;
  private map?: google.maps.Map;
  private latitude?: number;
  private longitude?: number;
  private zoom?: number;

  static get observedAttributes() {
    return ["latitude", "longitude", "zoom"];
  }

  private markerQueue: GoogleMarkerProps[] = [];
  private markers: { [key: string]: google.maps.marker.AdvancedMarkerElement } = {};

  constructor() {
    super();
    this.loader = new Loader({
      apiKey: "GOOGLE_MAPS_API_KEY",
      libraries: ["maps"],
    });
  }
  addMarker(params: GoogleMarkerProps) {
    if (this.map == null) {
      this.markerQueue.push(params);
      return;
    }
    this.loader.importLibrary("marker").then(({ AdvancedMarkerElement }) => {
      if (this.markers[params.id] != null) {
        this.markers[params.id].position = {
          lat: params.latitude,
          lng: params.longitude,
        };
      } else {
        const marker = new AdvancedMarkerElement({
          position: {
            lat: params.latitude,
            lng: params.longitude
          },
        });

        marker.addListener("click", () => {
          const event = new CustomEvent("markertap", {
            detail: {
              id: params.id,
            },
          });
          this.dispatchEvent(event);
        });

        this.markers[params.id] = marker;
        marker.map = this.map;
      }
    });
  }

  connectedCallback() {
    const div = document.createElement("div");
    div.classList.add("map-wrapper");

    const style = document.createElement("style");
    style.textContent = `
      .map-wrapper {
        height: 100%;
      }
    `;

    if (this.hasAttribute('latitude')) {
      this.latitude = parseFloat(this.getAttribute('latitude') || '0');
    }

    if (this.hasAttribute('longitude')) {
      this.longitude = parseFloat(this.getAttribute('longitude') || '0');
    }

    if (this.hasAttribute('zoom')) {
      this.zoom = parseFloat(this.getAttribute('zoom') || '0');
    }

    this.loader.importLibrary('maps').then(({ Map }) => {
      this.map = new Map(div, {
        mapId: "GOOGLE_MAPS_MAP_ID",
        center: { lat: this.latitude!, lng: this.longitude! },
        zoom: this.zoom,
        disableDefaultUI: true,
      });
      if (this.markerQueue.length > 0) {
        this.markerQueue.forEach((params) => {
          this.addMarker(params);
        });
      }
      this.map.addListener("center_changed", () => {
        if (this.map == null) {
          return;
        }

        const event = new CustomEvent("camerapositionchange", {
          detail: {
            latitude: this.map.getCenter()!.lat(),
            longitude: this.map.getCenter()!.lng(),
            zoom: this.map.getZoom(),
          },
        });
        this.dispatchEvent(event);
      });
      shadow.appendChild(div);
    });
    const shadow = this.attachShadow({ mode: "open" });

    shadow.appendChild(style);
  }

  attributeChangedCallback(name: string, _: string, newValue: string) {
    console.log(name, newValue);
    switch (name) {
      case 'latitude':
        this.latitude = parseFloat(newValue);
        break;
      case 'longitude':
        this.longitude = parseFloat(newValue);
        break;
      case 'zoom':
        this.zoom = parseFloat(newValue);
        break;
    }

    if (this.map != null) {
      this.map.setCenter({ lat: this.latitude!, lng: this.longitude! });
      this.map.setZoom(this.zoom!);
    }
  }
}

customElements.define(
  "google-map",
  GoogleMapElement,
);

customElements.define(
  "apple-map",
  class extends GoogleMapElement { }
);


