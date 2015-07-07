
#ifndef _DYN_ACTORS_
#define _DYN_ACTORS_

#include "DynActorComponents/identifierComponent.h"
#include "DynActorComponents/AIComponent.h"
#include "DynActorComponents/audioComponent.h"
#include "DynActorComponents/directionComponent.h"
#include "DynActorComponents/physicsComponent.h"
#include "DynActorComponents/collisionsComponent.h"

#define MAX_ACTOR_COUNT 10
typedef struct _Dyn_Actors_t
{
	// Various Components used by every Dynamic Actor
	IdentifierComponent_t		identifier		[MAX_ACTOR_COUNT];
	AIComponent_t 					AI						[MAX_ACTOR_COUNT];
	AudioComponent_t				audio					[MAX_ACTOR_COUNT];
	DirectionComponent_t		direction			[MAX_ACTOR_COUNT];
	PhysicsComponent_t 			physics				[MAX_ACTOR_COUNT];
	CollisionsComponent_t		collisions		[MAX_ACTOR_COUNT];
	
	U8	 										ActiveActor		[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
} Dyn_Actors_t;

Dyn_Actors_t Dyn_Actors;

void	genAllDyn_Actors						(void);
void	freeAllDyn_Actors						(void);
void	genActor										(U8);
void	freeActor										(U8);
void	updateDyn_Actors						(void);
U8		getFirstInactiveDyn_Actor		(void);
U8 		AddActor										(void);

/*
void Move(Dyn_Actors_t *, F64, F64);
void setPos(Dyn_Actors_t *, F64, F64);
*/

#endif /* _DYN_ACTOR_ */
