
#include "AIComponent.h"

#include "../actors.h"
#include <stdlib.h>
#include "physics/vector.h"
#include "physicsComponent.h"
#include "physics/physicsAttributeController.h"
#include "directionComponent.h"

void genAIComponent() {
	assignAIUpdate(UselessUpdate);
	AI_MOVE_TARGET = malloc(sizeof(vec3));
	*AI_MOVE_TARGET = genVec3(0.0, 0.0, 0.0);
	AI_CONTROLLED_MOVEMENT = malloc(sizeof(vec3));
	*AI_CONTROLLED_MOVEMENT = genVec3(0.0, 0.0, 0.0);
	bindPhysicsAttribute(VEL, AI_CONTROLLED_MOVEMENT, 1,  noRotationVec4); // TODO: load actor from file before this. Cannot use SPEED for this line as is.
	AI_STATE = 0;
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
