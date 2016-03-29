#!/bin/bash
clang libstd.a main.c -o name -g3 -I includes \
  -I/usr/local/include -L/usr/local/lib -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lcsfml-network
