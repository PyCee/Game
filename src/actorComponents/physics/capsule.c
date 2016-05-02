
#include "capsule.h"

#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

capsule genCapsule(vec3 * vecOne, vec3 *vecTwo, float rad)
{
	capsule cap;
	cap.point[0] = malloc(sizeof(vec3));
	cap.point[1] = malloc(sizeof(vec3));
	*cap.point[0] = *vecOne;
	*cap.point[1] = *vecTwo;
	cap.radius = rad;
	return cap;
}
void freeCapsule(capsule *cap)
{
	free(cap->point[0]);
	free(cap->point[1]);
	cap->point[0] = 0;
	cap->point[1] = 0;
}
unsigned char collisionCapsuleCapsule(capsule capOne, capsule capTwo)
{
	vec3 u = subtractVec3Vec3(*capOne.point[1], *capOne.point[0]);
	vec3 v = subtractVec3Vec3(*capTwo.point[1], *capTwo.point[0]);
	vec3 w = subtractVec3Vec3(*capTwo.point[0], *capOne.point[0]);
	
	float a = dotProduct(u, u);
	float b = dotProduct(u, v);
	float c = dotProduct(v, v);
	float d = dotProduct(u, w);
	float e = dotProduct(v, w);
	float s, t;
	
	float den = a * c - (b * b);
	if(den == 0){
		s = 0;
		t = d / b;// = e / c;
	} else{
		s = (b * e - c * d) / den;
		s *= (s < 0) ? -1: 1;
		t = (a * e - b * d) / den;
	}
	t *= (t < 0) ? -1: 1;
	vec3 base = subtractVec3Vec3(*capOne.point[0], *capTwo.point[0]);
	vec3 change = subtractVec3Vec3(scaleVec3(u, s), scaleVec3(v, t));
	printf("s = %f\nt = %f\n", s, t);
	
	vec3 difference = addVec3Vec3(base, change);
	float distance = capOne.radius + capTwo.radius;
	printf("distance * distance = %f\n", distance * distance);
	printf("mag sq = %f\n", magnitudeVec3Sq(difference));
	
	if(magnitudeVec3Sq(difference) <= distance * distance)
		return 1;
	return 0;
}
