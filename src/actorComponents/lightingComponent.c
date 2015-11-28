
#include "../dataTypes.h"
#include "lightingComponent.h"
#include <stdio.h>
#include "lighting/color.h"
#include "../actors.h"

void genLightingComponent
()
{
	AmbiantLight.Red = 128;
	AmbiantLight.Green = 128;
	AmbiantLight.Blue = 128;
	AmbiantLight.Alpha = 128;
	
	U8 lightID = 0;
	while (lightID < MAX_LIGHT_COUNT)
	{
		bindLight(lightID);
		Actors.lighting[getActor()].originatingPoint[getLight()] = 0;
		genColor(&(Actors.lighting[getActor()].intensity[getLight()]));
		Actors.lighting[getActor()].ActiveLights[getLight()] = 0;
		lightID++;
	}
}
void freeLightingComponent
()
{
}
void updateLightingComponent
(U32 deltaMS)
{
}
void bindFirstInactiveLight
()
{
	U8 lightID = 0;
	while (lightID < MAX_LIGHT_COUNT)
	{
		bindLight(lightID);
		if (Actors.lighting[getActor()].ActiveLights[getLight()] == 0)
			return;
		lightID++;
	}
	printf("ERROR::getFirstInactiveLight(void) called after ActiveLights array was filled::\
			First Inactive Light: %d::MAX_LIGHT_COUNT: %d\n", getLight(), MAX_LIGHT_COUNT);
	bindLight(lightID);
}
void addLight
(Vertex_t * origin)
{
	bindFirstInactiveLight();
	Actors.lighting[getActor()].originatingPoint[getLight()] = origin;
	Actors.lighting[getActor()].ActiveLights[getLight()] = 1;
}
