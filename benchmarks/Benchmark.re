module Cycle = {
  type t;
  [@bs.get] external target: t => string = "target";
  let result = x => x->target->Js.String.make;
};

module Suite = {
  type t;

  [@bs.module "benchmark"] [@bs.new] external make: string => t = "Suite";

  [@bs.send] external case: (t, string, unit => 'a) => t = "add";

  [@bs.send]
  external on:
    (
      t,
      [@bs.string] [
        | `cycle(Cycle.t => unit)
        | `complete([@bs.this] (t => unit))
      ]
    ) =>
    t =
    "on";
  [@bs.send] external run: t => unit = "run";
};

module Result = {
  type t;
  [@bs.send] external fastest: (Suite.t, [@bs.as "fastest"] _) => t = "filter";
  [@bs.send] external name: (t, [@bs.as "name"] _) => string = "map";
  let fastest = x => x->fastest->name;
};
