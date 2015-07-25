
#ifndef _LIGHTING_
#define _LIGHTING_

typedef struct _Vertex_t Vertex_t;
#include "lighting/color.h"

#include "../actorCounts.h"

typedef struct _LightingComponent_t{
	Color_t					intensity						[MAX_LIGHT_COUNT];
	Vertex_t		*		originatingPoint		[MAX_LIGHT_COUNT];
	U8							ActiveLights				[MAX_LIGHT_COUNT];
} LightingComponent_t;

Color_t AmbiantLight;

void		genLightingComponent			(U8);
void		freeLightingComponent			(U8);
void		updateLightingComponent		(U8, U32);
U8			getFirstInactiveLight			(U8);
U8			addLight									(U8, Vertex_t *);

#endif /* _LIGHTING_ */
