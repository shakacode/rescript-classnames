module Cycle = {
  type t
  @get external target: t => string = "target"
  let result = x => x->target->Js.String.make
}

module Suite = {
  type t

  @module("benchmark") @new external make: string => t = "Suite"

  @send external case: (t, string, unit => 'a) => t = "add"

  @send
  external on: (
    t,
    @string
    [
      | #cycle(Cycle.t => unit)
      | #complete(@this (t => unit))
    ],
  ) => t = "on"
  @send external run: t => unit = "run"
}

module Result = {
  type t
  @send external fastest: (Suite.t, @as("fastest") _) => t = "filter"
  @send external name: (t, @as("name") _) => string = "map"
  let fastest = x => x->fastest->name
}
