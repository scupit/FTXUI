# Sky fork of FTXUI

> This is my personal FTXUI fork used for simple human-in-the-loop scripting.

For the real FTXUI, see [https://github.com/ArthurSonzogni/FTXUI](https://github.com/ArthurSonzogni/FTXUI).

This fork allows you to specify which output stream is used
to render the TUI contents. See the [cli-list-select](./src/ftxui/cli-list-select.cpp) example;
By specifying `std::cerr` as the output stream, we leave
`std::cout` free for actual application output. This means
we can use TUIs as intermediate steps in shell scripting pipelines.

One use case is: Using a "dropdown-like" TUI to select
which GPG key you want to use before signing a commit.

## Main Changes from the Original

- `std::cout` isn't hardcoded as the output stream. Interactive "screen" objects like `ftxui::ScreenInteractive::TerminalOutput` now accept an optional `std::ostream&` parameter.

The parameter is optional, so existing FTXUI code will still "just work".

- We use the old rendering behavior; Instead of taking over the terminal 'screen' and clearing contents beneath the TUI, the TUI component just renders after any contents already in the terminal. I use this fork more for quality of life "TUI widgets" rather than full TUI applications. Use the [actual FTXUI library](https://github.com/ArthurSonzogni/FTXUI) for that.
