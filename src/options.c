
#include "options.h"
#include <stdio.h>

void InitOptions
()
{
	// load options from file
	printf("Initing Options.\n");
	FILE *configFile;
	if ((configFile = fopen(CONFIG_LOC, "a+")) == NULL)
	{
		printf("ERROR::CONFIG::LOCATION::FILE_NOT_FOUND\n");
	} else
	{
		fprintf(configFile, "asd\n");
		fclose(configFile);
	}
	printf("Options Inited.\n");
}
void SaveOptions
()
{
	// write to file
}
void ResetAllOptions
()
{
	ResetAllSoundOptions();
	ResetAllVideoOptions();
	ResetAllControlOptions();
}
void ResetAllSoundOptions
()
{
	ResetSoundLevel();
	ResetMusicLevel();
	ResetEffectsLevel();
}
void ResetSoundLevel
()
{
	SoundLevel = DEFAULT_SOUND_LEVEL;
}
void ResetMusicLevel
()
{
	MusicLevel = DEFAULT_MUSIC_LEVEL;
}
void ResetEffectsLevel
()
{
	EffectsLevel = DEFAULT_EFFECTS_LEVEL;
}
void ResetAllVideoOptions
()
{
	ResetBrightness();
	ResetFOV();
}
void ResetBrightness
()
{
	Brightness = DEFAULT_BRIGHTNESS;
}
void ResetFOV
()
{
	FOV = DEFAULT_FOV;
}
void ResetAllControlOptions
()
{
	ResetMouseSensitivity();
}
void ResetMouseSensitivity
()
{
	MouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
}
