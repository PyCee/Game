
#include <SDL2/SDL.h>

#include "keyboard.h"

#include "character.h"
#include "protag.h"
#include "globalBinds.h"

extern char IAMALIVE;

void InitKeyboard
()
{	
	//will want in final project, keep mouse on screen/hidden
	SDL_SetRelativeMouseMode(1);
	int index = 0;
	while(index < 274){
		pressed[index] = 0;
		press[index] = UselessFunction;
		release[index] = UselessFunction;
		index++;
	}
	press[SDLK_ESCAPE] = EndGame;
	press[SDLK_w] = setForwardTrue;
	release[SDLK_w] = setForwardFalse;
	press[SDLK_a] = setLeftTrue;
	release[SDLK_a] = setLeftFalse;
	press[SDLK_s] = setBackwardTrue;
	release[SDLK_s] = setBackwardFalse;
	press[SDLK_d] = setRightTrue;
	release[SDLK_d] = setRightFalse;
	press[SDLK_SPACE] = Jump;
}

void handleEvents
()
{
  SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				IAMALIVE = 0;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym < 274){
					if(pressed[event.key.keysym.sym] == 0){
					press[event.key.keysym.sym](GetControlledCharacter());
					pressed[event.key.keysym.sym] = 1;
					}
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym < 274){
					if(pressed[event.key.keysym.sym] == 1){
					release[event.key.keysym.sym](GetControlledCharacter());
					pressed[event.key.keysym.sym] = 0;
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT){}
				else if (event.button.button == SDL_BUTTON_RIGHT){}
				else if (event.button.button == SDL_BUTTON_MIDDLE){}
        break;
      case SDL_MOUSEMOTION:
      // move camera (tilt world)
      	if (event.motion.xrel > 1.5){}
      	if (event.motion.xrel < 1.5){}
      	if (event.motion.yrel > 1.5){}
      	if (event.motion.yrel < 1.5){}
      	break;
			default:
				break;
		}
	}
}
void EndGame
()
{
	IAMALIVE = 0;
}
void UselessFunction
()
{
}
