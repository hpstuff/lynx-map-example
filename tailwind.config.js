const lynxPreset = require('@lynx-js/tailwind-preset');

/** @type {import('tailwindcss').Config} */
export default {
  mode: 'jit',
  presets: [lynxPreset], // Use the preset
  content: ['./src/**/*.{js,ts,jsx,tsx}'], // Adjust paths as needed
  purge: ['./src/**/*.{js,ts,jsx,tsx}'],
  plugins: [],
  theme: {
    extend: {
      colors: {
        transparent: 'transparent',
        current: 'currentColor',
        'white': '#ffffff',
        'purple': '#3f3cbb',
        'midnight': '#121063',
        'metal': '#565584',
        'tahiti': '#3ab7bf',
        'silver': '#ecebff',
        'bubble-gum': '#ff77e9',
        'bermuda': '#78dcca',
      },
    },
  },
};
