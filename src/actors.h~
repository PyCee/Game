
#ifndef _ACTORS_
#define _ACTORS_

#include "ActorComponents/identifierComponent.h"
#include "ActorComponents/timeLineComponent.h"
#include "ActorComponents/AIComponent.h"
#include "ActorComponents/audioComponent.h"
#include "ActorComponents/directionComponent.h"
#include "ActorComponents/physicsComponent.h"
#include "ActorComponents/collisionsComponent.h"
#include "ActorComponents/lightingComponent.h"
#include "ActorComponents/renderComponent.h"

#define DYN 0
#define STA 1

#define MAX_ACTOR_COUNT 20
typedef struct _Actors_t
{
	// Various Components used by every Dynamic Actor
	IdentifierComponent_t		identifier		[MAX_ACTOR_COUNT];
	TimeLineComponent_t			timeLine			[MAX_ACTOR_COUNT];
	AIComponent_t 					AI						[MAX_ACTOR_COUNT];
	AudioComponent_t				audio					[MAX_ACTOR_COUNT];
	DirectionComponent_t		direction			[MAX_ACTOR_COUNT];
	PhysicsComponent_t 			physics				[MAX_ACTOR_COUNT];
	CollisionsComponent_t		collisions		[MAX_ACTOR_COUNT];
	LightingComponent_t			lighting			[MAX_ACTOR_COUNT];
	RenderComponent_t				render				[MAX_ACTOR_COUNT];
	
	U8	 										ActiveActor		[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
	U8											ActorType			[MAX_ACTOR_COUNT];
} Actors_t;

Actors_t Actors;

U8 			addDyn_Actor						(void);
U8 			addSta_Actor						(void);
void		genAllActors						(void);
void		freeAllActors						(void);
void		freeActor								(U8);
void		updateActors						(void);

#endif /* _ACTOR_ */
