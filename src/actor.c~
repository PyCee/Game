
#include "dataTypes.h"
#include "actor.h"

#include <stdlib.h>
#include <stdio.h>
#include "math/normal.h"
#include "ActorComponents/physics.h"

void genActor
(Actor_t **actor)
{
	*actor = malloc(sizeof(Actor_t));
	Actor_t *_actor = *actor;
	AssignActorID(_actor);
	genPhysics(&(_actor->physics));
	genNormal3(&(_actor->direction));
	_actor->Update = UselessUpdate;
	_actor->Health = HEALTH_MAX;
}
void freeActor
(Actor_t **actor)
{
	Actor_t *_actor = *actor;
	freePhysics(&(_actor->physics));
	free(*actor);
	*actor = 0;
}
void AssignActorID
(Actor_t *actor)
{
	actor->ActorID = actorID;
	actorID++;
}
U64 getActorID
(Actor_t *actor)
{
	return actor->ActorID;
}
void Update
(Actor_t *actor, U64 deltaMS)
{
	UpdatePhysics(actor->physics, deltaMS);
	actor->Update(actor, deltaMS);
	DrawBoundingBox(actor->physics);
}
void UselessUpdate(Actor_t *actor, U64 deltaMS){}

void Move
(Actor_t *actor, F64 x, F64 y)
{
	actor->physics->Pos->X += x;
	actor->physics->Pos->Y += y;
}
void setPos
(Actor_t *actor, F64 x, F64 y)
{
	actor->physics->Pos->X = x;
	actor->physics->Pos->Y = y;
}


