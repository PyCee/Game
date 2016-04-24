
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/applyImpulses.h"
#include "physics/updatePosition.h"
#include "physics/physicsAttributeController.h"
#include "physics/vector.h"
#include "../math/quaternion.h"
#include "../math/matrix.h"
#include "directionComponent.h"

void genPhysicsComponent()
{
	POS = malloc(sizeof(physicsAttributeController));
	*POS = genPhysicsAttributeController(POS_ATTRIBUTES);
	VEL = malloc(sizeof(physicsAttributeController));
	*VEL = genPhysicsAttributeController(VEL_ATTRIBUTES);
	ACC = malloc(sizeof(physicsAttributeController));
	*ACC = genPhysicsAttributeController(ACC_ATTRIBUTES);
	JRK = malloc(sizeof(physicsAttributeController));
	*JRK = genPhysicsAttributeController(JRK_ATTRIBUTES);
	
	PREVIOUSPOSITION = malloc(sizeof(vec3));
	*PREVIOUSPOSITION = *POSITION;
	
	GRAVITY = malloc(sizeof(vec3));
	*GRAVITY = genVec3(0.0, -1 * ACC_GRAVITY, 0.0);
	vec4 *noRotation = malloc(sizeof(vec4));
	*noRotation = UnitQuaternion(genVec3(0, 0, 1), 0);
	bindPhysicsAttribute(ACC, GRAVITY, 1,  noRotation);
	SPEED = 0.0;
	SPEED_SIDE = 0.9;
	SPEED_BACK = 0.5;
}
void freePhysicsComponent() {
	freePhysicsAttributeController(POS);
	freePhysicsAttributeController(VEL);
	freePhysicsAttributeController(ACC);
	freePhysicsAttributeController(JRK);
	free(POS);
	free(VEL);
	free(ACC);
	free(JRK);
	free(GRAVITY);
}

void updatePhysicsComponent(unsigned short deltaMS)
{
	applyPhysicsImpulses();
	updatePosition(deltaMS);
}







