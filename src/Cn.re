let make = cns => cns->Belt.List.keep(x => x !== "")->String.concat(" ", _);

let ifTrue = (cn, x) => x ? cn : "";

let ifSome = (cn, x) =>
  switch (x) {
  | Some(_) => cn
  | None => ""
  };

let mapSome = (x, fn) =>
  switch (x) {
  | Some(x) => x->fn
  | None => ""
  };

let unpack =
  fun
  | Some(x) => x
  | None => "";
