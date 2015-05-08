
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
	//SDL_SetRelativeMouseMode(1);
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

void handleEvents
(void)
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
void EndGame
(void)
{
	IAMALIVE = 0;
}
void UselessFunction
(void)
{
}
