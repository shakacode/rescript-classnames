open Jest;

type t =
  | One
  | Two
  | Three;

describe("CnNext", () => {
  open Expect;

  test("CnNext.(+): 2", () => {
    let result = CnNext.("one" + "two");
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.(+): 3", () => {
    let result = CnNext.("one" + "two" + "three");
    let className = "one two three";

    expect(result) |> toBe(className);
  });

  test("CnNext.on: true", () => {
    let result = CnNext.("one" + "two"->on(true));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.on: false", () => {
    let result = CnNext.("one" + "two"->on(false));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.onSome: Some", () => {
    let result = CnNext.("one" + "two"->onSome(Some("thing")));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.onSome: None", () => {
    let result = CnNext.("one" + "two"->onSome(None));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapSome: Some", () => {
    let result =
      CnNext.(
        "one"
        + mapSome(
            Some(Two),
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapSome: None", () => {
    let result =
      CnNext.(
        "one"
        + mapSome(
            None,
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.take: Some", () => {
    let result = CnNext.("one" + Some("two")->take);
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.take: None", () => {
    let result = CnNext.("one" + None->take);
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.onOk: Ok", () => {
    let result = CnNext.("one" + "two"->onOk(Ok()));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.onOk: Error", () => {
    let result = CnNext.("one" + "two"->onOk(Error()));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapOk: Ok", () => {
    let result =
      CnNext.(
        "one"
        + mapOk(
            Ok(Two),
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapOk: Error", () => {
    let result =
      CnNext.(
        "one"
        + mapOk(
            Error(),
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.onErr: Ok", () => {
    let result = CnNext.("one" + "two"->onErr(Ok()));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.onErr: Error", () => {
    let result = CnNext.("one" + "two"->onErr(Error()));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapErr: Ok", () => {
    let result =
      CnNext.(
        "one"
        + mapErr(
            Ok(),
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("CnNext.mapErr: Error", () => {
    let result =
      CnNext.(
        "one"
        + mapErr(
            Error(Two),
            fun
            | One => "one"
            | Two => "two"
            | Three => "three",
          )
      );
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("All together", () => {
    let result =
      CnNext.(
        "one"
        + Some(Two)
          ->mapSome(
              fun
              | One => "one"
              | Two => "two"
              | Three => "three",
            )
        + None->take
        + "four"->onErr(Ok())
        + "five"->on(true)
        + "six"->onSome(Some("thing"))
        + Ok(Three)
          ->mapOk(
              fun
              | One => "one"
              | Two => "two"
              | Three => "three",
            )
      );
    let className = "one two five six three";

    expect(result) |> toBe(className);
  });
});
