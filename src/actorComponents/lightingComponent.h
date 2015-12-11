#ifndef _LIGHTING_
#define _LIGHTING_

typedef struct _Vertex_t Vertex_t;
#include "lighting/color.h"

#include "../actorSelection.h"

typedef struct _LightingComponent {
	Color_t intensity[MAX_LIGHT_COUNT];
	Vertex_t * originatingPoint[MAX_LIGHT_COUNT];
	unsigned char ActiveLights[MAX_LIGHT_COUNT];
} LightingComponent;

Color_t AmbiantLight;

void genLightingComponent(void);
void freeLightingComponent(void);
void updateLightingComponent(unsigned short);
void getFirstInactiveLight();
void addLight(Vertex_t *);

#endif /* _LIGHTING_ */
