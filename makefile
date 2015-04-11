
run:
	clear
	echo Compiling...
	gcc -c src/main.c
	gcc -c src/options.c
	gcc -c src/globalBinds.c
	gcc -c src/keyboard.c
	gcc -c src/physics.c
	gcc -c src/character.c
	gcc -c src/terrain.c
	gcc -c src/protag.c
	gcc -c src/draw.c
	gcc -c src/math/gMath.c
	gcc -c src/math/trig.c
	gcc -c src/math/vector.c
	gcc -c src/math/vertex.c
	gcc -c src/math/matrix.c
	gcc -c src/math/transform.c
	
	gcc -g -o bin/Morte main.o options.o globalBinds.o keyboard.o physics.o \
	character.o terrain.o protag.o draw.o gMath.o trig.o vector.o vertex.o \
	matrix.o transform.o -lSDL2 -lGL -lm
	rm main.o options.o globalBinds.o keyboard.o physics.o \
	character.o terrain.o protag.o draw.o gMath.o trig.o vector.o vertex.o \
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
