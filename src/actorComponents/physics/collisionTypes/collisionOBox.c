#include "collisionOBox.h"
#include "../collisionController.h"
#include "../vector.h"

collisionController genCollisionOBox(vec3 *vecOne, float halfSize)
{
	collisionController box;
	vec3 *points[1] = {vecOne};
	float radius[1] = {halfSize};
	collisionControllerElement(&box, &points, 1, COLLISION_VEC3);
	collisionControllerElement(&box, &radius, 1, COLLISION_FLOAT);
	box.collisionObjectType = COLLISION_TYPE_OBOX;
	return box;
}
unsigned char collisionOBoxOBox(collisionController box1, collisionController box2)
{
	return 0;
}
