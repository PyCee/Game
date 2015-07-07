run:
	clear
	echo Compiling...
	gcc -c src/main.c
	gcc -c src/options.c
	gcc -c src/save.c
	gcc -c src/camera.c
	gcc -c src/globalBinds.c
	gcc -c src/keyboard.c
	gcc -c src/DynActorComponents/identifierComponent.c
	gcc -c src/DynActorComponents/AIComponent.c
	gcc -c src/DynActorComponents/audioComponent.c
	gcc -c src/DynActorComponents/directionComponent.c
	gcc -c src/DynActorComponents/physicsComponent.c
	gcc -c src/DynActorComponents/collisionsComponent.c
	gcc -c src/DynActorComponents/audioComponent.c
	gcc -c src/dyn_actors.c
	gcc -c src/terrain.c
	gcc -c src/protag.c
	gcc -c src/gruel.c
	gcc -c src/draw.c
	gcc -c src/localTimeLine.c
	gcc -c src/globalTimeLine.c
	gcc -c src/dataTypes.c
	gcc -c src/math/gMath.c
	gcc -c src/math/trig.c
	gcc -c src/math/vector.c
	gcc -c src/math/matrix.c
	gcc -c src/math/transform.c
	gcc -c src/math/normal.c
	
	gcc -g -o bin/Morte main.o options.o save.o camera.o globalBinds.o keyboard.o \
	identifierComponent.o AIComponent.o audioComponent.o directionComponent.o physicsComponent.o collisionsComponent.o \
	dyn_actors.o terrain.o protag.o gruel.o \
	draw.o localTimeLine.o globalTimeLine.o dataTypes.o gMath.o trig.o vector.o \
	matrix.o transform.o normal.o \
	-lSDL2 -lSDL2_mixer -lGL -lm
	
	rm main.o options.o save.o camera.o globalBinds.o keyboard.o \
	identifierComponent.o AIComponent.o audioComponent.o directionComponent.o physicsComponent.o collisionsComponent.o \
	dyn_actors.o terrain.o protag.o gruel.o \
	draw.o localTimeLine.o globalTimeLine.o dataTypes.o gMath.o trig.o vector.o \
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
