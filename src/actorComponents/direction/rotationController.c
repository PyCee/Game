
#include "rotationController.h"

#include "../../actors.h"
#include <stdio.h>
#include "../../math/gMath.h"
#include "../../math/angles.h"
#include "../physics/vector.h"
#include "../physics/physicsAttributeController.h"
#include "../../math/quaternion.h"
#include "../../actors.h"
#include "../physicsComponent.h"
#include "../../math/pythag.h"
#include "../../math/angles.h"
#include <math.h>
#include <stdlib.h>
#include "../directionComponent.h"

rotationController getRotationToVec3(vec3 *pos)
{
	rotationController rot;
	vec3 difference = subtractVec3Vec3(*pos, *POSITION);
	difference = normalizeVec3(difference);
	if(difference.vec[0] == 0){
		rot.yaw = 0;
	} else{
		vec3 yawDifference = genVec3(difference.vec[0], 0.0, difference.vec[2]);
		yawDifference = normalizeVec3(yawDifference);
		rot.yaw = acos(dotProduct(yawDifference, nk));
		rot.yaw = RadiansToDegrees(rot.yaw);
		while(rot.yaw > 180)
			rot.yaw -= 360;
		if(POSITION->vec[0] < pos->vec[0])
			rot.yaw *= -1.0;
	}
	if(difference.vec[1] == 0){
		rot.pitch = 0;
	} else{
		vec3 pitchDifference = genVec3(difference.vec[0], 0.0, difference.vec[2]);
		pitchDifference = normalizeVec3(pitchDifference);
		
		vec3 cross = crossProduct(pitchDifference, difference);
		rot.pitch = asin(cross.vec[0] * cross.vec[0] + cross.vec[1] * cross.vec[1] + cross.vec[2] * cross.vec[2]);
		rot.pitch = RadiansToDegrees(rot.pitch);
		while(rot.pitch > 90)
			rot.pitch -= 90;
		while(rot.pitch < -1.0 * 90)
			rot.pitch += 90;
		if(POSITION->vec[1] > pos->vec[1])
			rot.pitch *= -1.0;
	}
	rot.roll = 0;
	return rot;
}
