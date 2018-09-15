open Jest;

type t =
  | One
  | Two
  | Tree;

describe("ClassNames", () => {
  open Expect;

  test("Cn.make: 2", () => {
    let classNames = ["one", "two"];
    let className = "one two";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.make: 3", () => {
    let classNames = ["one", "two", "three"];
    let className = "one two three";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.ifTrue: true", () => {
    let classNames = ["one", "two"->Cn.ifTrue(true)];
    let className = "one two";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.ifTrue: false", () => {
    let classNames = ["one", "two"->Cn.ifTrue(false)];
    let className = "one";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.ifSome: Some", () => {
    let classNames = ["one", "two"->Cn.ifSome(Some("thing"))];
    let className = "one two";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.ifSome: None", () => {
    let classNames = ["one", "two"->Cn.ifSome(None)];
    let className = "one";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.mapSome: Some", () => {
    let classNames = [
      "one",
      Cn.mapSome(
        Some(Two),
        fun
        | One => "one"
        | Two => "two"
        | Tree => "three",
      ),
    ];
    let className = "one two";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.mapSome: None", () => {
    let classNames = [
      "one",
      Cn.mapSome(
        None,
        fun
        | One => "one"
        | Two => "two"
        | Tree => "three",
      ),
    ];
    let className = "one";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.unpack: Some", () => {
    let classNames = ["one", Some("two")->Cn.unpack];
    let className = "one two";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("Cn.unpack: None", () => {
    let classNames = ["one", None->Cn.unpack];
    let className = "one";

    expect(classNames->Cn.make) |> toBe(className);
  });

  test("all together", () => {
    let classNames = [
      "one",
      Cn.mapSome(
        Some(Two),
        fun
        | One => "one"
        | Two => "two"
        | Tree => "three",
      ),
      None->Cn.unpack,
      "four"->Cn.ifTrue(true),
      "five"->Cn.ifSome(Some("thing")),
    ];
    let className = "one two four five";

    expect(classNames->Cn.make) |> toBe(className);
  });
});
