#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include "dataTypes.h"
#include "save.h"
#include "keyboard.h"
#include "actor.h"
#include "protag.h"
#include "gruel.h"
#include "draw.h"
#include "globalTimeLine.h"
#include "globalBinds.h"
#include "terrain.h"
#include "math/matrix.h"
#include "math/gMath.h"
#include "math/normal.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 520
#define WINDOW_HEIGHT 480

U8 IAMALIVE;
U8 BLINK;

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
	
	Camera_t *camera;
	genCamera(&camera);
	
	Actor_t *player;
	genProtag(&player);
	
	Actor_t *gru;
	genGruel(&gru);
	
	Actor_t *terrain;
	genTerrain(&terrain);
	
	BindCameraView(camera);
	BindControlledActor(player);
	BindMapTerrain(terrain);
	BindGlobalTimeLine(globalTimeLine);
	
	Mix_Music *BGMusic = NULL;
	//BGMusic = Mix_LoadMUS(""); //get .wav and put path in quotes
	//Mix_PlayChannel(-1, BGMusic, 4);
	
	Actor_t *list[] = {player, terrain, gru};
  
	IAMALIVE = 1;
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	drawInit();
	
	Matrix_t *turn1;
	Matrix_t *turn2;
	Matrix_t *turn3;
	genMatrix(&turn1, 1, 4);
	genMatrix(&turn2, 1, 4);
	genMatrix(&turn3, 1, 4);
	*getMatrixEle(turn2, 0, 0) = -0.1;
	*getMatrixEle(turn3, 0, 0) = 0.1;
	*getMatrixEle(turn1, 0, 0) = 0.0;
	*getMatrixEle(turn1, 0, 1) = 0.2;
	
	printf("Main Initialized.\nMain Loop Starting.\n");
	while(IAMALIVE == 1){
	
		SDL_GL_SwapWindow(gameWindow);
		SDL_Delay(16);
		
		updateGlobalTimeLine(getGlobalTimeLine());
		
		F64 pos[] = {list[0]->physics->Pos->X, list[0]->physics->Pos->Y};
		
		glClearColor(0.0, 0.0, 0.0, 1.0);
		if (BLINK == 0)
			glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.3f, 1.0f, 0.4f);
		glBegin(GL_POLYGON);
 			glVertex2f(list[1]->physics->Pos->X, list[1]->physics->Pos->Y);
 			glVertex2f(list[1]->physics->Pos->X + list[1]->physics->Width, list[1]->physics->Pos->Y);
 			glVertex2f(list[1]->physics->Pos->X + list[1]->physics->Width, list[1]->physics->Pos->Y + list[1]->physics->Height + 0.75);
 			glVertex2f(list[1]->physics->Pos->X, list[1]->physics->Pos->Y + list[1]->physics->Height + 0.75);
		glEnd();
		
		glColor3f(1.0f, 0.85f, 0.2f);
		turn1 = Roll(turn1, 3.1415926 / 500);
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
		
		draw();
		
		handleEvents();
		
		Update(list[0], getPrevFrameDuration(getGlobalTimeLine()));
		Update(list[2], getPrevFrameDuration(getGlobalTimeLine()));
		
		U8 collision = CheckBoundingBoxCollision(list[0]->physics, list[1]->physics);
		if( collision == 1){
			if(list[0]->physics->Pos->Y < list[1]->physics->Pos->Y + list[1]->physics->Height){
				list[0]->physics->Pos->Y = list[1]->physics->Pos->Y + list[1]->physics->Height;
				list[0]->physics->Vel->Y = 0.0;
			}
		}
		collision = CheckBoundingBoxCollision(list[2]->physics, list[1]->physics);
		if( collision == 1){
			if(list[2]->physics->Pos->Y < list[1]->physics->Pos->Y + list[1]->physics->Height){
				list[2]->physics->Pos->Y = list[1]->physics->Pos->Y + list[1]->physics->Height;
				list[2]->physics->Vel->Y = 0.0;
			}
		}
		if (BLINK == 1){
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
	printf("MainLoop Ending.\n%s Ending.\n", PROGRAM_NAME);
	drawDel();
	UnbindControlledActor();
	UnbindMapTerrain();
	UnbindCameraView();
	UnbindGlobalTimeLine();
	freeCamera(&camera);
	freeActor(&player);
	freeActor(&terrain);
	freeGlobalTimeLine(&globalTimeLine);
	freeMatrix(&turn1);
	freeMatrix(&turn2);
	freeMatrix(&turn3);
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
