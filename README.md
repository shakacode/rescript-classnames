# rescript-classnames

[![version](https://img.shields.io/npm/v/rescript-classnames.svg?style=flat-square)](https://www.npmjs.com/package/rescript-classnames)
[![build](https://github.com/MinimaHQ/rescript-classnames/workflows/build/badge.svg)](https://github.com/MinimaHQ/rescript-classnames/actions?query=workflow%3Abuild)
[![license](https://img.shields.io/npm/l/rescript-classnames.svg?style=flat-square)](https://www.npmjs.com/package/rescript-classnames)

Reimplementation of [classnames](https://github.com/JedWatson/classnames) in [ReScript](https://rescript-lang.org).

## Installation

```shell
# yarn
yarn add rescript-classnames

# or npm
npm install --save rescript-classnames
```

Then add it to `bsconfig.json`:

```json
"bs-dependencies": [
  "rescript-classnames"
]
```

## API
You can use either `Cn.make` function:

```rescript
Cn.make(["one", "two", "three"]) // => "one two three"
```

Or open `Cx` module and use `cx` alias:

```rescript
open Cx

cx(["one", "two", "three"]) // => "one two three"
```

You can open `Cx` module globally via `bsconfig.json` and `cx` function will be available everywhere without a need to `open Cx`.

```json
"bsc-flags": ["-open Cx"]
```

To conditionally render a classname, use an empty string to indicate an absence of it.

```rescript
cx(["button", disabled ? "disabled" : ""])
```

Or use pattern matching to select the right classname for an input:

```rescript
cx([
  "button",
  disabled ? "disabled" : "",
  switch color {
  | Green => "green"
  | Red => "red"
  },
])
```

## Performance
First of all, if you are really concerned with performance, consider using string interpolation as it's the fastest possible way to render classnames.

```rescript
`button ${disabled ? "disabled" : ""}`
```

Otherwise, `rescript-classnames` is reasonably fast.

```
js interpolation x 775,890,362 ops/sec ±1.46% (87 runs sampled)
rescript-classnames x 2,493,334 ops/sec ±0.64% (89 runs sampled)
classnames.js x 794,502 ops/sec ±0.62% (91 runs sampled)
```

## License
See [LICENSE](./LICENSE).
