#include "collisionDetection.h"

#include "collisionData.h"
#include "../physicsComponent.h"
#include "octree.h"
#include "../../actors.h"
#include "physicsAttributeController.h"
#include "../../actorList.h"
#include "collisionController.h"
#include "vector.h"
#include "collisionTypes/collisionPlane.h"
#include "collisionTypes/collisionSphere.h"
#include "../directionComponent.h"
#include <stdlib.h>

static actorList possibleActorCollisions(void);
static collisionData *colSphereTriangle(collisionController, vec3 *, vec3 *, vec3 *);
static char pointOnTriangle(vec3, vec3, vec3, vec3);

collisionData *collisionDetection(void)
{
	actorList possibleCollides = possibleActorCollisions(); //TODO: go through with more specific collisions with actors in possibleCollides
				//TODO: test if octree system is functioning as expected
	collisionData *data = 0;
	unsigned char id = getActor();
	collisionController boundingBox = *BOUNDING_BOX;
	int index = 0;
	while(index < possibleCollides.numActors){
		bindActor(possibleCollides.list[index]);
		if(collisionAABoxAABox(boundingBox, BOUNDING_BOX) == 0){
			removeActorListID(&possibleCollides, getActor());
			continue;
		}
		
		index++;
	}
	bindActor(id);
	// TODO: test actors from possibleCollides more in-depth
	
	//collisionData *data = ...;
	
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
	for(index = 0; index < actors.numActors; index++){
		if(index == id)
			continue;
		bindActor(index);
		if(isOctreeParent(activeOctree, CONTAINING_OCTREE_NODE))
			addActorListID(&possibleCollides, index);
	}
	bindActor(id);
	return possibleCollides;
}
/*static collisionData *colSpherePolysoup(collisionController sph, (void) *soup)
{
	int index;
	float smallestCollisionTime = 1;
	int closestCollisionTriangleIndex = 0;
	collisionData *data;
	collsionData *collidingTriangle = malloc(sizeof(collisionData));
	*collidingTriangle = genCollisionData();
	
	for(index = 0; index < soup.numPolygons; index++){
		if(data = colSphereTriangle(sph, tri1, tri2, tri3) && data->t < collidingTriangle->t){
				closestCollisionTriangleIndex = index;
				*collidingTriangle = *data;
		}
		freeCollisionData(data);
		if(data) free(data);
	}
	
	
	return 0;
}*/
static collisionData *colSphereTriangle(collisionController sph, vec3 *p1, vec3 *p2, vec3 *p3)
{
	vec3 velocity = subtractVec3Vec3(*PREVIOUSPOSITION, *POSITION);
	collisionData *data = 0;
	collisionController pla = genCollisionPlaneFromTriangle(p1, p2, p3);
	float den = dotProduct(*pla.PLANE_NORMAL, velocity);
	float dist = distancePlanePoint(pla, *sph.SPHERE_P1);//TODO: make this the point from previousPosition
	float t0, t1;
	if(den == 0){// sphere is traveling parrallel to plane
		if(dist <= sph.SPHERE_RADIUS){//colliding at all times
			data = malloc(sizeof(collisionData));
			*data->normal = *pla.PLANE_NORMAL;
			*data->validActorPosition = subtractVec3Vec3(*sph.SPHERE_P1, scaleVec3(*pla.PLANE_NORMAL, 2 * sph.SPHERE_RADIUS - dist));
			*data->remainingVelocity = velocity;
			data->t = 0;
		}
		return data;
	}
	t0 = (1 - dist) / den;
	t1 = (-1 - dist) / den;
	
	float tmp = t0;
	t0 = (t0 < t1) ? t0 : t1;
	t1 = (tmp < t1) ? t1 : tmp;
	if(t0 > 1 || t1 < 0) return data;// no collision
		
	vec3 contactSph = subtractVec3Vec3(*sph.SPHERE_P1, scaleVec3(velocity, t0));
	vec3 contactPoi = subtractVec3Vec3(contactSph, *pla.PLANE_NORMAL);
	// test if we need to replace 'pla.PLANE_NORMAL' with 'scaleVec3(pla.PLANE_NORMAL, sph.SPHERE_RADIUS)'
	
	//test if contactPoi is on the specific triangle
	if(pointOnTriangle(contactPoi, *p1, *p2, *p3)){
		
		data = malloc(sizeof(collisionData));
		*data = genCollisionData();
		*data->normal = *pla.PLANE_NORMAL;
		*data->validActorPosition = contactSph;
		*data->remainingVelocity = velocity;
		data->t = t0;
		return data;
	}//TODO test triangle points and lines with swept sphere
	float A = dotProduct(velocity, velocity);
	float B = 2 * dotProduct(velocity, subtractVec3Vec3(contactSph, *p1));
	float C = magnitudeVec3Sq(subtractVec3Vec3(*p1, contactSph)) - 1;
	//TODO: solve quadratic equation
	
}
static char pointOnTriangle(vec3 poi, vec3 p1, vec3 p2, vec3 p3)
{
	// Compute vectors        
	vec3 v0 = subtractVec3Vec3(p3, p1);
	vec3 v1 = subtractVec3Vec3(p2, p1);
	vec3 v2 = subtractVec3Vec3(poi, p1);
	
	// Compute dot products
	float dot00 = dotProduct(v0, v0);
	float dot01 = dotProduct(v0, v1);
	float dot02 = dotProduct(v0, v2);
	float dot11 = dotProduct(v1, v1);
	float dot12 = dotProduct(v1, v2);
	
	// Compute barycentric coordinates
	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;
	
	// Check if point is in triangle
	return (u >= 0) && (v >= 0) && (u + v < 1);
}
