#include "capsule.h"

#include "collisionController.h"
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

collisionController genCapsule(vec3 *vecOne, vec3 *vecTwo, float rad)
{
	collisionController cap;
	vec3 *points[2] = {vecOne, vecTwo};
	float radius[1] = {rad};
	collisionControllerElement(&cap, &points, 2, COLLISION_VEC3);
	collisionControllerElement(&cap, &radius, 1, COLLISION_FLOAT);
	return cap;
}
unsigned char collisionCapsuleCapsule(collisionController conOne, collisionController conTwo)
{
	vec3 u = subtractVec3Vec3(*conOne._vec3[1], *conOne._vec3[0]);
	vec3 v = subtractVec3Vec3(*conTwo._vec3[1], *conTwo._vec3[0]);
	vec3 w = subtractVec3Vec3(*conTwo._vec3[0], *conOne._vec3[0]);
	float a = dotProduct(u, u);
	float b = dotProduct(u, v);
	float c = dotProduct(v, v);
	float d = dotProduct(u, w);
	float e = dotProduct(v, w);
	float s, t;
	float den = a * c - (b * b);
	if(den == 0){
		s = 0;
		t = d / b;// or = e / c;
	} else{
		s = (b * e - c * d) / den;
		s *= (s < 0) ? -1: 1;
		t = (a * e - b * d) / den;
	}
	t *= (t < 0) ? -1: 1;
	vec3 base = subtractVec3Vec3(*conOne._vec3[0], *conTwo._vec3[0]);
	vec3 change = subtractVec3Vec3(scaleVec3(u, s), scaleVec3(v, t));
	
	vec3 difference = addVec3Vec3(base, change);
	float distance = conOne._float[0] + conTwo._float[0];
	
	if(magnitudeVec3Sq(difference) <= distance * distance)
		return 1;
	return 0;
}
