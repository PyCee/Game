
#include "collisionPoint.h"
#include "../collisionController.h"
#include "../vector.h"
#include <stdlib.h>
#include <stdio.h>

collisionController genCollisionPoint(vec3 *poi)
{
	collisionController point;
	vec3 *location[1] = {poi};
	collisionControllerElement(&point, &location, 1, COLLISION_VEC3);
	point.collisionObjectType = COLLISION_TYPE_POINT;
	return point;
}

unsigned char collisionPointPoint(collisionController poiOne, collisionController poiTwo)
{
	return poiOne._vec3[0]->vec[0] == poiTwo._vec3[0]->vec[0] &&
		poiOne._vec3[0]->vec[1] == poiTwo._vec3[0]->vec[1] &&
		poiOne._vec3[0]->vec[2] == poiTwo._vec3[0]->vec[2];
}
unsigned char collisionPointSphere(collisionController poi, collisionController sph)
{
	vec3 diff = subtractVec3Vec3(*poi._vec3[0], *sph._vec3[0]);
	return (magnitudeVec3Sq(diff) <= (sph._float[0] * sph._float[0]));
}
unsigned char collisionSpherePoint(collisionController sph, collisionController poi)
{
	return collisionPointSphere(poi, sph);
}
unsigned char collisionPointAABox(collisionController poi, collisionController box)
{
	vec3 place = *poi._vec3[0];
	return place.vec[0] <= box._vec3[0]->vec[0] + box._float[0] &&
		place.vec[0] >= box._vec3[0]->vec[0] - box._float[0] &&
		place.vec[1] <= box._vec3[0]->vec[1] + box._float[1] &&
		place.vec[1] >= box._vec3[0]->vec[1] - box._float[1] &&
		place.vec[2] <= box._vec3[0]->vec[2] + box._float[2] &&
		place.vec[2] >= box._vec3[0]->vec[2] - box._float[2];
}
unsigned char collisionAABoxPoint(collisionController box, collisionController poi)
{
	return collisionPointAABox(poi, box);
}
unsigned char collisionPointCapsule(collisionController poi, collisionController cap)
{
	return (leastDistPointLineSq(*poi._vec3[0], *cap._vec3[0], *cap._vec3[1]) <= cap._float[0] * cap._float[0]);
}
unsigned char collisionCapsulePoint(collisionController cap, collisionController poi)
{
	return collisionPointCapsule(poi, cap);
}

