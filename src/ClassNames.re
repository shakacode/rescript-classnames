let make = (classNames: list(string)) : string =>
  List.filter(className => className !== "", classNames)
  |> String.concat(" ");

let ifBool = (maybe, className) => maybe ? className : "";

let ifOpt = maybe =>
  switch (maybe) {
  | Some(value) => value
  | None => ""
  };

let mapOpt = (maybe, map) =>
  switch (maybe) {
  | Some(value) => map(value)
  | None => ""
  };
