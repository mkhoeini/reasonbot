let dbName = "./reasonbot";

let createDb = (cont: option(Rxdb.rxDatabase) => unit) =>
  Js.Promise.(
    Rxdb.create(~name=dbName)
    |> catch(err => {
         Js.log("Failed to connect to DB: " ++ dbName);
         Js.log(err);
         cont(None);
         reject(Failure("Db Creation Error!"));
       })
    |> then_(v => cont(Some(v)) |> resolve)
    |> ignore
  );
