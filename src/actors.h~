#ifndef _ACTORS_
#define _ACTORS_

#include "actorSelection.h"

#include "actorComponents/identifierComponent.h"
#include "actorComponents/timeLineComponent.h"
#include "actorComponents/audioComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/renderComponent.h"
typedef struct _Actors_t {
	// Various Components used by every Dynamic Actor
	IdentifierComponent identifier[MAX_ACTOR_COUNT];
	TimeLineComponent timeLine[MAX_ACTOR_COUNT];
	AudioComponent audio[MAX_ACTOR_COUNT];
	DirectionComponent direction[MAX_ACTOR_COUNT];
	PhysicsComponent physics[MAX_ACTOR_COUNT];
	CollisionsComponent collisions[MAX_ACTOR_COUNT];
	AIComponent AI[MAX_ACTOR_COUNT];
	LightingComponent lighting[MAX_ACTOR_COUNT];
	RenderComponent render[MAX_ACTOR_COUNT];

	unsigned char ActiveActor[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
} Actors_t;

Actors_t Actors;
unsigned char allActorsPaused;

void initActorComponents(void);
void addActor(void);
void addDyn_Actor(void);
void addSta_Actor(void);
void genAllActors(void);
void freeAllActors(void);
void freeActor(void);
void updateActors(void);
void UselessFunction(void);
void toggleAllPause(void);

#endif /* _ACTOR_ */
