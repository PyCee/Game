
#ifndef _ACTOR_
#define _ACTOR_

#define HEALTH_MAX 100
#define HEALTH_MIN 0

static U64 actorID = 0;

//typedef struct _Physics_t Physics_t;
#include "ActorComponents/physics.h"
typedef struct _Matrix_t Normal_t;

typedef struct _Actor_t
{
	void (*Update)(struct _Actor_t *, U64);
	U64 ActorID;
	I8 Health;
	U8 Control;
	Physics_t *physics;
	Normal_t *direction;
} Actor_t;

void genActor(Actor_t **);
void freeActor(Actor_t **);

void AssignActorID(Actor_t *);
U64 getActorID(Actor_t *);
void setBounds(Actor_t *, F64, F64);
void Update(Actor_t *, U64);

void UselessUpdate(Actor_t *, U64);

void Move(Actor_t *, F64, F64);
void setPos(Actor_t *, F64, F64);

#endif
