
#include "physics.h"
#include "actor.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void genActor
(Actor_t **actor)
{
	printf("genactor.\n");
	*actor = malloc(sizeof(Actor_t));
	Actor_t *_actor = *actor;
	_actor->Update = UselessUpdate;
	genPhysics(&(_actor->physics));
}
void freeActor
(Actor_t **actor)
{
	Actor_t *_actor = *actor;
	freePhysics(&(_actor->physics));
	_actor->physics = 0;
	free(*actor);
	*actor = 0;
}

void Update
(Actor_t *actor, uint64_t deltaMS)
{
	UpdatePhysics(actor->physics, deltaMS);
	actor->Update(actor, deltaMS);
}

void UselessUpdate(Actor_t *actor, uint64_t deltaMS){}

void setBounds
(Actor_t *actor, double width, double height)
{
	actor->physics->Width = width;
	actor->physics->Height = height;
}
char CheckBoundingBoxCollision
(Actor_t *actorOne, Actor_t *actorTwo)
{
	if (actorOne->physics->Pos->X < actorTwo->physics->Pos->X + actorTwo->physics->Width &&
   actorOne->physics->Pos->X + actorOne->physics->Width > actorTwo->physics->Pos->X &&
   actorOne->physics->Pos->Y < actorTwo->physics->Pos->Y + actorTwo->physics->Height &&
   actorOne->physics->Pos->Y + actorOne->physics->Height > actorTwo->physics->Pos->Y/* &&
   actorOne->physics->Pos->Z < actorTwo->physics->Pos->Z + actorTwo->physics->Length &&
   actorOne->physics->Pos->Z + actorOne->physics->Length > actorTwo->physics->Pos->Z */)
    // collision detected!
  	return 1;
	return 0;
}

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


