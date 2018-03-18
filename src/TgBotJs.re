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
