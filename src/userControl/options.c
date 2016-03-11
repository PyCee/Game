
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
		MasterLevel = strtol(data.children, &afterPtr, 10);
		printf("MasterSoundLevel: %hhu\n", MasterLevel);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<music_level>");
		MusicLevel = strtol(data.children, &afterPtr, 10);
		printf("MusicLevel: %hhu\n", MusicLevel);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<sound_effects_level>");
		SoundEffectsLevel = strtol(data.children, &afterPtr, 10);
		printf("SoundEffectsLevel: %hhu\n", SoundEffectsLevel);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<field_of_view>");
		FieldOfView = strtol(data.children, &afterPtr, 10);
		printf("FieldOfView: %hhu\n", FieldOfView);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<brightness>");
		Brightness = strtol(data.children, &afterPtr, 10);
		printf("Brightness: %hhu\n", Brightness);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<mouse_sensitivity>");
		MouseSensitivity = strtol(data.children, &afterPtr, 10);
		printf("MouseSensitivity: %hhu\n", MouseSensitivity);
		freeXMLElement(data);
		
		data = readXMLElements(fileSource, "<lock_mouse_to_window>");
		MouseLock = strtol(data.children, &afterPtr, 10);
		printf("MouseLock: %hhu\n", MouseLock);
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
