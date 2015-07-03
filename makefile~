run:
	clear
	echo Compiling...
	gcc -c src/main.c
	gcc -c src/options.c
	gcc -c src/save.c
	gcc -c src/camera.c
	gcc -c src/globalBinds.c
	gcc -c src/keyboard.c
	gcc -c src/ActorComponents/physics.c
	gcc -c src/ActorComponents/audio.c
	gcc -c src/actor.c
	gcc -c src/terrain.c
	gcc -c src/protag.c
	gcc -c src/gruel.c
	gcc -c src/draw.c
	gcc -c src/localTimeLine.c
	gcc -c src/dataTypes.c
	gcc -c src/math/gMath.c
	gcc -c src/math/trig.c
	gcc -c src/math/vector.c
	gcc -c src/math/vertex.c
	gcc -c src/math/matrix.c
	gcc -c src/math/transform.c
	gcc -c src/math/normal.c
	
	gcc -g -o bin/Morte main.o options.o save.o camera.o globalBinds.o keyboard.o \
	physics.o audio.o \
	actor.o terrain.o protag.o gruel.o \
	draw.o localTimeLine.o dataTypes.o gMath.o trig.o vector.o vertex.o \
	matrix.o transform.o normal.o \
	-lSDL2 -lSDL2_mixer -lGL -lm
	
	rm main.o options.o save.o camera.o globalBinds.o keyboard.o \
	physics.o audio.o \
	actor.o terrain.o protag.o gruel.o \
	draw.o localTimeLine.o gMath.o trig.o vector.o vertex.o \
	matrix.o transform.o normal.o
	echo Compiled.
install:
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-mixer-dev
#	cd SDL
#	./configure
#	make
#	sudo make install
git push:
	clear
	echo GitHub...
	git add .
	git commit -a
	git push
git pull:
	clear
	git pull
goodbye:
	echo FAREWELL CRUEL WORLD
