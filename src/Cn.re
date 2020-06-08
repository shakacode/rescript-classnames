let none = "";

let append = (x1, x2) =>
  switch (x1, x2) {
  | ("", x)
  | (x, "") => x
  | (x1, x2) => x1 ++ " " ++ x2
  };

let (+) = append;

let (<:>) = append; // Alt infix for users with warning 44 enabled

let fromList = {
  let rec aux = acc =>
    fun
    | [] => acc
    | ["", ...rest] => aux(acc, rest)
    | [cn, ...rest] => aux(acc ++ " " ++ cn, rest);
  aux("");
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

let mapSomeU = (x, fn) =>
  switch (x) {
  | Some(x) => fn(. x)
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

let mapOkU = (x, fn) =>
  switch (x) {
  | Ok(x) => fn(. x)
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

let mapErrU = (x, fn) =>
  switch (x) {
  | Ok(_) => none
  | Error(x) => fn(. x)
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
