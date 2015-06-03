
#include "options.h"
#include <stdio.h>

void InitOptions
()
{
	// load options from file
	printf("Initing Options.\n");
	FILE *configFile;
	if ((configFile = fopen(CONFIG_PATH, "r")) == NULL)
	{
		if ((configFile = fopen(CONFIG_PATH, "a+")) == NULL)
			printf("ERROR::CONFIG::LOCATION::FILE_NOT_CREATED\n");
		else
		{
			DefaultAllOptions();
			fprintf(configFile, STR_SOUND_LEVEL, SoundLevel);
			fprintf(configFile, STR_MUSIC_LEVEL, MusicLevel);
			fprintf(configFile, STR_SOUND_EFFECTS_LEVEL, SoundEffectsLevel);
			fprintf(configFile, STR_FIELD_OF_VIEW, FieldOfView);
			fprintf(configFile, STR_BRIGHTNESS, Brightness);
			fprintf(configFile, STR_MOUSE_SENSITIVITY, MouseSensitivity);
			fclose(configFile);
		}
	} else
	{
		fscanf(configFile, "%*s%*s%hhu", &SoundLevel);
		fscanf(configFile, "%*s%*s%hhu", &MusicLevel);
		fscanf(configFile, "%*s%*s%*s%hhu", &SoundEffectsLevel);
		fscanf(configFile, "%*s%*s%*s%hhu", &FieldOfView);
		fscanf(configFile, "%*s%hhu", &Brightness);
		fscanf(configFile, "%*s%*s%hhu", &MouseSensitivity);
		fclose(configFile);
	}
	printf("Options Inited.\n");
}
void SaveOptions
()
{
	// write to file
	FILE *configFile;
	if ((configFile = fopen(CONFIG_PATH, "w")) == NULL)
	{
		printf("ERROR::CONFIG::LOCATION::FILE_NOT_FOUND\n");
	} else
	{
		fprintf(configFile, STR_SOUND_LEVEL, SoundLevel);
		fprintf(configFile, STR_MUSIC_LEVEL, MusicLevel);
		fprintf(configFile, STR_SOUND_EFFECTS_LEVEL, SoundEffectsLevel);
		fprintf(configFile, STR_FIELD_OF_VIEW, FieldOfView);
		fprintf(configFile, STR_BRIGHTNESS, Brightness);
		fprintf(configFile, STR_MOUSE_SENSITIVITY, MouseSensitivity);
		fclose(configFile);
	}
}
void DefaultAllOptions
()
{
	DefaultAllSoundOptions();
	DefaultAllVideoOptions();
	DefaultAllControlOptions();
}
void DefaultAllSoundOptions
()
{
	DefaultSoundLevel();
	DefaultMusicLevel();
	DefaultEffectsLevel();
}
void DefaultSoundLevel
()
{
	SoundLevel = DEFAULT_SOUND_LEVEL;
}
void DefaultMusicLevel
()
{
	MusicLevel = DEFAULT_MUSIC_LEVEL;
}
void DefaultEffectsLevel
()
{
	SoundEffectsLevel = DEFAULT_SOUND_EFFECTS_LEVEL;
}
void DefaultAllVideoOptions
()
{
	DefaultBrightness();
	DefaultFieldOfView();
}
void DefaultBrightness
()
{
	Brightness = DEFAULT_BRIGHTNESS;
}
void DefaultFieldOfView
()
{
	FieldOfView = DEFAULT_FIELD_OF_VIEW;
}
void DefaultAllControlOptions
()
{
	DefaultMouseSensitivity();
}
void DefaultMouseSensitivity
()
{
	MouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
}
