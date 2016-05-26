#include "updatePosition.h"

#include "../../actors.h"
#include "../physicsComponent.h"
#include "physicsAttributeController.h"
#include "vector.h"
#include "../../math/quaternion.h"
#include <stdio.h>

void updatePosition(unsigned short deltaMS)
{
	double deltaS = (double)deltaMS / 1000.0;
	unsigned char index;
	vec3 change;
	for(index = 0; index < JRK_ATTRIBUTES; index++){
		if(JRK->active[index]){
			change = applyRotationQuaternion(*(JRK->attribute[index]), *(JRK->adjustment[index]));
			*ACCELERATION = addVec3Vec3(*ACCELERATION, scaleVec3(change, JRK->multiplier[index] * deltaS));
		}
	}
	for(index = 0; index < ACC_ATTRIBUTES; index++){
		if(ACC->active[index]){
			change = applyRotationQuaternion(*(ACC->attribute[index]), *(ACC->adjustment[index]));
			*VELOCITY = addVec3Vec3(*VELOCITY, scaleVec3(change, ACC->multiplier[index] * deltaS));
		}
	}
	*PREVIOUSPOSITION = *POSITION;
	for(index = 0; index < VEL_ATTRIBUTES; index++){
		if(VEL->active[index]){
			change = applyRotationQuaternion(*(VEL->attribute[index]), *(VEL->adjustment[index]));
			*POSITION = addVec3Vec3(*POSITION, scaleVec3(change, VEL->multiplier[index] * deltaS));
		}
	}
}
