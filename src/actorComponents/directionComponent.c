
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
	genNormal(&(Actors.direction[actorID].forward));
	setVectorX(&(Actors.direction[actorID].forward), 0);
	setVectorY(&(Actors.direction[actorID].forward), 0);
	setVectorZ(&(Actors.direction[actorID].forward), 1);
}
void	freeDirectionComponent
(U8 actorID)
{
	// Don't free forward since it was not dynamically allocated
}
void	updateDirectionComponent	(U8 actorID, U16 deltaMS)
{
	NormalizeNormal(&(Actors.direction[actorID].forward));
	PrintVector(Actors.direction[actorID].forward);
}
void DirectionPitch
(U8 actorID, F32 angle)
{
	rotateVector(&(Actors.direction[actorID].forward), i, angle);
}
void DirectionYaw
(U8 actorID, F32 angle)
{
	rotateVector(&(Actors.direction[actorID].forward), j, angle);
}
void DirectionRoll
(U8 actorID, F32 angle)
{
	rotateVector(&(Actors.direction[actorID].forward), k, angle);
}
