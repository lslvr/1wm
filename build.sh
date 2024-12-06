#! /bin/sh


rm -f mwm; ${CC:-tcc} -lX11 mwm.c -o mwm
