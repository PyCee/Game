compile:
	sh compile.sh
comp2:
	#! /bin/bash
	SRC=$(find . src -name "*.c" -print)
	echo Compiling
	for fie in $SRC
	do
		gcc -c $fie
		echo "Compiling $fie"
	done
	echo Compiled
build:
	LINK="-lSDL2 -lSDL2_mixer -lGL -lm -lassimp -lSOIL"
	BUI=$(find -name "*.o" -print)
	
	echo Building and Linking
	gcc -o bin/Morte $BUI $LINK
	echo Built and Linked
clean:
	BUI=$(find -name "*.o" -print)
	TMP=$(find -name "*~" -print)
	echo Cleaning
	for fie in $BUI
	do
		echo "Removing Compiled $fie"
		rm $fie
	done
	for fie in $TMP
	do
		echo "Removing Temp $fie"
		rm $fie
	done
	echo Cleaned
run:
	echo Running
	cd bin;./Morte;cd ..
	echo Ran
v:
	echo Running
	cd bin;valgrind --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all ./Morte;cd ..
	echo Ran
val:
	echo Running
	cd bin;valgrind --tool=memcheck --leak-check=yes --num-callers=20 --track-fds=yes ./Morte;cd ..
	echo Ran
todo:
	grep -r -n *"TODO"*
	
install:
	sudo apt-get install libsdl2-dev # library that handels window creation and input
	sudo apt-get install libsdl2-mixer-dev
	sudo apt-get install libassimp-dev # library for importing 3d models
	git config --global user.email "Kpampusch@yahoo.com"
	git config --global user.name "NotSarcastic"
#	cd SDL
#	./configure
#	make
#	sudo make install
	sudo apt-get install libsoil-dev
push:
	clear
	echo GitHub...
	git add .
	git commit -a
	git push
pull:
	clear
	git pull
goodbye:
	echo FAREWELL CRUEL WORLD
