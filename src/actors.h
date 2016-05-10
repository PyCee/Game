#ifndef _ACTORS_
#define _ACTORS_

#include "actorSelection.h"

// Various Components used by every Actor
struct IdentifierComponent **identifier;
struct TimelineComponent **localTimeline;
struct CallbackComponent **callback;
struct AudioComponent **audio;
struct DirectionComponent **direction;
struct PhysicsComponent **physics;
struct AIComponent **ai;
struct LightingComponent **lighting;
struct ModelComponent **model;
struct RenderComponent **render;

extern unsigned char numActors;
extern unsigned char allActorsPaused;

void initActorComponents(void);
unsigned char addActor(void);
void freeAllActors(void);
void freeActor(void);
void updateActors(void);
void UselessFunction(void);
void toggleAllPause(void);
void printActor(void);

#endif /* _ACTOR_ */
