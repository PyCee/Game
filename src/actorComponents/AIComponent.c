#include "../dataTypes.h"
#include "AIComponent.h"

#include "../actors.h"

void genAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void freeAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void updateAIComponent(U16 deltaMS) {
	Actors.AI[getActor()].update(deltaMS);
}
void assignAIUpdate(void (*updateFunction)(U16)) {
	Actors.AI[getActor()].update = updateFunction;
}

void UselessUpdate(U16 deltaMS) {
}
