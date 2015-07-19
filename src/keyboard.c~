
#include "dataTypes.h"
#include "keyboard.h"


#include <SDL2/SDL.h>
#include "camera.h"
#include "actors.h"
#include "protag.h"
#include "globalBinds.h"
#include "ActorComponents/physics/vector.h"
#include "ActorComponents/direction/normal.h"

extern U8 IAMALIVE;
extern U8 BLINK;

void InitKeyboard
(void)
{
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
		LoadKeyBindings();
	}
	U16 index = 0;
	while(index < 274){
		pressed[index] = 0;
		index++;
	}
}
void DefaultKeyboard
(void)
{
	U16 keys = 0;
	while (keys < 274 * 2){
		keyFunctions[keys] = UselessFunction;
		keys++;
	}
	keyFunctions[2 * SDLK_p] = EndGame;
	keyFunctions[2 * SDLK_p + 1] = UselessFunction;
	functionKeys[0] = 'p';
	keyFunctions[2 * SDLK_w] = ControlledActorForward;
	keyFunctions[2 * SDLK_w + 1] = ControlledActorBackward;
	functionKeys[1] = 'w';
	keyFunctions[2 * SDLK_a] = ControlledActorLeft;
	keyFunctions[2 * SDLK_a + 1] = ControlledActorRight;
	functionKeys[2] = 'a';
	keyFunctions[2 * SDLK_s] = ControlledActorBackward;
	keyFunctions[2 * SDLK_s + 1] = ControlledActorForward;
	functionKeys[3] = 's';
	keyFunctions[2 * SDLK_d] = ControlledActorRight;
	keyFunctions[2 * SDLK_d + 1] = ControlledActorLeft;
	functionKeys[4] = 'd';
	keyFunctions[2 * SDLK_l] = Jump;
	keyFunctions[2 * SDLK_l + 1] = UselessFunction;
	functionKeys[5] = 'l';
	SaveKeyBindings();
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
						keyFunctions[2 * event.key.keysym.sym]();
						pressed[event.key.keysym.sym] = 1;
					}
				}// for mods, test with SDLK_---
				if(event.key.keysym.mod & KMOD_NUM){
					printf("%d\n", KMOD_NUM);
					printf("aaskdjuir\n");
				} else if(event.key.keysym.mod & KMOD_LALT){
					printf("%d\n", KMOD_LALT);
					
				} else if(event.key.keysym.mod & KMOD_RALT){
					printf("%d\n", KMOD_RALT);
					
				} else if(event.key.keysym.mod & KMOD_CAPS){
					printf("%d\n", KMOD_CAPS);
					
				} else if(event.key.keysym.mod & KMOD_LCTRL){
					printf("%d\n", KMOD_LCTRL);
					
				} else if(event.key.keysym.mod & KMOD_RCTRL){
					printf("%d\n", KMOD_RCTRL);
					
				} else if(event.key.keysym.mod & KMOD_LSHIFT){
					printf("%d\n", KMOD_LSHIFT);
					
				} else if(event.key.keysym.mod & KMOD_RSHIFT){
					printf("%d\n", KMOD_RSHIFT);
					
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym < 274){
					if(pressed[event.key.keysym.sym] == 1){
						keyFunctions[2 * event.key.keysym.sym + 1]();
						pressed[event.key.keysym.sym] = 0;
					}
				} else if(event.key.keysym.mod & KMOD_NUM){
					
				} else if(event.key.keysym.mod & KMOD_LALT){
					
				} else if(event.key.keysym.mod & KMOD_RALT){
					
				} else if(event.key.keysym.mod & KMOD_CAPS){
					
				} else if(event.key.keysym.mod & KMOD_LCTRL){
					
				} else if(event.key.keysym.mod & KMOD_RCTRL){
					
				} else if(event.key.keysym.mod & KMOD_LSHIFT){
					
				} else if(event.key.keysym.mod & KMOD_RSHIFT){
					
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						BLINK = 1;
						break;
					case SDL_BUTTON_RIGHT:
						break;
					case SDL_BUTTON_MIDDLE:
						break;
					default:
						break;
				}
        break;
			case SDL_MOUSEBUTTONUP:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						BLINK = 0;
						break;
					case SDL_BUTTON_RIGHT:
						break;
					case SDL_BUTTON_MIDDLE:
						break;
					default:
						break;
				}
        break;
      case SDL_MOUSEMOTION:
      	// Tilt Global Camera
      	DirectionYaw(getCameraView(), event.motion.xrel);
      	DirectionPitch(getCameraView(), event.motion.yrel);
      	PrintNormal(Actors.direction[getCameraView()].forward);
      	break;
			default:
				break;
		}
	}
}
void LoadKeyBindings
(void)
{
	printf("Loading Key Bindings\n");
	FILE *loadFile;
	if ((loadFile = fopen(KEY_BINDINGS_PATH, "r")) == NULL)
	{
		if ((loadFile = fopen(KEY_BINDINGS_PATH, "a+")) == NULL)
			printf("ERROR::KEY::BINDINGS::LOCATION::FILE_NOT_CREATED\n");
		else
		{
			printf("KEY::BINDINGS::LOCATION::FILE_CREATED\n");
			fclose(loadFile);
			DefaultKeyboard();
		}
	} else {
		U16 keys = 0;
		while (keys < 274 * 2){
			keyFunctions[keys] = UselessFunction;
			keys++;
		}
		U8 line = 0;
		void (*Press)(void), (*Release)(void);
		while(line < 6/* number of keyfunctions */){
			switch(line){
				case 0: // on first line,
					Press = EndGame;
					Release = UselessFunction;
					break;
				case 1:
					Press = ControlledActorForward;
					Release = ControlledActorBackward;
					break;
				case 2:
					Press = ControlledActorLeft;
					Release = ControlledActorRight;
					break;
				case 3:
					Press = ControlledActorBackward;
					Release = ControlledActorForward;
					break;
				case 4:
					Press = ControlledActorRight;
					Release = ControlledActorLeft;
					break;
				case 5:
					Press = Jump;
					Release = UselessFunction;
					break;
				default:
					printf("NO::CASE::STATEMENT::FOR::-->%i<--::IN::LoadKeyBindings\n", line);
				break;
			}
			I8 key[6];
			fscanf(loadFile, "%*s %s ", key);
			switch (strlen(key)){
			case 1:
				keyFunctions[2 * key[0]] = Press;
				keyFunctions[2 * key[0] + 1] = Release;
				functionKeys[line] = key[0];
				break;
			case 2:
				if (key[0] == 'f'){
					switch (key[1]){
						case '1':
							break;
						case '2':
							break;
						case '3':
							break;
						case '4':
							break;
						case '5':
							break;
						case '6':
							break;
						case '7':
							break;
						case '8':
							break;
						case '9':
							break;
						default:
							printf("INVALID::INPUT::keyBindings Line %d::F%c\n", line, key[1]);
							break;
					}
				}
				break;
			case 3:
				if (strcmp(key, "num")){
					//keyFunctions[2 * SDLK_NUM] = Press;
					//keyFunctions[2 * SDLK_NUM + 1] = Release;
				}
				break;
			case 4:
				if (strcmp(key, "lalt")){
					//keyFunctions[2 * SDLK_LALT] = Press;
					//keyFunctions[2 * SDLK_LALT + 1] = Release;
				} else if (strcmp(key, "ralt")){
					//keyFunctions[2 * SDLK_RALT] = Press;
					//keyFunctions[2 * SDLK_RALT + 1] = Release;
				}else if (strcmp(key, "caps")){
					//keyFunctions[2 * SDLK_CAPS] = Press;
					//keyFunctions[2 * SDLK_CAPS + 1] = Release;
				}
				break;
			case 5:
				if (strcmp(key, "lctrl")){
					//keyFunctions[2 * SDLK_LCTRL] = Press;
					//keyFunctions[2 * SDLK_LCTRL + 1] = Release;
				} else if (strcmp(key, "rctrl")){
					//keyFunctions[2 * SDLK_RCTRL] = Press;
					//keyFunctions[2 * SDLK_RCTRL + 1] = Release;
				}
				break;
			case 6:
				if (strcmp(key, "escape")){
					keyFunctions[2 * SDLK_ESCAPE] = Press;
					keyFunctions[2 * SDLK_ESCAPE + 1] = Release;
				} else if (strcmp(key, "lshift")){
					//keyFunctions[2 * SDLK_LSHIFT] = Press;
					//keyFunctions[2 * SDLK_LSHIFT + 1] = Release;
				} else if (strcmp(key, "rshift")){
					//keyFunctions[2 * SDLK_RSHIFT] = Press;
					//keyFunctions[2 * SDLK_RSHIFT + 1] = Release;
				}
				break;
			default:
				printf("ERROR::INVALID::STRING::ENTERED::IN::KEY_BINDING_FILE::AT::LINE::%d\n", line);
				break;
			}
			line++;
		}
	}
	printf("Key Bindings Loaded\n");
}
void SaveKeyBindings
(void)
{
	printf("Saving Key Bindings\n");
	FILE *keyBindingsFile;
	keyBindingsFile = fopen(KEY_BINDINGS_PATH, "w");
	fprintf(keyBindingsFile, STR_SAVE_FILE_EXIT, functionKeys[0]);
	fprintf(keyBindingsFile, STR_SAVE_FILE_FOREWARD, functionKeys[1]);
	fprintf(keyBindingsFile, STR_SAVE_FILE_LEFT, functionKeys[2]);
	fprintf(keyBindingsFile, STR_SAVE_FILE_BACKWARD , functionKeys[3]);
	fprintf(keyBindingsFile, STR_SAVE_FILE_RIGHT, functionKeys[4]);
	fprintf(keyBindingsFile, STR_SAVE_FILE_JUMP, functionKeys[5]);
	fclose(keyBindingsFile);
	printf("Key Bindings Saved\n");
}
