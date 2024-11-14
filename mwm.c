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

  grab ("q", "n", "l", "space", "Return", "Right", "Left", "Up", "Down");

  while (!XNextEvent (d, &e)) {
    E (KeyPress,
       K("n", XCirculateSubwindowsUp(d, r); XSetInputFocus(d, e.xkey.window, 2, 0))
       K("q", XKillClient(d, e.xkey.subwindow))
       K("l",      system("rotK &"))
       K("space",  system("chromium &"))
       K("Return", system("xterm &"))
       K("Right",  system("vol 5%+ &"))
       K("Left",   system("vol 5%- &"))
       K("Up",     system("bri +100 &"))
       K("Down",   system("bri -100 &")))

    E (MapRequest,
      XMapWindow(d, e.xmaprequest.window);
      XSetInputFocus(d, e.xmaprequest.window, 2, 0))

    E (ConfigureRequest,
      XMoveResizeWindow (d, e.xconfigure.window, 0, 0, e.xconfigure.width, e.xconfigure.height);
      XMoveResizeWindow (d, e.xconfigure.window, 0, 0, 1920, 1080))
  }
}
