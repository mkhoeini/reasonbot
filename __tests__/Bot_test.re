open TestHelper;

test("token is not empty", () =>
  expect(Bot.token |> String.length) |> not_ |> toBe(0)
);

testAsync("bot constructs successfully", cb =>
  Bot.createBot(_bot => cb(pass)) |> ignore
);
