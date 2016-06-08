#include "collisionPlane.h"

#include "../collisionController.h"
#include "collisionCapsule.h"
#include "collisionSphere.h"
#include <stdlib.h>
#include <stdio.h>
#include "../vector.h"

float distancePlanePoint(collisionController pla, vec3 poi)
{
	return dotProduct(*pla.PLANE_NORMAL, poi) + pla.PLANE_D;
}
collisionController genCollisionPlane(vec3 *pos, vec3 *norm)
{
	collisionController pla;
	vec3 *vectors[2] = {pos, norm};
	float D[1] = {dotProduct(scaleVec3(*norm, -1), *pos)};
	collisionControllerElement(&pla, &vectors, 2, COLLISION_VEC3);
	collisionControllerElement(&pla, &D, 1, COLLISION_FLOAT);
	pla.collisionObjectType = COLLISION_TYPE_PLANE;
	return pla;
}
collisionController genCollisionPlaneFromTriangle(vec3 *p1, vec3 *p2, vec3 *p3)
{
	vec3 *norm = malloc(sizeof(vec3));
	*norm = normalizeVec3(crossProduct(subtractVec3Vec3(*p1, *p2), subtractVec3Vec3(*p3, *p1)));
	return genCollisionPlane(p1, norm);
}
unsigned char collisionPlanePlane(collisionController cyl1, collisionController cyl2)//TODO: do and test
{
	return 0;
}
unsigned char collisionPlaneCapsule(collisionController pla, collisionController cap)
{
	return (distancePlanePoint(pla, *cap.CAPSULE_P1) < cap.CAPSULE_RADIUS) || (distancePlanePoint(pla, *cap.CAPSULE_P2) < cap.CAPSULE_RADIUS);
}
unsigned char collisionCapsulePlane(collisionController cap, struct collisionController pla)
{
	return collisionPlaneCapsule(pla, cap);
}
unsigned char collisionPlaneSphere(collisionController pla, collisionController sph)
{
	return distancePlanePoint(pla, *sph.SPHERE_P1) < sph.SPHERE_RADIUS;
}
unsigned char collisionSpherePlane(collisionController sph, collisionController pla)
{
	return collisionPlaneSphere(pla, sph);
}
