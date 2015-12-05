#include "dataTypes.h"
#include "loadActorData.h"
#include "loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include "actors.h"
#include "actorSelection.h"

void loadActorData(U8 *loc)
{
	U8 *fileSource = readFile(loc);
	I8 *afterPtr;
	
	U8 *content = readXMLElements(fileSource, "<actorName>");
	Actors.identifier[getActor()].actorName = (U8 *)strtol(content, &afterPtr, 10);
	printf("actor Name: %s\n", Actors.identifier[getActor()].actorName);
}
