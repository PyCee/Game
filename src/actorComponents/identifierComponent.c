#include "../dataTypes.h"
#include "identifierComponent.h"

#include "../actors.h"

void genIdentifierComponent() {
	Actors.identifier[getActor()].ActorName = UNDEFINED_NAME;
}
void freeIdentifierComponent() {
	Actors.identifier[getActor()].ActorName = 0;
}
