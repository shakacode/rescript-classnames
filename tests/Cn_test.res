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

    expect(result) |> toBe(className)
  })

  test("3 classnames", () => {
    let result = Cn.make(["one", "two", "three"])
    let className = "one two three"

    expect(result) |> toBe(className)
  })

  test("2 classnames with truthy condition", () => {
    let result = Cn.make(["one", true ? "two" : ""])
    let className = "one two"

    expect(result) |> toBe(className)
  })

  test("2 classnames with falsy condition", () => {
    let result = Cn.make(["one", false ? "two" : ""])
    let className = "one"

    expect(result) |> toBe(className)
  })

  test("3 classnames with truthy condition", () => {
    let result = Cn.make(["one", true ? "two" : "", "three"])
    let className = "one two three"

    expect(result) |> toBe(className)
  })

  test("3 classnames with falsy condition", () => {
    let result = Cn.make(["one", false ? "two" : "", "three"])
    let className = "one three"

    expect(result) |> toBe(className)
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

    expect(result) |> toBe(className)
  })
})
