#include "collisionAABox.h"
#include "../collisionController.h"
#include "../vector.h"
#include <stdlib.h>
#include <stdio.h>

collisionController genCollisionAABox(vec3 *vecOne, float halfWidth, float halfHeight, float halfLength)
{
	collisionController cap;
	vec3 *points[1] = {vecOne};
	float radius[3] = {halfWidth, halfHeight, halfLength};
	collisionControllerElement(&cap, &points, 1, COLLISION_VEC3);
	collisionControllerElement(&cap, &radius, 3, COLLISION_FLOAT);
	cap.collisionObjectType = COLLISION_TYPE_AABOX;
	return cap;
}
unsigned char collisionAABoxAABox(collisionController boxOne, collisionController boxTwo)
{
	return boxOne._vec3[0]->vec[0] - boxOne._float[0] < boxTwo._vec3[0]->vec[0] + boxTwo._float[0]
			&& boxOne._vec3[0]->vec[0] + boxOne._float[0] > boxTwo._vec3[0]->vec[0] - boxTwo._float[0]
			&& boxOne._vec3[0]->vec[1] - boxOne._float[1] < boxTwo._vec3[0]->vec[1] + boxTwo._float[1]
			&& boxOne._vec3[0]->vec[1] + boxOne._float[1] > boxTwo._vec3[0]->vec[1] - boxTwo._float[1]
			&& boxOne._vec3[0]->vec[2] - boxOne._float[2] < boxTwo._vec3[0]->vec[2] + boxTwo._float[2]
			&& boxOne._vec3[0]->vec[2] + boxOne._float[2] > boxTwo._vec3[0]->vec[2] - boxTwo._float[2];
}
unsigned char collisionAABoxSphere(collisionController box, collisionController sph)
{
	vec3 *mx = malloc(sizeof(vec3));
	vec3 *mn = malloc(sizeof(vec3));
	
	*mx = genVec3(box._vec3[0]->vec[0] + box._float[0], 0.0, 0.0);
	*mn = genVec3(box._vec3[0]->vec[0] - box._float[0], 0.0, 0.0);
	vec3 v = subtractVec3Vec3(*mx, *mn);
	vec3 w = subtractVec3Vec3(*sph._vec3[0], *mn);
	float b = dotProduct(w, v) / dotProduct(v, v);
	b = (b > 1) ? 1 : b;
	b = (b < 0) ? 0 : b;
	b *= 2;
	b -= 1;
	float nearestX = box._vec3[0]->vec[0] + b * box._float[0];
	
	*mx = genVec3(0.0, box._vec3[0]->vec[1] + box._float[1], 0.0);
	*mn = genVec3(0.0, box._vec3[0]->vec[1] - box._float[1], 0.0);
	v = subtractVec3Vec3(*mx, *mn);
	w = subtractVec3Vec3(*sph._vec3[0], *mn);
	b = dotProduct(w, v) / dotProduct(v, v);
	b = (b > 1) ? 1 : b;
	b = (b < 0) ? 0 : b;
	b *= 2;
	b -= 1;
	float nearestY = box._vec3[0]->vec[1] + b * box._float[1];
	
	*mx = genVec3(0.0, 0.0, box._vec3[0]->vec[2] + box._float[2]);
	*mn = genVec3(0.0, 0.0, box._vec3[0]->vec[2] - box._float[2]);
	v = subtractVec3Vec3(*mx, *mn);
	w = subtractVec3Vec3(*sph._vec3[0], *mn);
	b = dotProduct(w, v) / dotProduct(v, v);
	b = (b > 1) ? 1 : b;
	b = (b < 0) ? 0 : b;
	b *= 2;
	b -= 1;
	float nearestZ = box._vec3[0]->vec[2] + b * box._float[2];
	
	free(mx);
	free(mn);
	vec3 AABoxPoint = genVec3(nearestX, nearestY, nearestZ);
	printVec3(AABoxPoint);
	if(magnitudeVec3Sq(subtractVec3Vec3(AABoxPoint, *sph._vec3[0])) <= sph._float[0] * sph._float[0])
		return 1;
	return 0;
}
unsigned char collisionSphereAABox(collisionController sph, collisionController box)
{
	return collisionAABoxSphere(box, sph);
}
unsigned char collisionAABoxCapsule(collisionController box, collisionController cap)
{
	//TODO: do.
}
unsigned char collisionCapsuleAABox(collisionController cap, collisionController box)
{
	return collisionAABoxCapsule(box, cap);
}
