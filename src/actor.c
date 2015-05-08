
#include "actor.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "ActorComponents/physics.h"

void genActor
(Actor_t **actor)
{
	*actor = malloc(sizeof(Actor_t));
	Actor_t *_actor = *actor;
	AssignActorID(_actor);
	genPhysics(&(_actor->physics));
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
unsigned long getActorID
(Actor_t *actor)
{
	return actor->ActorID;
}
void Update
(Actor_t *actor, uint64_t deltaMS)
{
	UpdatePhysics(actor->physics, deltaMS);
	actor->Update(actor, deltaMS);
}
void UselessUpdate(Actor_t *actor, uint64_t deltaMS){}

void Move
(Actor_t *actor, double x, double y)
{
	actor->physics->Pos->X += x;
	actor->physics->Pos->Y += y;
}
void setPos
(Actor_t *actor, double x, double y)
{
	actor->physics->Pos->X = x;
	actor->physics->Pos->Y = y;
}


