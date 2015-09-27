
#include "save.h"

#include <stdio.h>

void LoadSave
(char *_saveFile)
{
	printf("Loading Save.\n");
	FILE *saveFile;
	if ((saveFile = fopen(_saveFile, "r")) == NULL)
	{
		NewSave(_saveFile);
		saveFile = fopen(_saveFile, "r");
	}
	// read from file
	fclose(saveFile);
	printf("Loaded Save.\n");
}
void SaveGame
(char *_saveFile)
{
	printf("Saving Game.\n");
	FILE *saveFile;
	saveFile = fopen(_saveFile, "w");
	// write all needed current data
	fclose(saveFile);
	printf("Saved Game.\n");
}
void NewSave
(char *_saveFile)
{
	printf("Creating New Save.\n");
	FILE *saveFile = fopen(_saveFile, "w");
	// write to new save
	fclose(saveFile);
	printf("Created New Save.\n");
}
