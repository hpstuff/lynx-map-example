export default {
  plugins: {
    cssnano: process.env["NODE_ENV"] === "production" ? {} : false,
  },
};
