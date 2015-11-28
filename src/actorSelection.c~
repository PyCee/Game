
#include "dataTypes.h"
#include "actorSelection.h"

#include <stdio.h>

#include "camera.h"
#include "actors.h"
#include "globalTimeLine.h"


void bindActor(U8 actor)
{
	if(actor >= MAX_ACTOR_COUNT || actor < 0)
		printf("Invalid ActorID bound.\n ActorID = %i.\n", actor);
	currentActor = actor;
}
U8 getActor(void)
{
	return currentActor;
}
void bindLight(U8 light)
{
	if(light >= MAX_LIGHT_COUNT || light < 0)
		printf("Invalid LightID bound.\n LightID = %i.\n", light);
	currentLight = light;
}
U8 getLight(void)
{
	return currentLight;
}
void bindCameraView(U8 camera)
{
	cameraView = camera;
}
U8 getCameraView(void)
{
	return cameraView;
}
void bindControlledActor(U8 protag)
{
	controlledActor = protag;
}
U8 getControlledActor(void)
{
	return controlledActor;
}
void bindMapTerrain(U8 terrain)
{
	mapTerrain = terrain;
}
U8 getMapTerrain(void)
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
