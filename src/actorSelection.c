
#include "actorSelection.h"

#include <stdio.h>
#include "camera.h"
#include "actors.h"
#include "globalTimeline.h"
#include "actorComponents/lightingComponent.h"


void bindActor(unsigned char actor)
{
	if(actor >= numActors || actor < 0)
		printf("Invalid ActorID bound.\n ActorID = %i.\n", actor);
	currentActor = actor;
}
unsigned char getActor(void)
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
void bindGlobalTimeline(globalTimeline *timeLine)
{
	globalTime = timeLine;
}
globalTimeline *getGlobalTimeline(void)
{
	return globalTime;
}
