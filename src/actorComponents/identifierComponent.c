
#include "identifierComponent.h"

#include "../actors.h"

void genIdentifierComponent() {
	Actors.identifier[getActor()].name = "default";
}
void freeIdentifierComponent() {
	Actors.identifier[getActor()].name = 0;
}
