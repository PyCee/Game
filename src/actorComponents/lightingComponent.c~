
#include "../dataTypes.h"
#include "lightingComponent.h"
#include <stdio.h>
#include "lighting/color.h"
#include "../actors.h"

void genLightingComponent
(U8 actorID)
{
	AmbiantLight.Red = 128;
	AmbiantLight.Green = 128;
	AmbiantLight.Blue = 128;
	AmbiantLight.Alpha = 128;
	
	U8 lightID = 0;
	while (lightID < MAX_LIGHT_COUNT)
	{
		Actors.lighting[actorID].originatingPoint[lightID] = 0;
		genColor(&(Actors.lighting[actorID].intensity[lightID]));
		Actors.lighting[actorID].ActiveLights[lightID] = 0;
		lightID++;
	}
}
void freeLightingComponent
(U8 actorID)
{
}
void updateLightingComponent
(U8 actorID, U32 deltaMS)
{
}
U8 getFirstInactiveLight
(U8 actorID)
{
	U8 lightID = 0;
	while (lightID < MAX_LIGHT_COUNT)
	{
		if (Actors.lighting[actorID].ActiveLights[lightID] == 0)
			return lightID;
		lightID++;
	}
	printf("ERROR::getFirstInactiveLight(void) called after ActiveLights array was filled::\
			First Inactive Light: %d::MAX_LIGHT_COUNT: %d\n", lightID, MAX_LIGHT_COUNT);
	return lightID;
}
U8 addLight
(U8 actorID, Vertex_t * origin)
{
	U8 lightID = getFirstInactiveLight(actorID);
	Actors.lighting[actorID].originatingPoint[lightID] = origin;
	Actors.lighting[actorID].ActiveLights[lightID] = 1;
	
	return lightID;
}
