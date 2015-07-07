
#include "dataTypes.h"
#include "dyn_actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "math/vector.h"
#include "math/normal.h"
#include "math/matrix.h"


void genAllDyn_Actors
(void)
{
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		Dyn_Actors.ActiveActor[actorID] = 0;
		genActor(actorID);
		actorID++;
	}
}
void freeAllDyn_Actors
(void)
{
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		freeActor(actorID);
		actorID++;
	}
}
void genActor
(U8 actorID)
{
	if (Dyn_Actors.ActiveActor[actorID])
		return;
	else
	printf("Gening Actor %d\n", actorID);
	genIdentifierComponent(actorID);
	genAIComponent(actorID);
	genAudioComponent(actorID);
	genDirectionComponent(actorID);
	genPhysicsComponent(actorID);
	genCollisionsComponent(actorID);
}
void freeActor
(U8 actorID)
{
	if (!Dyn_Actors.ActiveActor[actorID])
		return;
	printf("Freeing Actor %d\n", actorID);
	freeCollisionsComponent(actorID);
	freePhysicsComponent(actorID);
	freeDirectionComponent(actorID);
	freeAudioComponent(actorID);
	freeAIComponent(actorID);
	freeIdentifierComponent(actorID);
	Dyn_Actors.ActiveActor[actorID] = 0;
}
void updateDyn_Actors
(void)
{
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		if (Dyn_Actors.ActiveActor[actorID])
		{
			updateAIComponent(actorID, getPrevFrameDuration(getGlobalTimeLine()));
		}
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		if (Dyn_Actors.ActiveActor[actorID])
		{
			updateAudioComponent(actorID, getPrevFrameDuration(getGlobalTimeLine()));
		}
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		if (Dyn_Actors.ActiveActor[actorID])
		{
			updatePhysicsComponent(actorID, getPrevFrameDuration(getGlobalTimeLine()));
		}
		actorID++;
	}
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		if (Dyn_Actors.ActiveActor[actorID])
		{
			updateCollisionsComponent(actorID, getPrevFrameDuration(getGlobalTimeLine()));
		}
		actorID++;
	}
}
U8 AddActor
(void)
{
	U8 firstInactiveActor = getFirstInactiveDyn_Actor();
	if (firstInactiveActor < MAX_ACTOR_COUNT)
	{
		Dyn_Actors.ActiveActor[firstInactiveActor] = 1;
		printf("Adding ActorID: %d\n", firstInactiveActor);
		return firstInactiveActor;
	}
	return MAX_ACTOR_COUNT;
}
U8 getFirstInactiveDyn_Actor
(void)
{
	U8 actorID = 0;
	while (actorID < MAX_ACTOR_COUNT)
	{
		if (!Dyn_Actors.ActiveActor[actorID])
			return actorID;
		actorID++;
	}
	printf("ERROR::AddActor(void) called after ActiveActors array was filled::\
			First Inactive Actor: %d::MAX_ACTOR_COUNT: %d\n", MAX_ACTOR_COUNT, getFirstInactiveDyn_Actor());
	return MAX_ACTOR_COUNT;
}
