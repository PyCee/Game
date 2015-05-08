
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
	gcc -c src/math/gMath.c
	gcc -c src/math/trig.c
	gcc -c src/math/vector.c
	gcc -c src/math/vertex.c
	gcc -c src/math/matrix.c
	gcc -c src/math/transform.c
	
	gcc -g -o bin/Morte main.o options.o save.o camera.o globalBinds.o keyboard.o \
	physics.o audio.o \
	actor.o terrain.o protag.o gruel.o \
	draw.o gMath.o trig.o vector.o vertex.o \
	matrix.o transform.o \
	-lSDL2 -lGL -lm
	rm main.o options.o save.o camera.o globalBinds.o keyboard.o \
	physics.o audio.o \
	actor.o terrain.o protag.o gruel.o \
	draw.o gMath.o trig.o vector.o vertex.o \
	matrix.o transform.o
	echo Compiled.
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
