open Benchmark

module Process = {
  @val @scope(("process", "exit"))
  external exit: int => unit = "exit"
}

let rescriptClassnames = () => {
  Cn.make([
    "A",
    "B",
    true ? "C" : "",
    "D",
    "E",
    "F",
    "G",
    "H",
    false ? "I" : "",
    "J",
    "K",
    "L",
    "M",
    switch Some("!") {
    | Some(_) => "N"
    | None => ""
    },
    "O",
    "P",
    "Q",
    "R",
    switch None {
    | Some(_) => "S"
    | None => ""
    },
    "T",
    "U",
    "V",
    "W",
    switch Some("X") {
    | Some(x) => x
    | None => ""
    },
    "Y",
    "Z",
  ])
}

let jsInterpolation = () => {
  `A B ${true ? "C" : ""} D E F G H ${false ? "I" : ""} J K L M ${switch Some("!") {
    | Some(_) => "N"
    | None => ""
    }} O P Q R ${switch None {
    | Some(_) => "S"
    | None => ""
    }} T U V W ${switch Some("X") {
    | Some(x) => x
    | None => ""
    }} Y Z`
}

let classnamesJs = () =>
  ClassnamesJs.make([
    "A",
    "B",
    true ? "C" : "",
    "D",
    "E",
    "F",
    "G",
    "H",
    false ? "I" : "",
    "J",
    "K",
    "L",
    "M",
    switch Some("!") {
    | Some(_) => "N"
    | None => ""
    },
    "O",
    "P",
    "Q",
    "R",
    switch None {
    | Some(_) => "S"
    | None => ""
    },
    "T",
    "U",
    "V",
    "W",
    switch Some("X") {
    | Some(x) => x
    | None => ""
    },
    "Y",
    "Z",
  ])

{
  let check = (~case, ~result: [#Clean(string) | #WithMultipleSpaces(string)]) => {
    let expectedCleanResult = "A B C D E F G H J K L M N O P Q R T U V W X Y Z"
    let expectedResultWithSpaces = "A B C D E F G H  J K L M N O P Q R  T U V W X Y Z"

    let (expectedResult, actualResult, notEqual) = switch result {
    | #Clean(actualResult) => (
        expectedCleanResult,
        actualResult,
        expectedCleanResult != actualResult,
      )
    | #WithMultipleSpaces(actualResult) => (
        expectedResultWithSpaces,
        actualResult,
        expectedResultWithSpaces != actualResult,
      )
    }
    if notEqual {
      Console.error(
        `${case} returns invalid result:\n  E: "${expectedResult}"\n  A: "${actualResult}"`,
      )

      Process.exit(1)
    }
  }

  check(~case="rescript-classnames", ~result=#Clean(rescriptClassnames()))
  check(~case="Js interpolation", ~result=#WithMultipleSpaces(jsInterpolation()))
  check(~case="classnames.js", ~result=#Clean(classnamesJs()))
}

{
  open Suite

  make("Cn")
  ->case("js interpolation", jsInterpolation)
  ->case("rescript-classnames", rescriptClassnames)
  ->case("classnames.js", classnamesJs)
  ->on(#cycle(cycle => cycle->Cycle.result->Console.log))
  ->on(#complete(@this suite => suite->Result.fastest->Console.log2("The fastest:", _)))
  ->run
}
