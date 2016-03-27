
#include "options.h"
#include <stdio.h>
#include "../fileSupport/loadFiles.h"
#include "../fileSupport/XML.h"
#include <stdlib.h>

void loadOptions(unsigned char *configLoc)
{
	// load options from file
	printf("Initing Options.\n");
	FILE *configFile;
	if ((configFile = fopen(CONFIG_PATH, "r")) == NULL) {
		if ((configFile = fopen(CONFIG_PATH, "a+")) == NULL)
			printf("ERROR::CONFIG::LOCATION::FILE_NOT_CREATED\n");
		else {
			fclose(configFile);
			DefaultOptions();
			SaveOptions();
		}
	} else {
		unsigned char *fileSource = readFile(configLoc);
		
		char *afterPtr;
		XMLElement data = readXMLElements(fileSource, "<master_level>");
		Option[MASTER_SOUND_LEVEL] = strtol(data.children, &afterPtr, 10);
		printf("MasterSoundLevel: %hhu\n", Option[MASTER_SOUND_LEVEL]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<music_level>");
		Option[MUSIC_LEVEL] = strtol(data.children, &afterPtr, 10);
		printf("MusicLevel: %hhu\n", Option[MUSIC_LEVEL]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<sound_effects_level>");
		Option[SOUND_EFFECTS_LEVEL] = strtol(data.children, &afterPtr, 10);
		printf("SoundEffectsLevel: %hhu\n", Option[SOUND_EFFECTS_LEVEL]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<field_of_view>");
		Option[FIELD_OF_VIEW] = strtol(data.children, &afterPtr, 10);
		printf("FieldOfView: %hhu\n", Option[FIELD_OF_VIEW]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<brightness>");
		Option[BRIGHTNESS] = strtol(data.children, &afterPtr, 10);
		printf("Brightness: %hhu\n", Option[BRIGHTNESS]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<aspect_ratio_y>");
		Option[ASPECT_RATIO_Y] = strtol(data.children, &afterPtr, 10);
		printf("aspect ratio: %hhu\n", Option[ASPECT_RATIO_Y]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<aspect_ratio_x>");
		Option[ASPECT_RATIO_X] = strtol(data.children, &afterPtr, 10);
		printf("aspect ratio: %hhu\n", Option[ASPECT_RATIO_X]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<mouse_sensitivity>");
		Option[MOUSE_SENSITIVITY] = strtol(data.children, &afterPtr, 10);
		printf("MouseSensitivity: %hhu\n", Option[MOUSE_SENSITIVITY]);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<lock_mouse_to_window>");
		Option[MOUSE_LOCK] = strtol(data.children, &afterPtr, 10);
		printf("MouseLock: %hhu\n", Option[MOUSE_LOCK]);
		freeXMLElement(data);
		
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
		return;
	}
	unsigned char *configSource = readFile(DEFAULT_CONFIG_PATH);
}
void DefaultOptions(void)
{
	loadOptions(DEFAULT_CONFIG_PATH);
}
