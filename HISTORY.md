# History

## 7.0.0
- `rescript` is updated to `v11`.
- **[ BREAKING ]** Old Reason API is removed.

## 6.0.0
- Library transitioned to the ReScript syntax with the new name: `rescript-classnames`.
- **[ BREAKING ]** We reduced the API surface by a lot. See [re-classnames#api](https://github.com/MinimaHQ/re-classnames#api).
- **[ DEPRECATED ]** Old api is deprecated and available under `CnRe` namespace.

## 5.0.1
- Even faster :) Thanks, **[@Et7f3](https://github.com/Et7f3)**!

## 5.0.0
- Perf! We're ~5.5 times faster than `v4` and ~4 times faster than [`classnames.js`](https://www.npmjs.com/package/classnames) counterpart.
- **[ NEW ]** `(+)` infix operator
- **[ NEW ]** `append` function
- **[ NEW ]** `fromList` function
- **[ NEW ]** `none` alias
- **[ NEW ]** `onOk` combinator
- **[ NEW ]** `mapOk` combinator
- **[ NEW ]** `onErr` combinator
- **[ NEW ]** `mapErr` combinator
- **[ DEPRECATED ]** `make`. Use either `(+)` (recommended) or `fromList` (slower).
- **[ DEPRECATED ]** `ifTrue`. Use `on`.
- **[ DEPRECATED ]** `ifSome`. Use `onSome`.
- **[ DEPRECATED ]** `unpack`. Use `take`.

## 4.1.0
- `bs-platform` updated to `v7`.

## 4.0.0
- **[ BREAKING ]** `bs-platform` updated to `5.0.0`.

## 3.0.0
- **[ BREAKING ]** API style is changed from data-last to data-first (use `->` instead of `|>`)
- **[ BREAKING ]** `Cn.unwrap` renamed to `Cn.unpack` (in Rust `unwrap` throws on `None`, while `Cn` just ignores it)
- **[ BREAKING ]** `ClassNames` module is removed, use `Cn`


## 2.1.0
- `bs-platform` updated to `4.0.2`.

## 2.0.0
- **[ BREAKING ]** `Cn.ifBool` renamed to `Cn.ifTrue`
- **[ BREAKING ]** `Cn.ifOpt` renamed to `Cn.unwrap`
- **[ BREAKING ]** `Cn.mapOpt` renamed to `Cn.mapSome`
- `Cn.ifSome` added.

## 1.1.0
- `bs-platform` updated to `3.0.0`.

## 1.0.0
- **[ BREAKING ]** `bs-platform` updated to `2.2.2`.

## 0.0.1
Initial release.
