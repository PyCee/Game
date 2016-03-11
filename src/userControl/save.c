
#include "save.h"

#include <stdio.h>

#include "../quest/quest.h"

void LoadSave(char *_saveFile)
{
	printf("Loading Save.\n");
	FILE *saveFile;
	if ((saveFile = fopen(_saveFile, "r")) == NULL)
	{
		// Chosen save file does not exist, creating new save.
		EmNewSave();
		SaveGame(_saveFile);
	}
	// read from file
	loadQuests(saveFile);
	fclose(saveFile);
	printf("Loaded Save.\n");
}
void SaveGame(char *_saveFile)
{
	printf("Saving Game.\n");
	FILE *saveFile;
	saveFile = fopen(_saveFile, "w");
	saveQuests(saveFile);
	// write all needed current data
	fclose(saveFile);
	printf("Saved Game.\n");
}
void EmNewSave()
{
	printf("Emulating New Save.\n");
	
	resetQuests();
	// write to new save
	printf("Emulated New Save.\n");
}
