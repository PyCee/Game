
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/applyImpulses.h"
#include "physics/updatePosition.h"
#include "physics/octree.h"
#include "physics/checkOctree.h"
#include "physics/physicsAttributeController.h"
#include "physics/collisionTypes/collisionSphere.h"
#include "physics/collisionTypes/collisionCapsule.h"
#include "physics/collisionTypes/collisionOBox.h"
#include "physics/collisionTypes/collisionAABox.h"
#include "physics/collisionTypes/collisionPoint.h"
#include "physics/collisionTypes/collisionCylinder.h"
#include "physics/collisionController.h"
#include "physics/collisionDetection.h"
#include "physics/vector.h"
#include "../math/quaternion.h"
#include "../math/matrix.h"
#include "directionComponent.h"
#include "identifierComponent.h"
#include "physics/collisionData.h"

unsigned char (*collisionTable[COLLISION_TABLE_SIZE][COLLISION_TABLE_SIZE])(collisionController, collisionController);

void initPhysics(void)
{
	collisionTable[COLLISION_TYPE_CAPSULE][COLLISION_TYPE_CAPSULE] = collisionCapsuleCapsule;
	collisionTable[COLLISION_TYPE_CAPSULE][COLLISION_TYPE_SPHERE] = collisionCapsuleSphere;
	collisionTable[COLLISION_TYPE_CAPSULE][COLLISION_TYPE_AABOX] = collisionCapsuleAABox;
	collisionTable[COLLISION_TYPE_CAPSULE][COLLISION_TYPE_POINT] = collisionCapsulePoint;
	collisionTable[COLLISION_TYPE_CAPSULE][COLLISION_TYPE_CYLINDER] = collisionCapsuleCylinder;
	collisionTable[COLLISION_TYPE_SPHERE][COLLISION_TYPE_SPHERE] = collisionSphereSphere;
	collisionTable[COLLISION_TYPE_SPHERE][COLLISION_TYPE_CAPSULE] = collisionSphereCapsule;
	collisionTable[COLLISION_TYPE_SPHERE][COLLISION_TYPE_AABOX] = collisionSphereAABox;
	collisionTable[COLLISION_TYPE_SPHERE][COLLISION_TYPE_POINT] = collisionSpherePoint;
	collisionTable[COLLISION_TYPE_SPHERE][COLLISION_TYPE_CYLINDER] = collisionSphereCylinder;
	collisionTable[COLLISION_TYPE_AABOX][COLLISION_TYPE_AABOX] = collisionAABoxAABox;
	collisionTable[COLLISION_TYPE_AABOX][COLLISION_TYPE_SPHERE] = collisionAABoxSphere;
	collisionTable[COLLISION_TYPE_AABOX][COLLISION_TYPE_CAPSULE] = collisionAABoxCapsule;
	collisionTable[COLLISION_TYPE_AABOX][COLLISION_TYPE_POINT] = collisionAABoxPoint;
	collisionTable[COLLISION_TYPE_AABOX][COLLISION_TYPE_CYLINDER] = collisionAABoxCylinder;
	collisionTable[COLLISION_TYPE_POINT][COLLISION_TYPE_AABOX] = collisionPointAABox;
	collisionTable[COLLISION_TYPE_POINT][COLLISION_TYPE_SPHERE] = collisionPointSphere;
	collisionTable[COLLISION_TYPE_POINT][COLLISION_TYPE_CAPSULE] = collisionPointCapsule;
	collisionTable[COLLISION_TYPE_POINT][COLLISION_TYPE_POINT] = collisionPointPoint;
	collisionTable[COLLISION_TYPE_POINT][COLLISION_TYPE_CYLINDER] = collisionPointCylinder;
	collisionTable[COLLISION_TYPE_CYLINDER][COLLISION_TYPE_AABOX] = collisionCylinderAABox;
	collisionTable[COLLISION_TYPE_CYLINDER][COLLISION_TYPE_SPHERE] = collisionCylinderSphere;
	collisionTable[COLLISION_TYPE_CYLINDER][COLLISION_TYPE_CAPSULE] = collisionCylinderCapsule;
	collisionTable[COLLISION_TYPE_CYLINDER][COLLISION_TYPE_POINT] = collisionCylinderPoint;
	collisionTable[COLLISION_TYPE_CYLINDER][COLLISION_TYPE_CYLINDER] = collisionCylinderCylinder;
}
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
	
	MOVEMENT = malloc(sizeof(vec3));
	*MOVEMENT = genVec3(0.0, 0.0, 0.0);
	PREVIOUSPOSITION = malloc(sizeof(vec3));
	*PREVIOUSPOSITION = *POSITION;
	
	GRAVITY = malloc(sizeof(vec3));
	*GRAVITY = genVec3(0.0, -1 * ACC_GRAVITY, 0.0);
	bindPhysicsAttribute(ACC, GRAVITY, 1,  noRotationVec4);
	SPEED = 0.0;
	SPEED_SIDE = 1.0;
	SPEED_BACK = 1.0;
	
	HEIGHT = 1;
	WIDTH = 1;
	DRAW_BOUNDS = 1;
	BOUNDING_BOX = 0;
	CONTAINING_OCTREE_NODE = &globalOctree;
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
	
	if (strcmp(TYPE, "dynamic") == 0){
		applyPhysicsImpulses();
		updatePosition(deltaMS);
	}
	CONTAINING_OCTREE_NODE = checkOctree(CONTAINING_OCTREE_NODE);
	
	collisionData collision = collisionDetection();
	
	/* TODO: finish and test
	unsigned char numResponses = 0;
	while(collision.remainingVel->vec[0] ||
		collision.remainingVel->vec[1] ||
		collision.remainingVel->vec[2]){
		if(numResponses >= MAX_COLLISION_RESPONSES) *POSITION = *PREVIOUSPOSITION;
		collisionResponse(collision);
		collision = collisionDetection();
		numResponses++;
	}
	*/
}
unsigned char CheckBoundingBoxCollision(unsigned char actorID) {
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
