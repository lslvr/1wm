#! /bin/sh

rm -f 1wm; ${CC:-tcc} 1wm.c -lX11 -o 1wm
