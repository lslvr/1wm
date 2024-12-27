# mwm

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

This is the smallest, actually usable window manager I know about. Even
TinyWM is twice as large. However, it doesn't let you launch programs, or
switch between windows. `mwm` does.

---

_`xterm`, with the `micro` editor, editing `mwm`'s source._

![2024-12-27-172602_1920x1080_scrot](https://github.com/user-attachments/assets/a369645f-bb80-40fc-9658-0225583d8741)

## Why?

Most software today is crappy. Do you really need all the bells and whistles?
Generally, you don't. You need to get the job done.

We are in dire need of software that is hackable, fun, small, malleable, and
that you can wrap your head around, because: is it truly free software if, due
to its complexity, you cannot modify it? ;)

## How?

Two macros are available for assigning keybindings: `grab` and `map`. Read
`mwm-custom.c` for an example on how to use them (my own setup).

You first need to `grab` the keys you want to be able to bind. Then you `map`
them to actions.

## Building.

Run `./build.sh`. Pass `CC=...` to use a different C compiler (I use `tcc`).

Dead simple.
