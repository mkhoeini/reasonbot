type createConfigType = {
  .
  "name": string,
  "adapter": Js.undefined(string),
  "password": Js.undefined(string),
  "multiInstance": Js.undefined(Js.boolean)
};

type rxDatabase;

[@bs.obj]
external createConfig :
  (
    ~name: string,
    ~adapter: string=?,
    ~password: string=?,
    ~multiInstance: Js.boolean=?,
    unit
  ) =>
  createConfigType =
  "";

[@bs.module "rxdb"]
external create_ : createConfigType => Js.Promise.t(rxDatabase) = "create";

[%%raw "require('rxdb').plugin(require('pouchdb-adapter-memory'))"];

let create = (~name) => create_(createConfig(~name, ~adapter="memory", ()));
