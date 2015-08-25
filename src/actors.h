
#ifndef _ACTORS_
#define _ACTORS_

#include "actorCounts.h"

#include "actorComponents/identifierComponent.h"
#include "actorComponents/timeLineComponent.h"
#include "actorComponents/audioComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/renderComponent.h"
typedef struct _Actors_t
{
	// Various Components used by every Dynamic Actor
	IdentifierComponent_t		identifier		[MAX_ACTOR_COUNT];
	TimeLineComponent_t		timeLine		[MAX_ACTOR_COUNT];
	AudioComponent_t		audio			[MAX_ACTOR_COUNT];
	DirectionComponent_t		direction		[MAX_ACTOR_COUNT];
	PhysicsComponent_t 		physics			[MAX_ACTOR_COUNT];
	CollisionsComponent_t		collisions		[MAX_ACTOR_COUNT];
	AIComponent_t 			AI			[MAX_ACTOR_COUNT];
	LightingComponent_t		lighting		[MAX_ACTOR_COUNT];
	RenderComponent_t		render			[MAX_ACTOR_COUNT];
	
	U8	 			ActiveActor		[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
	U8				ActorType		[MAX_ACTOR_COUNT];
} Actors_t;

Actors_t Actors;

void	initActorComponents(void);
U8 	addDyn_Actor						(void);
U8 	addSta_Actor						(void);
void	genAllActors						(void);
void	freeAllActors						(void);
void	freeActor						(U8);
void	updateActors						(void);

#endif /* _ACTOR_ */
