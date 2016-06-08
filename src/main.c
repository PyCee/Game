#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include "userControl/save.h"
#include "userControl/keyboard.h"
#include "userControl/options.h"
#include "actors.h"
#include "actors/protag.h"
#include "globalTimeline.h"
#include "actorSelection.h"
#include "actorComponents/physics/vector.h"
#include "actorComponents/physics/physicsAttributeController.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/renderComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/callbackComponent.h"
#include "math/angles.h"
#include "math/quaternion.h"
#include "shaders/shaders.h"
#include "fileSupport/loadFiles.h"
#include "fileSupport/XML.h"
#include "loadActorData.h"
#include "SOIL/SOIL.h"
#include "actorComponents/physics/collisionController.h"
#include "actorComponents/physics/collisionTypes/collisionCapsule.h"
#include "actorComponents/physics/collisionTypes/collisionSphere.h"
#include "actorComponents/physics/collisionTypes/collisionOBox.h"
#include "actorComponents/physics/collisionTypes/collisionAABox.h"
#include "actorComponents/physics/collisionTypes/collisionCylinder.h"
#include "actorComponents/physics/collisionTypes/collisionPoint.h"
#include "actorComponents/callback/callbackController.h"
#include "actorComponents/callback/timeout.h"
#include "actorComponents/callback/distanceCheck.h"
#include "actorComponents/callback/endGame.h"
#include "actorComponents/physics/octree.h"
#include "actorComponents/physics/checkOctree.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 650
#define MAX_LIFE_TIME 60 * 10
#define MAX_LIFE_TIME_MS 1000 * MAX_LIFE_TIME

#define ACT 0

char IAMALIVE;

//<CL>change later</CL> ideas to be kept, but implimented differently later

int main(int argc, char *argv[])
{	
	IAMALIVE = 1;

	printf("%s Starting.\nMain Initializing.\n", PROGRAM_NAME);
	
	srand(time(0));
	
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
	genFrustum();
	loadQuests("asd");//TODO replace with actual save-file selecting.
	
	globalTimeline gTime;
	gTime = genGlobalTimeline();
	bindGlobalTimeline(&gTime);
	
	unsigned char ter = addActor();
	loadActorData("actors/arena.xml");
	*POSITION = genVec3(0.0, -1.0, -8);
	
	unsigned char pro = addActor();
	loadActorData("actors/actor.xml");
	*POSITION = genVec3(0.0, 2.0, -1 * 2.0);
	
	callbackController *timeoutGame = malloc(sizeof(callbackController));
	*timeoutGame = genTimeout(endGame, MAX_LIFE_TIME_MS);
	enableCallbackController(timeoutGame);
	
	unsigned char cam = addActor();
	loadActorData("actors/camera.xml");
	*POSITION = genVec3(0.0, 2.0, -1 * 2.0);
	SHOULD_RENDER = 0;
	
	unsigned char thin = addActor();
	loadActorData("actors/thing.xml");
	*POSITION = genVec3(1.5, 0.0, -1 * 7.0);
	
	unsigned char buz = addActor();
	loadActorData("actors/buzz.xml");
	*POSITION = genVec3(0.0, 2.0, 0.0);
	
	bindCameraView(cam);
	bindMapTerrain(ter);
	bindControlledActor(pro);
	
	bindActor(thin);
	vec3 *pos = POSITION;
	bindActor(getControlledActor());
	callbackController *test = malloc(sizeof(callbackController));
	*test = genDistanceCheck(endGame, 1.75, pos);
	enableCallbackController(test);
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	printf("IAMALIVE: %d\n", IAMALIVE);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	
	float averageFrameMS = 1/60;
	float runningAverageMod = 0.6;
	
	
	nextOctreeNodeID = 0;
	globalOctree = genOctreeNode();
	globalOctree.size = 100;
	*globalOctree.placement = genVec3(0.0, 0.0, 0.0);
	resetOctreeBox(&globalOctree);
	
	
	unsigned char gameState = ACT;
	while(IAMALIVE == 1){
		averageFrameMS = averageFrameMS * runningAverageMod + getPrevFrameDuration(*getGlobalTimeline()) * (1.0 - runningAverageMod);
		SDL_GL_SwapWindow(gameWindow);
		
		SDL_Delay(16);
		
		glClearColor(0.0, 0.3, 0.0, 1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		updateGlobalTimeline(getGlobalTimeline());
		switch(gameState){
		case ACT:
			//<CL "physics upgrade: collisions">
			bindActor(pro);
			unsigned char collision = CheckBoundingBoxCollision(ter);
			vec3 proPos = *POSITION;
			bindActor(ter);
			vec3 terPos = *POSITION;
			if( collision == 1){
				bindActor(getMapTerrain());
				if(proPos.vec[1] < terPos.vec[1] + HEIGHT){
					float terHeight = HEIGHT;
					bindActor(pro);
					POSITION->vec[1] = terPos.vec[1] + terHeight;
					VELOCITY->vec[1] = 0.0;
				}
			}
			//</CL>
			handleEvents();
			updateActors();
			updateQuests();
			
			/*
			bindActor(pro);
			octreeNode *proOct = CONTAINING_OCTREE_NODE;
			printf("\n\nproOct id: %d\n", proOct->octreeNodeID);
			bindActor(thin);
			octreeNode *thinOct = CONTAINING_OCTREE_NODE;
			printf("\n\nthinOct id: %d\n", thinOct->octreeNodeID);
			
			printf("pro is in oct: %hhu\n\n\n", isOctreeParent(thinOct, proOct));
			*/
			
			break;
		default:
			break;
		}
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	
	bindCameraView(0);
	bindMapTerrain(0);
	bindControlledActor(0);
	bindGlobalTimeline(0);
	freeAllActors();
	freeGlobalTimeline(&gTime);
	SaveOptions();
	DefaultKeyboard();
	
	Mix_FreeMusic(BGMusic);
	BGMusic = NULL;
	Mix_Quit();
	SDL_Quit();
	printf("Average frame duration = %fms\nAverage FPS = %f frames/second\n", averageFrameMS, 1000 / averageFrameMS);
	printf("%s Ended.\n", PROGRAM_NAME);
	
	
	/*vec3 *p1 = malloc(sizeof(vec3));
	vec3 *p2 = malloc(sizeof(vec3));
	vec3 *p3 = malloc(sizeof(vec3));
	*p1 = genVec3(0.0, 0.0, 0.0);
	*p2 = genVec3(0.0, 5.0, 0.0);
	*p3 = genVec3(0.1, 4.01, 0.01);
	
	
	collisionController box1 = genCollisionAABox(p1, p2, 1);
	collisionController box2 = genCollisionAABox(p3);
	
	printf("collide = %hhu\n", containingAABoxAABox(box1, box2));
	*/
	
	
}
