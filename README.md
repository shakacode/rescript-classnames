# re-classnames

[![npm version](https://img.shields.io/npm/v/re-classnames.svg?style=flat-square)](https://www.npmjs.com/package/re-classnames)
[![build status](https://img.shields.io/travis/alexfedoseev/re-classnames/master.svg?style=flat-square)](https://travis-ci.org/alexfedoseev/re-classnames)
[![license](https://img.shields.io/npm/l/re-classnames.svg?style=flat-square)](https://www.npmjs.com/package/re-classnames)

Simple reimplementation of [classnames](https://github.com/JedWatson/classnames) in [ReasonML](https://reasonml.github.io).

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

## Usage

### `Cn.make`
```reason
Cn.make(["one", "two"]) /* => "one two" */
```

### `Cn.ifTrue`
```reason
Cn.make(["one", "two"->Cn.ifTrue(true)]) /* => "one two" */
Cn.make(["one", "two"->Cn.ifTrue(false)]) /* => "one" */
```

### `Cn.ifSome`
```reason
Cn.make(["one", "two"->Cn.ifSome(Some("thing"))]) /* => "one two" */
Cn.make(["one", "two"->Cn.ifSome(None)]) /* => "one" */
```

### `Cn.mapSome`
```reason
type t =
  | One
  | Two
  | Tree;

Cn.make([
  "one",
  Cn.mapSome(
    Some(Two),
    fun
    | One => "one"
    | Two => "two"
    | Tree => "three",
  )
]) /* => "one two" */

Cn.make([
  "one",
  Cn.mapSome(
    None,
    fun
    | One => "one"
    | Two => "two"
    | Tree => "three",
  )
]) /* => "one" */
```

### `Cn.unpack`
```reason
Cn.make(["one", Some("two")->Cn.unpack]) /* => "one two" */
Cn.make(["one", None->Cn.unpack]) /* => "one" */
```

## License
It's MIT.
