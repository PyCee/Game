#ifndef _DIRECTION_COMPONENT_
#define _DIRECTION_COMPONENT_

#include "physics/vector.h"
#include "direction/normal.h"

typedef struct _DirectionComponent {
	Normal_t forward;
} DirectionComponent;

vec3 i;
vec3 j;
vec3 k;

void genDirectionComponent();
void freeDirectionComponent();
void updateDirectionComponent(unsigned short);

void DirectionPitch(float);
void DirectionYaw(float);
void DirectionRoll(float);
#endif /* _DIRECTION_COMPONENT_ */
