# rescript-classnames

[![version](https://img.shields.io/npm/v/rescript-classnames.svg?style=flat-square)](https://www.npmjs.com/package/rescript-classnames)
[![build](https://github.com/MinimaHQ/rescript-classnames/workflows/build/badge.svg)](https://github.com/MinimaHQ/rescript-classnames/actions?query=workflow%3Abuild)
[![license](https://img.shields.io/npm/l/rescript-classnames.svg?style=flat-square)](https://www.npmjs.com/package/rescript-classnames)

Reimplementation of [classnames](https://github.com/JedWatson/classnames) in [ReScript](https://rescript-lang.org).

> ### ShakaCode
> If you are looking for help with the development and optimization of your project, [ShakaCode](https://www.shakacode.com) can help you to take the reliability and performance of your app to the next level.
>
> If you are a developer interested in working on ReScript / TypeScript / Rust / Ruby on Rails projects, [we're hiring](https://www.shakacode.com/career/)!

## Installation

```shell
# yarn
yarn add rescript-classnames

# or npm
npm install --save rescript-classnames
```

Then add it to `rescript.json`:

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

P.S. To run benchmarks, change `package-specs.module` to `commonjs` in `rescript.json`.

## License
See [LICENSE](./LICENSE).

## Supporters

<a href="https://www.jetbrains.com">
  <img src="https://user-images.githubusercontent.com/4244251/184881139-42e4076b-024b-4b30-8c60-c3cd0e758c0a.png" alt="JetBrains" height="120px">
</a>
<a href="https://scoutapp.com">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/4244251/184881147-0d077438-3978-40da-ace9-4f650d2efe2e.png">
    <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/4244251/184881152-9f2d8fba-88ac-4ba6-873b-22387f8711c5.png">
    <img alt="ScoutAPM" src="https://user-images.githubusercontent.com/4244251/184881152-9f2d8fba-88ac-4ba6-873b-22387f8711c5.png" height="120px">
  </picture>
</a>
<br />
<a href="https://www.browserstack.com">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/4244251/184881122-407dcc29-df78-4b20-a9ad-f597b56f6cdb.png">
    <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/4244251/184881129-e1edf4b7-3ae1-4ea8-9e6d-3595cf01609e.png">
    <img alt="BrowserStack" src="https://user-images.githubusercontent.com/4244251/184881129-e1edf4b7-3ae1-4ea8-9e6d-3595cf01609e.png" height="55px">
  </picture>
</a>
<a href="https://railsautoscale.com">
  <img src="https://user-images.githubusercontent.com/4244251/184881144-95c2c25c-9879-4069-864d-4e67d6ed39d2.png" alt="Rails Autoscale" height="55px">
</a>
<a href="https://www.honeybadger.io">
  <img src="https://user-images.githubusercontent.com/4244251/184881133-79ee9c3c-8165-4852-958e-31687b9536f4.png" alt="Honeybadger" height="55px">
</a>

<br />
<br />

The following companies support our open source projects, and ShakaCode uses their products!
