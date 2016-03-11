#! /bin/bash
clear
SRC=$(find . src -name "*.c" -print)
echo Compiling
#gcc -c $SRC
for fie in $SRC
do
	gcc -c $fie
	echo "Compiling $fie"
done
echo Compiled

LINK="-lSDL2 -lSDL2_mixer -lGL -lm -lassimp -lSOIL"
BUI=$(find -name "*.o" -print)
TMP=$(find -name "*~" -print)

echo Building
gcc -o bin/Morte $BUI $LINK
echo Built

echo Cleaning
rm $BUI
rm $TMP
echo Cleaned
