#include "collisionCylinder.h"

#include "../collisionController.h"
#include "collisionCapsule.h"
#include <stdlib.h>
#include <stdio.h>
#include "../vector.h"

collisionController genCollisionCylinder(vec3 *p1, vec3 *p2, float rad)
{
	collisionController cyl = genCollisionCapsule(p1, p2, rad);
	cyl.collisionObjectType = COLLISION_TYPE_CYLINDER;
	return cyl;
}
unsigned char collisionCylinderCylinder(collisionController cyl1, collisionController cyl2)//TODO: test
{
	return 0;
}
unsigned char collisionCylinderSphere(collisionController cyl, collisionController sph)//TODO: test
{
	return 0;
}
unsigned char collisionSphereCylinder(collisionController sph, collisionController cyl)
{
	collisionCylinderSphere(cyl, sph);
}
unsigned char collisionCylinderPoint(collisionController cyl, collisionController poi)
{
	unsigned char capCollision = collisionCapsulePoint(cyl, poi);
	if(capCollision == 0){
		return 0;
	}
	float close = closestPointLinePoint(*cyl._vec3[0], *cyl._vec3[1], *poi._vec3[0]);
	return !(close == 1 || close == 0);
}
unsigned char collisionPointCylinder(collisionController poi, collisionController cyl)
{
	return collisionCylinderPoint(cyl, poi);
}
unsigned char collisionCylinderCapsule(collisionController cyl, collisionController cap)//TODO: test
{
	return 0;
}
unsigned char collisionCapsuleCylinder(collisionController cap, collisionController cyl)
{
	return collisionCylinderCapsule(cyl, cap);
}
unsigned char collisionCylinderAABox(collisionController cyl, collisionController box)//TODO: test
{
	return 0;
}
unsigned char collisionAABoxCylinder(collisionController box, collisionController cyl)
{
	return collisionCylinderAABox(cyl, box);
}
unsigned char collisionCylinderBox(collisionController cyl, collisionController box)//TODO: test
{
	return 0;
}
unsigned char collisionBoxCylinder(collisionController box, collisionController cyl)
{
	return collisionCylinderBox(cyl, box);
}
