module Cycle = {
  type t
  @get external target: t => string = "target"
  let result = x => x->target->String.make
}

module Suite = {
  type t
  type result

  @module("benchmark") @scope("default") @new external make: string => t = "Suite"

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
  @send external filter: (t, string) => result = "filter"
  @send external map: (result, string) => string = "map"

  module Result = {
    let fastest = x => x->filter("fastest")->map("name")
  }
}
