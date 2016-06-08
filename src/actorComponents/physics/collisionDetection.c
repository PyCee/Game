#include "collisionDetection.h"

#include "collisionData.h"
#include "../physicsComponent.h"
#include "octree.h"
#include "../../actors.h"
#include "../../actorList.h"
#include "collisionController.h"
#include "vector.h"
#include "collisionTypes/collisionPlane.h"
#include "collisionTypes/collisionSphere.h"
#include "../directionComponent.h"

static actorList possibleActorCollisions(void);
static char colSphereTriangle(collisionController, vec3 *, vec3 *, vec3 *);

collisionData collisionDetection(void)
{
	actorList possibleCollides = possibleActorCollisions(); //TODO: go through with more specific collisions with actors in possibleCollides
				//TODO: test if octree system is functioning as expected
	collisionData data = genCollisionData();
	
	// TODO: test various other actors from possibleCollides
	
	/*
	data.normal = 
	data.pointOfCollision = 
	data.validActorPosition = 
	data.remainingVelocity = subtractVec3Vec3(data.validActorPosition, *POSITION);
	*/
	
	return data;
}
unsigned char testCollision(collisionController col1, collisionController col2)
{
	return collisionTable[col1.collisionObjectType][col2.collisionObjectType](col1, col2);
}

static actorList possibleActorCollisions(void)
{
	actorList possibleCollides = genActorList();
	octreeNode *activeOctree = CONTAINING_OCTREE_NODE;
	unsigned int id = getActor();
	unsigned int index;
	for(index = 0; index < numActors; index++){
		if(index == id)
			continue;
		bindActor(index);
		if(isOctreeParent(activeOctree, CONTAINING_OCTREE_NODE))
			addActorListID(&possibleCollides, index);
	}
	bindActor(id);
	return possibleCollides;
}
static char colSphereTriangle(collisionController sph, vec3 *p1, vec3 *p2, vec3 *p3)
{
	collisionController pla = genCollisionPlaneFromTriangle(p1, p2, p3);
	float den = dotProduct(*pla.PLANE_NORMAL, *MOVEMENT);
	float dist = distancePlanePoint(pla, *sph.SPHERE_P1);//TODO: make this the point from previousPosition
	float t0, t1;
	if(den == 0){// sphere is traveling parrallel to plane
		if(dist <= sph.SPHERE_RADIUS){//colliding at all times
			t0 = 0;
			t1 = 1;
		} else{// no collision
			return 0;
		}
	} else{
		t0 = (1 - dist) / den;
		t1 = (-1 - dist) / den;
		if((t0 > 1 || t0 < 0) && (t1 > 1 || t1 < 0)){// no collision
			return 0;
		}
	}
	vec3 contactSph = subtractVec3Vec3(*sph.SPHERE_P1, scaleVec3(*MOVEMENT, t0));
	vec3 pointOnPlane = subtractVec3Vec3(contactSph, *pla.PLANE_NORMAL);
		// test if we need to replace 'pla.PLANE_NORMAL' with 'scaleVec3(pla.PLANE_NORMAL, sph.SPHERE_RADIUS)'
	
	//test if pointOnPlane is on the specific triangle
	
}
