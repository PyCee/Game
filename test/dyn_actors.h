
#ifndef _DYN_ACTORS_
#define _DYN_ACTORS_

// TODO: find out reason forward declaration is not enough to move forward
//typedef struct _Physics_t Physics_t;
#include "DynActorComponents/identifierComponent.h"
#include "DynActorComponents/AIComponent.h"
#include "DynActorComponents/directionComponent.h"
#include "DynActorComponents/physicsComponent.h"

#define MAX_ACTOR_COUNT 10
#define UNDEFINED_ACTOR_NAME "UNDEFINED_Dyn_Actor_NAME"
typedef struct _Matrix_t Normal_t;

static U8 ActorID = 0;
typedef struct _Dyn_Actors_t
{
	// Components used by every Dynamic Actor
	IdentifierComponent		identifier		[MAX_ACTOR_COUNT];
	AIComponent 					AI						[MAX_ACTOR_COUNT];
	DirectionComponent		direction			[MAX_ACTOR_COUNT];
	Physics_t 						physics				[MAX_ACTOR_COUNT];
	
	U8	 									ActiveActor		[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
} Dyn_Actors_t;

static Dyn_Actors_t Dyn_Actors;

void genDynActors();
void freeDynActors();

// look at
/*
void setBounds(Dyn_Actors_t *, F64, F64);
void Update(Dyn_Actors_t *, U64);

void UselessUpdate(Dyn_Actors_t *, U64);

F64 getPosX(Dyn_Actors_t *);
F64 getPosY(Dyn_Actors_t *);
F64 getPosZ(Dyn_Actors_t *);
F64 getHeight(Dyn_Actors_t *);
F64 getWidth(Dyn_Actors_t *);
F64 getLength(Dyn_Actors_t *);

void Move(Dyn_Actors_t *, F64, F64);
void setPos(Dyn_Actors_t *, F64, F64);
*/

#endif /* _DYN_ACTOR_ */
