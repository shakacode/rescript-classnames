let make = (classNames: list(string)) : string =>
  classNames
  |> List.filter(className => className !== "")
  |> String.concat(" ");

let ifTrue = (maybe, className) => maybe ? className : "";

let ifSome = (maybe, className) =>
  switch (maybe) {
  | Some(_) => className
  | None => ""
  };

let mapSome = (maybe, map) =>
  switch (maybe) {
  | Some(value) => value |> map
  | None => ""
  };

let unwrap = maybe =>
  switch (maybe) {
  | Some(value) => value
  | None => ""
  };
