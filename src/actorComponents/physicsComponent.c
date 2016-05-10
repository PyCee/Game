
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
	*noRotation = UnitQuaternion(genVec3(0, 0, -1.0), 0);
	bindPhysicsAttribute(ACC, GRAVITY, 1,  noRotation);
	SPEED = 0.0;
	SPEED_SIDE = 0.9;
	SPEED_BACK = 0.5;
	
	HEIGHT = 1;
	WIDTH = 1;
	DRAW_BOUNDS = 1;
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
unsigned char CheckBoundingBoxCollision(unsigned char actorID) {
	//float Xsq = pow( POSX(getActor()) - POSX(actorID), 2);
	//float Zsq = pow( POSZ(getActor()) - POSZ(actorID), 2);
	//float distanceSq = Xsq + Zsq;
	unsigned char prevID = getActor();
	vec3 actOnePos = *POSITION;
	float actOneWidth = WIDTH;
	float actOneHeight = HEIGHT;
	bindActor(actorID);
	unsigned char collide;
	if (actOnePos.vec[0] - 0.5 * actOneWidth
			< POSITION->vec[0] + 0.5 * WIDTH
			&& actOnePos.vec[0] + 0.5 * actOneWidth
					> POSITION->vec[0] - 0.5 * WIDTH
			&& actOnePos.vec[1] < POSITION->vec[1] + HEIGHT
			&& actOnePos.vec[1] + actOneHeight > POSITION->vec[1])
		collide = 1;// Bounding Boxes Overlapping
	else
		collide = 0;// Bounding Boxes Not Overlapping
	bindActor(prevID);
	return collide;
}
