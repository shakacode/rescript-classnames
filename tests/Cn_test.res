open Jest

type t =
  | One
  | Two
  | Three

describe("Cn", () => {
  open Expect

  test("2 classnames", () => {
    let result = Cn.make(["one", "two"])
    let className = "one two"

    expect(result)->toBe(className)
  })

  test("3 classnames", () => {
    let result = Cn.make(["one", "two", "three"])
    let className = "one two three"

    expect(result)->toBe(className)
  })

  test("empty string at the first position", () => {
    let result = Cn.make([false ? "one" : "", "two", "three"])
    let className = "two three"

    expect(result)->toBe(className)
  })

  test("empty string in the middle", () => {
    let result = Cn.make(["one", false ? "two" : "", "three"])
    let className = "one three"

    expect(result)->toBe(className)
  })

  test("empty string at the last position", () => {
    let result = Cn.make(["one", "two", false ? "three" : ""])
    let className = "one two"

    expect(result)->toBe(className)
  })

  test("mix", () => {
    let result = Cn.make([
      "one",
      switch Some(Two) {
      | Some(One) => "one"
      | Some(Two) => "two"
      | Some(Three) => "three"
      | None => ""
      },
      switch None {
      | Some(x) => x
      | None => ""
      },
      switch Ok() {
      | Ok(_) => ""
      | Error(_) => "four"
      },
      true ? "five" : "",
      switch Some("thing") {
      | Some(_) => "six"
      | None => ""
      },
      switch Ok(Three) {
      | Ok(One) => "one"
      | Ok(Two) => "two"
      | Ok(Three) => "three"
      | Error(_) => ""
      },
    ])
    let className = "one two five six three"

    expect(result)->toBe(className)
  })
})

describe("Cx", () => {
  open Expect

  test("cx", () => {
    open Cx

    let result = cx(["one", "two"])
    let className = "one two"

    expect(result)->toBe(className)
  })
})
