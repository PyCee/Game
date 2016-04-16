#ifndef _DIRECTION_COMPONENT_
#define _DIRECTION_COMPONENT_

#include "physics/vector.h"

#define FORWARD direction[getActor()].forward
#define QUA direction[getActor()].qua

typedef struct DirectionComponent {
	vec3 forward;
	vec4 qua;
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
