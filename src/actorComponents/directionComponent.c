
#include "directionComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../math/gMath.h"
#include "../math/angles.h"
#include "physics/vector.h"
#include "../math/quaternion.h"
#include <math.h>

void genDirectionComponent() {
	FORWARD = genVec3(0, 0, 1);
	QUA = UnitQuaternion(genVec3(0, 0, 1), 0);

	i = genVec3(1.0, 0.0, 0.0);
	j = genVec3(0.0, 1.0, 0.0);
	k = genVec3(0.0, 0.0, 1.0);
}
void freeDirectionComponent() {
	// Don't free forward since it was not dynamically allocated
}
void updateDirectionComponent(unsigned short deltaMS) {
	//direction[getActor()].forward = normalizeVec3(direction[getActor()].forward);
	//printVec3(direction[getActor()].forward);
	float angle = (float) (acos(dotVec3(k, FORWARD)));
	angle *= 180 / M_PI;
	vec3 around = crossProduct(FORWARD, k);
	if( FORWARD.vec[2] == 1.0)
		around = k;
	around = normalizeVec3(around);
	QUA = UnitQuaternion(around, angle);
}
void DirectionPitch(float angle) {
	direction[getActor()].forward = rotateVec3(
			direction[getActor()].forward, i, angle);
}
void DirectionYaw(float angle) {
	direction[getActor()].forward = rotateVec3(
			direction[getActor()].forward, j, angle);
}
void DirectionRoll(float angle) {
	direction[getActor()].forward = rotateVec3(
			direction[getActor()].forward, k, angle);
}
