
#include "keyboard.h"


#include <SDL2/SDL.h>
#include "camera.h"
#include "actor.h"
#include "protag.h"
#include "globalBinds.h"

extern unsigned char IAMALIVE;
extern unsigned char BLINK;

void InitKeyboard
(void)
{	
	//will want in below final project, keep mouse on screen/hidden
//	SDL_SetRelativeMouseMode(1);
	KeyFunctions[2 * SDLK_ESCAPE] = EndGame;
	KeyFunctions[2 * SDLK_ESCAPE + 1] = UselessFunction;
	KeyFunctions[2 * SDLK_w] = ControlledActorForward;
	KeyFunctions[2 * SDLK_w + 1] = ControlledActorBackward;
	KeyFunctions[2 * SDLK_a] = ControlledActorForward;
	KeyFunctions[2 * SDLK_a + 1] = ControlledActorRight;
	KeyFunctions[2 * SDLK_s] = ControlledActorBackward;
	KeyFunctions[2 * SDLK_s + 1] = ControlledActorForward;
	KeyFunctions[2 * SDLK_d] = ControlledActorRight;
	KeyFunctions[2 * SDLK_d + 1] = ControlledActorLeft;
	KeyFunctions[2 * SDLK_SPACE] = Jump;
	KeyFunctions[2 * SDLK_SPACE + 1] = UselessFunction;
	
	FILE *keyBindingsFile;
	if ((keyBindingsFile = fopen(KEY_BINDINGS_PATH, "r")) == NULL)
	{
		if ((keyBindingsFile = fopen(KEY_BINDINGS_PATH, "a+")) == NULL)
			printf("ERROR::KEY::BINDINGS::LOCATION::FILE_NOT_CREATED\n");
		else
		{
			fclose(keyBindingsFile);
			DefaultKeyboard();
		}
	} else {
		
	}
	int index = 0;
	while(index < 274){
		pressed[index] = 0;
		press[index] = UselessFunction;
		release[index] = UselessFunction;
		index++;
	}
	press[SDLK_ESCAPE] = EndGame;
	press[SDLK_w] = ControlledActorForward;
	release[SDLK_w] = ControlledActorBackward;
	press[SDLK_a] = ControlledActorLeft;
	release[SDLK_a] = ControlledActorRight;
	press[SDLK_s] = ControlledActorBackward;
	release[SDLK_s] = ControlledActorForward;
	press[SDLK_d] = ControlledActorRight;
	release[SDLK_d] = ControlledActorLeft;
	press[SDLK_SPACE] = Jump;
}
void DefaultKeyboard
(void)
{
 FILE *keyBindingsFile;
	keyBindingsFile = fopen(KEY_BINDINGS_PATH, "w");
	int key = 0;
	while (key < 274){
		fprintf(keyBindingsFile, "%s = \n", SDL_GetKeyName(key));
		key++;
	}
	
	fclose(keyBindingsFile);
}
void UselessFunction
(void)
{
}
void EndGame
(void)
{
	IAMALIVE = 0;
}
void handleEvents
(void)
{
  SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				EndGame();
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym < 274){
					if(pressed[event.key.keysym.sym] == 0){
					press[event.key.keysym.sym]();
					pressed[event.key.keysym.sym] = 1;
					}
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym < 274){
					if(pressed[event.key.keysym.sym] == 1){
					release[event.key.keysym.sym]();
					pressed[event.key.keysym.sym] = 0;
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
					BLINK = 1;
				else if (event.button.button == SDL_BUTTON_RIGHT){}
				else if (event.button.button == SDL_BUTTON_MIDDLE){}
        break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
					BLINK = 0;
				else if (event.button.button == SDL_BUTTON_RIGHT){}
				else if (event.button.button == SDL_BUTTON_MIDDLE){}
        break;
      case SDL_MOUSEMOTION:
      	// move camera (tilt world)
      	CameraYaw(GetCameraView(), event.motion.xrel);
      	CameraPitch(GetCameraView(), event.motion.yrel);
      	break;
			default:
				break;
		}
	}
}
void LoadKeyBindings
(char *_loadFile)
{
	FILE *loadFile;
	if ((loadFile = fopen(KEY_BINDINGS_PATH, "r")) == NULL)
	{
		if ((loadFile = fopen(KEY_BINDINGS_PATH, "a+")) == NULL)
			printf("ERROR::KEY::BINDINGS::LOCATION::FILE_NOT_CREATED\n");
		else
		{
			fclose(loadFile);
			DefaultKeyboard();
		}
	} else {
		
	}
}
void SaveKeyBindings
(void)
{
	FILE *keyBindingsFile;
	keyBindingsFile = fopen(KEY_BINDINGS_PATH, "w");
	//fprintf(keyBingindsFile, "%c = %c", (denote key), (key function));
	
	fclose(keyBindingsFile);
}
