#!/bin/bash
echo int puts(const char *str) { return 0 } > evil.c
gcc -shared -fPIC -o evil.so evil.c
LD_PRELOAD=./evil.so ./gm 9 8 10 24 75 9
