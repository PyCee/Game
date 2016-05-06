#include "sphere.h"

#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

sphere genSphere(struct vec3 *vec, float rad)
{
	sphere sph;
	sph.point = malloc(sizeof(vec3));
	*sph.point = *vec;
	sph.radius = rad;
	return sph;
}
void freeSphere(sphere *sph)
{
	free(sph->point);
	sph->point = 0;
}

unsigned char collisionSphereSphere(sphere sphOne, sphere sphTwo)
{
	float radDist = sphOne.radius + sphTwo.radius;
	vec3 diff = subtractVec3Vec3(*sphOne.point, *sphTwo.point);
	float distSq = diff.vec[0] * diff.vec[0] + diff.vec[1] * diff.vec[1] + diff.vec[2] * diff.vec[2];
	unsigned char collide = 0;
	printf("if %f <= %f\n", distSq, radDist * radDist);
	if(distSq <= radDist * radDist)
		collide = 1;
	
	return collide;
	
}
