#include <X11/Xlib.h>
#include <stdlib.h>

#define stk(s)    XKeysymToKeycode(d, XStringToKeysym(s))
#define K(k, x)   if (e.xkey.keycode == stk(k)) { x; }
#define E(_, x)   if (e.type == _) { x; }
#define grab(...)  const char *l[] = { __VA_ARGS__ }; \
                    for (size_t i = 0; i < sizeof(l) / sizeof(*l); ++i) \
                      XGrabKey (d, stk(l[i]), Mod4Mask, r, 1, 1, 1);

int main () {
  Display *d = XOpenDisplay(0); Window r = DefaultRootWindow(d); XEvent e;
  XSelectInput (d, r, SubstructureRedirectMask);

  grab ("n", "q", "w", "t", "l", "u", "i", "o", "p");

  while (!XNextEvent (d, &e)) {
    E (KeyPress,
       K("n", XCirculateSubwindowsUp(d, r); XSetInputFocus(d, e.xkey.window, 2, 0))
       K("q", XKillClient(d, e.xkey.subwindow))
       K("w", system("chromium --enable-features=WebContentsForceDark &"))
       K("t", system("xterm &"))
       K("l", system("rotK"))
       K("u", system("vol 5%-"))
       K("i", system("vol 5%+"))
       K("o", system("bri -100"))
       K("p", system("bri +100")))

    E (MapRequest, XMapWindow(d, e.xmaprequest.window);
                   XSetInputFocus(d, e.xmaprequest.window, 2, 0))

    E (ConfigureRequest,
       XMoveResizeWindow (d, e.xconfigure.window, 0, 0, e.xconfigure.width, e.xconfigure.height);
       XMoveResizeWindow (d, e.xconfigure.window, 0, 0, 1920, 1080))
  }
}
