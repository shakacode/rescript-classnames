# History

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
