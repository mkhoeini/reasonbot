let dbName = "./reasonbot";

exception DBError(Js.Promise.error);

let db = {
  print_string("Trying to connect to DB: " ++ dbName);
  Js.Promise.(
    Rxdb.create(~name=dbName)
    |> then_(v => {
         print_string("Successfully connected to DB.");
         resolve(v);
       })
    |> catch(err => {
         Js.log2("Failed to connect to DB: " ++ dbName, err);
         raise(DBError(err));
       })
  );
};
