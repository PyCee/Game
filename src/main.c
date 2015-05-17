#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "save.h"
#include "keyboard.h"
#include "actor.h"
#include "protag.h"
#include "gruel.h"
#include "draw.h"
#include "globalBinds.h"
#include "terrain.h"
#include "math/matrix.h"
#include "math/gMath.h"

#define PROGRAM_NAME "LDM"
#define WINDOW_WIDTH 520
#define WINDOW_HEIGHT 480

unsigned char IAMALIVE;
unsigned char BLINK;

int main
(int argc, char *argv[])
{
	printf("%s Starting.\nMain Initializing.\n", PROGRAM_NAME);
	SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* gameWindow = SDL_CreateWindow(PROGRAM_NAME, 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext gameContext = SDL_GL_CreateContext(gameWindow);
	
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
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
	
	Actor_t *list[] = {player, terrain, gru};
	InitKeyboard();
  
	IAMALIVE = 1;
	
	
	uint64_t oldTime;
	uint64_t newTime;
	newTime = SDL_GetTicks();
	oldTime = newTime;
	
	glClearColor(0.0, 1.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(gameWindow);
	
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
		
		newTime = SDL_GetTicks();
		uint64_t deltaTime = newTime - oldTime;
		oldTime = newTime;
		
		double pos[] = {list[0]->physics->Pos->X, list[0]->physics->Pos->Y};
		
		if (BLINK == 0)
			glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
 			glVertex2f(list[1]->physics->Pos->X, list[1]->physics->Pos->Y);
 			glVertex2f(list[1]->physics->Pos->X + list[1]->physics->Width, list[1]->physics->Pos->Y);
 			glVertex2f(list[1]->physics->Pos->X + list[1]->physics->Width, list[1]->physics->Pos->Y + list[1]->physics->Height + 0.5);
 			glVertex2f(list[1]->physics->Pos->X, list[1]->physics->Pos->Y + list[1]->physics->Height + 0.5);
		glEnd();
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
		
		Update(list[0], deltaTime);
		Update(list[2], deltaTime);
		
		char collision = CheckBoundingBoxCollision(list[0]->physics, list[1]->physics);
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
		glClearColor(0.0, 1.0, 0.0, 1.0);
		}
	}
	printf("MainLoop Ending.\nDel Sequence Starting.\n");
	drawDel();
	SDL_Quit();
	UnbindControlledActor();
	UnbindMapTerrain();
	UnbindCameraView();
	freeCamera(&camera);
	freeActor(&player);
	freeActor(&terrain);
	freeMatrix(&turn1);
	freeMatrix(&turn2);
	freeMatrix(&turn3);
	printf("Del Sequence Ending.\n");
	printf("%s Ending.\n", PROGRAM_NAME);
	InitOptions();
	SaveOptions();
}
