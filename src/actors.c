
#include "dataTypes.h"
#include "actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "ActorComponents/physics/vector.h"
#include "ActorComponents/direction/normal.h"

static U8 getFirstInactiveActor (void)
{
	U8 actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( !Actors.ActiveActor[actorID] )
			return actorID;
		actorID++;
	}
	printf("ERROR::getFirstInactiveActor(void) called after ActiveActors array was filled::\
			First Inactive Actor: %d::MAX_ACTOR_COUNT: %d\n", actorID, MAX_ACTOR_COUNT);
	// TODO: What Should I Return Here? For An Invalid actorID.
	return actorID;
}
static U8 AddActor (void)
{
	U8 firstInactiveActor = getFirstInactiveActor();
	if ( firstInactiveActor < MAX_ACTOR_COUNT ) {
		Actors.ActiveActor[firstInactiveActor] = 1;
		printf("Adding ActorID: %d\n", firstInactiveActor);
		return firstInactiveActor;
	}
	// TODO: What Should I Return Here? For An Invalid actorID.
	return firstInactiveActor;
}
U8 addDyn_Actor (void)
{
	U8 actorID = AddActor();
	Actors.ActorType[actorID] = DYN;
	return actorID;
}
U8 addSta_Actor (void)
{
	U8 actorID = AddActor();
	Actors.ActorType[actorID] = STA;
	return actorID;
}
static void genActor (U8 actorID)
{
	if ( Actors.ActiveActor[actorID] )
		return;
	printf("Gening Actor %d\n", actorID);
	genIdentifierComponent(actorID);
	genTimeLineComponent(actorID);
	genAIComponent(actorID);
	genAudioComponent(actorID);
	genDirectionComponent(actorID);
	genPhysicsComponent(actorID);
	genCollisionsComponent(actorID);
	genLightingComponent(actorID);
	genRenderComponent(actorID);
}
void genAllActors (void)
{
	U8 actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		Actors.ActiveActor[actorID] = 0;
		genActor(actorID);
		actorID++;
	}
}
void freeAllActors (void)
{
	U8 actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		freeActor(actorID);
		actorID++;
	}
}
void freeActor (U8 actorID)
{
	if ( !Actors.ActiveActor[actorID] )
		return;
	printf("Freeing Actor %d\n", actorID);
	freeRenderComponent(actorID);
	freeLightingComponent(actorID);
	freeCollisionsComponent(actorID);
	freePhysicsComponent(actorID);
	freeDirectionComponent(actorID);
	freeAudioComponent(actorID);
	freeAIComponent(actorID);
	freeTimeLineComponent(actorID);
	freeIdentifierComponent(actorID);
	Actors.ActiveActor[actorID] = 0;
}
void updateActors (void)
{
	U8 actorID = 0;
	U16 localTime[MAX_ACTOR_COUNT];
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			localTime[actorID] = updateTimeLineComponent(actorID);
			printf("local time: %hu\n", localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			if (Actors.ActorType[actorID] != STA)
				updateAIComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			updateAudioComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			updateDirectionComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			if (Actors.ActorType[actorID] != STA)
				updatePhysicsComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			updateCollisionsComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			updateLightingComponent(actorID, localTime[actorID]);
		actorID++;
	}
	actorID = 0;
	while ( actorID < MAX_ACTOR_COUNT ) {
		if ( Actors.ActiveActor[actorID] )
			updateRenderComponent(actorID, localTime[actorID]);
		actorID++;
	}
}
