#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
#include "actorComponents/physics/physicsAttributeController.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/renderComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "math/angles.h"
#include "math/quaternion.h"
#include "shaders/shaders.h"
#include "fileSupport/loadFiles.h"
#include "fileSupport/XML.h"
#include "loadActorData.h"
#include "SOIL/SOIL.h"
#include "actorComponents/physics/capsule.h"
#include "actorComponents/physics/sphere.h"
#include "callback/callback.h"
#include "callback/timeout.h"
#include "callback/endGame.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define MAX_LIFE_TIME 3
#define MAX_LIFE_TIME_MS 1000 * MAX_LIFE_TIME

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
	
	addVec3Vec3Actor();
	unsigned char ter = getActor();
	loadActorData("actors/arena.xml");
	*POSITION = genVec3(0.0, -1.0, -8);
	
	addVec3Vec3Actor();
	unsigned char pro = getActor();
	loadActorData("actors/actor.xml");
	*POSITION = genVec3(0.0, 0.9, -1 * 2.0);
	
	addVec3Vec3Actor();
	unsigned char cam = getActor();
	loadActorData("actors/camera.xml");
	render[cam].render = 0;
	
	addVec3Vec3Actor();
	unsigned char thin = getActor();
	loadActorData("actors/thing.xml");
	*POSITION = genVec3(1.5, 0.0, -1 * 7.0);
	//printActor();
	bindCameraView(cam);
	bindMapTerrain(ter);
	bindControlledActor(pro);
	
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	printf("IAMALIVE: %d\n", IAMALIVE);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	
	globalTimeLine_t *globalTimeLine;
	genGlobalTimeLine(&globalTimeLine);
	bindGlobalTimeLine(globalTimeLine);
	
	printf("max ms: %d\n", MAX_LIFE_TIME_MS);
	int tim = MAX_LIFE_TIME_MS;
	printf("max ms: %d\n", tim);
	callback timeoutGame = genTimeout(tim, endGame);
	enableCallback(&timeoutGame);
	
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
			vec3 proPos = *POSITION;
			bindActor(ter);
			vec3 terPos = *POSITION;
			if( collision == 1){
				bindActor(getMapTerrain());
				if(proPos.vec[1] < terPos.vec[1] + getHeight()){
					float terHeight = getHeight();
					bindActor(pro);
					POSITION->vec[1] = terPos.vec[1] + terHeight;
					VELOCITY->vec[1] = 0.0;
				}
			}
			//</CL>
			handleEvents();
			updateActors();
			updateQuests();
			updateCallbacks();
			break;
		default:
			break;
		}
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	
	bindCameraView(0);
	bindMapTerrain(0);
	bindControlledActor(0);
	bindGlobalTimeLine(0);
	freeAllActors();
	freeCallbacks();
	freeGlobalTimeLine(&globalTimeLine);
	SaveOptions();
	DefaultKeyboard();
	
	Mix_FreeMusic(BGMusic);
	BGMusic = NULL;
	Mix_Quit();
	SDL_Quit();
	printf("%s Ended.\n", PROGRAM_NAME);
	
	vec3 *poi1 = malloc(sizeof(vec3));
	*poi1 = genVec3(0.0, 0.0, 0.0);
	sphere sph1 = genSphere(poi1, 1.3000);
	
	vec3 *poi3 = malloc(sizeof(vec3));
	*poi3 = genVec3(2.0, 0.0, 0.0);
	sphere sph2 = genSphere(poi3, 0.7);
	
	unsigned char colis = collisionSphereSphere(sph1, sph2);
	printf("collided = %hhu\n", colis);
}
