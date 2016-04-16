
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/vector.h"
#include "physics/physicsAttributeController.h"
#include "../math/quaternion.h"
#include "../math/matrix.h"

void genPhysicsComponent()
{
	POS = malloc(sizeof(physicsAttributeController));
	*POS = genPhysicsAttributeController();
	VEL = malloc(sizeof(physicsAttributeController));
	*VEL = genPhysicsAttributeController();
	ACC = malloc(sizeof(physicsAttributeController));
	*ACC = genPhysicsAttributeController();
	JRK = malloc(sizeof(physicsAttributeController));
	*JRK = genPhysicsAttributeController();
	
	GRAVITY = malloc(sizeof(vec3));
	*GRAVITY = genVec3(0.0, 1 * ACC_GRAVITY, 0.0);
	
	vec4 *noRotation = malloc(sizeof(vec4));
	*noRotation = UnitQuaternion(genVec3(0, 0, 1), 0);
	
	bindPhysicsAttribute(ACC, GRAVITY, 1,  noRotation);
	
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
	updatePosition(deltaMS);
}
void updatePosition(unsigned short deltaMS)
{
	unsigned char index;
	for(index = 0; index < ATTRIBUTE_QTY; index++){
		if(JRK->active[index])
			*(ACC->attribute[0]) = addVec3(*(ACC->attribute[0]), scaleVec3(applyRotationQuaternion(*(JRK->attribute[index]), *(JRK->adjustment[index])), JRK->multiplier[index] * deltaMS));
	}
	for(index = 0; index < ATTRIBUTE_QTY; index++){
		if(ACC->active[index]){
			*VEL->attribute[0] = addVec3(*(VEL->attribute[0]), scaleVec3(applyRotationQuaternion(*(ACC->attribute[index]), *(ACC->adjustment[index])), ACC->multiplier[index] * deltaMS));
		}
	}
	for(index = 0; index < ATTRIBUTE_QTY; index++){
		if(VEL->active[index])
			*POS->attribute[0] = addVec3(*(POS->attribute[0]), scaleVec3(applyRotationQuaternion(*(VEL->attribute[index]), *(VEL->adjustment[index])), VEL->multiplier[index] * deltaMS));
	}
}






