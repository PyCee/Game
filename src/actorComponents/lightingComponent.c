
#include "lightingComponent.h"
#include <stdio.h>
#include "lighting/color.h"
#include "../actors.h"

void genLightingComponent() {
	AmbiantLight.Red = 128;
	AmbiantLight.Green = 128;
	AmbiantLight.Blue = 128;
	AmbiantLight.Alpha = 128;

	unsigned char lightID = 0;
	while (lightID < MAX_LIGHT_COUNT) {
		bindLight(lightID);
		lighting[getActor()].originatingPoint[getLight()] = 0;
		genColor(&(lighting[getActor()].intensity[getLight()]));
		lighting[getActor()].ActiveLights[getLight()] = 0;
		lightID++;
	}
}
void freeLightingComponent() {
}
void updateLightingComponent(unsigned short deltaMS) {
}
void bindFirstInactiveLight() {
	unsigned char lightID = 0;
	while (lightID < MAX_LIGHT_COUNT) {
		bindLight(lightID);
		if (lighting[getActor()].ActiveLights[getLight()] == 0)
			return;
		lightID++;
	}
	printf(
			"ERROR::getFirstInactiveLight(void) called after ActiveLights array was filled::\
			First Inactive Light: %d::MAX_LIGHT_COUNT: %d\n",
			getLight(), MAX_LIGHT_COUNT);
	bindLight(lightID);
}
void addLight(Vertex_t * origin) {
	bindFirstInactiveLight();
	lighting[getActor()].originatingPoint[getLight()] = origin;
	lighting[getActor()].ActiveLights[getLight()] = 1;
}
