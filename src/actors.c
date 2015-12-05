#include "dataTypes.h"
#include "actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "actorComponents/physics/vector.h"
#include "actorComponents/direction/normal.h"
#include "actorSelection.h"

void initActorComponents(void) {
	initRender();
}
static void bindFirstInactiveActor(void) {
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (!Actors.ActiveActor[getActor()])
			return;
		actorID++;
	}
	printf(
			"ERROR::getFirstInactiveActor(void) called after ActiveActors array was filled::\
			First Inactive Actor: %d::MAX_ACTOR_COUNT: %d\n",
			actorID, MAX_ACTOR_COUNT);
	// TODO: What Should I Return Here? For An Invalid actorID.
}
static void AddActor(void) {
	bindFirstInactiveActor();
	Actors.ActiveActor[getActor()] = 1;
	printf("Adding ActorID: %d\n", getActor());
}
void addDyn_Actor(void) {
	AddActor();
	Actors.identifier[getActor()].type = "dynamic";
}
void addSta_Actor(void) {
	AddActor();
	Actors.identifier[getActor()].type = "static";
}
static void genActor(void) {
	if (Actors.ActiveActor[getActor()])
		return;
	printf("Gening Actor %d\n", getActor());
	genIdentifierComponent();
	genTimeLineComponent();
	genAudioComponent();
	genDirectionComponent();
	genPhysicsComponent();
	genCollisionsComponent();
	genAIComponent();
	genLightingComponent();
	genRenderComponent();
}
void freeActor(void) {
	if (!Actors.ActiveActor[getActor()])
		return;
	printf("Freeing Actor %d\n", getActor());
	freeRenderComponent();
	freeLightingComponent();
	freeAIComponent();
	freeCollisionsComponent();
	freePhysicsComponent();
	freeDirectionComponent();
	freeAudioComponent();
	freeTimeLineComponent();
	freeIdentifierComponent();
	Actors.ActiveActor[getActor()] = 0;
}
void genAllActors(void) {
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		Actors.ActiveActor[getActor()] = 0;
		genActor();
		actorID++;
	}
}
void freeAllActors(void) {
	U8 actorID = 0;
	U8 actorCount = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			actorCount++;
		freeActor();
		actorID++;
	}
	printf("Freed %i Actors.\n", actorCount);
}
void updateActors(void) {
	U8 actorID = 0;
	U16 localTime[MAX_ACTOR_COUNT];
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			localTime[getActor()] = updateTimeLineComponent();
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			updateAudioComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			updateDirectionComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			if (Actors.identifier[getActor()].type != "static")
				updatePhysicsComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			updateCollisionsComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			//if (Actors.ActorType[actorID] != STA)
			updateAIComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			updateLightingComponent(localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (Actors.ActiveActor[getActor()])
			updateRenderComponent(localTime[actorID]);
		actorID++;
	}
}
