
#include "keyboard.h"

#include <SDL2/SDL.h>
#include "../actors/camera.h"
#include "options.h"
#include "../actors.h"
#include "controls.h"
#include "../actorComponents/physics/vector.h"
#include "../actorComponents/directionComponent.h"
#include "../math/quaternion.h"

extern unsigned char IAMALIVE;

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
	unsigned short index = 0;
	while(index < 274){
		pressed[index] = 0;
		index++;
	}
}
void DefaultKeyboard
(void)
{
	unsigned short keys = 0;
	while (keys < 274 * 2){
		keyFunctions[keys] = UselessFunction;
		detectWhilePaused[keys] = 1;
		keys++;
	}
	keyFunctions[2 * SDLK_p] = toggleAllPause;
	keyFunctions[2 * SDLK_p + 1] = UselessFunction;
	functionKeys[0] = 'p';
	keyFunctions[2 * SDLK_t] = EndGame;
	keyFunctions[2 * SDLK_t + 1] = UselessFunction;
	functionKeys[0] = 't';
	keyFunctions[2 * SDLK_w] = ControlledActorForward;
	keyFunctions[2 * SDLK_w + 1] = UnControlledActorForward;
	functionKeys[1] = 'w';
	keyFunctions[2 * SDLK_a] = ControlledActorLeft;
	keyFunctions[2 * SDLK_a + 1] = UnControlledActorLeft;
	functionKeys[2] = 'a';
	keyFunctions[2 * SDLK_s] = ControlledActorBackward;
	keyFunctions[2 * SDLK_s + 1] = UnControlledActorBackward;
	functionKeys[3] = 's';
	keyFunctions[2 * SDLK_d] = ControlledActorRight;
	keyFunctions[2 * SDLK_d + 1] = UnControlledActorRight;
	functionKeys[4] = 'd';
	keyFunctions[2 * SDLK_SPACE] = ControlledActorJump;
	keyFunctions[2 * SDLK_SPACE + 1] = UselessFunction;
	detectWhilePaused[2 * SDLK_SPACE] = 0;
	keyFunctions[2 * SDLK_r] = ToggleLockOn;
	keyFunctions[2 * SDLK_r + 1] = UselessFunction;
	detectWhilePaused[2 * SDLK_r] = 0;
	functionKeys[5] = 'l';
	SaveKeyBindings();
}
void EndGame(void)
{
	printf("Endgamecalled \n");
	IAMALIVE = 0;
}
void handleEvents(void)
{
  SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				EndGame();
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym < 274){
					if(!allActorsPaused || (detectWhilePaused[2 * event.key.keysym.sym] == 1)){
						if(pressed[event.key.keysym.sym] == 0){
							keyFunctions[2 * event.key.keysym.sym]();
							pressed[event.key.keysym.sym] = 1;
						}
					}
				}// for mods, test with SDLK_---
				if(event.key.keysym.mod & KMOD_NUM){
					printf("%d\n", KMOD_NUM);
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
					if((!allActorsPaused) || (detectWhilePaused[2 * event.key.keysym.sym] == 1)){
						if(pressed[event.key.keysym.sym] == 1){
							keyFunctions[2 * event.key.keysym.sym + 1]();
							pressed[event.key.keysym.sym] = 0;
						}
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
				// Rotate Global Camera
				//printf("Mouse Movement\n Side Movement: %f\n Up Movement: %f\n", (float)event.motion.xrel, (float)event.motion.yrel);
				
				//float yaw = -1 * event.motion.xrel * 10 * MouseSensitivity / 256;
				//float pitch = -1 * event.motion.yrel * 10 * MouseSensitivity / 256;
				
				bindActor(getCameraView());
				DirectionYaw(-1.0 * event.motion.xrel * 10 * MouseSensitivity / 256);
				DirectionPitch(-1.0 * event.motion.yrel * 10 * MouseSensitivity / 256);
				bindActor(getControlledActor());
				DirectionYaw(-1.0 * event.motion.xrel * 10 * MouseSensitivity / 256);
				DirectionPitch(-1.0 * event.motion.yrel * 10 * MouseSensitivity / 256);
				bindActor(0);
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
		unsigned short keys = 0;
		while (keys < 274 * 2){
			keyFunctions[keys] = UselessFunction;
			keys++;
		}
		unsigned char line = 0;
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
					Press = ControlledActorJump;
					Release = UselessFunction;
					break;
				default:
					printf("NO::CASE::STATEMENT::FOR::-->%i<--::IN::LoadKeyBindings\n", line);
				break;
			}
			char key[6];
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
