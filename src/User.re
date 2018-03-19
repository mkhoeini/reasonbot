let userSchema = {
  "title": "user schema",
  "version": 0,
  "type": "object",
  "properties": {
    "id": {
      "type": "string",
      "primary": Js.true_
    },
    "first_name": {
      "type": "string"
    },
    "last_name": {
      "type": "string"
    },
    "username": {
      "type": "string"
    },
    "is_bot": {
      "type": "boolean"
    },
    "language_code": {
      "type": "string"
    },
    "created_at": {
      "type": "number"
    },
    "updated_at": {
      "type": "number"
    },
    "version": {
      "type": "number",
      "default": 0
    }
  }
};

let onCreate = d => {
  let now = Js.Date.now();
  d##created_at#=now;
  d##updated_at#=now;
  ();
};

let onUpdate = d => {
  let now = Js.Date.now();
  d##updated_at#=now;
  let ver = d##version + 1;
  d##version#=ver;
  ();
};

let createUser = (db: Rxdb.rxDatabase, cb: Rxdb.rxCollection => unit) =>
  Rxdb.collection(db, {"name": "user", "schema": userSchema})
  |> Js.Promise.then_(col => {
       col
       |> Rxdb.preInsert(
            [@bs.this] ((_, document) => onCreate(document)),
            Js.false_
          )
       |> Rxdb.preSave(
            [@bs.this] ((_, document) => onUpdate(document)),
            Js.false_
          )
       |> ignore;
       cb(col);
       Js.Promise.resolve();
     })
  |> ignore;

let upsertObj = (col: Rxdb.rxCollection, user: 'a) => {
  col
  |> Rxdb.updateOne({"id": user##id}, user, {"upsert": Js.true_}, err =>
       if (Js.test(err)) {
         Js.log("Error occured during upsert:");
         Js.log(err);
         ();
       }
     )
  |> ignore;
  ();
};
