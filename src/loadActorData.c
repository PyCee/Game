
#include "loadActorData.h"
#include "fileSupport/XML.h"
#include "fileSupport/loadFiles.h"
#include <stdlib.h>
#include <stdio.h>
#include "actors.h"
#include "actorSelection.h"

#include "actorComponents/AIComponent.h"
#include "protag.h"

static const unsigned char *lookupUpdateFunctionsStr[] = {
	"UselessUpdate",
	"UpdateProtag"
};
static void (*lookupUpdateFunctions[]) (unsigned short) = {
	UselessUpdate,
	UpdateProtag
};
void loadActorData(unsigned char *loc)
{
	//somevariables must be converted to floats/doubles instead of ints
	
	unsigned char *fileSource = readFile(loc);
	char *afterPtr;
	unsigned char *content;
	
	XMLElement data = readXMLElements(fileSource, "<name>");
	identifier[getActor()].name = data.children;
	printf("data.children: %s\n", data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<type>");
	identifier[getActor()].type = data.children;
	printf("data.children: %s\n", data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<mass>");
	physics[getActor()].mass = strtol(data.children, &afterPtr, 10);
	printf("data.children mass: %s\n", data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<speed>");
	physics[getActor()].speed = strtol(data.children, &afterPtr, 10);
	printf("data.children speed: %s\n", data.children);
	freeXMLElement(data);
	
	//get spawnpoint from world.xml file
	
	data = readXMLElements(fileSource, "<width>");
	float dataWidth = strtod(data.children, &afterPtr);
	printf("data.children width: %s\n", data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<height>");
	float dataHeight = strtod(data.children, &afterPtr);
	printf("data.children height: %s\n", data.children);
	freeXMLElement(data);
	printf("h: %f\n", dataHeight);
	printf("w: %f\n", dataWidth);
	
	setBounds(dataWidth, dataHeight);
	
	data = readXMLElements(fileSource, "<drawBounds>");
	collisions[getActor()].drawBounds = strtol(data.children, &afterPtr, 10);
	printf("data.children drawBounds: %s\n", data.children);
	freeXMLElement(data);
	printf("size: %zu\n", sizeof(lookupUpdateFunctionsStr));
	data = readXMLElements(fileSource, "<update>");
	
	unsigned char index;
	for(index = 0; index < (sizeof(lookupUpdateFunctionsStr) / 8); index++){
		if(!strcmp(data.children, lookupUpdateFunctionsStr[index])){
			assignAIUpdate(lookupUpdateFunctions[index]);
			break;	
		} else if(index == ((sizeof(lookupUpdateFunctionsStr) / 8) - 1))
			printf("\'%s\' is not a valid update function.\n", data.children);
	}
	printf("data.children update: %s\n", data.children);
	freeXMLElement(data);
	
	data = readXMLElements(fileSource, "<mesh>");
	loadModelFromFile(data.children);
	printf("data.children mesh: %s\n %i\n", data.children, model[getActor()].numMeshes);
	for(index = 0; index < model[getActor()].numMeshes; index++)
		setupMesh(&(model[getActor()].meshes[index]));
	
	freeXMLElement(data);
}
