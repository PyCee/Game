
#ifndef _ACTOR_
#define _ACTOR_

#include <stdint.h>

#define HEALTH_MAX 100
#define HEALTH_MIN 0

static unsigned long actorID = 0;

//typedef struct _Physics_t Physics_t;
#include "ActorComponents/physics.h"
typedef struct _Actor_t
{
	void (*Update)(struct _Actor_t *, uint64_t);
	unsigned char Control;
	unsigned long ActorID;
	char Health;
	Physics_t *physics;
} Actor_t;

void genActor(Actor_t **);
void freeActor(Actor_t **);

void AssignActorID(Actor_t *);
unsigned long getActorID(Actor_t *);
void setBounds(Actor_t *, double, double);
void Update(Actor_t *, uint64_t);

void UselessUpdate(Actor_t *, uint64_t);

void Move(Actor_t *, double, double);
void setPos(Actor_t *, double, double);

#endif
