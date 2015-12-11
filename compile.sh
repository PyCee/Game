#! /bin/bash
clear
SRC=$(find . src -name "*.c" -print)
gcc -c $SRC

LINK="-lSDL2 -lSDL2_mixer -lGL -lm -lassimp"
BUI=$(find -name "*.o" -print)

gcc -o bin/Morte $BUI $LINK

rm $BUI
