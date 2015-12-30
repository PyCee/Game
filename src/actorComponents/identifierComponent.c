
#include "identifierComponent.h"

#include "../actors.h"

void genIdentifierComponent() {
	identifier[getActor()].name = "default";
}
void freeIdentifierComponent() {
	identifier[getActor()].name = 0;
}
