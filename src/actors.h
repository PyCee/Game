#ifndef _ACTORS_
#define _ACTORS_

#include "actorSelection.h"

/*
#include "actorComponents/identifierComponent.h"
#include "actorComponents/timeLineComponent.h"
#include "actorComponents/audioComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/modelComponent.h"
#include "actorComponents/renderComponent.h"
*/

// Various Components used by every Dynamic Actor
struct IdentifierComponent *identifier;
struct TimeLineComponent *timeLine;
struct AudioComponent *audio;
struct DirectionComponent *direction;
struct PhysicsComponent *physics;
struct CollisionsComponent *collisions;
struct AIComponent *AI;
struct LightingComponent *lighting;
struct ModelComponent *model;
struct RenderComponent *render;

extern unsigned char ActiveActor[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
extern unsigned char allActorsPaused;

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
void printActor(void);

#endif /* _ACTOR_ */
