#ifndef _LIGHTING_
#define _LIGHTING_

#include "lighting/color.h"
#include "../actorSelection.h"

#define LIGHTING lighting[getActor()]
#define LIGHT_ORIGIN LIGHTING->originatingPoint
#define LIGHT_INTENSITY LIGHTING->intensity
#define NUM_LIGHTS LIGHTING->num_lights

typedef struct LightingComponent {
	struct vertex **originatingPoint;
	color *intensity;
	unsigned char num_lights;
} LightingComponent;

color AmbiantLight;

void genLightingComponent(void);
void freeLightingComponent(void);
void updateLightingComponent(unsigned short);
unsigned char nextFreeLight(void);
unsigned char addLight(struct vertex *, color);

#endif /* _LIGHTING_ */
