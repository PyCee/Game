#ifndef _LIGHTING_
#define _LIGHTING_

typedef struct _Vertex_t Vertex_t;
#include "lighting/color.h"

#include "../actorSelection.h"

typedef struct _LightingComponent_t {
	Color_t intensity[MAX_LIGHT_COUNT];
	Vertex_t * originatingPoint[MAX_LIGHT_COUNT];
	U8 ActiveLights[MAX_LIGHT_COUNT];
} LightingComponent_t;

Color_t AmbiantLight;

void genLightingComponent(void);
void freeLightingComponent(void);
void updateLightingComponent(U32);
void getFirstInactiveLight();
void addLight(Vertex_t *);

#endif /* _LIGHTING_ */
