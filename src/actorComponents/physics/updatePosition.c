#include "updatePosition.h"

#include "../../actors.h"
#include "../physicsComponent.h"
#include "physicsAttributeController.h"
#include "vector.h"
#include "../../math/quaternion.h"

void updatePosition(unsigned short deltaMS)
{
	unsigned char index;
	for(index = 0; index < JRK_ATTRIBUTES; index++){
		if(JRK->active[index])
			*ACCELERATION = addVec3Vec3(*ACCELERATION, scaleVec3(applyRotationQuaternion(*(JRK->attribute[index]), *(JRK->adjustment[index])), JRK->multiplier[index] * deltaMS));
	}
	for(index = 0; index < ACC_ATTRIBUTES; index++){
		if(ACC->active[index]){
			*VELOCITY = addVec3Vec3(*VELOCITY, scaleVec3(applyRotationQuaternion(*(ACC->attribute[index]), *(ACC->adjustment[index])), ACC->multiplier[index] * deltaMS));
		}
	}
	*PREVIOUSPOSITION = *POSITION;
	for(index = 0; index < VEL_ATTRIBUTES; index++){
		if(VEL->active[index]){
			*POSITION = addVec3Vec3(*POSITION, scaleVec3(applyRotationQuaternion(*(VEL->attribute[index]), *(VEL->adjustment[index])), VEL->multiplier[index] * deltaMS));
		}
	}
}
