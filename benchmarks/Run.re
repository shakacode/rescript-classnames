open Benchmark;

Suite.(
  make("Cn")
  ->case("Cn.(+)", () =>
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
  ->case("Cn.fromList", () =>
      Cn.(
        fromList([
          "A",
          "B",
          "C"->on(true),
          "D",
          "E",
          "F",
          "G",
          "H",
          "I"->on(false),
          "J",
          "K",
          "L",
          "M",
          "N"->onSome(Some("!")),
          "O",
          "P",
          "Q",
          "R",
          "S"->onSome(None),
          "T",
          "U",
          "V",
          "W",
          Some("X")->take,
          "Y",
          "Z",
        ])
      )
    )
  ->case("Cn.make", () =>
      Cn.(
        [@warning "-3"]
        make([
          "A",
          "B",
          "C"->on(true),
          "D",
          "E",
          "F",
          "G",
          "H",
          "I"->on(false),
          "J",
          "K",
          "L",
          "M",
          "N"->onSome(Some("!")),
          "O",
          "P",
          "Q",
          "R",
          "S"->onSome(None),
          "T",
          "U",
          "V",
          "W",
          Some("X")->take,
          "Y",
          "Z",
        ])
      )
    )
  ->case("classnames.js", () =>
      ClassnamesJs.make([|
        "A",
        "B",
        "C"->Cn.on(true),
        "D",
        "E",
        "F",
        "G",
        "H",
        "I"->Cn.on(false),
        "J",
        "K",
        "L",
        "M",
        "N"->Cn.onSome(Some("!")),
        "O",
        "P",
        "Q",
        "R",
        "S"->Cn.onSome(None),
        "T",
        "U",
        "V",
        "W",
        Some("X")->Cn.take,
        "Y",
        "Z",
      |])
    )
  ->on(`cycle(cycle => cycle->Cycle.result->Js.log))
  ->on(
      `complete(
        [@bs.this] suite => suite->Result.fastest->Js.log2("The fastest:", _),
      ),
    )
  ->run
);
