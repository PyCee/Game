#include "collisionCapsule.h"

#include "../collisionController.h"
#include <stdlib.h>
#include <stdio.h>
#include "../vector.h"

collisionController genCollisionCapsule(vec3 *vecOne, vec3 *vecTwo, float rad)
{
	collisionController cap;
	vec3 *points[2] = {vecOne, vecTwo};
	float radius[1] = {rad};
	collisionControllerElement(&cap, &points, 2, COLLISION_VEC3);
	collisionControllerElement(&cap, &radius, 1, COLLISION_FLOAT);
	cap.collisionObjectType = COLLISION_TYPE_CAPSULE;
	return cap;
}
unsigned char collisionCapsuleCapsule(collisionController conOne, collisionController conTwo)
{
	float magSq = leastDistLineLineSq(*conOne._vec3[0], *conOne._vec3[1], *conTwo._vec3[0], *conTwo._vec3[1]);
	float distance = conOne._float[0] + conTwo._float[0];
	if(magSq <= distance * distance)
		return 1;
	return 0;
}

unsigned char collisionCapsuleSphere(collisionController cap, collisionController sph)
{
	float di = leastDistPointLineSq(*sph._vec3[0], *cap._vec3[0], *cap._vec3[1]);
	float distance = cap._float[0] + sph._float[0];
	if(di <= distance * distance)
		return 1;
	return 0;
}
unsigned char collisionSphereCapsule(collisionController sph, collisionController cap)
{
	return collisionCapsuleSphere(cap, sph);
}
