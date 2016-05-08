
#include "AIComponent.h"

#include "../actors.h"

void genAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void freeAIComponent() {
	assignAIUpdate(UselessUpdate);
}
void updateAIComponent(unsigned short deltaMS) {
	AI_UPDATE(deltaMS);
}
void assignAIUpdate(void (*updateFunction)(unsigned short)) {
	AI_UPDATE = updateFunction;
}

void UselessUpdate(unsigned short deltaMS) {
}
