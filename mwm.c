#include <X11/Xlib.h>

#define stok(s)     XKeysymToKeycode(d, XStringToKeysym(s))
#define on(k, a)    if (e.xkey.keycode == stok(k)) { a; continue; }
#define grab(k, m)  XGrabKey (d, stok(k), m, r, 1, 1, 1)

int main (int argc, char **argv) {
  Display *d = XOpenDisplay(0); Window r = DefaultRootWindow(d); XEvent e;
  XSelectInput (d, r, SubstructureRedirectMask);

  grab ("KEY", MODIFIER);

  while (!XNextEvent (d, &e)) {
    if (e.type == KeyPress) {
      on ("KEY", ACTIONS);
    }
  }
}
