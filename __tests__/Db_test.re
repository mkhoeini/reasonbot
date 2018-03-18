open TestHelper;

testAsync("Db connects Successfully", cb =>
  Db.createDb(db =>
    switch db {
    | Some(_) => cb(pass)
    | None => cb(fail("Db failed to construct"))
    }
  )
  |> ignore
);
