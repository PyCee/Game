#include "sphere.h"

#include <stdlib.h>
#include <stdio.h>
#include "collisionController.h"

#include "vector.h"

collisionController genSphere(vec3 *vec, float rad)
{
	collisionController con;
	vec3 *points[1] = {vec};
	float radius[1] = {rad};
	collisionControllerElement(&con, &points, 1, COLLISION_VEC3);
	collisionControllerElement(&con, &radius, 1, COLLISION_FLOAT);
	return con;
}
unsigned char collisionSphereSphere(collisionController sphOne, collisionController sphTwo)
{
	float radDist = sphOne._float[0] + sphTwo._float[0];
	vec3 diff = subtractVec3Vec3(*sphOne._vec3[0], *sphTwo._vec3[0]);
	float distSq = diff.vec[0] * diff.vec[0] + diff.vec[1] * diff.vec[1] + diff.vec[2] * diff.vec[2];
	unsigned char collide = 0;
	printf("if %f <= %f\n", distSq, radDist * radDist);
	if(distSq <= radDist * radDist)
		collide = 1;
	
	return collide;
	
}
