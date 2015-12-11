
#include "actorSelection.h"

#include <stdio.h>
#include "camera.h"
#include "actors.h"
#include "globalTimeLine.h"


void bindActor(unsigned char actor)
{
	if(actor >= MAX_ACTOR_COUNT || actor < 0)
		printf("Invalid ActorID bound.\n ActorID = %i.\n", actor);
	currentActor = actor;
}
unsigned char getActor(void)
{
	return currentActor;
}
void bindLight(unsigned char light)
{
	if(light >= MAX_LIGHT_COUNT || light < 0)
		printf("Invalid LightID bound.\n LightID = %i.\n", light);
	currentLight = light;
}
unsigned char getLight(void)
{
	return currentLight;
}
void bindCameraView(unsigned char camera)
{
	cameraView = camera;
}
unsigned char getCameraView(void)
{
	return cameraView;
}
void bindControlledActor(unsigned char protag)
{
	controlledActor = protag;
}
unsigned char getControlledActor(void)
{
	return controlledActor;
}
void bindMapTerrain(unsigned char terrain)
{
	mapTerrain = terrain;
}
unsigned char getMapTerrain(void)
{
	return mapTerrain;
}
void bindGlobalTimeLine(globalTimeLine_t *timeLine)
{
	globalTimeLine = timeLine;
}
globalTimeLine_t *getGlobalTimeLine(void)
{
	return globalTimeLine;
}
