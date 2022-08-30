module.exports = {
  purge: [
    './pages/**/*.{js,ts,jsx,tsx}',
    './components/**/*.{js,ts,jsx,tsx}'
  ],
  darkMode: false, // or 'media' or 'class'
  theme: {
    extend: {},
    olors: {
      'blue': '#222160',
      'red': '#e61e2a',
      'yellow': '#fac800',
    },
  },
  variants: {
    extend: {},
  },
  plugins: [],
}
