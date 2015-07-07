
#include "../dataTypes.h"
#include "directionComponent.h"

#include "../dyn_actors.h"

#include "../math/gMath.h"
#include "../math/normal.h"
#include "../math/matrix.h"

void genDirectionComponent
(U8 actorID)
{
	genNormal3(&(Dyn_Actors.direction[actorID].forward));
}
void freeDirectionComponent
(U8 actorID)
{
	// Don't free forward since it was not dynamically allocated
}
void DirectionPitch
(U8 actorID, F64 angle)
{//TODO: make copyMatrix(Matrix_t *copyTo, Matrix_t copy)
	copyMatrix(&(Dyn_Actors.direction[actorID].forward), Pitch(Dyn_Actors.direction[actorID].forward, degRad(angle)));
	NormalizeNormal3(&(Dyn_Actors.direction[actorID].forward));
}
void DirectionYaw
(U8 actorID, F64 angle)
{
	copyMatrix(&(Dyn_Actors.direction[actorID].forward), Yaw(Dyn_Actors.direction[actorID].forward, degRad(angle)));
	NormalizeNormal3(&(Dyn_Actors.direction[actorID].forward));
}
void DirectionRoll
(U8 actorID, F64 angle)
{
	copyMatrix(&(Dyn_Actors.direction[actorID].forward), Roll(Dyn_Actors.direction[actorID].forward, degRad(angle)));
	NormalizeNormal3(&(Dyn_Actors.direction[actorID].forward));
}
