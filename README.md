# re-classnames

[![version](https://img.shields.io/npm/v/re-classnames.svg?style=flat-square)](https://www.npmjs.com/package/re-classnames)
[![build](https://github.com/MinimaHQ/re-classnames/workflows/build/badge.svg)](https://github.com/MinimaHQ/re-classnames/actions?query=workflow%3Abuild)
[![license](https://img.shields.io/npm/l/re-classnames.svg?style=flat-square)](https://www.npmjs.com/package/re-classnames)

Reimplementation of [classnames](https://github.com/JedWatson/classnames) in [ReasonML](https://reasonml.github.io).

## Installation

```shell
# yarn
yarn add re-classnames

# or npm
npm install --save re-classnames
```

Then add it to `bsconfig.json`:

```json
"bs-dependencies": [
  "re-classnames"
]
```

## API
- [`(+) infix operator`](#-infix-operator)
- [`append`](#append)
- [`fromList`](#fromlist)
- [`on`](#on)
- [`onSome`](#onsome)
- [`mapSome`](#mapsome)
- [`take`](#take)
- [`onOk`](#onok)
- [`mapOk`](#mapok)
- [`onErr`](#onerr)
- [`mapErr`](#maperr)
- [`none`](#none)

### `(+) infix operator`
The primary way to build a classname is to `+` its parts. See [FAQ](#how--works) with details on how this syntax works.

```reason
Cn.("one" + "two" + "three") // => "one two three"
```

### `append`
This is equivalent to `(+)` infix operator above but in the shape of a function for composability.

```reason
Cn.append("one", "two") // => "one two"
```

### `fromList`
It's also possible to build a classname from a list of strings. Be aware that it is slower than using `(+)` operator. See [Benchmarks](#benchmarks).

```reason
Cn.fromList(["one", "two", "three"]) // => "one two three"
```

### `on`
`bool` combinator that applies classname if a value is `true`.

```reason
Cn.("one" + "two"->on(true)) // => "one two"
Cn.("one" + "two"->on(false)) // => "one"
```

### `onSome`
`option` combinator that applies classname if a value is `Some(_)`.

```reason
Cn.("one" + "two"->onSome(Some("thing"))) // => "one two"
Cn.("one" + "two"->onSome(None)) // => "one"
```

### `mapSome`
`option` combinator that maps `Some(value)` to the specific classname.

```reason
type t =
  | One
  | Two
  | Tree;

Cn.(
  "one"
  + mapSome(
      Some(Two),
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one two"

Cn.(
  "one",
  + mapSome(
      None,
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one"
```

Uncurried version:

```reason
let mapSomeU: (option('a), (. 'a) => string) => string;
```

### `take`
`option` combinator that takes `value` out of `Some(value)` and applies it as a classname.

```reason
Cn.("one" + Some("two")->take) // => "one two"
Cn.("one" + None->take) // => "one"
```

### `onOk`
`result` combinator that applies classname if a value is `Ok(_)`.

```reason
Cn.("one" + "two"->onOk(Ok("ok"))) // => "one two"
Cn.("one" + "two"->onOk(Error("err"))) // => "one"
```

### `mapOk`
`result` combinator that maps `Ok(value)` to the specific classname.

```reason
type t =
  | One
  | Two
  | Tree;

Cn.(
  "one"
  + mapOk(
      Ok(Two),
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one two"

Cn.(
  "one",
  + mapOk(
      Error(),
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one"
```

Uncurried version:

```reason
let mapOkU: (result('a, 'b), (. 'a) => string) => string;
```

### `onErr`
`result` combinator that applies classname if a value is `Error(_)`.

```reason
Cn.("one" + "two"->onErr(Ok("ok"))) // => "one"
Cn.("one" + "two"->onErr(Error("err"))) // => "one two"
```

### `mapErr`
`result` combinator that maps `Error(value)` to the specific classname.

```reason
type t =
  | One
  | Two
  | Tree;

Cn.(
  "one"
  + mapErr(
      Ok(Two),
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one"

Cn.(
  "one",
  + mapErr(
      Error(),
      fun
      | One => "one"
      | Two => "two"
      | Tree => "three",
    )
) // => "one two"
```

Uncurried version:

```reason
let mapErrU: (result('a, 'b), (. 'b) => string) => string;
```

### `none`
An alias of an empty string `""`. It supposed to be used to express the absence of a classname in a more explicit manner.

```reason
Cn.(
  switch (x) {
  | Loading => Css.loading
  | Loaded => ""
  }
);

// vs

Cn.(
  switch (x) {
  | Loading => Css.loading
  | Loaded => none
  }
);
```

## Benchmarks
```
Cn.(+) x 3,781,425 ops/sec ±0.56% (90 runs sampled)
Cn.fromList x 1,545,656 ops/sec ±0.61% (93 runs sampled)
classnames.js x 926,701 ops/sec ±0.82% (89 runs sampled)
```

## FAQ
### How (+) works
In Reason, you can define your own infix operators.

```reason
1 + 1 // => 2
"1" ++ "1" // => "11"
"1" + "1" // => error, `+` is for ints

let (+) = (x1, x2) => x1 ++ x2;
"1" + "1" // => "11"
```

`Cn.(+)` is an infix operator that takes 2 strings and combines them into a valid classname:

```reason
Cn.("one" + "two") // => "one two"
```

What about `Cn.()` part? Since `(+)` operator is defined inside `Cn` module, to apply it, you need to bring it into the scope. You can do so by [locally open](https://reasonml.github.io/docs/en/module#open-ing-a-module) `Cn` module:

```reason
Cn.(
  // everything from Cn module is now available here,
  // including (+) operator, combinators etc.
)
```

### Warning 44
In the default BuckleScript configuration, you might see a warning `44` when using `(+)` operator. For some reason, BuckleScript enables this warning by default, although it is disabled in the modern OCaml.

What does it mean? Since `(+)` operator is available globally as infix operator for summing ints, opening `Cn` module would shadow it by its own `(+)` operator.

There are 2 ways to handle this.
1. Disable warning `44` via `bsconfig.json`:
```json
"warnings": {
  "number": "-44"
}
```

2. Use alternative infix operator, provided by `Cn`:
```reason
Cn.("one" <:> "two" <:> "three") // => "one two three"
```

### Uncurried versions
All `map*` functions have [uncurried versions](https://bucklescript.github.io/docs/en/function#solution-guaranteed-uncurrying):

```reason
let mapSomeU: (option('a), (. 'a) => string) => string;

Cn.mapSomeU(
  Some(Two),
  (. x) =>
    switch (x) {
    | One => "one"
    | Two => "two"
    | Tree => "three"
    },
)
```

It might gain a tiny bit of performance but in the majority of the cases, it wouldn't be noticeable.

## License
See [LICENSE](./LICENSE).
