
#include "actorSelection.h"

#include <stdio.h>
#include "actors/camera.h"
#include "actors.h"
#include "actorList.h"
#include "globalTimeline.h"
#include "actorComponents/lightingComponent.h"


void bindActor(unsigned int actor)
{
	if(actor >= actors.numActors || actor < 0)
		printf("Invalid ActorID bound.\n ActorID = %i.\n", actor);
	currentActor = actor;
}
unsigned int getActor(void)
{
	return currentActor;
}
void bindLight(unsigned char light)
{
	if(light >= NUM_LIGHTS || light < 0)
		printf("Invalid LightID bound.\n LightID = %i.\n", light);
	currentLight = light;
}
unsigned char getLight(void)
{
	return currentLight;
}
void bindCameraView(unsigned int camera)
{
	cameraView = camera;
}
unsigned int getCameraView(void)
{
	return cameraView;
}
void bindControlledActor(unsigned int protag)
{
	controlledActor = protag;
}
unsigned int getControlledActor(void)
{
	return controlledActor;
}
void bindMapTerrain(unsigned int terrain)
{
	mapTerrain = terrain;
}
unsigned int getMapTerrain(void)
{
	return mapTerrain;
}
void bindGlobalTimeline(globalTimeline *timeLine)
{
	globalTime = timeLine;
}
globalTimeline *getGlobalTimeline(void)
{
	return globalTime;
}
