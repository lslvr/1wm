# mwm

For the true minimalist:

- ~40 LOC.
- No default keybindings (just edit the source).
- No title bars, no status bars, no buttons, no borders, no menus, etc.
- No eye-candy.
- No mouse control.
- No virtual desktops.
- No configuration files.
- Absolutely adaptable to your needs.
- Includes just what is strictly needed.
- Not standards-compliant.
- All windows are full-screen, just one is visible at any given time.
- No modes.

## Why?

Most software today is crappy. Do you really need all that? I found out
through experience that, generally, you don't. Do you really need to have
a dozen windows opened simultaneously? When you do, you will need a way to
organize that mess. Virtual desktops, window tags, etc. are ways to cope
with the symptoms of a underlying issue.

We are in dire need of software that is hackable, fun, small, malleable,
and that you can wrap your head around, because: is it truly free software
if, due to its complexity, you cannot modify it? ;)

## How?

Two macros are available for assigning keybindings: `grab` and `K`.
Read the source for an example on how to use them (my own setup).

Run `./build.sh`. Pass `CC=` to use a different C compiler (I use tcc).

Dead simple.
