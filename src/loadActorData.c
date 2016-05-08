
#include "loadActorData.h"
#include "fileSupport/XML.h"
#include "fileSupport/loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include "actors.h"
#include <string.h>
#include "actorSelection.h"

#include "actorComponents/AIComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/modelComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/identifierComponent.h"

#include "protag.h"
#include "camera.h"

static const unsigned char *lookupUpdateFunctionsStr[] = {
	"UselessUpdate",
	"UpdateProtag",
	"UpdateCamera"
};
static void (*lookupUpdateFunctions[]) (unsigned short) = {
	UselessUpdate,
	UpdateProtag,
	UpdateCamera
};
void loadActorData(unsigned char *loc)
{
	unsigned char *fileSource = readFile(loc);
	char *afterPtr;
	
	ORIGIN_FILE = malloc(sizeof(loc));
	strcpy(ORIGIN_FILE, loc);
	
	printf("Loading from file: %s\n", ORIGIN_FILE);
	
	XMLElement data = readXMLElements(fileSource, "<name>");
	NAME = malloc(sizeof(data.children));
	strcpy(NAME, data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<type>");
	TYPE = malloc(sizeof(data.children));
	strcpy(TYPE, data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<mass>");
	MASS = strtol(data.children, &afterPtr, 10);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<speed>");
	SPEED = strtod(data.children, &afterPtr);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<speed_side>");
	SPEED_SIDE = strtod(data.children, &afterPtr);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<speed_back>");
	SPEED_BACK = strtod(data.children, &afterPtr);
	freeXMLElement(data);
	
	//get spawnpoint from world.xml file
	
	data = readXMLElements(fileSource, "<width>");
	float dataWidth = strtod(data.children, &afterPtr);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<height>");
	float dataHeight = strtod(data.children, &afterPtr);
	freeXMLElement(data);
	setBounds(dataWidth, dataHeight);
	
	data = readXMLElements(fileSource, "<drawBounds>");
	DRAW_BOUNDS = strtol(data.children, &afterPtr, 10);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<update>");
	unsigned char index;
	for(index = 0; index < (sizeof(lookupUpdateFunctionsStr) / 8); index++){
		if(!strcmp(data.children, lookupUpdateFunctionsStr[index])){
			assignAIUpdate(lookupUpdateFunctions[index]);
			break;	
		} else if(index == ((sizeof(lookupUpdateFunctionsStr) / 8) - 1))
			printf("\'%s\' is not a valid update function.\n", data.children);
	}
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<mesh>");
	loadModelFromFile(data.children);
	for(index = 0; index < NUM_MESHES; index++)
		setupMesh(&(MESHES[index]));
	freeXMLElement(data);
}
