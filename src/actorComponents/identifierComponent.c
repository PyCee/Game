
#include "identifierComponent.h"

#include "../actors.h"

void genIdentifierComponent() {
	identifier[getActor()].name = "default";
	identifier[getActor()].type = "notAssigned";
	identifier[getActor()].file = "actors.xml";
}
void freeIdentifierComponent() {
	identifier[getActor()].name = 0;
}
