# 1wm
> _The smallest, actually usable window manager._

- _~30 LOC._
- _No modes, no mouse control, no virtual desktops, no menus._
- _No configs, no eye-candy, not standards-compliant._
- _Only one full-screen window visible at a time._
- _Depends only on Xlib._

This is the whole thing as seen in `1wm.c`:

```C
#include <X11/Xlib.h>
#include <stdlib.h>

#define stk(s)    XKeysymToKeycode(d, XStringToKeysym(s))
#define on(_, x)  if (e.type == _) { x; }
#define map(k, x) if (e.xkey.keycode == stk(k)) { x; }
#define grab(...) const char *l[] = { __VA_ARGS__, 0 }; \
                    for (int i = 0; l[i]; i++) XGrabKey(d, stk(l[i]), Mod4Mask, r, 1, 1, 1);

int main() {
  Display *d = XOpenDisplay(0); Window r = DefaultRootWindow(d); XEvent e;
  XSelectInput(d, r, SubstructureRedirectMask);
  grab("n", "q", "e");

  while (!XNextEvent (d, &e)) {
    on(ConfigureRequest, XMoveResizeWindow(d, e.xconfigure.window, 0, 0, e.xconfigure.width, e.xconfigure.height));
          on(MapRequest, XMapWindow(d, e.xmaprequest.window);
                         XSetInputFocus(d, e.xmaprequest.window, 2, 0));
            on(KeyPress, map("n", Window rt, pr, *c = 0; unsigned n = 0; \
                                  XCirculateSubwindowsUp(d, r); \
                                  XQueryTree(d, r, &rt, &pr, &c, &n); \
                                  if (n) XSetInputFocus(d, c[n - 1], 2, 0); \
                                  if (c) XFree(c))
                         map("q", XKillClient(d, e.xkey.subwindow))
                         map("e", system("dmenu_run &")));
  }
}
```

## Why?
Because software should be small, hackable and fun.
You can grasp this one in <5 minutes.

## How?
The essential things a window manager should let me do are:

- Launch applications (`dmenu`): `Mod4 + e`.
- Switch between windows: `Mod4 + n`.
- Close windows: `Mod4 + q`.

## Building
`CC=gcc ./build.sh`, or use `tcc` by default: `./build.sh`.

## Customizing
See `1wm-custom.c` for my own setup, adds ~10 LOC.
