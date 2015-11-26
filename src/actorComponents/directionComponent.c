
#include "../dataTypes.h"
#include "directionComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../math/gMath.h"
#include "../math/angles.h"
#include "direction/normal.h"
#include "../math/quaternion.h"

void genDirectionComponent
()
{
	Actors.direction[getActor()].forward = genNormal();
	
	i = genVec3(1.0, 0.0, 0.0);
	j = genVec3(0.0, 1.0, 0.0);
	k = genVec3(0.0, 0.0, 1.0);
}
void	freeDirectionComponent
()
{
	// Don't free forward since it was not dynamically allocated
}
void	updateDirectionComponent	(U16 deltaMS)
{
	Actors.direction[getActor()].forward = NormalizeNormal(Actors.direction[getActor()].forward);
	//printVec3(Actors.direction[getActor()].forward);
}
void DirectionPitch
(F32 angle)
{
	Actors.direction[getActor()].forward = rotateVec3(Actors.direction[getActor()].forward, i, angle);
}
void DirectionYaw
(F32 angle)
{
	Actors.direction[getActor()].forward = rotateVec3(Actors.direction[getActor()].forward, j, angle);
}
void DirectionRoll
(F32 angle)
{
	Actors.direction[getActor()].forward = rotateVec3(Actors.direction[getActor()].forward, k, angle);
}
