
#include "vector.h"

#include "../../math/pythag.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
vec2 genVec2(float X, float Y)
{
	vec2 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	return result;
}
vec3 genVec3(float X, float Y, float Z)
{
	vec3 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	return result;
}
vec4 genVec4(float X, float Y, float Z, float W)
{
	vec4 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	result.vec[3] = W;
	return result;
}
float magnitudeVec3Sq(vec3 vec)
{
	return vec.vec[0] * vec.vec[0] + vec.vec[1] * vec.vec[1] + vec.vec[2] * vec.vec[2];
}
vec3 normalizeVec3(vec3 vec)
{
	vec3 result;
	double change = PythagoreanTheorum(vec.vec[0], vec.vec[1], vec.vec[2]);
	if(change == 0){
		printf("Pythagorean Theorem equated out to 0 during normalization.\n");
		return genVec3(0, 0, 1);
	}
	return scaleVec3(vec, 1 / change);
}
vec3 addVec3Vec3(vec3 vecOne, vec3 vecTwo)
{
	vec3 result;
	result.vec[0] = vecOne.vec[0] + vecTwo.vec[0];
	result.vec[1] = vecOne.vec[1] + vecTwo.vec[1];
	result.vec[2] = vecOne.vec[2] + vecTwo.vec[2];
	return result;
}
vec3 subtractVec3Vec3(vec3 vecOne, vec3 vecTwo)
{
	return addVec3Vec3(vecOne, scaleVec3(vecTwo, -1));
}
unsigned char cmpVec3Vec3(vec3 vecOne, vec3 vecTwo)
{
	return vecOne.vec[0] == vecTwo.vec[0] &&
		vecOne.vec[1] == vecTwo.vec[1] &&
		vecOne.vec[2] == vecTwo.vec[2];
}
vec3 scaleVec3(vec3 vector, double scale)
{
	return genVec3(vector.vec[0] * scale, vector.vec[1] * scale, vector.vec[2] * scale);
}
float dotProduct(vec3 vecOne, vec3 vecTwo)
{
	return vecOne.vec[0] * vecTwo.vec[0] + vecOne.vec[1] * vecTwo.vec[1] + vecOne.vec[2] * vecTwo.vec[2];
}
vec3 crossProduct(vec3 vecOne, vec3 vecTwo)
{
	float X = vecOne.vec[1] * vecTwo.vec[2] - vecOne.vec[2] * vecTwo.vec[1];
	float Y = vecOne.vec[2] * vecTwo.vec[0] - vecOne.vec[0] * vecTwo.vec[2];
	float Z = vecOne.vec[0] * vecTwo.vec[1] - vecOne.vec[1] * vecTwo.vec[0];
	return genVec3(X, Y, Z);
}
void printVec3(vec3 vec)
{
	printf("[ %f, %f, %f]\n", vec.vec[0], vec.vec[1], vec.vec[2]);
}
void printVec4(vec4 vec)
{
	printf("[ %f, %f, %f, %f]\n", vec.vec[0], vec.vec[1], vec.vec[2], vec.vec[3]);
}
float leastDistPointLineSq(vec3 point, vec3 p1, vec3 p2)
{
	vec3 v = subtractVec3Vec3(p2, p1);
	vec3 w = subtractVec3Vec3(point, p1);
	
	float c1 = dotProduct(w, v);
	float c2 = dotProduct(v, v);
	
	float b = c1 / c2;
	b = (b > 1) ? 1 : b;
	b = (b < 0) ? 0 : b;
	vec3 closePoint = addVec3Vec3(p1, scaleVec3(v, b));
	return magnitudeVec3Sq(subtractVec3Vec3(point, closePoint));
}
float leastDistLineLineSq(vec3 p1, vec3 p2, vec3 l1, vec3 l2)
{
	vec3 u = subtractVec3Vec3(p2, p1);
	vec3 v = subtractVec3Vec3(l2, l1);
	vec3 w = subtractVec3Vec3(l1, p1);
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
	vec3 base = subtractVec3Vec3(p1, l1);
	vec3 change = subtractVec3Vec3(scaleVec3(u, s), scaleVec3(v, t));
	
	vec3 difference = addVec3Vec3(base, change);
	return magnitudeVec3Sq(difference);
}
float closestPointLinePoint(vec3 p1, vec3 p2, vec3 point)
{
	vec3 v = subtractVec3Vec3(p2, p1);
	vec3 w = subtractVec3Vec3(point, p1);
	
	float c1 = dotProduct(w, v);
	float c2 = dotProduct(v, v);
	
	float b = c1 / c2;
	b = (b > 1) ? 1 : b;
	b = (b < 0) ? 0 : b;
	return b;
}
float *closestPointsLineLine(vec3 p1, vec3 p2, vec3 l1, vec3 l2)
{
	vec3 u = subtractVec3Vec3(p2, p1);
	vec3 v = subtractVec3Vec3(l2, l1);
	vec3 w = subtractVec3Vec3(l1, p1);
	float a = dotProduct(u, u);
	float b = dotProduct(u, v);
	float c = dotProduct(v, v);
	float d = dotProduct(u, w);
	float e = dotProduct(v, w);
	static float points[2];
	float den = a * c - (b * b);
	if(den == 0){
		points[0] = 0;
		points[1] = d / b;// or = e / c;
	} else{
		points[0] = (b * e - c * d) / den;
		points[0] *= (points[0] < 0) ? -1: 1;
		points[1] = (a * e - b * d) / den;
	}
	points[1] *= (points[1] < 0) ? -1: 1;
	
	return points;
}
