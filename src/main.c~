#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include "dataTypes.h"
#include "userControl/save.h"
#include "userControl/keyboard.h"
#include "actors.h"
#include "protag.h"
#include "globalTimeLine.h"
#include "actorSelection.h"
#include "actorComponents/physics/vector.h"
#include "math/angles.h"
#include "math/quaternion.h"
#include "shaders/shaders.h"
#include "loadFiles.h"
#include "loadActorData.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 520
#define WINDOW_HEIGHT 480

char IAMALIVE;

//<CL>change later</CL> ideas to be kept, but implimented differently as to apply globally

int main
(int argc, char *argv[])
{	
	IAMALIVE = 1;

	printf("%s Starting.\nMain Initializing.\n", PROGRAM_NAME);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );
	SDL_Window* gameWindow = SDL_CreateWindow(PROGRAM_NAME, 500, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext gameContext = SDL_GL_CreateContext(gameWindow);
	
	 //Initialize SDL_mixer
	 if(  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
	 	printf("ERROR::SDL_mixer::NOT::INITIALIZED::SDL_mixer Error: %s\n", Mix_GetError());
	 }
	
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	InitOptions();
	InitKeyboard();
	
	globalTimeLine_t *globalTimeLine;
	genGlobalTimeLine(&globalTimeLine);
	bindGlobalTimeLine(globalTimeLine);
	
	initActorComponents();
	genAllActors();
	
	unsigned char ter = genTerrain();
	unsigned char pro = genProtag();
	unsigned char cam = genCamera();
	bindCameraView(cam);
	bindMapTerrain(ter);
	bindControlledActor(pro);
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	char list[] = {pro, ter};
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	//drawInit();
	
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	
	printf("IAMALIVE: %d\n", IAMALIVE);
	IAMALIVE = 0;
	while( IAMALIVE == 1 ) {
	
		SDL_GL_SwapWindow(gameWindow);
		
		SDL_Delay(16);
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		updateGlobalTimeLine(getGlobalTimeLine());
		
		//<CL "physics upgrade: collisions">
		bindActor(pro);
		U8 collision = CheckBoundingBoxCollision(ter);
		vec3 proPos = Actors.physics[getActor()].Pos;
		bindActor(ter);
		vec3 terPos = Actors.physics[getActor()].Pos;
		if( collision == 1){
			if(proPos.vec[1] < terPos.vec[1] + getHeight()){
				F32 terHeight = getHeight();
				bindActor(pro);
				setPos(genVec3(proPos.vec[0], terPos.vec[1] + terHeight, proPos.vec[2]));
				vec3 proVel = Actors.physics[getActor()].Vel;
				setVel(genVec3(proVel.vec[0], 0.0, proVel.vec[2]));
			}
		}
		printf("%i\n", collision);
		//</CL>
		handleEvents();
		updateActors();
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	bindCameraView(0);
	bindMapTerrain(0);
	bindControlledActor(0);
	bindGlobalTimeLine(0);
	freeAllActors();
	freeGlobalTimeLine(&globalTimeLine);
	SaveOptions();
	DefaultKeyboard();
	
	Mix_FreeMusic(BGMusic);
	BGMusic = NULL;
	Mix_Quit();
	SDL_Quit();
	
	char *got = readXMLElements(readFile("actors/actor.xml"), "<speed>");
	printf("The house has %s rooms.\n", got);
	free(got);
	
	printf("%s Ended.\n", PROGRAM_NAME);
	loadActorData("actors/actor.xml");
}
