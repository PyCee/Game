#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include "userControl/save.h"
#include "userControl/keyboard.h"
#include "userControl/options.h"
#include "actors.h"
#include "protag.h"
#include "globalTimeLine.h"
#include "actorSelection.h"
#include "actorComponents/physics/vector.h"
#include "math/angles.h"
#include "math/quaternion.h"
#include "shaders/shaders.h"
#include "fileSupport/loadFiles.h"
#include "fileSupport/XML.h"
#include "loadActorData.h"
#include "SOIL/SOIL.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define MAX_LIFE_TIME 1000 * 60

#define ACT 0

char IAMALIVE;

//<CL>change later</CL> ideas to be kept, but implimented differently as to apply globally

int main(int argc, char *argv[])
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
	
	glEnable(GL_DEPTH_TEST);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	loadOptions(DEFAULT_CONFIG_PATH);
	InitKeyboard();
	DefaultKeyboard();
	initActorComponents();
	genAllActors();
	genFrustum();
	
	printf("IAMALIVE: %d\n", IAMALIVE);
	
	addActor();
	unsigned char ter = getActor();
	loadActorData("actors/arena.xml");
	POS = genVec3(0.0, -1.0, -8);
	printActor();
	
	addActor();
	unsigned char pro = getActor();
	loadActorData("actors/actor.xml");
	POS = genVec3(0.0, 0.3, -1 * 1.0);
	printActor();
	
	unsigned char cam = genCamera();
	render[cam].render = 0;
	
	
	addActor();
	unsigned char thin = getActor();
	loadActorData("actors/thing.xml");
	POS = genVec3(1.5, 0.0, -1 * 7.0);
	printActor();
	bindCameraView(cam);
	bindMapTerrain(ter);
	bindControlledActor(pro);
	
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	printf("IAMALIVE: %d\n", IAMALIVE);
	char list[] = {pro, ter};
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	
	globalTimeLine_t *globalTimeLine;
	genGlobalTimeLine(&globalTimeLine);
	bindGlobalTimeLine(globalTimeLine);
	
	unsigned char gameState = ACT;
	while( IAMALIVE == 1 ) {
		SDL_GL_SwapWindow(gameWindow);
		
		SDL_Delay(16);
		
		glClearColor(0.0, 0.3, 0.0, 1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		updateGlobalTimeLine(getGlobalTimeLine());
		switch(gameState){
		//<CL "physics upgrade: collisions">
		case ACT:
			bindActor(pro);
			unsigned char collision = CheckBoundingBoxCollision(ter);
			vec3 proPos = POS;
			bindActor(ter);
			vec3 terPos = POS;
			if( collision == 1){
				if(proPos.vec[1] < terPos.vec[1] + getHeight()){
					float terHeight = getHeight();
					bindActor(pro);
					POS = genVec3(proPos.vec[0], terPos.vec[1] + terHeight, proPos.vec[2]);
					//vec3 proVel = VEL;
					VEL[0]->vec[1] = 0.0;
				}
			}
			///printf("%i\n", collision);
			//</CL>
			printf("Handling Events\n");
			handleEvents();
			printf("Events Handled\n");
			updateActors();
			updateQuests();
			break;
		default:
			break;
		}
		if(getElapsedTime(globalTimeLine) > MAX_LIFE_TIME)
			IAMALIVE = 0;
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
	
	printf("%s Ended.\n", PROGRAM_NAME);
}
