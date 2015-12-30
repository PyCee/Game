compile:
	echo Compiling.
	sh compile.sh
	echo Compiled
run:
	echo Running
	cd bin;./Morte;cd ..
	echo Ran
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
