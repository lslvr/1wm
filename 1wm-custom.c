#include <X11/Xlib.h>
#include <stdlib.h>

#define stk(s)      XKeysymToKeycode(d, XStringToKeysym(s))
#define on(ev, x)   if (e.type == ev) { x; }
#define keys(k, _)  XGrabKey(d, stk(k), Mod4Mask, r, 1, 1, 1);
#define map(k, x)   if (e.xkey.keycode == stk(k)) { x; }

#define TBL(x)  x("n", XCirculateSubwindowsUp(d, r); XSetInputFocus(d, e.xkey.window, 2, 0)) \
                x("q", XKillClient(d, e.xkey.subwindow)) \
                x("w", system("vivaldi &")) \
                x("t", system("xterm &")) \
                x("l", system("rotK")) \
                x("u", system("vol -")) \
                x("i", system("vol +")) \
                x("o", system("bri -100")) \
                x("p", system("bri +100"))

int main() {
    Display *d = XOpenDisplay(0); Window r = DefaultRootWindow(d); XEvent e;
    XSelectInput(d, r, SubstructureRedirectMask);
    TBL(keys);

    while (!XNextEvent (d, &e)) {
        on(ConfigureRequest,  XMoveResizeWindow(d, e.xconfigure.window, 0, 0, e.xconfigure.width, e.xconfigure.height);
                              XMoveResizeWindow(d, e.xconfigure.window, 0, 0, 1920, 1080))
              on(MapRequest,  XMapWindow(d, e.xmaprequest.window);
                              XSetInputFocus(d, e.xmaprequest.window, 2, 0))
                on(KeyPress,  TBL(map))
    }
}
