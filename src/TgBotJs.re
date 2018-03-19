type telegramBotApi;

type botConfig = {
  .
  "polling": Js.undefined(Js.boolean),
  "webhook": Js.undefined(int)
};

[@bs.obj]
external createBotConfig :
  (~polling: Js.boolean=?, ~webhook: int=?, unit) => botConfig =
  "";

[@bs.new] [@bs.module]
external createTelegramBot : (string, botConfig) => telegramBotApi =
  "node-telegram-bot-api";

[@bs.send.pipe : telegramBotApi]
external on : (string, 'a => unit) => telegramBotApi = "";

type keyboardMarkupKey = {
  .
  "text": string,
  "switch_inline_query_current_chat": Js.undefined(string),
  "callback_data": Js.undefined(string)
};

[@bs.send.pipe : telegramBotApi]
external sendMessage : (float, string, 'a) => telegramBotApi = "";

type message = {
  .
  "message_id": float,
  "text": Js.undefined(string),
  "date": float,
  "chat": {.},
  "from": {. "id": float},
  "entities": array({.})
};
