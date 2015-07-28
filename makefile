run:
	clear
	echo Compiling...
	gcc -c src/main.c
	gcc -c src/options.c
	gcc -c src/save.c
	gcc -c src/camera.c
	gcc -c src/globalBinds.c
	gcc -c src/keyboard.c
	gcc -c src/ActorComponents/identifierComponent.c
	gcc -c src/ActorComponents/timeLineComponent.c
	gcc -c src/ActorComponents/AIComponent.c
	gcc -c src/ActorComponents/audioComponent.c
	gcc -c src/ActorComponents/directionComponent.c
	gcc -c src/ActorComponents/direction/normal.c
	gcc -c src/ActorComponents/physicsComponent.c
	gcc -c src/ActorComponents/physics/vector.c
	gcc -c src/ActorComponents/physics/vertex.c
	gcc -c src/ActorComponents/collisionsComponent.c
	gcc -c src/ActorComponents/lightingComponent.c
	gcc -c src/ActorComponents/lighting/reflection.c
	gcc -c src/ActorComponents/lighting/color.c
	gcc -c src/ActorComponents/renderComponent.c
	gcc -c src/actors.c
	gcc -c src/terrain.c
	gcc -c src/protag.c
	gcc -c src/shaders/shaders.c
	gcc -c src/globalTimeLine.c
	gcc -c src/dataTypes.c
	gcc -c src/math/gMath.c
	gcc -c src/math/pythag.c
	gcc -c src/math/angles.c
	
	gcc -g -o bin/Morte main.o options.o save.o camera.o globalBinds.o keyboard.o \
	identifierComponent.o timeLineComponent.o AIComponent.o audioComponent.o \
	directionComponent.o normal.o \
	physicsComponent.o vector.o vertex.o \
	collisionsComponent.o \
	lightingComponent.o reflection.o color.o \
	renderComponent.o \
	actors.o terrain.o protag.o \
	shaders.o globalTimeLine.o dataTypes.o gMath.o pythag.o \
	angles.o \
	-lSDL2 -lSDL2_mixer -lGL -lm -lassimp
	
	rm main.o options.o save.o camera.o globalBinds.o keyboard.o \
	identifierComponent.o timeLineComponent.o AIComponent.o audioComponent.o \
	directionComponent.o normal.o \
	physicsComponent.o vector.o vertex.o \
	collisionsComponent.o \
	lightingComponent.o reflection.o color.o \
	renderComponent.o \
	actors.o terrain.o protag.o \
	shaders.o globalTimeLine.o dataTypes.o gMath.o pythag.o \
	angles.o
	
	echo Compiled.
install:
	sudo apt-get install libsdl2-dev # library that handels window creation and input
	sudo apt-get install libsdl2-mixer-dev
	sudo apt-get install libassimp-dev # library for importing 3d models
	git config --global user.email "Kpampusch@yahoo.com"
	git config --global user.name "NotSarcastic"
	git config --global core.editor gedit
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
