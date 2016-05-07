#ifndef _ACTORS_
#define _ACTORS_

#include "actorSelection.h"

// Various Components used by every Actor
struct IdentifierComponent *identifier;
struct TimeLineComponent *timeLine;
struct CallbackComponent *callback;
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
unsigned char addActor(void);
void genAllActors(void);
void freeAllActors(void);
void freeActor(void);
void updateActors(void);
void UselessFunction(void);
void toggleAllPause(void);
void printActor(void);

#endif /* _ACTOR_ */
