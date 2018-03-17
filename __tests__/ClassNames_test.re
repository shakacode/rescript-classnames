open Jest;

type t =
  | One
  | Two
  | Tree;

describe("ClassNames", () => {
  open Expect;
  test("make: 2", () => {
    let classNames = ["one", "two"];
    let className = "one two";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("make: 3", () => {
    let classNames = ["one", "two", "three"];
    let className = "one two three";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("ifBool: true", () => {
    let cond = true;
    let classNames = ["one", "two" |> Cn.ifBool(cond)];
    let className = "one two";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("ifBool: false", () => {
    let cond = false;
    let classNames = ["one", "two" |> Cn.ifBool(cond)];
    let className = "one";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("ifOpt: Some", () => {
    let classNames = ["one", Some("two") |> Cn.ifOpt];
    let className = "one two";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("ifOpt: None", () => {
    let classNames = ["one", None |> Cn.ifOpt];
    let className = "one";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("mapOpt: Some", () => {
    let classNames = [
      "one",
      Cn.mapOpt(Some(Two), v =>
        switch (v) {
        | One => "one"
        | Two => "two"
        | Tree => "three"
        }
      ),
    ];
    let className = "one two";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("mapOpt: None", () => {
    let classNames = [
      "one",
      Cn.mapOpt(None, v =>
        switch (v) {
        | One => "one"
        | Two => "two"
        | Tree => "three"
        }
      ),
    ];
    let className = "one";
    expect(classNames |> Cn.make) |> toBe(className);
  });
  test("all together", () => {
    let classNames = [
      "one",
      Cn.mapOpt(Some(Two), v =>
        switch (v) {
        | One => "one"
        | Two => "two"
        | Tree => "three"
        }
      ),
      None |> Cn.ifOpt,
      "four" |> Cn.ifBool(true),
    ];
    let className = "one two four";
    expect(classNames |> Cn.make) |> toBe(className);
  });
});
