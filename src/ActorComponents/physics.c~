
#include "physics.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../math/vector.h"
#include "../math/matrix.h"

void genPhysics(Physics_t **physics)
{
	*physics = malloc(sizeof(Physics_t));
	Physics_t *_physics = *physics;
	genVec3(&(_physics->Pos));
	genVec3(&(_physics->Vel));
	genVec3(&(_physics->Acc));
	genVec3(&(_physics->Jrk));
	_physics->Height = 0;
	_physics->Width = 0;
	_physics->Length = 0;
}
void freePhysics(Physics_t **physics)
{
	Physics_t *_physics = *physics;
	freeVec3(&(_physics->Pos));
	_physics->Pos = 0;
	freeVec3(&(_physics->Vel));
	_physics->Vel = 0;
	freeVec3(&(_physics->Acc));
	_physics->Acc = 0;
	freeVec3(&(_physics->Jrk));
	_physics->Jrk = 0;
}

void UpdatePhysics
(Physics_t *physics, uint64_t deltaMS)
{
	if (physics->Terrain == 0){
		Vec3_t *jrk = physics->Jrk;
		Vec3_t *acc = physics->Acc;
		Vec3_t *vel = physics->Vel;
		Vec3_t *pos = physics->Pos;
		acc->X += deltaMS * (jrk->X * 1);
		acc->Y += deltaMS * (jrk->Y * 1);
		acc->Z += deltaMS * (jrk->Z * 1);
		vel->X += deltaMS * (acc->X * 1);
		vel->Y += deltaMS * ((acc->Y * 1) - ACC_GRAVITY);
		vel->Z += deltaMS * (acc->Z * 1);
		pos->X += deltaMS * vel->X * 1;
		pos->Y += deltaMS * vel->Y * 1;
		pos->Z += deltaMS * vel->Z * 1;
	}
}
unsigned char CheckBoundingBoxCollision
(Physics_t *physicsOne, Physics_t *physicsTwo)
{
	if (physicsOne->Pos->X < physicsTwo->Pos->X + physicsTwo->Width &&
   physicsOne->Pos->X + physicsOne->Width > physicsTwo->Pos->X &&
   physicsOne->Pos->Y < physicsTwo->Pos->Y + physicsTwo->Height &&
   physicsOne->Pos->Y + physicsOne->Height > physicsTwo->Pos->Y/* &&
   physicsOne->Pos->Z < physicsTwo->Pos->Z + physicsTwo->Length &&
   physicsOne->Pos->Z + physicsOne->Length > physicsTwo->Pos->Z */)
    // collision detected!
  	return 1;
	return 0;
}
