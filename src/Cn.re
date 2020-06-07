let none = "";

let (+) = (x1, x2) =>
  switch (x1, x2) {
  | ("", "") => none
  | (x1, "") => x1
  | ("", x2) => x2
  | (x1, x2) => {j|$(x1) $(x2)|j}
  };

let on = (cn, x) => x ? cn : none;

let onSome = (cn, x) =>
  switch (x) {
  | Some(_) => cn
  | None => none
  };

let mapSome = (x, fn) =>
  switch (x) {
  | Some(x) => x->fn
  | None => none
  };

let take =
  fun
  | Some(x) => x
  | None => none;

let onOk = (cn, x) =>
  switch (x) {
  | Ok(_) => cn
  | Error(_) => none
  };

let mapOk = (x, fn) =>
  switch (x) {
  | Ok(x) => x->fn
  | Error(_) => none
  };

let onErr = (cn, x) =>
  switch (x) {
  | Ok(_) => none
  | Error(_) => cn
  };

let mapErr = (x, fn) =>
  switch (x) {
  | Ok(_) => none
  | Error(x) => x->fn
  };

// --- Deprected

let make = cns => cns->Belt.List.keep(x => x !== "")->String.concat(" ", _);

let ifTrue = (cn, x) => x ? cn : "";

let ifSome = (cn, x) =>
  switch (x) {
  | Some(_) => cn
  | None => ""
  };

let unpack =
  fun
  | Some(x) => x
  | None => "";
