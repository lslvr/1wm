# mwm

For the true minimalist:

- ~20 LOC.
- No default keybindings.
- No title bars, no status bars, no buttons, no borders, no menus, etc.
- No mouse control.
- No virtual desktops.
- No configuration files.
- Absolutely adabptable to your needs.
- Includes just what is strictly needed.

`mwm` just loops through X key press events and lets you bind
actions to key presses. It provides two macros: `grab` and `on`.
You first `grab` the key (e.g.: `grab("Return", Mod4Mask)`), then you bind
an action to it (e.g.: `on("Return", system("xterm &"))`). More than
one action can be provided (e.g.: `on("Tab", XCirculateSubwindowsUp(d, r); XSetInputFocus(d, e.xkey.window, 0, 0)))`).

Dead simple.
