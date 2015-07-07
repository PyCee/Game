
#include "../dataTypes.h"
#include "AIComponent.h"

#include "../dyn_actors.h"

void genAIComponent
(U8 actorID)
{
	assignAIUpdate(actorID, UselessUpdate);
}
void freeAIComponent
(U8 actorID)
{
	assignAIUpdate(actorID, UselessUpdate);
}
void updateAIComponent
(U8 actorID, U16 deltaMS)
{
	Dyn_Actors.AI[actorID].update(actorID, deltaMS);
}
void assignAIUpdate
(U8 actorID, void (*updateFunction)(U8, U16))
{
	Dyn_Actors.AI[actorID].update = updateFunction;
}

void UselessUpdate(U8 actorID, U16 deltaMS){}
