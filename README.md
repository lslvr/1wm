# 1wm

The window manager for the true minimalist:

- 20 LOC.
- No modes.
- No "eye-candy".
- No mouse control.
- No virtual desktops.
- No configuration files.
- Not standards-compliant.
- No title bars, no status bars, no buttons, no borders, no menus, etc.
- All windows are full-screen, just one is visible at any given time.
- Absolutely adaptable to your needs.
- Includes just what is strictly needed.

This is the smallest, actually usable window manager I know about. Even `TinyWM` is
twice as large, but you cannot launch programs or assign key bindings.

---

![2024-12-27-172602_1920x1080_scrot](https://github.com/user-attachments/assets/a369645f-bb80-40fc-9658-0225583d8741)

_`xterm`, with the `micro` editor, editing `1wm`'s source._

# Why?

Most software today is heavily bloated. Do you _really_ need all the bells and whistles?
Probably not.

We need software that is hackable, fun, small, malleable, and that you can wrap your head
around, because: is it truly free if, due to its complexity, you cannot modify it? ;)

# How?

The very essential things a window manager should let me do are:

- Launch applications (which might create new windows).
- Switch between windows.
- Close windows.

Well, that's what `1wm` lets you do:

- Launch `dmenu`: `Mod4 + e`.
- Cycle to next window (the "`Alt + Tab`" behavior): `Mod4 + n`.
- Close current window: `Mod4 + q`.

You may add more keybindings to your liking; see `1wm-custom.c`.

First, you need to `grab()` the keys you want to bind, then you `map()` them to actions.

# Building.

Run `./build.sh`. Pass `CC=...` to use a different C compiler (I use `tcc`).
Dead simple.
