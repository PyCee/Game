
#include "lightingComponent.h"
#include <stdio.h>
#include <stdlib.h>
#include "lighting/color.h"
#include "model/vertex.h"
#include "../actors.h"

void genLightingComponent(void)
{
	AmbiantLight = genColor(128, 128, 128, 255);
	LIGHT_ORIGIN = 0;
	LIGHT_INTENSITY = 0;
}
void freeLightingComponent(void)
{
	if(LIGHT_ORIGIN)
		free(LIGHT_ORIGIN);
	LIGHT_ORIGIN = 0;
	if(LIGHT_INTENSITY)
		free(LIGHT_INTENSITY);
	NUM_LIGHTS = 0;
}
void updateLightingComponent(unsigned short deltaMS)
{
}
unsigned char nextFreeLight(void)
{
	unsigned char lightID = 0;
	while (lightID < NUM_LIGHTS) {
		bindLight(lightID);
		if (LIGHT_ORIGIN == 0)
			return lightID;
		lightID++;
	}
	return NUM_LIGHTS;
}
unsigned char addLight(vertex *origin, color col)
{
	unsigned char next;
	if(NUM_LIGHTS == 0){
		NUM_LIGHTS = 1;
		next = 0;
		LIGHT_ORIGIN = malloc(sizeof(vertex *));
		LIGHT_INTENSITY = malloc(sizeof(color));
	} else if(nextFreeLight() == NUM_LIGHTS){
		NUM_LIGHTS += 1;
		next = NUM_LIGHTS - 1;
		LIGHT_ORIGIN = realloc(LIGHT_ORIGIN, sizeof(vertex *) * NUM_LIGHTS);
		LIGHT_INTENSITY = realloc(LIGHT_INTENSITY, sizeof(color) * NUM_LIGHTS);
	}
	LIGHT_ORIGIN[next] = origin;
	LIGHT_INTENSITY[next] = col;
	return next;
}
