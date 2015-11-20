compile:
	clear
	echo Compiling...
	gcc -c src/main.c
	gcc -c src/userControl/options.c
	gcc -c src/userControl/save.c
	gcc -c src/camera.c
	gcc -c src/globalBinds.c
	gcc -c src/userControl/keyboard.c
	gcc -c src/actorComponents/identifierComponent.c
	gcc -c src/actorComponents/timeLineComponent.c
	gcc -c src/actorComponents/audioComponent.c
	gcc -c src/actorComponents/directionComponent.c
	gcc -c src/actorComponents/direction/normal.c
	gcc -c src/actorComponents/physicsComponent.c
	gcc -c src/actorComponents/physics/vector.c
	gcc -c src/actorComponents/physics/vertex.c
	gcc -c src/actorComponents/collisionsComponent.c
	gcc -c src/actorComponents/AIComponent.c
	gcc -c src/actorComponents/lightingComponent.c
	gcc -c src/actorComponents/lighting/reflection.c
	gcc -c src/actorComponents/lighting/color.c
	gcc -c src/actorComponents/renderComponent.c
	gcc -c src/actors.c
	gcc -c src/terrain.c
	gcc -c src/protag.c
	gcc -c src/shaders/shaders.c
	gcc -c src/globalTimeLine.c
	gcc -c src/dataTypes.c
	gcc -c src/math/gMath.c
	gcc -c src/math/pythag.c
	gcc -c src/math/angles.c
	gcc -c src/math/quaternion.c
	gcc -c src/math/matrix.c
	
	gcc -g -o bin/Morte main.o options.o save.o camera.o globalBinds.o keyboard.o \
	identifierComponent.o timeLineComponent.o audioComponent.o \
	directionComponent.o normal.o \
	physicsComponent.o vector.o vertex.o \
	collisionsComponent.o AIComponent.o \
	lightingComponent.o reflection.o color.o \
	renderComponent.o \
	actors.o terrain.o protag.o \
	shaders.o globalTimeLine.o dataTypes.o gMath.o pythag.o \
	angles.o quaternion.o matrix.o \
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
	angles.o quaternion.o matrix.o
	
	echo Compiled.
run:
	./bin/Morte
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
site:
	clear
	sudo cp -r website/. ../../../var/www/html
	echo Website Updated.
goodbye:
	echo FAREWELL CRUEL WORLD
