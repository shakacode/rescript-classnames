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

## Supporters

<a href="https://www.jetbrains.com">
  <img src="https://user-images.githubusercontent.com/4244251/184837695-2c00e329-7241-4d9b-9373-644c1ce215be.png" alt="JetBrains" height="120px">
</a>
<a href="https://scoutapp.com">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/4244251/184837700-a910106b-1b1b-4117-88b8-9b5389425e66.png">
    <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/4244251/184837704-83960568-1599-485b-b184-5fd8b05d5051.png">
    <img alt="ScoutAPM" src="https://user-images.githubusercontent.com/4244251/184837704-83960568-1599-485b-b184-5fd8b05d5051.png" height="120px">
  </picture>
</a>
<br />
<a href="https://www.browserstack.com">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/4244251/184838560-ada89877-abd1-4d11-b144-b52ef69e0bb9.png">
    <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/4244251/184838569-35f4d4b1-5545-4ee4-a015-41ca7a5dbc7c.png">
    <img alt="BrowserStack" src="https://user-images.githubusercontent.com/4244251/184838569-35f4d4b1-5545-4ee4-a015-41ca7a5dbc7c.png" height="55px">
  </picture>
</a>
<a href="https://railsautoscale.com">
  <img src="https://user-images.githubusercontent.com/4244251/184838579-f8c2fd95-f376-4f0d-a661-50bbdeee892b.png" alt="Rails Autoscale" height="55px">
</a>
<a href="https://www.honeybadger.io">
  <img src="https://user-images.githubusercontent.com/4244251/184838575-e56cac82-5853-448c-a623-67280a91d75f.png" alt="Honeybadger" height="55px">
</a>

<br />
<br />

The following companies support our open source projects, and ShakaCode uses their products!
