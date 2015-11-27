
#ifndef _DIRECTION_COMPONENT_
#define _DIRECTION_COMPONENT_

#include "physics/vector.h"
#include "direction/normal.h"

typedef struct _DirectionComponent_t{
	Normal_t forward;
} DirectionComponent_t;

vec3 i;
vec3 j;
vec3 k;

void		genDirectionComponent				();
void		freeDirectionComponent			();
void		updateDirectionComponent		(U16);

void		DirectionPitch							(F32);
void		DirectionYaw								(F32);
void		DirectionRoll								(F32);
#endif /* _DIRECTION_COMPONENT_ */
