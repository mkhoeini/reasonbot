type keyMarkup = {
  .
  "reply_markup": {
    .
    "inline_keyboard": array(array(TgBotJs.keyboardMarkupKey))
  }
};

let defaultKeys: keyMarkup = {
  "reply_markup": {
    "inline_keyboard": [|
      [|
        {
          "text": "جستج�\136�\140 آ�\135�\134گ",
          "switch_inline_query_current_chat": Js.Undefined.return(""),
          "callback_data": Js.undefined
        }
      |],
      [|
        {
          "text": "آ�\135�\134گ�\135ا�\140 جد�\140د",
          "switch_inline_query_current_chat": Js.undefined,
          "callback_data": Js.Undefined.return("song_latest")
        }
      |],
      [|
        {
          "text": "آ�\135�\134گ�\135ا�\140 برتر",
          "switch_inline_query_current_chat": Js.undefined,
          "callback_data": Js.Undefined.return("song_top")
        }
      |],
      [|
        {
          "text": "آ�\132ب�\136�\133�\135ا�\140 جد�\140د",
          "switch_inline_query_current_chat": Js.undefined,
          "callback_data": Js.Undefined.return("album_latest")
        }
      |],
      [|
        {
          "text": "آ�\132ب�\136�\133�\135ا�\140 برتر",
          "switch_inline_query_current_chat": Js.undefined,
          "callback_data": Js.Undefined.return("album_top")
        }
      |]
    |]
  }
};

let sendDefaultKeys = (bot: TgBotJs.telegramBotApi, id: float) =>
  bot
  |> TgBotJs.sendMessage(
       id,
       "�\140ک�\140 از گز�\140�\134�\135 �\135ا�\140 ز�\140ر را ا�\134تخاب ک�\134�\140د:",
       defaultKeys
     )
  |> ignore;

let searchKey: string => keyMarkup =
  msg => {
    "reply_markup": {
      inline_keyboard: [|
        [|
          {
            "text": "جستج�\136",
            "switch_inline_query_current_chat": Js.Undefined.return(msg),
            "callback_data": Js.undefined
          }
        |]
      |]
    }
  };

let sendSearchKey = (bot: TgBotJs.telegramBotApi, id: float) =>
  bot
  |> TgBotJs.sendMessage(
       id,
       "ر�\136�\140 دک�\133�\135 ز�\140ر ک�\132�\140ک ک�\134 �\136 صبر ک�\134 تا �\134تا�\140ج را بب�\140�\134�\140:",
       searchKey
     )
  |> ignore;

let handler =
    (
      user: Rxdb.rxCollection,
      bot: TgBotJs.telegramBotApi,
      msg: TgBotJs.message
    ) =>
  switch (Js.Undefined.toOption(msg##text)) {
  | None => ()
  | Some("/start") =>
    User.upsertObj(user, msg##from);
    sendDefaultKeys(bot, msg##from##id);
  | Some("/menu") => sendDefaultKeys(bot, msg##from##id)
  | _ =>
    User.upsertObj(user, msg##from);
    sendSearchKey(bot, msg##from##id);
  };
