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

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 520
#define WINDOW_HEIGHT 480

U8 IAMALIVE;
U8 BLINK;

//<CL>change later</CL> ideas to be kept, but implimented differently as to apply globally

I32 main
(I32 argc, I8 *argv[])
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
	BindGlobalTimeLine(globalTimeLine);
	
	initActorComponents();
	genAllActors();
	
	U8 ter = genTerrain();
	U8 pro = genProtag();
	U8 cam = genCamera();
	BindCameraView(cam);
	
	BindMapTerrain(ter);
	BindControlledActor(pro);
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	U8 list[] = {pro, ter};
	
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	//drawInit();
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	
	while( IAMALIVE == 1 ) {
	
		SDL_GL_SwapWindow(gameWindow);
		
		SDL_Delay(16);
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		updateGlobalTimeLine(getGlobalTimeLine());
		
		//<CL "physics upgrade: collisions">
		
		U8 collision = CheckBoundingBoxCollision(pro, ter);
		if( collision == 1){
			if(getPosY(pro) < getPosY(ter) + getHeight(ter)){
				setPosY(pro, getPosY(ter) + getHeight(ter));
				setVelY(pro, 0.0);
			}
		}
		//</CL>
		handleEvents();
		updateActors();
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	UnbindControlledActor();
	UnbindMapTerrain();
	UnbindCameraView();
	UnbindGlobalTimeLine();
	freeAllActors();
	freeGlobalTimeLine(&globalTimeLine);
	SaveOptions();
	DefaultKeyboard();
	
	Mix_FreeMusic(BGMusic);
	BGMusic = NULL;
	Mix_Quit();
	SDL_Quit();
	
	/*Vector_t asd;
	genVector(&asd, 0, 1, 0);
	PrintVector(asd);
	NormalizeNormal(&asd);
	copyVector(&asd, *PitchVector(asd, 90));//DegreesToRadians(90)));
	NormalizeNormal(&asd);
	PrintVector(asd);
	*/
	/*FILE *loadFile;
	loadFile = fopen(KEY_BINDINGS_PATH, "r");
	fscanf(loadFile, "%*s %*s");
	char i = getc(loadFile);
	if (i == '\n')
		printf("jfhjfhfjfhfjdj");
	fclose(loadFile);*/
}
