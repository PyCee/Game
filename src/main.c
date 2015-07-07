#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include "dataTypes.h"
#include "save.h"
#include "keyboard.h"
#include "dyn_actors.h"
#include "protag.h"
#include "gruel.h"
#include "draw.h"
#include "globalTimeLine.h"
#include "globalBinds.h"
#include "terrain.h"
#include "math/matrix.h"
#include "math/gMath.h"
#include "math/normal.h"
#include "math/vector.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 520
#define WINDOW_HEIGHT 480

U8 IAMALIVE;
U8 BLINK;

//<CL>change later</CL> ideas to be kept, but implimented differently as to apply globally

I32 main
(I32 argc, I8 *argv[])
{
	printf("%s Starting.\nMain Initializing.\n", PROGRAM_NAME);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );
  SDL_Window* gameWindow = SDL_CreateWindow(PROGRAM_NAME, 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext gameContext = SDL_GL_CreateContext(gameWindow);
	
	 //Initialize SDL_mixer
	 if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
	 	printf("ERROR::SDL_mixer::NOT::INITIALIZED::SDL_mixer Error: %s\n", Mix_GetError());
	 }
	
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	InitOptions();
	InitKeyboard();
	
	globalTimeLine_t *globalTimeLine;
	genGlobalTimeLine(&globalTimeLine);
	BindGlobalTimeLine(globalTimeLine);
	
	genAllDyn_Actors();
	
	U8 ter = genTerrain();
	U8 pro = genProtag();
	BindCameraView(genCamera());
	BindMapTerrain(ter);
	BindControlledActor(pro);
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	U8 list[] = {pro, ter};
  
	IAMALIVE = 1;
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	drawInit();
	
	Matrix_t *turn1 = malloc(sizeof(Matrix_t));
	Matrix_t *turn2 = malloc(sizeof(Matrix_t));
	Matrix_t *turn3 = malloc(sizeof(Matrix_t));
	genMatrix(turn1, 1, 4);
	genMatrix(turn2, 1, 4);
	genMatrix(turn3, 1, 4);
	*getMatrixEle(turn2, 0, 0) = -0.1;
	*getMatrixEle(turn3, 0, 0) = 0.1;
	*getMatrixEle(turn1, 0, 0) = 0.0;
	*getMatrixEle(turn1, 0, 1) = 0.2;
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	while(IAMALIVE == 1){
	
		SDL_GL_SwapWindow(gameWindow);
		SDL_Delay(16);
		
		glClearColor(0.1, 0.1, 0.1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		updateGlobalTimeLine(getGlobalTimeLine());
		
		//<CL "basic drawing">
		
		glColor3f(1.0f, 0.85f, 0.2f);
		turn1 = Roll(*turn1, 3.1415926 / 500);
		if(*getMatrixEle(turn1, 0, 1) > 0){
			glBegin(GL_POLYGON);
 				glVertex2f(*getMatrixEle(turn2, 0, 0), *getMatrixEle(turn2, 0, 1));
 				glVertex2f(*getMatrixEle(turn3, 0, 0), *getMatrixEle(turn3, 0, 1));
 				glVertex2f(*getMatrixEle(turn1, 0, 0), *getMatrixEle(turn1, 0, 1));
			glEnd();
		} else if(*getMatrixEle(turn1, 0, 1) < 0){
			glBegin(GL_POLYGON);
 				glVertex2f(*getMatrixEle(turn2, 0, 0), *getMatrixEle(turn2, 0, 1));
 				glVertex2f(*getMatrixEle(turn1, 0, 0), *getMatrixEle(turn1, 0, 1));
 				glVertex2f(*getMatrixEle(turn3, 0, 0), *getMatrixEle(turn3, 0, 1));
			glEnd();
		}
		//</CL>
		
		draw();
		
		//<CL "physics upgrade: collisions">
		
		U8 collision = CheckBoundingBoxCollision(pro, ter);
		if( collision == 1){
			if(getPosY(pro) < getPosY(ter) + getHeight(ter)){
				*getPosYPtr(pro) = getPosY(ter) + getHeight(ter);
				*getVecYPtr(&(Dyn_Actors.physics[getControlledActor()].Vel)) = 0.0;
			}
		}
		if (BLINK == 1){
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		//</CL>
		handleEvents();
		updateDyn_Actors();
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	drawDel();
	UnbindControlledActor();
	UnbindMapTerrain();
	UnbindCameraView();
	UnbindGlobalTimeLine();
	freeAllDyn_Actors();
	freeGlobalTimeLine(&globalTimeLine);
	freeMatrix(turn1);
	freeMatrix(turn2);
	freeMatrix(turn3);
	SaveOptions();
	DefaultKeyboard();
	
	Mix_FreeMusic(BGMusic);
	BGMusic = NULL;
	Mix_Quit();
	SDL_Quit();
	
	/*FILE *loadFile;
	loadFile = fopen(KEY_BINDINGS_PATH, "r");
	fscanf(loadFile, "%*s %*s");
	char i = getc(loadFile);
	if (i == '\n')
		printf("jfhjfhfjfhfjdj");
	fclose(loadFile);*/
}
