
#include "dataTypes.h"
#include "dyn_actor.h"

#include <stdlib.h>
#include <stdio.h>
#include "math/normal.h"
#include "DynActorComponents/physics.h"
#include "DynActorComponents/audio.h"
/*
void genDyn_Actor
(Dyn_Actor_t **actor)
{
	*actor = malloc(sizeof(Dyn_Actor_t));
	Dyn_Actor_t *_actor = *actor;
	AssignDyn_ActorID(_actor);
	genPhysics(&(_actor->physics));
	genNormal3(&(_actor->direction));
	_actor->Update = UselessUpdate;
	_actor->Health = HEALTH_MAX;
	_actor->ActorName = UNDEFINED_ACTOR_NAME;
}
void freeDyn_Actor
(Dyn_Actor_t **actor)
{
	Dyn_Actor_t *_actor = *actor;
	if (_actor->physics)
		freePhysics(&(_actor->physics));
	free(*actor);
	*actor = NULL;
}
void AssignDyn_ActorID
(Dyn_Actor_t *actor)
{
	actor->ActorID = ActorID;
	ActorID++;
}
U64 getDyn_ActorID
(Dyn_Actor_t *actor)
{
	return actor->ActorID;
}
void Update
(Dyn_Actor_t *actor, U64 deltaMS)
{
	UpdatePhysics(actor->physics, deltaMS);
	actor->Update(actor, deltaMS);
	DrawBoundingBox(actor->physics);
}
void UselessUpdate(Dyn_Actor_t *actor, U64 deltaMS){}
F64 getPosX
(Dyn_Actor_t *actor)
{
	return *getVecX(actor->physics->Pos);
}
F64 getPosY
(Dyn_Actor_t *actor)
{
	return *getVecY(actor->physics->Pos);
}
F64 getPosZ
(Dyn_Actor_t *actor)
{
	return *getVecZ(actor->physics->Pos);
}
F64 getHeight
(Dyn_Actor_t *actor)
{
	return actor->physics->Height;
}
F64 getWidth
(Dyn_Actor_t *actor)
{
	return actor->physics->Width;
}
F64 getLength
(Dyn_Actor_t *actor)
{
	return actor->physics->Length;
}

void Move
(Dyn_Actor_t *actor, F64 x, F64 y)
{
	*getVecX(actor->physics->Pos) += x;
	*getVecY(actor->physics->Pos) += y;
}
void setPos
(Dyn_Actor_t *actor, F64 x, F64 y)
{
	*getVecX(actor->physics->Pos) = x;
	*getVecY(actor->physics->Pos) = y;
}
*/

