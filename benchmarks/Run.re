[@warning "-3"];

open Benchmark;

Suite.(
  make("Cn")
  ->case("Cn List API", () =>
      Cn.(
        make([
          "A",
          "B",
          "C"->ifTrue(true),
          "D",
          "E",
          "F",
          "G",
          "H",
          "I"->ifTrue(false),
          "J",
          "K",
          "L",
          "M",
          "N"->ifSome(Some("!")),
          "O",
          "P",
          "Q",
          "R",
          "S"->ifSome(None),
          "T",
          "U",
          "V",
          "W",
          Some("X")->unpack,
          "Y",
          "Z",
        ])
      )
    )
  ->case("Cn (+) API", () =>
      Cn.(
        "A"
        + "B"
        + "C"->on(true)
        + "D"
        + "E"
        + "F"
        + "G"
        + "H"
        + "I"->on(false)
        + "J"
        + "K"
        + "L"
        + "M"
        + "N"->onSome(Some("!"))
        + "O"
        + "P"
        + "Q"
        + "R"
        + "S"->onSome(None)
        + "T"
        + "U"
        + "V"
        + "W"
        + Some("X")->take
        + "Y"
        + "Z"
      )
    )
  ->on(`cycle(cycle => cycle->Cycle.result->Js.log))
  ->on(
      `complete(
        [@bs.this] suite => suite->Result.fastest->Js.log2("The fastest:", _),
      ),
    )
  ->run
);
