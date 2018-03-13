open Jest;

open! Expect.Operators;

open Js.Promise;

testPromise("Db connects Successfully", () =>
  Db.db |> then_((_) => resolve(pass))
);
