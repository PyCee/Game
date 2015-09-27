
#include "../dataTypes.h"
#include "directionComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../math/gMath.h"
#include "../math/angles.h"
#include "direction/normal.h"
#include "../math/quaternion.h"

void genDirectionComponent
(U8 actorID)
{
	Actors.direction[actorID].forward = genNormal();
	
	i = genVec3(1.0, 0.0, 0.0);
	j = genVec3(0.0, 1.0, 0.0);
	k = genVec3(0.0, 0.0, 1.0);
}
void	freeDirectionComponent
(U8 actorID)
{
	// Don't free forward since it was not dynamically allocated
}
void	updateDirectionComponent	(U8 actorID, U16 deltaMS)
{
	Actors.direction[actorID].forward = NormalizeNormal(Actors.direction[actorID].forward);
	//PrintVec3(Actors.direction[actorID].forward);
}
void DirectionPitch
(U8 actorID, F32 angle)
{
	Actors.direction[actorID].forward = rotateVec3(Actors.direction[actorID].forward, i, angle);
}
void DirectionYaw
(U8 actorID, F32 angle)
{
	Actors.direction[actorID].forward = rotateVec3(Actors.direction[actorID].forward, j, angle);
}
void DirectionRoll
(U8 actorID, F32 angle)
{
	Actors.direction[actorID].forward = rotateVec3(Actors.direction[actorID].forward, k, angle);
}
