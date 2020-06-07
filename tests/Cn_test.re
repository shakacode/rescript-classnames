open Jest;

type t =
  | One
  | Two
  | Three;

describe("Cn", () => {
  open Expect;

  test("Cn.(+): 2", () => {
    let result = Cn.("one" + "two");
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.(+): 3", () => {
    let result = Cn.("one" + "two" + "three");
    let className = "one two three";

    expect(result) |> toBe(className);
  });

  test("Cn.fromList: 2", () => {
    let result = Cn.fromList(["one", "two"]);
    let className = "two one ";

    expect(result) |> toBe(className);
  });

  test("Cn.fromList: 3", () => {
    let result = Cn.fromList(["one", "two", "three"]);
    let className = "three two one ";

    expect(result) |> toBe(className);
  });

  test("Cn.(<:>): warning 44", () => {
    let result = [@warning "+44"] Cn.("one" <:> "two" <:> "three");
    let className = "one two three";

    expect(result) |> toBe(className);
  });

  test("Cn.on: true", () => {
    let result = Cn.("one" + "two"->on(true));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.on: false", () => {
    let result = Cn.("one" + "two"->on(false));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("Cn.onSome: Some", () => {
    let result = Cn.("one" + "two"->onSome(Some("thing")));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.onSome: None", () => {
    let result = Cn.("one" + "two"->onSome(None));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("Cn.mapSome: Some", () => {
    let result =
      Cn.(
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

  test("Cn.mapSome: None", () => {
    let result =
      Cn.(
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

  test("Cn.take: Some", () => {
    let result = Cn.("one" + Some("two")->take);
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.take: None", () => {
    let result = Cn.("one" + None->take);
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("Cn.onOk: Ok", () => {
    let result = Cn.("one" + "two"->onOk(Ok()));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.onOk: Error", () => {
    let result = Cn.("one" + "two"->onOk(Error()));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("Cn.mapOk: Ok", () => {
    let result =
      Cn.(
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

  test("Cn.mapOk: Error", () => {
    let result =
      Cn.(
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

  test("Cn.onErr: Ok", () => {
    let result = Cn.("one" + "two"->onErr(Ok()));
    let className = "one";

    expect(result) |> toBe(className);
  });

  test("Cn.onErr: Error", () => {
    let result = Cn.("one" + "two"->onErr(Error()));
    let className = "one two";

    expect(result) |> toBe(className);
  });

  test("Cn.mapErr: Ok", () => {
    let result =
      Cn.(
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

  test("Cn.mapErr: Error", () => {
    let result =
      Cn.(
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

  test("Cn.(+): mix", () => {
    let result =
      Cn.(
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

  test("Cn.fromList: mix", () => {
    let result =
      Cn.(
        fromList([
          "one",
          Some(Two)
          ->mapSome(
              fun
              | One => "one"
              | Two => "two"
              | Three => "three",
            ),
          None->take,
          "four"->onErr(Ok()),
          "five"->on(true),
          "six"->onSome(Some("thing")),
          Ok(Three)
          ->mapOk(
              fun
              | One => "one"
              | Two => "two"
              | Three => "three",
            ),
        ])
      );
    let className = "three six five two one ";

    expect(result) |> toBe(className);
  });
});
