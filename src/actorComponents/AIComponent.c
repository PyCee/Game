
#include "AIComponent.h"

#include "../actors.h"

void genAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void freeAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void updateAIComponent(unsigned short deltaMS) {
	AI[getActor()].update(deltaMS);
}
void assignAIUpdate(void (*updateFunction)(unsigned short)) {
	AI[getActor()].update = updateFunction;
}

void UselessUpdate(unsigned short deltaMS) {
}
