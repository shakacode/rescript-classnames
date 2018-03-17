let make = (classNames: list(string)) : string =>
  classNames
  |> List.filter(className => className !== "")
  |> String.concat(" ");

let ifBool = (maybe, className) => maybe ? className : "";

let ifOpt = maybe =>
  switch (maybe) {
  | Some(value) => value
  | None => ""
  };

let mapOpt = (maybe, map) =>
  switch (maybe) {
  | Some(value) => value |> map
  | None => ""
  };
