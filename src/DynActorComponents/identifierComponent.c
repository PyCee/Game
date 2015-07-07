
#include "../dataTypes.h"
#include "identifierComponent.h"

#include "../dyn_actors.h"

void genIdentifierComponent
(U8 actorID)
{
	Dyn_Actors.identifier[actorID].ActorName = UNDEFINED_NAME;
}
void freeIdentifierComponent
(U8 actorID)
{
	Dyn_Actors.identifier[actorID].ActorName = 0;
}
