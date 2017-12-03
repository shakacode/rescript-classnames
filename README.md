# re-classnames

Simple reimplementation of [classnames](https://github.com/JedWatson/classnames) in [ReasonML](https://reasonml.github.io).

## Installation

```shell
# yarn / npm
yarn add re-classnames
npm install --save re-classnames
```

## Usage

```reason
Cn.make(["one", "two"]) /* => "one two" */
```

### `Cn.ifBool`
```reason
Cn.make(["one", "two" |> Cn.ifBool(true)]) /* => "one two" */
Cn.make(["one", "two" |> Cn.ifBool(false)]) /* => "one" */
```

### `Cn.ifOpt`
```reason
/* Cn.ifOpt */
Cn.make(["one", Some("two") |> Cn.ifOpt]) /* => "one two" */
Cn.make(["one", None |> Cn.ifOpt]) /* => "one" */
```

### `Cn.mapOpt`
```reason
type t =
  | One
  | Two
  | Tree;

Cn.make([
  "one",
  Cn.mapOpt(
    Some(Two),
    (v) =>
      switch v {
      | One => "one"
      | Two => "two"
      | Tree => "three"
      }
  )
]) /* => "one two" */

Cn.make([
  "one",
  Cn.mapOpt(
    None,
    (v) =>
      switch v {
      | One => "one"
      | Two => "two"
      | Tree => "three"
      }
  )
]) /* => "one" */
```

## License
It's MIT.
