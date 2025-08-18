#! /bin/sh

rm -f 1wm; ${CC:-tcc} -lX11 1wm.c -o 1wm
