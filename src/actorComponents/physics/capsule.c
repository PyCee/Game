
#include "capsule.h"

#include <stdlib.h>

#include "vector.h"

capsule genCapsule(vec3 * vecOne, vec3 *vecTwo, float rad)
{
	capsule cap;
	cap.pointOne = malloc(sizeof(vec3));
	cap.pointTwo = malloc(sizeof(vec3));
	*cap.pointOne = *vecOne;
	*cap.pointTwo = *vecTwo;
	cap.radius = rad;
	return cap;
}
void freeCapsule(capsule *cap)
{
	free(cap->pointOne);
	free(cap->pointTwo);
}
unsigned char collisionCapsuleCapsule(capsule *capOne, capsule *capTwo)
{
	// float 0 <= n <= 1
	// n = point along line
	// vec3 dir = addVec3Vec3(*cap.pointOne, scaleVec3(*cap.pointTwo, -1.0));
	// vec3 line = addVec3Vec3(cap.pointOne, scaleVec3(dir, n));
	
	return 0;
}
