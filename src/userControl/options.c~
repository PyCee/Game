
#include "../dataTypes.h"
#include "options.h"
#include <stdio.h>

void InitOptions
(void)
{
	// load options from file
	printf("Initing Options.\n");
	FILE *configFile;
	if ((configFile = fopen(CONFIG_PATH, "r")) == NULL) {
		if ((configFile = fopen(CONFIG_PATH, "a+")) == NULL)
			printf("ERROR::CONFIG::LOCATION::FILE_NOT_CREATED\n");
		else {
			fclose(configFile);
			DefaultAllOptions();
			SaveOptions();
		}
	} else {
		fscanf(configFile, " %*s %hhu", &SoundLevel);
		fscanf(configFile, " %*s %hhu", &MusicLevel);
		fscanf(configFile, " %*s %hhu", &SoundEffectsLevel);
		fscanf(configFile, " %*s %hhu", &FieldOfView);
		fscanf(configFile, " %*s %hhu", &Brightness);
		fscanf(configFile, " %*s %hhu", &MouseSensitivity);
		fscanf(configFile, " %*s %hhu", &MouseLock);
		fclose(configFile);
		
		SDL_SetRelativeMouseMode(MouseLock);
	}
	printf("Options Inited.\n");
}
void SaveOptions
(void)
{
	// write to file
	FILE *configFile;
	if ((configFile = fopen(CONFIG_PATH, "w")) == NULL)
	{
		printf("ERROR::CONFIG::LOCATION::FILE_NOT_FOUND\n");
	} else
	{
		fprintf(configFile, "%25s %u\n", STR_SOUND_LEVEL, SoundLevel);
		fprintf(configFile, "%25s %u\n", STR_MUSIC_LEVEL, MusicLevel);
		fprintf(configFile, "%25s %u\n", STR_SOUND_EFFECTS_LEVEL, SoundEffectsLevel);
		fprintf(configFile, "%25s %u\n", STR_FIELD_OF_VIEW, FieldOfView);
		fprintf(configFile, "%25s %u\n", STR_BRIGHTNESS, Brightness);
		fprintf(configFile, "%25s %u\n", STR_MOUSE_SENSITIVITY, MouseSensitivity);
		fprintf(configFile, "%25s %u\n", STR_MOUSE_LOCK, MouseLock);
		fclose(configFile);
	}
}
void DefaultAllOptions
(void)
{
	DefaultAllSoundOptions();
	DefaultAllVideoOptions();
	DefaultAllControlOptions();
}
void DefaultAllSoundOptions
(void)
{
	DefaultSoundLevel();
	DefaultMusicLevel();
	DefaultEffectsLevel();
}
void DefaultSoundLevel
(void)
{
	SoundLevel = DEFAULT_SOUND_LEVEL;
}
void DefaultMusicLevel
(void)
{
	MusicLevel = DEFAULT_MUSIC_LEVEL;
}
void DefaultEffectsLevel
(void)
{
	SoundEffectsLevel = DEFAULT_SOUND_EFFECTS_LEVEL;
}
void DefaultAllVideoOptions
(void)
{
	DefaultBrightness();
	DefaultFieldOfView();
}
void DefaultBrightness
(void)
{
	Brightness = DEFAULT_BRIGHTNESS;
}
void DefaultFieldOfView
(void)
{
	FieldOfView = DEFAULT_FIELD_OF_VIEW;
}
void DefaultAllControlOptions
(void)
{
	DefaultMouseSensitivity();
	DefaultMouseLock();
}
void DefaultMouseSensitivity
(void)
{
	MouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
}

void DefaultMouseLock
(void)
{
	MouseLock = DEFAULT_MOUSE_LOCK;
}
