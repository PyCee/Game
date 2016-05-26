#ifndef _ACTORS_
#define _ACTORS_

#include "actorSelection.h"

// Various Components used by every Actor
extern struct IdentifierComponent **identifier;
extern struct TimelineComponent **localTimeline;
extern struct CallbackComponent **callback;
extern struct AudioComponent **audio;
extern struct DirectionComponent **direction;
extern struct PhysicsComponent **physics;
extern struct AIComponent **ai;
extern struct LightingComponent **lighting;
extern struct ModelComponent **model;
extern struct RenderComponent **render;

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
