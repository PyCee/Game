
#include "directionComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../math/gMath.h"
#include "../math/angles.h"
#include "direction/normal.h"
#include "../math/quaternion.h"

void genDirectionComponent() {
	direction[getActor()].forward = genNormal();

	i = genVec3(1.0, 0.0, 0.0);
	j = genVec3(0.0, 1.0, 0.0);
	k = genVec3(0.0, 0.0, 1.0);
}
void freeDirectionComponent() {
	// Don't free forward since it was not dynamically allocated
}
void updateDirectionComponent(unsigned short deltaMS) {
	direction[getActor()].forward = NormalizeNormal(
			direction[getActor()].forward);
	//printVec3(direction[getActor()].forward);
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
